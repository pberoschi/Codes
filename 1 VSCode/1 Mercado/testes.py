import MetaTrader5 as mt5
import pandas as pd
import telepot
from time import sleep

# BUSCAR DADOS SENSIVEIS EM ARQUIVO TXT #
# dados = open('C:\\Users\\johnn\\Google Drive\\Pessoal\\1_Programacao\\Python Scripts\\Dados\\ZeroMarkets_dados.txt', 'r', encoding='utf-8')
# leitura = dados.readlines()
# login       = int(leitura[0])
# server      = leitura[1]
# password    = leitura[2]
# dados.close()


if not mt5.initialize(login=82491017, server="MetaQuotes-Demo", password="V+1dHiKp"):
    print("initialize() failed, error code =",mt5.last_error())
    quit()


lista = ['EURUSD','GBPUSD','NZDUSD','AUDUSD','USDCAD','USDJPY','USDCHF','USDHKD']

x = "XAUAUD"


### OBTENÇÃO DOS DADOS
dados = mt5.copy_rates_from_pos(x, mt5.TIMEFRAME_M1, 0, 210)
tabela = pd.DataFrame(dados)
# tabela['time']=pd.to_datetime(tabela['time'], unit='s')
# tabela = tabela[['time','open','high','low','close','tick_volume']]
print(tabela.tail())

# calculo do MACD
# tabela['EMA12'] = tabela['close'].ewm(span=12, adjust=False).mean()         # Calculate the 12-period EMA
# tabela['EMA26'] = tabela['close'].ewm(span=26, adjust=False).mean()         # Calculate the 26-period EMA
# tabela['MACD'] = tabela['EMA12'] - tabela['EMA26']                          # Calculate MACD (the difference between 12-period EMA and 26-period EMA)
# tabela['Signal_Line'] = tabela['MACD'].ewm(span=9, adjust=False).mean()     # Calculate the 9-period EMA of MACD (Signal Line)
# print(tabela.tail())



# import MetaTrader5 as mt5
# # display data on the MetaTrader 5 package
# print("MetaTrader5 package author: ",mt5.__author__)
# print("MetaTrader5 package version: ",mt5.__version__)
 
# # establish connection to the MetaTrader 5 terminal
# if not mt5.initialize():
#     print("initialize() failed, error code =",mt5.last_error())
#     quit()
 
# get all symbols
# symbols=mt5.symbols_get()
# print('Symbols: ', len(symbols))
# count=0

# display the first five ones
# for s in symbols:
#     count+=1
#     print("{}. {}".format(count,s.name))
#     if count==5: break
# print()
 
# get symbols containing RU in their names
# ru_symbols=mt5.symbols_get("*RU*")
# print('len(*RU*): ', len(ru_symbols))
# for s in ru_symbols:
#     print(s.name)
# print()
 
# # get symbols whose names do not contain USD, EUR, JPY and GBP
# group_symbols=mt5.symbols_get(group="*,!*USD*,!*EUR*,!*JPY*,!*GBP*")
# print('len(*,!*USD*,!*EUR*,!*JPY*,!*GBP*):', len(group_symbols))
# for s in group_symbols:
#     print(s.name,":",s)

# get symbols whose names do not contain USD, EUR, JPY and GBP
# group_symbols=mt5.symbols_get(group="*XAU*")
# print(':', len(group_symbols))
# for s in group_symbols:
#     print(s.name,":",s)