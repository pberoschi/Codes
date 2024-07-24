from datetime import datetime
import MetaTrader5 as mt5
import time
import telepot
import pytz

import pandas as pd
pd.set_option('display.max_columns', 500) # número de colunas
pd.set_option('display.width', 1500)      # largura máxima da tabela
pd.options.mode.chained_assignment = None  # default='warn'

agora = datetime.now()
#print(f'Buscando dados...{agora}')

#if not mt5.initialize(login=54679378, server="MetaQuotes-Demo", password="hz7ulfri"):
if not mt5.initialize(login=1092947504, server="ClearInvestimentos-DEMO", password="Joh0516"):
    print("initialize() failed, error code =",mt5.last_error())
    quit()

def run():
    symbols = ['WDOZ22','WINZ22'] 
    
    for symbol in symbols:
        print(symbol)
        # CRIAÇÃO DOS CÁLCULOS (MÉDIAS)
        #timezone = pytz.timezone("Etc/UTC")
        #utc_from = datetime(2022, 1, diaAmanha, tzinfo=timezone)
        #ratesM10 = mt5.copy_rates_from_pos(symbol, mt5.TIMEFRAME_M10, 0, 500)
        ratesM10 = mt5.copy_rates_from_pos(symbol, mt5.TIMEFRAME_M10, 0, 500)
        rates_frameM10 = pd.DataFrame(ratesM10)
        rates_frameM10['time']=pd.to_datetime(rates_frameM10['time'], unit='s')
        dfM10 = rates_frameM10[['time','open','high','low','close']]

        #PARA ESTUDOS
        #dfM15 = dfM1.loc[dfM1["time"].between('2022-1-4 10:01:00', '2022-1-4 18:00:00')]

        dfM10['INSIDE'] = ''
        
        if (dfM10['high'].iloc[-3] > dfM10['high'].iloc[-2]) & (dfM10['low'].iloc[-3] < dfM10['low'].iloc[-2]):
            tempo = dfM10['time'].iloc[-1]
            dfM10['INSIDE'].iloc[-1] = 'INSIDE'

            # ENVIAR MENSAGEM TELEGRAM
            bot = telepot.Bot('1827005235:AAGr4ss18HkJo11QKjBYBG-TqnKLv79Ph6Q')
            bot.sendMessage(984798692, f'>> INSIDE: {symbol} / TIMEFRAME: 10M ({tempo}) <<')

        else:
            dfM10['INSIDE'].iloc[-1] = ''

        print(dfM10.tail(5))
        
    print('Fim do processo')


while True:
    # HORARIO DAS OPERAÇÕES
    agora = datetime.now()
    agora1 = str(agora)
    agoraRes = agora1[11:16]

    if ('08:59' < agoraRes < '18:00'):
        run()
        time.sleep(600)
    else:
        print('Fora do horário')
        time.sleep(600)