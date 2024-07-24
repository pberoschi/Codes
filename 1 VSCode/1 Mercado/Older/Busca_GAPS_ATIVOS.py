from datetime import datetime
import telepot
import pytz
import yfinance as yf
import numpy as np
from time import sleep

# importamos o módulo pandas para exibir os dados recebidos na forma de uma tabela
import pandas as pd
pd.set_option('display.max_columns', 500) # número de colunas
pd.set_option('display.width', 1500)      # largura máxima da tabela
pd.options.mode.chained_assignment = None  # default='warn'

#symbols = ['^BVSP','VALE3.SA','PETR4.SA','ITUB4.SA','BBDC4.SA']
symbols = ['^BVSP','USDBRL=X','VALE3.SA','PETR4.SA','ITUB4.SA','BBDC4.SA','PETR3.SA','B3SA3.SA','ELET3.SA','ABEV3.SA','RENT3.SA','BBAS3.SA','WEGE3.SA','ITSA4.SA','SUZB3.SA','BPAC11.SA','HAPV3.SA','EQTL3.SA','GGBR4.SA','JBSS3.SA','RADL3.SA','PRIO3.SA','LREN3.SA','RDOR3.SA','RAIL3.SA','BBDC3.SA']
# SEM O DOLAR:
#symbols = ['^BVSP','VALE3.SA','PETR4.SA','ITUB4.SA','BBDC4.SA','PETR3.SA','B3SA3.SA','ELET3.SA','ABEV3.SA','RENT3.SA','BBAS3.SA','WEGE3.SA','ITSA4.SA','SUZB3.SA','BPAC11.SA','HAPV3.SA','EQTL3.SA','GGBR4.SA','JBSS3.SA','RADL3.SA','PRIO3.SA','LREN3.SA','RDOR3.SA','RAIL3.SA','BBDC3.SA']

for symbol in symbols: 
    resumo2 = yf.download (symbol, 
                    period = "1w",
                    start = '2022-09-31', 
                    end = '2023-12-02',
                    interval = "1D",
                    #group_by = 'ticker', ## poderá chamar df[ticker]
                    progress = False)

    resumo = resumo2[['High','Low']] 
    #resumo['Variacao'] = ''
    resumo['ALERTA'] = ''

    #for x in range (1, len(resumo)):
    if resumo['Low'].iloc[-1] > resumo['High'].iloc[-2]:
        print(f'{symbol}: GAP de Alta')
        bot = telepot.Bot('1827005235:AAGr4ss18HkJo11QKjBYBG-TqnKLv79Ph6Q')
        bot.sendMessage(984798692, f'>> {symbol}: GAP de Alta <<') 
        #resumo['ALERTA'][x] = 'GAP de Alta'
        print(resumo.tail(2))
    
     
    elif resumo['High'].iloc[-1] < resumo['Low'].iloc[-2]:
        print(f'{symbol}: GAP de Baixa')
        bot = telepot.Bot('1827005235:AAGr4ss18HkJo11QKjBYBG-TqnKLv79Ph6Q')
        bot.sendMessage(984798692, f'>> {symbol}: GAP de Baixa <<') 
        #resumo['ALERTA'][x] = 'GAP de Baixa'
        print(resumo.tail())  

print('Fim da execucao do script')
