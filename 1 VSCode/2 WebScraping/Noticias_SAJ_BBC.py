#https://www.youtube.com/watch?v=-yhAIadiiaU&t=319s

import requests
from bs4 import BeautifulSoup
#import pandas as pd
import telepot
from time import sleep 

telegramBot = telepot.Bot('1827005235:AAH9nEG0gU44dWcmk-x3iMbJhjckQbNapT4')


def saj(): 
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
        # print(titulo)
        
        # telegramBot.sendMessage(984798692,titulo)
        # telegramBot.sendMessage(984798692,resumo)
        telegramBot.sendMessage(984798692,link)

def bbc():
    headers = {'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/90.0.4430.212 Safari/537.36'}
    url = ('https://www.bbc.com/portuguese')
    r = requests.get(url, headers=headers)
    soup = BeautifulSoup(r.text, 'lxml')
    base = soup.find('div',{'data-testid':'hierarchical-grid'})
    tabela = base.find_all('h3')

    for item in tabela:
        titulo = item.find('a').text
        link = item.find('a').get('href')
        # print(titulo)
        # print(link)
        # print('')
        telegramBot.sendMessage(984798692,link)


saj()
# telegramBot.sendMessage(984798692,'BBC Noticias' + '\n\n\n' + '.')
bbc()

        



