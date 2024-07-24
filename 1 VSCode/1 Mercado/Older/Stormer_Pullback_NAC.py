#VERSAO 2 (YFINANCE)

from datetime import datetime
#import MetaTrader5 as mt5
import time
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


def run():
    #symbols = ['^BVSP','VALE3.SA','PETR4.SA','ITUB4.SA','BBDC4.SA']
    #symbols = ['^BVSP','USDBRL=X','VALE3.SA','PETR4.SA','ITUB4.SA','BBDC4.SA','PETR3.SA','B3SA3.SA','ELET3.SA','ABEV3.SA','RENT3.SA','BBAS3.SA','WEGE3.SA','ITSA4.SA','SUZB3.SA','BPAC11.SA','HAPV3.SA','EQTL3.SA','GGBR4.SA','JBSS3.SA','RADL3.SA','PRIO3.SA','LREN3.SA','RDOR3.SA','RAIL3.SA','BBDC3.SA']
    # SEM O DOLAR:
    symbols = ['^BVSP','VALE3.SA','PETR4.SA','ITUB4.SA','BBDC4.SA','PETR3.SA','B3SA3.SA','ELET3.SA','ABEV3.SA','RENT3.SA','BBAS3.SA','WEGE3.SA','ITSA4.SA','SUZB3.SA','BPAC11.SA','HAPV3.SA','EQTL3.SA','GGBR4.SA','JBSS3.SA','RADL3.SA','PRIO3.SA','LREN3.SA','RDOR3.SA','RAIL3.SA','BBDC3.SA']

    for symbol in symbols: 
        #print(symbol)
        resumo6  = yf.download (symbol, 
                        period = "1w",
                        start = '2022-09-30', 
                        end = '2023-11-01',
                        interval = "1H",
                        #group_by = 'ticker', ## poderá chamar df[ticker]
                        progress = False)
        
        # IMPRESSÃO DOS VALORES #
        LTA1 = resumo6['Low'].iloc[-1]
        LTA2 = resumo6['Low'].iloc[-2]
        LTA3 = resumo6['Low'].iloc[-3]
        LTA4 = resumo6['Low'].iloc[-4]
        LTA5 = resumo6['Low'].iloc[-5]

        LTB1 = resumo6['High'].iloc[-1]
        LTB2 = resumo6['High'].iloc[-2]
        LTB3 = resumo6['High'].iloc[-3]
        LTB4 = resumo6['High'].iloc[-4]
        LTB5 = resumo6['High'].iloc[-5]

        #MME 21
        resumo6['EMA21'] = resumo6.Close.ewm(span=21).mean()
        resumo6['EMA17'] = resumo6.Close.ewm(span=17).mean() 

        #if (resumo6['EMA21'].iloc[-2] > resumo6['EMA21'].iloc[-3]):
        if (resumo6['EMA17'].iloc[-2] < resumo6['EMA21'].iloc[-2]):    
            if (resumo6['High'].iloc[-2] < resumo6['High'].iloc[-3] > resumo6['High'].iloc[-4] > resumo6['High'].iloc[-5]):
                print(f'{symbol}: >>> COMPRA <<<')
                #print(resumo6.tail())
                bot = telepot.Bot('1827005235:AAGr4ss18HkJo11QKjBYBG-TqnKLv79Ph6Q')
                bot.sendMessage(984798692, f'>> {symbol} Perda de TOPO: POSSÍVEL COMPRA <<')
                #print('Perda de TOPO: POSSÍVEL COMPRA')

        #elif (resumo6['EMA21'].iloc[-2] < resumo6['EMA21'].iloc[-3]):
        elif (resumo6['EMA17'].iloc[-2] > resumo6['EMA21'].iloc[-2]):
            if (resumo6['Low'].iloc[-2] > resumo6['Low'].iloc[-3] < resumo6['Low'].iloc[-4] < resumo6['Low'].iloc[-5]):
                print(f'{symbol}: >>> VENDA <<<')
                #print(resumo6.tail())
                bot = telepot.Bot('1827005235:AAGr4ss18HkJo11QKjBYBG-TqnKLv79Ph6Q')
                bot.sendMessage(984798692, f'>> {symbol} Perda de FUNDO: POSSÍVEL VENDA <<')
                #print('Perda de FUNDO: POSSÍVEL VENDA')

        else:
            #print('\n')
            print(f'>>> Sem tendência definida <<<'.upper())
            #print('')
    print('>>> FIM DA EXECUÇÃO DO SCRIPT <<<')
    bot = telepot.Bot('1827005235:AAGr4ss18HkJo11QKjBYBG-TqnKLv79Ph6Q')
    bot.sendMessage(984798692, f'>> FIM DA PROCURA POR ENTRADAS NO OPERACIONAL PB <<')
run()

""" while True:
    # HORARIO DAS OPERAÇÕES
    agora = datetime.now()
    agora1 = str(agora)
    agoraRes = agora1[11:16]

    if ('08:59' < agoraRes < '18:00'):
        run() """