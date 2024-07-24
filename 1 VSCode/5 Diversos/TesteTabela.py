import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import pandas_datareader.data as web
from datetime import date
import plotly.graph_objects as go

#!pip install yfinance --upgrade --no-cache-dir
import yfinance as yf
yf.pdr_override()

acao = input(f'Qual a AÇÃO:')+'.SA'
ticker = web.get_data_yahoo(acao, period='1y')
ticker2 = web.get_data_yahoo(acao, period='6mo')
print(acao.upper())



# GRÁFICO 01 / PERÍODO: 1 ANO
ticker['Adj Close'].plot(figsize=(22,8), label=acao.upper())
ticker['Adj Close'].rolling(100).mean().plot(label='Média 100 dias')
plt.legend()
print(f'DATA FINAL: {date.today()}')

df = pd.DataFrame(ticker)
df.insert(loc=0,column='Data',value=df.index)




# GRÁFICO 02 / PERÍODO: 6 MESES
df = pd.DataFrame(ticker2)
df.insert(loc=0,column='Data',value=df.index)

fig = go.Figure(data=[go.Candlestick(
                x=ticker2['Data'],
                open=ticker2['Open'],
                high=ticker2['High'],
                low=ticker2['Low'],
                close=ticker2['Adj Close'])])
fig.update_layout(
    xaxis_rangeslider_visible=False,
    title=acao.upper(),
    yaxis_title='VALOR R$',
    )
fig.show()