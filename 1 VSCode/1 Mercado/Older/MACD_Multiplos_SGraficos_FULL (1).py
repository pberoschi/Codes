#https://www.youtube.com/watch?v=Hsex337XARI&list=PL_A8vbdzAGJQnIz6rPywVDRvxFbecl34e&index=8&t=1677s

from selenium import webdriver
from time import sleep
import pandas as pd
import time
import telegram
import yfinance as yf
import pandas as pd
#yf.pdr_override()

pd.options.mode.chained_assignment = None

ticker = [
    'ARZZ3.SA',
    'ABEV3.SA',
    'ASAI3.SA',
    'AZUL4.SA',
    'AMAR3.SA',
    'BTOW3.SA',
    'B3SA3.SA',
    'BIDI11.SA',
    'BBSE3.SA',
    'BRML3.SA',
    'BBDC3.SA',
    'BBDC4.SA',
    'BRAP4.SA',
    'BBAS3.SA',
    'BRKM5.SA',
    'BRFS3.SA',
    'BPAC11.SA',
    'CRFB3.SA',
    'CCRO3.SA',
    'CMIG4.SA',
    'HGTX3.SA',
    'CIEL3.SA',
    'COGN3.SA',
    'CPLE6.SA',
    'CSAN3.SA',
    'CPFE3.SA',
    'CVCB3.SA',
    'CYRE3.SA',
    'ECOR3.SA',
    'ELET3.SA',
    'ELET6.SA',
    'EMBR3.SA',
    'ENBR3.SA',
    'ENGI11.SA',
    'ENEV3.SA',
    'EGIE3.SA',
    'EQTL3.SA',
    'EZTC3.SA',
    'FLRY3.SA',
    'GGBR4.SA',
    'GOAU4.SA',
    'GOLL4.SA',
    'NTCO3.SA',
    'HAPV3.SA',
    'HYPE3.SA',
    'IGTA3.SA',
    'GNDI3.SA',
    'IRBR3.SA',
    'ITSA4.SA',
    'ITUB4.SA',
    'JBSS3.SA',
    'JHSF3.SA',
    'KLBN11.SA',
    'RENT3.SA',
    'LCAM3.SA',
    'LWSA3.SA',
    'LAME4.SA',
    'LREN3.SA',
    'MGLU3.SA',
    'MRFG3.SA',
    'BEEF3.SA',
    'MRVE3.SA',
    'MULT3.SA',
    'MOVI3.SA',
    'OIBR3.SA',
    'PCAR3.SA',
    'PETR3.SA',
    'PETR4.SA',
    'BRDT3.SA',
    'PRIO3.SA',
    'QUAL3.SA',
    'RADL3.SA',
    'RAIL3.SA',
    'SBSP3.SA',
    'SANB11.SA',
    'CSNA3.SA',
    'SULA11.SA',
    'SUZB3.SA',
    'TAEE11.SA',
    'VIVR3.SA',
    'VIVT3.SA',
    'TIMS3.SA',
    'TOTS3.SA',
    'UGPA3.SA',
    'USIM5.SA',
    'VALE3.SA',
    'VVAR3.SA',
    'WEGE3.SA',
    'YDUQ3.SA'
]


# ANALISE DE CADA PAPEL
for x in ticker:
    dia2 = yf.Ticker(x)
    Dia = dia2.history(period='1d', interval='5m').tail(1)
    Ano = yf.download(x, period='1y')
    print(x)     
    #ANO: criando coluna Data e transferindo valores
    Ano.insert(loc=0, column='DataMain', value=Ano.index)
    #remove a ultima data
    removedata = Ano.loc[(Ano['DataMain']==pd.to_datetime('today').normalize())]
    Ano = Ano.drop(removedata.index)
    #DIA: criando coluna Data e transferindo valores
    Dia.insert(loc=0, column='DataMain', value=Dia.index)
    #unindo os periodos
    Resumo = Ano.append(Dia)
    #ajuste da data
    Resumo['DataMain'] = pd.to_datetime(Resumo['DataMain'], utc=True).dt.date
    #resumindo as colunas desejadas (data e fechamento)
    ResumoEnd = Resumo[['DataMain', 'Close']]
    #calculo MACD
    rapidoMME = ResumoEnd.Close.ewm(span=12).mean()
    lentaMME = ResumoEnd.Close.ewm(span=26).mean()
    MACD = rapidoMME - lentaMME
    Sinal = MACD.ewm(span=9).mean()
    ResumoEnd['MACD'] = MACD
    ResumoEnd['Sinal'] = Sinal
    #ajuste index e retira data; coloca data como index
    ResumoEnd = ResumoEnd.set_index(pd.DatetimeIndex(ResumoEnd['DataMain'].values))
    ResumoEnd = ResumoEnd.drop('DataMain', 1)
    # criar código para verificar a compra ou venda
    ResumoEnd['flag'] = ''
    ResumoEnd['preco_compra'] = ''
    ResumoEnd['preco_venda'] = ''
    for i in range (1, len(ResumoEnd.Sinal)):
      if ResumoEnd['MACD'][i] > ResumoEnd['Sinal'][i]:
        if ResumoEnd['flag'][i-1] == 'C':
          ResumoEnd['flag'][i] = 'C'
        else:
          ResumoEnd['flag'][i] = 'C'
          ResumoEnd['preco_compra'][i] = ResumoEnd['Close'][i]
            
      elif ResumoEnd['MACD'][i] < ResumoEnd['Sinal'][i]:
        if ResumoEnd['flag'][i-1] == 'V':
            ResumoEnd['flag'][i] = 'V'
        else:
            ResumoEnd['flag'][i] = 'V'
            ResumoEnd['preco_venda'][i] = ResumoEnd['Close'][i]
            
    # mensagem ao TELEGRAM
    my_token = '1852343442:AAEBBS1NjjFRIqt-XTbb3rzRxipvk8ZqI5I'
    chat_id = '-351556985'
    def envia_mensagem(msg, chat_id, token = my_token):
      bot = telegram.Bot(token = token)
      bot.sendMessage(chat_id = chat_id, text=msg)
    hoje = ResumoEnd.flag[-1]
    ontem = ResumoEnd.flag[-2]
    flag = hoje
    ticker2 = x[0:-3]
    site = f'https://www.google.com/search?q={ticker2}&rlz=1C1EJFC_enBR915BR916&oq={ticker2}&aqs=chrome..69i57j0l5j0i10i433j69i60.4408j0j7&sourceid=chrome&ie=UTF-8'
    preco_fechamento = round(ResumoEnd.Close.tail(1)[-1],2)
    msg = f'{ticker2}  \n>>> {flag} <<< \nPreço de Fechamento: {preco_fechamento}\n\nTotal de ações analisadas: {len(ticker)}\n{site}'
    #msg = f'{ticker2}  \n>>> {flag} <<< \nPreço de Fechamento: {preco_fechamento}\n\nTotal de ações analisadas: {len(ticker)}'
    #verificar se houve alteração do sinal
    if ontem != hoje:
      envia_mensagem(msg, chat_id, my_token)
    time.sleep(0.5)





