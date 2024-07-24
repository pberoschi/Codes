#https://www.youtube.com/watch?v=-yhAIadiiaU&t=319s

import requests
from bs4 import BeautifulSoup
#import pandas as pd
import telepot

telegramBot = telepot.Bot('1827005235:AAGr4ss18HkJo11QKjBYBG-TqnKLv79Ph6Q')



headers = {'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/90.0.4430.212 Safari/537.36'}
url = ('https://blogdovalente.com.br/categoria/noticias/saj/')
r = requests.get(url, headers=headers)
soup = BeautifulSoup(r.text, 'lxml')

base = soup.find('div',{'class':'content row'})

tabela = base.find_all('div',{'class':'col-sm-7'})[0:10]


for item in tabela:
    titulo = item.find('h2').text.strip()
    resumo = item.find('p').text.strip()
    link = item.find('a').get('href')
    
    #telegramBot.sendMessage(984798692,titulo)
    #telegramBot.sendMessage(984798692,resumo)
    telegramBot.sendMessage(984798692,link)