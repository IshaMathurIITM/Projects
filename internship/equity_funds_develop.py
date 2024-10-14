### equity_funds_ver_1

## here I am going process and get returns for mutual fund data

from util import *
from products import equity_funds, benchmark

today = dt.today()

class emf:
    def __init__(self, drive = 'F'):
        """
        Parameters
        ----------
        drive : str
            Drive name in which the data and plots are to be saved. Default value is 'F'.
        """
        
        self.location = f'{drive.upper()}:/PROJECT/MF'
        os.makedirs(self.location, exist_ok = True)
        
        #Name of all the funds and ticker for them is available in equity_funds()
        self.funds = equity_funds()

    def get_data(self, day = today, years = 6, update = True, columns = ['ticker']):
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
                            continue
                            
                        #otherwise it will get data for the particular period
                        data = si.get_data(ticker, start_date = f'{today.year-years}-{today.month}-{today.day}',
                                           end_date = today, index_as_date = False)
                        data = self.process_data(data, columns = columns)
                        data.to_csv(f'{file_path}/{fund_name}.csv', index = False)
                        
                #Same for updating files except it updates all the files
                else:
                    if years == 'na':
                        data = si.get_data(ticker, index_as_date = False)
                        continue
                    data = si.get_data(ticker, start_date = f'{today.year-years}-{today.month}-{today.day}',
                                       end_date = today, index_as_date = False)
                    data = self.process_data(data, columns)
                    data.to_csv(f'{file_path}/{fund_name}.csv', index = False)
                    
        #Location for the saved file will be printed
        print(f'Files have been saved to {path}')
        return None
        
    def get_plots(self, years = 5, show = False, get_data = False):
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
                fig = px.line(x = data['date'], y = data['adjclose'],
                              labels = {'x': 'date', 'y': 'Closing Price'},
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
            if data['adjclose'].iloc[index+1]/data['adjclose'].iloc[index] > 4:
                lst = np.append(lst, index+1)
        data.drop(lst, inplace = True)
        return data
        
    def product_data(self, ticker,
                          end = True, index_as_date = False,
                          interval = '1d', drop_columns = ['ticker']):
        """
        function for internal use!
        """
        """
        Parameters
        ----------
        ticker : str
            The is the ticker for the fund/stock that is retrieved from yahoo finance.
        end : bool
            if True, it gives data for present and false thengive data for the starting i.e. price 1 or 3 or 5 years ago.
        index_as_date : bool
            By default is False, if True then will have index as dates
        drop_columns : list
                By default is ['ticker'], this is list of unnecessary columns those are need to be removed.
        
        Returns
        -------
        data: float
            It is the closing price for a particular day to calculate return.
        """
        
        day = self.day; month = self.month; year = self.year
        if end:
            ex_year = self.period // 12; ex_month = self.period % 12
        else:
            ex_year = 0; ex_month = 0
        for run in range(100):
            #Getting data for a particular date
            try:
                data= si.get_data(ticker,
                                  start_date='%s-%s-%s'%(year + ex_year, month + ex_month, day),
                                  end_date='%s-%s-%s'%(self.year + ex_year, self.month + ex_month, self.day+1),
                                  index_as_date = index_as_date, interval= interval
                                 )

                data.drop(drop_columns, axis = 1, inplace = True)
                data.dropna(inplace = True) 
                break
            except:
                '''It's a fail safe in case the data for fund that is not that old, so it gives whatever 
                starting data is available data'''
                if run > 10:
                    data = si.get_data(ticker, index_as_date = index_as_date)
                    data.drop(drop_columns, axis = 1, inplace = True)
                    data.dropna(inplace = True) 
                    data = data.iloc[0]
                day -= 1
                if day == 0:
                    day = 31
                    if month == 1:
                        month = 12; year -= 1
                    else: month-=1
        return data
    
    def investment(self) -> None:
        """
        function for internal use!
        """
        #dictionary for storing details about equity class, fund_name and the change over time
        self.returns = {}
        
        for equity_class, funds in self.funds.items():
            self.returns[equity_class] = {}
        
            for fund_name, ticker in funds.items():
                #First getting the data for the starting date i.e. the date when the investment was made
                start_data = self.product_data(ticker, end = False)
                end_data = self.product_data(ticker)
                
                change = end_data['adjclose']/start_data['adjclose']
                self.returns[equity_class][fund_name] = change

    def profit_visual(self, CAGR: 'bool' = True,
                      save: 'bool' = False, show: 'bool' = True) -> None:
        
        """
        Parameters
        ----------

        CAGR : bool
            By default 'True' and gives annualized return, if false then give gives return from the beginning
        save : bool
            By default False, If True then the charts will be saved in the drive
        show : bool
            By default True, If False then 
        
        Returns : None
        -------
            After successful execution, it print the path where the plots are stored.
        """
        
        path = f'{self.location}/Returns'
        self.amount = 100000

        period = np.array([1, 3, 5])
        for years in period:

            self.year = today.year - years
            self.month = today.month
            self.day = today.day

            self.period = 12*years
            self.investment()
            
            file_path = f'{self.location}/Returns/{years}Yr'
            os.makedirs(file_path, exist_ok = True)
            
            for equity_class, funds in self.funds.items():
                BenchMark, benchmark_return = self.get_benchmark_return(equity_class, years)
                
                name_of_fund = np.array([BenchMark])
                percentage_returns = np.array([benchmark_return])
                
                fund, Returns = self.get_equity_return(equity_class, years)
                name_of_fund = np.append(name_of_fund, fund)
                percentage_returns = np.append(percentage_returns, Returns)

                #Calculation of CAGR
                if CAGR:
                    percentage_returns = (np.power(percentage_returns, 1/years)-1) * 100
                else:
                    percentage_returns = (percentage_returns-1) * 100

                colors = ['crimson']*len(BenchMark) + ['blue']*(len(name_of_fund)-len(BenchMark))
                
                fig = go.Figure(data = [go.Bar(x = name_of_fund, y = percentage_returns,
                                               marker_color = colors, text=[str(i)[0:5] for i in percentage_returns],
                                               textposition = 'outside', cliponaxis = False
                                        )])
#                 fig.update_traces(textposition = 'outside', cliponaxis=False)
                fig.update_layout(title_text=f'%s: %d years Annualized return (%s)'
                             %(equity_class, years, today), uniformtext=dict( minsize=10))
                filename = f'{file_path}/{equity_class}_{years}Yr.html'
                if save:
                    fig.write_html(filename)
                if show:
                    fig.show()
        if save:
            print(f'Plots have been saved to {self.location}/Returns')
        return None
    
    def get_benchmark_return(self, equity_class, years) -> float:
        path = 'F:/PROJECT/MF/Benchmark'
        benchmarks = benchmark()
        change = []; Benchmark_name = []
        for index in benchmarks[equity_class]:
            data = pd.read_csv(f'{path}/Benchmark_{index}.csv')
            if len(data) >= 250*years:
                change.append(data['Close'].iloc[len(data)-1]/data['Close'].iloc[len(data)-1-250*years])
                Benchmark_name.append(index)
        return Benchmark_name, change 
    
    def get_equity_return(self, equity_class, years):
        
        path = f'F:/PROJECT/MF/data/{equity_class}'
        equity_classes = equity_funds()
        
        change = []; fund_name = []
        for fund in equity_classes[equity_class]:
            data = pd.read_csv(f'{path}/{fund}.csv')
            if len(data) >= 250*years:
                change.append(data['close'].iloc[len(data)-1]/data['close'].iloc[len(data)-1-250*years])   
            else:
                change.append(data['close'].iloc[len(data)-1]/data['close'].iloc[0])
            fund_name.append(fund)     
        
        return fund_name, change
        