### equity_funds_ver_1

## here I am going process and get returns for mutual fund data

''' 

To run this code, first import visualizing_mutual_fund
Run visual().get_data() to get and save all the data
Run visual().get_plots(), it will save all the plots
To compare the performance with benchmark, run visual().compare_fund_with_benchmark()

'''

from util import *
from products import *

today = dt.today()

class visual:
    def __init__(self, drive = 'd'):
        """
        Parameters
        ----------
        drive : str
            Drive name in which the data and plots are to be saved. Default value is 'F'.
        """
        
        self.location = f'{drive.upper()}:/PROJECT/Visualizing'
        os.makedirs(self.location, exist_ok = True)
        
        #Name of all the funds and ticker for them is available in equity_funds()
        self.funds = equity_funds()

    def get_data(self, day = today, years = 'na', update = True, columns = ['ticker']):
        """
        Parameters
        ----------
        day : datetime.date
            it's day in datetime.date format can be input as "datetime.date('your_date')" or "datetime.datetime("your_date")".
        years : int
            The number of years from today for which data is required, id "years = 'na'" then it will get all the historical data.
        update : bool
            By default is True. Whenever it is true, it updates the overwrite the current saved files.
        columns : list
            It's a list of unnecessary attributes/columns which need to be removed available in the data.
            
        Returns : None
        -------
            After successful execution, it print the path where the data is stored.
        """
        
        #Running it for each of the equity_class(or equity type)
        open_path = f'{self.location}/data/All Data Files'
        os.makedirs(open_path, exist_ok = True)
        
        for equity_class, funds in self.funds.items():
            
            #Creating different paths for each equity class
            path = f'{self.location}/data'
            file_path = f'{self.location}/data/{equity_class}'
            os.makedirs(file_path, exist_ok = True)
 
            #This is for individual fund
            for fund_name, ticker in funds.items():
            
                '''if update is False and file doesn't exist then it will create file for that equity_fund
                and if True then it will overwrite all the existing files as well'''
                if not update:
                    if not os.path.exists(f'{file_path}/{fund_name}.csv'):
                        if years == 'na':
                            
                            data = si.get_data(ticker, index_as_date = False)
                        else:    
                            #otherwise it will get data for the particular period
                            data = si.get_data(ticker, start_date = f'{today.year-years}-{today.month}-{today.day}',
                                               end_date = today, index_as_date = False)
                        data = self.process_data(data, columns = columns)
                        data.to_csv(f'{file_path}/{fund_name}.csv', index = True)
                        
                #Same for updating files except it updates all the files
                else:
                    if years == 'na':
                        data = si.get_data(ticker, index_as_date = False)
                        
                    else:
                        data = si.get_data(ticker, start_date = f'{today.year-years}-{today.month}-{today.day}',
                                           end_date = today, index_as_date = False)
                        
                    data = self.process_data(data, columns)
                    
                    data.to_csv(f'{file_path}/{fund_name}.csv', index = False)
                    data.to_csv(f'{open_path}/{fund_name}.csv', index = False)
                    
        #Location for the saved file will be printed
        print(f'Files have been saved to {path}')
        return None
        
    def get_plots(self, years = 'na', show = False, get_data = False):
        """
        Parameters
        ----------
        years : int
            This is the number of years for which we need the data to plot the data and for them "get_data = True".
        show : bool
            By default False and if True, the plots will be printed.
        get_data : bool
            By default False and if True, all the files will be updated and plotted.
            
        Returns : None
        -------
            After successful execution, it print the path where the plots are stored.
        """
        
        if get_data:
            self.get_data(years = years)
        
        #Running it for each of the equity_classes
        for equity_class, funds in self.funds.items():
            
            #Creating paths for saving the plots
            path = f'{self.location}/Plots'
            file_path = f'{self.location}/Plots/{equity_class}'
            os.makedirs(file_path, exist_ok = True)

            
            for fund_name, _ in funds.items():
                csv_file_path = f'{self.location}/data/{equity_class}/{fund_name}.csv'
                '''This makes sure that data for all the funds in the list exist and if not then it will get the data for those funds'''
                try:
                    data = pd.read_csv(csv_file_path)
                except:
                    self.get_data(years = years, update = False)
                    data = pd.read_csv(csv_file_path)
                
                #Plotting the data and saving to a location
                fig = px.line(x = data['Date'], y = data['Close'],
                              labels = {'x': 'Date', 'y': 'Closing Price'},
                              title = fund_name)
                
                filename = f'{file_path}/{fund_name}.html'
                fig.write_html(filename)
                
                #it is to decided whether to show the chart or just save it
                if show:
                    fig.show()
        #Location for the saved file will be printed
        print(f'Plots have been saved to {path}')
        
    def process_data(self, data, columns):
        """
        function for internal use!
        """
        
        '''droping the unneccesary columns and droping na and resetting index 
        before processing to make sure that the data is good and then saving file'''
        data.drop(columns, axis = 1, inplace = True)
        data.dropna(inplace = True)
        data.reset_index(inplace = True)
        
        #This is to remove the data rows which are obviously wrong and the data 4 to 5 times more in just one day interval
        lst = np.array([])
        for index in range(len(data)-1):
            if data['close'].iloc[index+1]/data['close'].iloc[index] > 4:
                lst = np.append(lst, index+1)
 
        data.drop(lst, inplace = True)
        data.rename(columns = {'date': 'Date', 'close': 'Close'}, inplace = True)
        data = self.date_formatting(data)

        return data
    
    def date_formatting(self, data):
        #formatting the date format so that we can have same 
        new_date = np.array([])

        for i in range(len(data)) :
            date_str = data['Date'].iloc[i]
            try:
                date_obj = datetime.strptime(str(date_str), '%Y-%m-%d %H:%M:%S')
            except:
                date_obj = datetime.strptime(str(date_str), '%d-%b-%y')
 
            # Format the datetime object into the desired format
            new_date = np.append(new_date, date_obj.strftime('%d-%b-%Y'))

        data.drop(['Date'], axis=1, inplace = True)
        data.insert(1, 'Date', new_date, True)
        
        return data

    def get_fund_percent_data(self, fund_close):
        percent_fund = np.array([0])
        for i in range(1, len(fund_close)):
            percent_fund = np.append(percent_fund, (fund_close[i]-fund_close[0])/fund_close[0]*100)
        return percent_fund

    
    def compare_fund_with_benchmark_single(self):
        equity_class = fund_list()
        benchmarks = benchmark()
        for equity in equity_class:
            path = f'{self.location}/data/{equity}'
            bench_path = f'{self.location}/Benchmark'
            
            bench = benchmarks[equity][0]
            
            benchmark_data = pd.read_csv(f'{bench_path}/Benchmark_{bench}.csv')
            benchmark_data = self.date_formatting(benchmark_data)
            bench_df = pd.DataFrame({bench: benchmark_data.Close, 'Date': benchmark_data.Date})
            
            for fund_name in equity_class[equity]:
                fund_data = pd.read_csv(f'{path}/{fund_name}.csv')
                fund_df = pd.DataFrame({fund_name: fund_data.Close, 'Date': fund_data.Date})
    
                close_prices = pd.merge(bench_df, fund_df, how = 'inner', on = 'Date')
                close_prices.set_index('Date', inplace = True)
                close_prices.dropna(inplace = True)
                
                dummy_dataframe = pd.DataFrame([close_prices.iloc[0]]*len(close_prices), index = close_prices.index)
                percent_change = (close_prices-dummy_dataframe)/dummy_dataframe*100
                
                pd.options.plotting.backend = "plotly"
                fig = percent_change.plot.line()
#                 fig.update_layout({'plot_bgcolor': 'rgba(0,0,0,0)', 'paper_bgcolor': 'rgba(0,0,0,0)'})

                plot_path = f'{self.location}/Compare_Plots_single/{equity}'
                os.makedirs(plot_path, exist_ok = True)
#                     fig.show()
                fig.write_html(f'{plot_path}/{fund_name}.html')

    
    def compare_fund_with_benchmark_multi(self):
        equity_class = fund_list()
        benchmarks = benchmark()
        for equity in equity_class:
            path = f'{self.location}/data/{equity}'
            bench_path = f'{self.location}/Benchmark'
            
            bench = benchmarks[equity][0]
            
            benchmark_data = pd.read_csv(f'{bench_path}/Benchmark_{bench}.csv')
            benchmark_data = self.date_formatting(benchmark_data)
            bench_df = pd.DataFrame({bench: benchmark_data.Close, 'Date': benchmark_data.Date})
            
            
            fund_data = pd.read_csv(f'{path}/{equity_class[equity][0]}.csv')
            fund_df = pd.DataFrame({equity_class[equity][0]: fund_data.Close, 'Date': fund_data.Date})
            close_prices = pd.merge(bench_df, fund_df, how = 'inner', on = 'Date')
            
            for ind in range(1, len(equity_class[equity])):         
                fund_data = pd.read_csv(f'{path}/{equity_class[equity][ind]}.csv')
                fund_df = pd.DataFrame({equity_class[equity][ind]: fund_data.Close, 'Date': fund_data.Date})
    
                close_prices = pd.merge(close_prices, fund_df, how = 'inner', on = 'Date')
        
            close_prices.set_index('Date', inplace = True)
            close_prices.dropna(inplace = True)

            dummy_dataframe = pd.DataFrame([close_prices.iloc[0]]*len(close_prices), index = close_prices.index)
            percent_change = (close_prices-dummy_dataframe)/dummy_dataframe*100

            pd.options.plotting.backend = "plotly"
            fig = percent_change.plot.line()
#             fig.update_layout({'plot_bgcolor': 'rgba(0,0,0,0)', 'paper_bgcolor': 'rgba(0,0,0,0)'})

            plot_path = f'{self.location}/Compare_Plots_Multi'
            os.makedirs(plot_path, exist_ok = True)
#             fig.show()
#             fig.write_html(f'{plot_path}/{equity}.html')
    
    def compare_category_addition_with_benchmark(self, seed = 42):
        equity_class = fund_list()
        benchmarks = benchmark()
        for equity in equity_class:
            print(f'{equity}:\n')
            path = f'{self.location}/data/{equity}'
            bench_path = f'{self.location}/Benchmark'
            
            bench = benchmarks[equity][0]
            
            benchmark_data = pd.read_csv(f'{bench_path}/Benchmark_{bench}.csv')
            benchmark_data = self.date_formatting(benchmark_data)
            bench_df = pd.DataFrame({bench: benchmark_data.Close, 'Date': benchmark_data.Date})
            
            random.seed(seed)
            indices = random.sample(equity_class[equity], 5)    #taking five funds randomly
            print(f'{indices}\n')
            fund_data = pd.read_csv(f'{path}/{indices[0]}.csv')
            fund_df = pd.DataFrame({f'{indices[0]}': fund_data.Close, 'Date': fund_data.Date})
            close_prices = pd.merge(bench_df, fund_df, how = 'inner', on = 'Date')
            
            for ind in range(1, len(indices)):         
                fund_data = pd.read_csv(f'{path}/{indices[ind]}.csv')
                fund_df = pd.DataFrame({f'{indices[ind]}': fund_data.Close, 'Date': fund_data.Date})
    
                close_prices = pd.merge(close_prices, fund_df, how = 'inner', on = 'Date')

            close_prices.set_index('Date', inplace = True)
            close_prices.dropna(inplace = True)
            
            dummy_dataframe = pd.DataFrame([close_prices.iloc[0]]*len(close_prices), index = close_prices.index)
            avg = (close_prices - dummy_dataframe)/dummy_dataframe*100

            avg_bench = avg[bench]
            funds = avg.drop(columns = bench)
            avg_funds = pd.DataFrame({f'{equity} Average': funds.sum(axis = 1)/5}, index = funds.index)
            
            percent_avg = pd.concat([avg_bench, avg_funds], axis = 1)
            
            pd.options.plotting.backend = "plotly"
            fig = percent_avg.plot.line(title = f'Performance of 5 randomly selected funds from {equity} category'
                                        f' with index {bench}', labels = dict(index = 'Time', value = 'Percentage Change',
                                                                          variable = 'Investment Options'))
                           
#             fig.update_layout({'plot_bgcolor': 'rgba(0,0,0,0)', 'paper_bgcolor': 'rgba(0,0,0,0)'})

            plot_path = f'{self.location}/Compare_category_add_benchmark'
            os.makedirs(plot_path, exist_ok = True)
#             fig.show()
            fig.write_html(f'{plot_path}/{equity}.html')
    