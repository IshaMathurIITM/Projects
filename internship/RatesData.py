import MetaTrader5 as mt5
from datetime import datetime, timedelta
import pandas as pd
import os
import concurrent.futures

# Initialize MT5 connection
if not mt5.initialize():
    print("initialize() failed, error code =", mt5.last_error())
    quit()

# Define the timeframes to be fetched
timeframes = {
    'D1': mt5.TIMEFRAME_D1,
    'H4': mt5.TIMEFRAME_H4,
    'H1': mt5.TIMEFRAME_H1,
    'M30': mt5.TIMEFRAME_M30,
    'M15': mt5.TIMEFRAME_M15,
    'M5': mt5.TIMEFRAME_M5,
    'M1': mt5.TIMEFRAME_M1
}

# Define the start and end dates
start_date = datetime(2005, 1, 1)
end_date = datetime(2024, 1, 1)

# Create the base data directory if it doesn't exist
base_dir = "Data"
if not os.path.exists(base_dir):
    os.makedirs(base_dir)

# Function to fetch data in chunks
def fetch_data_chunk(symbol, timeframe, start, end):
    rates = mt5.copy_rates_range(symbol, timeframe, start, end)
    if rates is None:
        print(f"No data fetched for {symbol} {timeframe} for the range {start} to {end}")
    else:
        print(f"Fetched {len(rates)} records for {symbol} {timeframe} for the range {start} to {end}")
    return pd.DataFrame(rates)

# Function to fetch data for a given symbol and timeframe
def fetch_symbol_data(symbol):
    symbol_dir = os.path.join(base_dir, symbol)
    if not os.path.exists(symbol_dir):
        os.makedirs(symbol_dir)

    for timeframe_name, timeframe in timeframes.items():
        all_data = pd.DataFrame()
        current_date = start_date
        chunk_size = timedelta(days=365)

        while current_date < end_date:
            next_date = current_date + chunk_size
            if next_date > end_date:
                next_date = end_date
            chunk_data = fetch_data_chunk(symbol, timeframe, current_date, next_date)
            all_data = pd.concat([all_data, chunk_data], ignore_index=True)
            current_date = next_date

        # Check if the "time" column exists and convert it to datetime format
        if "time" in all_data.columns:
            all_data["time"] = pd.to_datetime(all_data["time"], unit="s")
        else:
            print(f"Column 'time' not found in the DataFrame for {symbol} {timeframe_name}.")

        # Save the data to a CSV file
        file_path = os.path.join(symbol_dir, f"{timeframe_name}.csv")
        all_data.to_csv(file_path, index=False)
        print(f"Data for {symbol} {timeframe_name} saved to {file_path}")

# List of major currency pairs
major_currency_pairs = ['EURUSD', 'GBPUSD', 'USDJPY', 'USDCHF', 'AUDUSD', 'USDCAD', 'NZDUSD']

# Use multithreading to fetch data for major currency pairs
with concurrent.futures.ThreadPoolExecutor(max_workers=10) as executor:
    executor.map(fetch_symbol_data, major_currency_pairs)

# Shutdown MT5 connection
mt5.shutdown()
