from binance import Client, ThreadedWebsocketManager, ThreadedDepthCacheManager
import pandas as pd 
import time
import telepot
import yfinance as yf
pd.options.mode.chained_assignment = None  # default='warn'

client = Client('jogobafi', '@')

#Selecionando ATIVOS com base em critério de volume
tickers = client.get_ticker()
tabela = pd.DataFrame(tickers)

#Listar em ordem DECRESCENTE
#tabela = tabela.sort_values(by=['lastPrice'], ascending=False)
tabela = tabela.sort_values(by=['volume'], ascending=False)

#Extrair apenas o nome do Ativo
ativosList = list(tabela['symbol'])
print(ativosList)

""" #Criando uma lista com 20 ativos
ativos = []
for ativo in ativosList:
    print('Buscando...')
    if ativo[-1] == 'T':
        ativos.append(ativo)        
        ativos = ativos[:10]

    #print(ativo)
    resumo4 = client.get_klines(symbol = ativo, interval = client.KLINE_INTERVAL_1HOUR)
    #resumo4 = client.get_klines(symbol = ativo, interval = client.KLINE_INTERVAL_5MINUTE)
    resumo5 = pd.DataFrame(resumo4, columns=['date','open','high','low','close','volume','close_time','asset_volume','n of trades','asset_column','taker_buy','based_asset_volume'])
    resumo6 = resumo5[['date','open','high','low','close','volume','n of trades']]
    resumo6.set_index('date', inplace=True)
    resumo6.index = pd.to_datetime(resumo6.index, unit='ms')
    
    # IMPRESSÃO DOS VALORES #
    LTA1 = resumo6['low'].iloc[-1]
    LTA2 = resumo6['low'].iloc[-2]
    LTA3 = resumo6['low'].iloc[-3]
    LTA4 = resumo6['low'].iloc[-4]
    LTA5 = resumo6['low'].iloc[-5]

    LTB1 = resumo6['high'].iloc[-1]
    LTB2 = resumo6['high'].iloc[-2]
    LTB3 = resumo6['high'].iloc[-3]
    LTB4 = resumo6['high'].iloc[-4]
    LTB5 = resumo6['high'].iloc[-5]

    #MME 21
    resumo6['EMA21'] = resumo6.close.ewm(span=21).mean()
    resumo6['EMA17'] = resumo6.close.ewm(span=17).mean() 

    if (resumo6['EMA21'].iloc[-2] > resumo6['EMA21'].iloc[-3]):
        if (resumo6['high'].iloc[-2] < resumo6['high'].iloc[-3] > resumo6['high'].iloc[-4] > resumo6['high'].iloc[-5]):
            print(ativo)
            print(f'>>> COMPRA <<<')
            #display(resumo6.tail())
    
    elif (resumo6['EMA21'].iloc[-2] < resumo6['EMA21'].iloc[-3]):
        if (resumo6['low'].iloc[-2] > resumo6['low'].iloc[-3] < resumo6['low'].iloc[-4] < resumo6['low'].iloc[-5]):
            print(ativo)
            print(f'>>> VENDA <<<')
            #display(resumo6.tail())

    else:
        #print('\n')
        print(f'>>> Sem tendência definida <<<'.upper())
        #print('')
    """