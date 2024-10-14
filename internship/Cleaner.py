import os
import pandas as pd
import concurrent.futures

# Define the base data directory
base_dir = "Data"

# Function to remove duplicate timestamps in a CSV file
def remove_duplicate_timestamps(file_path):
    # Read the CSV file into a DataFrame
    df = pd.read_csv(file_path)
    
    # Check if the "time" column exists
    if "time" in df.columns:
        # Remove duplicate rows based on the "time" column
        df.drop_duplicates(subset="time", keep='first', inplace=True)
        
        # Save the cleaned DataFrame back to the same CSV file
        df.to_csv(file_path, index=False)
        print(f"Cleaned duplicates in {file_path}")
    else:
        print(f"Column 'time' not found in {file_path}")

# Function to delete files that are 1KB in size
def delete_small_files(file_path):
    if os.path.getsize(file_path) == 1024:
        os.remove(file_path)
        print(f"Deleted 1KB file {file_path}")

# Function to check and remove empty directories
def delete_empty_directories(directory):
    if not os.listdir(directory):
        os.rmdir(directory)
        print(f"Deleted empty directory {directory}")

# Function to process all CSV files in the data directory
def clean_all_files(base_dir):
    with concurrent.futures.ThreadPoolExecutor(max_workers=10) as executor:
        futures = []
        
        for symbol_dir in os.listdir(base_dir):
            symbol_path = os.path.join(base_dir, symbol_dir)
            
            # Check if the path is a directory
            if os.path.isdir(symbol_path):
                for csv_file in os.listdir(symbol_path):
                    csv_file_path = os.path.join(symbol_path, csv_file)
                    
                    # Check if the path is a file and ends with .csv
                    if os.path.isfile(csv_file_path) and csv_file_path.endswith('.csv'):
                        futures.append(executor.submit(remove_duplicate_timestamps, csv_file_path))
                        futures.append(executor.submit(delete_small_files, csv_file_path))
                
                # Check and remove empty directories
                futures.append(executor.submit(delete_empty_directories, symbol_path))
        
        # Wait for all futures to complete
        concurrent.futures.wait(futures)

# Clean all files in the base directory
clean_all_files(base_dir)