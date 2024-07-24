
import pandas as pd
import requests
from bs4 import BeautifulSoup
import matplotlib.pyplot as plt
import pandas_datareader.data as web
from datetime import date
import yfinance as yf


url = 'https://www.fundsexplorer.com.br/ranking'

r = requests.get(url)
soup = BeautifulSoup(r.text, 'lxml')
table = soup.find_all('table')[0]

df = pd.read_html(str(table), decimal=',', thousands='.')[0]

# Ocultando resultados vazios
#df = pd.read_html(str(table), decimal=',', thousands='.')[0].dropna()

print(df)