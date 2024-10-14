# Import all the necessary libraries here


def equities():
    classes = np.array(['LargeCap', 'Large_MidCap', 'Flexi_Cap', 'MidCap_Fund', 'SmallCap_Fund', 'Value_Oriented', 'ELSS'])
    return classes

def equity_funds():
    funds = {'LargeCap':
             {
                 'Nippon_India_Large_Cap_Fund': '0P00009JAQ.BO',
                 'HDFC_Top_100_Fund': '0P0000XW91.BO',
                 'ICICI_Pru_Bluechip_Fund': '0P0000XWAT.BO',
                 'JM_Large_Cap_Fund': '0P0000XV40.BO',
                 'Quant_Focused_Fund': '0P0000XWCV.BO',
                 'DSP_Nifty_50_Equal_Weight_Index_Fund_Reg': '0P0001BOXZ.BO',
                 'Baroda_BNP_Paridas_Large_Cap_Fund': '0P0000XVYQ.BO',
                 'Edelweiss_Large_Cap_Fund_Reg': '0P0000K8MR.BO',
                 'Kotak_Bluechip_Fund_Reg': '0P00005WSE.BO',
                 'SBI_Bluechip_Fund': '0P0000XVJQ.BO',
                 'Canara_Robeco_Bluechip_Equity_Fund_Reg': '0P0000XW0O.BO'
             },
             
             'Large_MidCap':
             {
                 'ICICI_Pru_Large_Mid_Cap_Fund': '0P0000XUZ8.BO',
                 'HDFC_Large_Mid_Cap_Fund': '0P0000XVAE.BO',
                 'Motilal_Oswal_Large_Mid_Cap_Fund': '0P0001II3X.BO',
                 'Kotak_Equity_Opportunities_Fund': '0P0000XV6P.BO',
                 'SBI_Large_Mid_Cap_Fund': '0P0000XVL5.BO'
             },
             
             'Flexi_Cap':
             {
                 'ICICI_Pru_Retirement_Fund': '0P0001FT0U.BO',
                 'JM_Flexicap_Fund': '0P0000XV4Y.BO',
                 'HDFC_Focused_30_Fund': '0P0000XW75.BO',
                 'Bank_of_India_Flexi_Cap_Fund_Reg': '0P0001K2WW.BO',
                 'HDFC_Flexi_Cap_Fund': '0P0000XW77.BO',
                 'HDFC_Retirement_Savings_Fund_Equity_Plan_Reg': '0P00017K5R.BO',
                 'ICICI_Pru_Focused_Equity_Fund': '0P0000XX0F.BO',
                 'Franklin_India_Flexi_Cap_Fund': '0P0000XW5L.BO',
                 'Franklin_India_Focused_Equity_Fund': '0P0000XW5B.BO',
                 '360_ONE_Focused_Equity_Fund_Reg': '0P00014KAS.BO',
                 'Union_Flexi_Cap_Fund': '0P0000XVRX.BO'
             },
             
             'MidCap_Fund':
             {
                 'Motilal_Oswal_Midcap_Fund_Reg': '0P00012ALU.BO',
                 'Quant_Midcap_Fund': '0P0000XW4V.BO',
                 'Nippon_India_Growth_Fund': '0P0000XVDP.BO',
                 'HDFC_Midcap_Opportunities_Fund': '0P0000XW8F.BO',
                 'Edelweiss_Midcap_Fund_Reg': '0P0000A4KC.BO',
                 'SBI_Magnum_Midcap_Fund': '0P0000XVKO.BO',
                 'Kotak_Emerging_Equity_Fund_Reg': '0P00008TPO.BO',
             },
             
             'SmallCap_Fund':
             {
                 'Nippon_India_Small_Cap_Fund': '0P0000XVFY.BO',
                 'Tata_Small_Cap_Fund_Reg': '0P0001EUZZ.BO',
                 'ICICI_Prudential_Small_Cap_Fund': '0P0000XUY2.BO',
                 'Edelweiss_Small_Cap_Fund': '0P0001FI59.BO',
                 'Axis_Small_Cap_Fund': '0P0001FI59.BO'
             },
             
             'Value_Oriented':
             {
                 'SBI_Contra_Fund': '0P0000XVJR.BO',
                 'JM_Value_Fund': '0P0000XV3W.BO',
                 'Templeton_India_Value_Fund': '0P0000XVQQ.BO',
                 'Bandhan_Sterling_Value_Fund': '0P0000XV1H.BO',
                 'ICICI_Prudential_Value_Discovery_Fund': '0P0000XWAB.BO'
             },
             
             'ELSS':
             {
                 'SBI_Long_Term_Equity_Fund': '0P0000XVL9.BO',
                 'Quant_ELSS_Tax_Saver_Fund': '0P0000XW51.BO',
                 'Bank_of_India_ELSS_Tax_Saver_Fund': '0P0000XVZR.BO',
                 'Parag_Parikh_ELSS_Tax_Saver_Fund': '0P0001HZ17.BO',
                 'Kotak_ELSS_Tax_Saver': '0P0000XV6Q.BO',
                 'Bandhan_ELSS_Tax_Saver_Fund': '0P0000XV1I.BO',
                 'DSP_ELSS_Tax_Saver_Fund': '0P0000XW2T.BO',
                 'Union_ELSS_Tax_Saver_Fund': '0P0000XVS4.BO'
             }
            }
    return funds

def benchmark():
    benchmarks = {
                  'LargeCap': ['BSE_100', 'Nifty_100'],
                  'Large_MidCap': ['BSE_250_Large_Midcap', 'Nifty_Large_Midcap_250'],
                  'Flexi_Cap': ['BSE_500', 'Nifty_500'],
                  'MidCap_Fund': ['BSE_150_Midcap', 'Nifty_Midcap_150'],
                  'SmallCap_Fund': ['BSE_250_Smallcap', 'Nifty_Smallcap_250'],
                  'Value_Oriented': ['BSE_100', 'Nifty_100'],
                  'ELSS': ['BSE_500', 'Nifty_500']
                 }
    return benchmarks

def fund_list():
    funds = {'LargeCap':
             [
                 'Nippon_India_Large_Cap_Fund',
                 'HDFC_Top_100_Fund',
                 'ICICI_Pru_Bluechip_Fund',
                 'JM_Large_Cap_Fund',
                 'Quant_Focused_Fund',
                 'DSP_Nifty_50_Equal_Weight_Index_Fund_Reg',
                 'Baroda_BNP_Paridas_Large_Cap_Fund',
                 'Edelweiss_Large_Cap_Fund_Reg',
                 'Kotak_Bluechip_Fund_Reg',
                 'SBI_Bluechip_Fund',
                 'Canara_Robeco_Bluechip_Equity_Fund_Reg'
             ],
             
             'Large_MidCap':
             [
                 'ICICI_Pru_Large_Mid_Cap_Fund',
                 'HDFC_Large_Mid_Cap_Fund',
                 'Motilal_Oswal_Large_Mid_Cap_Fund',
                 'Kotak_Equity_Opportunities_Fund',
                 'SBI_Large_Mid_Cap_Fund'
             ],
             
             'Flexi_Cap':
             [
                 'ICICI_Pru_Retirement_Fund',
                 'JM_Flexicap_Fund',
                 'HDFC_Focused_30_Fund',
                 'Bank_of_India_Flexi_Cap_Fund_Reg',
                 'HDFC_Flexi_Cap_Fund',
                 'HDFC_Retirement_Savings_Fund_Equity_Plan_Reg',
                 'ICICI_Pru_Focused_Equity_Fund',
                 'Franklin_India_Flexi_Cap_Fund',
                 'Franklin_India_Focused_Equity_Fund',
                 '360_ONE_Focused_Equity_Fund_Reg',
                 'Union_Flexi_Cap_Fund'
             ],
             
             'MidCap_Fund':
             [
                 'Motilal_Oswal_Midcap_Fund_Reg',
                 'Quant_Midcap_Fund',
                 'Nippon_India_Growth_Fund',
                 'HDFC_Midcap_Opportunities_Fund',
                 'Edelweiss_Midcap_Fund_Reg',
                 'SBI_Magnum_Midcap_Fund',
                 'Kotak_Emerging_Equity_Fund_Reg',
             ],
             
             'SmallCap_Fund':
             [
                 'Nippon_India_Small_Cap_Fund',
                 'Tata_Small_Cap_Fund_Reg',
                 'ICICI_Prudential_Small_Cap_Fund',
                 'Edelweiss_Small_Cap_Fund',
                 'Axis_Small_Cap_Fund'
             ],
             
             'Value_Oriented':
             [
                 'SBI_Contra_Fund',
                 'JM_Value_Fund',
                 'Templeton_India_Value_Fund',
                 'Bandhan_Sterling_Value_Fund',
                 'ICICI_Prudential_Value_Discovery_Fund'
             ],
             
             'ELSS':
             [
                 'SBI_Long_Term_Equity_Fund',
                 'Quant_ELSS_Tax_Saver_Fund',
                 'Bank_of_India_ELSS_Tax_Saver_Fund',
                 'Parag_Parikh_ELSS_Tax_Saver_Fund',
                 'Kotak_ELSS_Tax_Saver',
                 'Bandhan_ELSS_Tax_Saver_Fund',
                 'DSP_ELSS_Tax_Saver_Fund',
                 'Union_ELSS_Tax_Saver_Fund'
             ]
            }
    return funds

def stock_list():
    stocks = {'Petronet LNG Ltd.' : 'PETRONET.NS',
              'Bikaji Foods International Ltd.' : 'BIKAJI.NS',
              'RBL Bank Ltd.' : 'RBLBANK.NS',
              'Polycab India Ltd.' : 'POLYCAB.NS',
              'Procter & Gamble Health Ltd.' : 'PGHL.NS',
              'PVR INOX Ltd.' : 'PVRINOX.NS',
              'Dr. Lal Path Labs Ltd.' : 'LALPATHLAB.NS',
              'Hawkins Cooker Ltd' : 'HAWKINCOOK.BO',
              'Indraprastha Gas Ltd.' : 'IGL.NS',
              'Juniper Hotels Ltd.' : 'JUNIPER.NS'}
    return stocks

