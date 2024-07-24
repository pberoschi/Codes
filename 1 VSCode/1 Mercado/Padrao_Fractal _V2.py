#VERSAO 2 (YFINANCE)

from datetime import datetime
#import MetaTrader5 as mt5
import time
import telepot
import pytz
import yfinance as yf
import numpy as np

# importamos o módulo pandas para exibir os dados recebidos na forma de uma tabela
import pandas as pd
pd.set_option('display.max_columns', 500) # número de colunas
pd.set_option('display.width', 1500)      # largura máxima da tabela
pd.options.mode.chained_assignment = None  # default='warn'


#symbols = ['^BVSP','USDBRL=X','VALE3.SA','PETR3.SA']
symbols = ['^BVSP','USDBRL=X','VALE3.SA','PETR4.SA','ITUB4.SA','BBDC4.SA','PETR3.SA','B3SA3.SA','ELET3.SA','ABEV3.SA','RENT3.SA','BBAS3.SA','WEGE3.SA','ITSA4.SA','SUZB3.SA','BPAC11.SA','HAPV3.SA','EQTL3.SA','GGBR4.SA','JBSS3.SA','RADL3.SA','PRIO3.SA','LREN3.SA','RDOR3.SA','RAIL3.SA','BBDC3.SA']

for symbol in symbols: 
    print(symbol)
    resumo  = yf.download (symbol, 
                       period = "1w",
                       #start = '2022-09-10', end = '2022-10-14',
                       interval = "1H",
                       #group_by = 'ticker', ## poderá chamar df[ticker]
                       progress = False)
   
    resumo = resumo[['Open','High','Low','Close','Volume']]
    resumo1 = resumo[['High','Low']]
    #print(resumo1.tail())
    #print('')
    
    # IMPRESSÃO DOS VALORES #
    #def Valores():
    LTA1 = resumo['Low'].iloc[-1]
    LTA2 = resumo['Low'].iloc[-2]
    LTA3 = resumo['Low'].iloc[-3]
    LTA4 = resumo['Low'].iloc[-4]
    LTA5 = resumo['Low'].iloc[-5]

    LTB1 = resumo['High'].iloc[-1]
    LTB2 = resumo['High'].iloc[-2]
    LTB3 = resumo['High'].iloc[-3]
    LTB4 = resumo['High'].iloc[-4]
    LTB5 = resumo['High'].iloc[-5]

    # MACD
    resumo['EMA12'] = resumo.Close.ewm(span=12).mean()
    resumo['EMA26'] = resumo.Close.ewm(span=26).mean()
    resumo['MACD'] = resumo.EMA12 - resumo.EMA26
    resumo['signal'] = resumo.MACD.ewm(span=9).mean()
    resumo['histog'] = resumo['MACD'] - resumo['signal']

    #MME 21
    resumo['EMA21'] = resumo.Close.ewm(span=21).mean()

    resumo2 = resumo[['Open','High','Low','Close','Volume','EMA21','histog']]
    #display(resumo2.tail())
    
    # IMPRESSÃO DOS VALORES #
    #def Valores():
    LTA1 = resumo['Low'].iloc[-1]
    LTA2 = resumo['Low'].iloc[-2]
    LTA3 = resumo['Low'].iloc[-3]
    LTA4 = resumo['Low'].iloc[-4]
    LTA5 = resumo['Low'].iloc[-5]

    LTB1 = resumo['High'].iloc[-1]
    LTB2 = resumo['High'].iloc[-2]
    LTB3 = resumo['High'].iloc[-3]
    LTB4 = resumo['High'].iloc[-4]
    LTB5 = resumo['High'].iloc[-5]

    # MACD
    resumo['EMA12'] = resumo.Close.ewm(span=12).mean()
    resumo['EMA26'] = resumo.Close.ewm(span=26).mean()
    resumo['MACD'] = resumo.EMA12 - resumo.EMA26
    resumo['signal'] = resumo.MACD.ewm(span=9).mean()
    resumo['histog'] = resumo['MACD'] - resumo['signal']

    #MME 21
    resumo['EMA21'] = resumo.Close.ewm(span=21).mean()

    resumo2 = resumo[['Open','High','Low','Close','Volume','EMA21','histog']]
    #display(resumo2.tail())
    
    if (
    (resumo2['Low'].iloc[-2] > resumo2['Low'].iloc[-3] < resumo2['Low'].iloc[-4] < resumo2['Low'].iloc[-5])
    & (resumo2['histog'].iloc[-2] > resumo2['histog'].iloc[-3]) 
    & (resumo2['EMA21'].iloc[-2] > resumo2['EMA21'].iloc[-3])
    ):
        print('\n')
        print(f'>>> COMPRA <<<')
        display(resumo2.tail())
    
    elif ( 
        (resumo['High'].iloc[-2] < resumo['High'].iloc[-3] > resumo['High'].iloc[-4] > resumo['High'].iloc[-5])
        & (resumo2['histog'].iloc[-2] < resumo2['histog'].iloc[-3]) 
        & (resumo2['EMA21'].iloc[-2] < resumo2['EMA21'].iloc[-3])
        ):
            print('\n')
            print(f'>>> VENDA <<<')
            display(resumo2.tail())

    else:
        #print('\n')
        print(f'>>> Sem tendência definida <<<'.upper())
        #print('')