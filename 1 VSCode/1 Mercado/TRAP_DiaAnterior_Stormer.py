from datetime import datetime
import MetaTrader5 as mt5
import time
import telepot
import pytz

# importamos o módulo pandas para exibir os dados recebidos na forma de uma tabela
import pandas as pd
pd.set_option('display.max_columns', 500) # número de colunas
pd.set_option('display.width', 1500)      # largura máxima da tabela
pd.options.mode.chained_assignment = None  # default='warn'

if not mt5.initialize(login=1092947504, server="ClearInvestimentos-DEMO", password=""):
#if not mt5.initialize(login=4999473749, server="MetaQuotes-Demo", password="elf4lnbx"):
    print("initialize() failed, error code =",mt5.last_error())
    quit()
    
#symbols = ['WDOZ22','WINZ22']
symbols = [
    'VALE3',
    #'PETR4',
    #'ITUB4',
    'BBDC4',
    #'PETR3',
    #'B3SA3',
    'ELET3',
    #'ABEV3',
    #'RENT3',
    #'BBAS3',
    #'WEGE3',
    'ITSA4',
    #'SUZB3',
    #'BPAC11',
    'HAPV3',
    'EQTL3',
    #'GGBR4',
    'JBSS3',
    #'RADL3',
    #'PRIO3',
    'LREN3',
    #'RDOR3',
    'RAIL3',
    #'BBDC3'
    ] 

def run():
    print('Analisando os ativos. Por favor, aguarde...')    

    for symbol in symbols:

        # Maxima e Minima DIA ANTERIOR
        ratesDA = mt5.copy_rates_from_pos(symbol, mt5.TIMEFRAME_D1, 0, 57)
        MaxMinDA = pd.DataFrame(ratesDA)
        MaxMinDA['time']=pd.to_datetime(MaxMinDA['time'], unit='s')
        #MaxMinDA = MaxMinDA[['time','open','high','low','close','tick_volume']]
        MaxMinDA = MaxMinDA[['time','high','low']]
        MaxMinDA = MaxMinDA.tail(2)
        #display(MaxMinDA)
        #print('')

        # Maxima e Minima MOMENTO ATUAL
        ratesMA = mt5.copy_rates_from_pos(symbol, mt5.TIMEFRAME_M1, 0, 580)
        MaxMinMA = pd.DataFrame(ratesMA)
        MaxMinMA['time']=pd.to_datetime(MaxMinMA['time'], unit='s')
        #resumo1 = rates_frame1[['time','open','high','low','close','tick_volume']]
        MaxMinMA = MaxMinMA[['time','high','low']]
        MaxMinMA = MaxMinMA.tail(1)
        #display(MaxMinMA)

        resumoTRAP = MaxMinDA.append(MaxMinMA)
        print(resumoTRAP)

        # alta
        if (resumoTRAP['high'].iloc[-1] > resumoTRAP['high'].iloc[-3]) & (resumoTRAP['low'].iloc[-1] < resumoTRAP['high'].iloc[-3]):
            bot = telepot.Bot('1827005235:AAGr4ss18HkJo11QKjBYBG-TqnKLv79Ph6Q')
            bot.sendMessage(984798692, f'>> TRAP: ROMPIMENTO DE MÁXIMA DO ANTERIOR NO {symbol} <<')
            print(f'TRAP: ROMPIMENTO DE MÁXIMA DO ANTERIOR NO {symbol}')

        # baixa
        elif (resumoTRAP['low'].iloc[-1] < resumoTRAP['low'].iloc[-3]) & (resumoTRAP['high'].iloc[-1] > resumoTRAP['low'].iloc[-3]):
            bot = telepot.Bot('1827005235:AAGr4ss18HkJo11QKjBYBG-TqnKLv79Ph6Q')
            bot.sendMessage(984798692, f'>> TRAP: ROMPIMENTO DE MÍNIMA DO ANTERIOR NO {symbol} <<')
            print(f'TRAP: ROMPIMENTO DE MÍNIMA DO ANTERIOR NO {symbol}')

while True:
    run()
    print(f'FIM DA EXECUÇÃO DO SCRIPT! {len(symbols)} ativos analisados')
    print('')
    time.sleep(60)