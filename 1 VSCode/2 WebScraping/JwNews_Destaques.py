import requests
import pandas as pd
from bs4 import BeautifulSoup
from time import sleep
from selenium import webdriver
from selenium.webdriver.chrome.options import Options

urljw = 'https://www.jw.org/pt/ultimos-artigos-destaque/'

headers = {'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/90.0.4430.212 Safari/537.36'}
r = requests.get(urljw, headers=headers)
soup = BeautifulSoup(r.content, 'html.parser')

main = soup.find_all("div", {'class':'syn-body lss'})

for item in main:
    teste = item.find('h3').text.strip()
    descricao = item.find('p').text.strip()
    link = item.find('a')['href']
    
    print(teste)
    print(descricao)
    print('www.jw.org' + link)
    print('-'*10)