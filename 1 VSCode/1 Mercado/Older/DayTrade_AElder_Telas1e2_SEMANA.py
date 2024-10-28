from datetime import datetime
import MetaTrader5 as mt5
import time
import telepot
import pytz
import pandas as pd
pd.set_option('display.max_columns', 500) # número de colunas
pd.set_option('display.width', 1500)      # largura máxima da tabela
pd.options.mode.chained_assignment = None  # default='warn'


# Acessando dados externos de usuario e senha
# dados = open('C:\\Users\\Johnny\\Documents\\1_DEV\\Dados\\DadosMeta_5031093261.txt', 'r', encoding='utf-8')
# leitura = dados.readlines()
# usuario = leitura[0]
# senha = leitura[1]
# print(f'Usuário: {usuario}'.strip())
# print(f'Senha: {senha}')
# dados.close() 


# Abrindo MT5
agora = datetime.now()
#print(f'Buscando dados...{agora}')
# if not mt5.initialize(login=54679378, server="MetaQuotes-Demo", password=""):
if not mt5.initialize():
# if not mt5.initialize(login=1092947504, server="ClearInvestimentos-DEMO", password=senha):
    print("initialize() failed, error code =",mt5.last_error())
    quit()

# Buscando lisa externa com os ativos
# dados = open('C:\\Users\johnn\\Google Drive\\Pessoal\\1_Programacao\\Python Scripts\\2_Dados\\lista_Ativos_MT5.txt', 'r', encoding='utf-8')
# ativos = dados.readlines()
# dados.close() 

# symbols = [
# 'ABEV3',
# 'ALPA4',
# 'AMER3',
# 'ARZZ3',
# 'ASAI3',
# 'AZUL4',
# 'B3SA3',
# 'BBAS3',
# 'BBDC3',
# 'BBDC4',
# 'BBSE3',
# 'BEEF3',
# 'BPAC11',
# 'BPAN4',
# 'BRAP4',
# 'BRFS3',
# 'BRKM5',
# 'BRML3',
# 'CASH3',
# 'CCRO3',
# 'CIEL3',
# 'CMIG4',
# 'CMIN3',
# 'COGN3',
# 'CPFE3',
# 'CPLE6',
# 'CRFB3',
# 'CSAN3',
# 'CSNA3',
# 'CVCB3',
# 'CYRE3',
# 'DXCO3',
# 'ECOR3',
# 'EGIE3',
# 'ELET3',
# 'ELET6',
# 'EMBR3',
# 'ENBR3',
# 'ENEV3',
# 'ENGI11',
# 'EQTL3',
# 'EZTC3',
# 'FLRY3',
# 'GGBR4',
# 'GOAU4',
# 'GOLL4',
# 'HAPV3',
# 'HYPE3',
# 'IGTI11',
# 'IRBR3',
# 'ITSA4',
# 'ITUB4',
# 'JBSS3',
# 'KLBN11',
# 'LREN3',
# 'LWSA3',
# 'MGLU3',
# 'MRFG3',
# 'MRVE3',
# 'MULT3',
# 'NTCO3',
# 'PCAR3',
# 'PETR3',
# 'PETR4',
# 'PETZ3',
# 'POSI3',
# 'PRIO3',
# 'QUAL3',
# 'RADL3',
# 'RAIL3',
# 'RAIZ4',
# 'RDOR3',
# 'RENT3',
# 'RRRP3',
# 'SANB11',
# 'SBSP3',
# 'SLCE3',
# 'SMTO3',
# 'SOMA3',
# 'SULA11',
# 'SUZB3',
# 'TAEE11',
# 'TIMS3',
# 'TOTS3',
# 'UGPA3',
# 'USIM5',
# 'VALE3',
# 'VBBR3',
# 'VIIA3',
# 'VIVT3',
# 'WEGE3',
# 'YDUQ3',
# ] 


symbols = [
'EURUSD',
'XAUUSD',
'USDJPY',
'GBPUSD',
'AUDUSD',
'USDCAD',
'NZDUSD',
'USDCHF',
'USDHKD',
'XAUEUR'
# 'IBOV'
# 'US500'
]

print('Analisando dados. Aguarde!')
for symbol in symbols:
    ### OBTENÇÃO DOS DADOS
    ratesMAIOR = mt5.copy_rates_from_pos(symbol, mt5.TIMEFRAME_D1, 0, 210)
    # ratesMAIOR = mt5.copy_rates_from_pos(symbol, mt5.TIMEFRAME_W1, 0, 210)
    rates_MAIOR = pd.DataFrame(ratesMAIOR)
    rates_MAIOR['time']=pd.to_datetime(rates_MAIOR['time'], unit='s')
    resumoMAIOR = rates_MAIOR[['time','open','high','low','close','tick_volume']]
    #resumoMENOR.tail()

    ratesMENOR = mt5.copy_rates_from_pos(symbol, mt5.TIMEFRAME_H1, 0, 210)
    # ratesMENOR = mt5.copy_rates_from_pos(symbol, mt5.TIMEFRAME_D1, 0, 210)
    rates_MENOR = pd.DataFrame(ratesMENOR)
    rates_MENOR['time']=pd.to_datetime(rates_MENOR['time'], unit='s')
    resumoMENOR = rates_MENOR[['time','open','high','low','close','tick_volume']]
    #resumoMENOR.tail()

    ### CRIAÇÃO DOS INDICADORES
    #MME 13 
    trezeMME = resumoMAIOR['close'].ewm(span=13).mean()
    resumoMAIOR['MME13'] = trezeMME

    # MACD
    resumoMAIOR['EMA12'] = resumoMAIOR.close.ewm(span=12).mean()
    resumoMAIOR['EMA26'] = resumoMAIOR.close.ewm(span=26).mean()
    resumoMAIOR['MACD'] = resumoMAIOR.EMA12 - resumoMAIOR.EMA26
    resumoMAIOR['signal'] = resumoMAIOR.MACD.ewm(span=9).mean()
    resumoMAIOR['histog'] = resumoMAIOR['MACD'] - resumoMAIOR['signal']

    # CALCULO DO ESTOCASTICO e MME 3
    n = 8
    highMax = resumoMENOR['high'].rolling(n).max() 
    lowMin = resumoMENOR['low'].rolling(n).min()

    #estocastico
    resumoMENOR['estoc %K'] = ((resumoMENOR['close'] - lowMin) / (highMax - lowMin)) * 100
    resumoMENOR['estoc %D'] = resumoMENOR['estoc %K'].rolling(3).mean()

    # estocastico lento a partir do df de menor tempo
    resumoMENOR["EstocS %K"] = resumoMENOR["estoc %D"]
    resumoMENOR["EstocS %D"] = resumoMENOR["EstocS %K"].rolling(3).mean()
    #resumo2.dropna(inplace=True) #remover espaços em branco

    # RESUMINDO DADOS A SEREM EXIBIDOS
    resumoMAIOR = resumoMAIOR[['time','open','high','low','close','tick_volume','MME13','histog']]
    resumoMENOR = resumoMENOR[['EstocS %D']]

    resumoMAIOR = resumoMAIOR.tail()
    resumoMENOR = resumoMENOR.tail()
    #display(resumoMAIOR)
    #display(resumoMENOR)

    # UNINDO DATAFRAMES
    resumoFINAL = resumoMAIOR
    resumoFINAL['Estoc'] = resumoMENOR['EstocS %D']

    resumoFINAL['Sinal'] = ''

    if resumoFINAL['histog'].iloc[-2] > resumoFINAL['histog'].iloc[-3]:
        if resumoFINAL['close'].iloc[-2] > resumoFINAL['MME13'].iloc[-2]:
            if resumoFINAL['Estoc'].iloc[-2] <= 50:
                if resumoFINAL['tick_volume'].iloc[-2] >= 00000:
                    resumoFINAL['Sinal'].iloc[-2] = 'COMPRA'
                    print(f'{symbol}: COMPRA')
                    # print(resumoFINAL)
        
    elif resumoFINAL['histog'].iloc[-2] < resumoFINAL['histog'].iloc[-3]:
        if resumoFINAL['close'].iloc[-2] < resumoFINAL['MME13'].iloc[-2]:
            if resumoFINAL['Estoc'].iloc[-2] >= 50:
                if resumoFINAL['tick_volume'].iloc[-2] >= 00000:
                    resumoFINAL['Sinal'].iloc[-2] = 'VENDA'
                    print(f'{symbol}: VENDA')
                    # print(resumoFINAL)
    # print(symbol)
    # print(resumoFINAL)

print(f'Total dos papeis analisados: {len(symbols)}')
