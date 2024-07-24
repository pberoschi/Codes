import requests
import pandas as pd
import telepot
from bs4 import BeautifulSoup
from selenium import webdriver
from time import sleep
from selenium.webdriver.chrome.options import Options

url = 'https://pacotes.123milhas.com/'

option = Options()
option.headless = True
driver = webdriver.Chrome(options=option)     # NAVEGADOR OFF
#driver = webdriver.Chrome()                  # NAVEGADOR ON
driver.get(url)
html = driver.page_source
soup = BeautifulSoup(html, 'html.parser')

#matriz = soup.find('div',{'class':'container'})
matriz = soup.find_all('li',{'class':'product-wrap'})

driver.close()

for item in matriz:
    destino = item.find('h5').text
    destino = destino[13:]
    titulo = item.find('a')['href']
    preco = item.find('h4').text
    resumo = (f'{destino} ({preco})\n{titulo}\n')

    print(resumo)
        
    #bot = telepot.Bot('1591788137:AAFXANf-i5DYCCFJMuEe5cCjP1X7-I1WwPM')
    #bot.sendMessage(984798692, resumo)