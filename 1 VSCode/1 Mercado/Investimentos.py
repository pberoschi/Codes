import pandas as pd
from bs4 import BeautifulSoup
import requests


url = 'https://www.fundsexplorer.com.br/ranking'

response = requests.get(url)
soup = BeautifulSoup(response.text, 'lxml')

table = soup.find_all('table')[0]
df = pd.read_html(str(table), decimal=',', thousands='.')[0]

print(df)

df.to_excel("fundos.xlsx", index = False)