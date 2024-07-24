import MetaTrader5 as mt5
import pandas as pd
import telepot
from time import sleep

# BUSCAR DADOS SENSIVEIS EM ARQUIVO TXT #
dados = open('C:\\Users\\johnn\\Google Drive\\Pessoal\\1_Programacao\\Python Scripts\\Dados\\ZeroMarkets_dados.txt', 'r', encoding='utf-8')
leitura = dados.readlines()
login       = int(leitura[0])
server      = leitura[1]
password    = leitura[2]
dados.close()


#if not mt5.initialize(login=50717088, server="ICMarketsSC-Demo", password=""):
if not mt5.initialize(path="C:\\Program Files\\Zero Markets MetaTrader 5 Terminal\\terminal64.exe",login=130023874, server="ZeroMarkets-Live-1", password=password):
# if not mt5.initialize(login=135022402, server="ZeroMarkets-Demo-1", password=""):
    print("initialize() failed, error code =",mt5.last_error())
    quit()



def sendTele(ativo):
      print('- Função sendTele acionada')
      bot = telepot.Bot('6372818731:AAFZXRVBq90-ufHCiTc5l_Mqj0ozYXHEV7o')
      chat_id = 984798692

      bot.sendMessage(chat_id, f'>>> CRUZAMENTO MACD LINHA - {ativo} <<<')



lista = ['EURUSD','GBPUSD','NZDUSD','AUDUSD','USDCAD','USDJPY','USDCHF','USDHKD']

def aut():
    for x in lista:
        try:
            ### OBTENÇÃO DOS DADOS
            # dados = mt5.copy_rates_from_pos(x, mt5.TIMEFRAME_H4, 0, 210)
            dados = mt5.copy_rates_from_pos(x, mt5.TIMEFRAME_M1, 0, 210)
            tabela = pd.DataFrame(dados)
            tabela['time']=pd.to_datetime(tabela['time'], unit='s')
            tabela = tabela[['time','open','high','low','close','tick_volume']]
            # print(tabela.tail())

            # calculo do MACD
            tabela['EMA12'] = tabela['close'].ewm(span=12, adjust=False).mean()         # Calculate the 12-period EMA
            tabela['EMA26'] = tabela['close'].ewm(span=26, adjust=False).mean()         # Calculate the 26-period EMA
            tabela['MACD'] = tabela['EMA12'] - tabela['EMA26']                          # Calculate MACD (the difference between 12-period EMA and 26-period EMA)
            tabela['Signal_Line'] = tabela['MACD'].ewm(span=9, adjust=False).mean()     # Calculate the 9-period EMA of MACD (Signal Line)

            # Check for MACD and Signal Line crossovers in the last two rows
            last_row = tabela.iloc[-1]
            second_last_row = tabela.iloc[-2]

            if (second_last_row['MACD'] > second_last_row['Signal_Line']) and (last_row['MACD'] < last_row['Signal_Line']) and (last_row['MACD'] <= 0):
                print(f'{x}: Sinal cruzou para BAIXO')
                sendTele(x)
            elif second_last_row['MACD'] < second_last_row['Signal_Line'] and last_row['MACD'] > last_row['Signal_Line'] and (last_row['MACD'] >= 0):
                print(f'{x}: Sinal cruzou para CIMA')
                sendTele(x)
            else:
                print(f'{x}: Sem cruzamento')

            

        except:
            print(f'Falha nos dados do {x}. Reiniciando...')
        
    # print(tabela.tail(3))


while True:
    aut()
    sleep(14400)
    print('...')


