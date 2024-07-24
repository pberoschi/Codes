import requests
import pandas as pd
from bs4 import BeautifulSoup
import time

origem = 'SSA'
destino = 'SAO'
#IDA
anoIda = '2022'
mesIda = '11'
dataIda = list(range(21,29))

def completo():
    for x in dataIda:
        headers = {'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/90.0.4430.212 Safari/537.36'}
        url = f'https://www.kayak.com.br/flights/{origem}-{destino}/{anoIda}-{mesIda}-{x}?sort=bestflight_a'
        r = requests.get(url, headers=headers)
        soup = BeautifulSoup(r.content, 'html.parser')
        time.sleep(5)

        tempo = soup.find('span',{'class':'js-subLabel js-duration _ibU _ibV _idj _kLa _kLb _kLc _kLe _kKW'})
        if tempo is not None:
            tempo = tempo.text.strip()
            preco = soup.find('span',{'class':'js-label js-price _itL _ibU _ibV _idj _kKW'}).text.strip()
            time.sleep(1)
            empresa = soup.find('span',{'class':'codeshares-airline-names'}).text.strip()
            time.sleep(1)

            print(f'DIA: {x}/{mesIda}/{anoIda}')
            #print('>>> MELHOR OPÇÃO <<<')
            if preco:
             print(f'Preço: {preco}')
            if tempo:
             print(f'Duração: {tempo}')
            if empresa:
                print(f'Empresa: {empresa}')
            print('-'*25)
        else:
            tempo = None
          
    print('*** FIM DA BUSCA ***')

def resumido():
    for x in dataIda:
        headers = {'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/90.0.4430.212 Safari/537.36'}
        url = f'https://www.kayak.com.br/flights/{origem}-{destino}/{anoIda}-{mesIda}-{x}?sort=bestflight_a'
        r = requests.get(url, headers=headers)
        soup = BeautifulSoup(r.content, 'html.parser')
        time.sleep(5)

        preco = soup.find('span',{'class':'js-label js-price _itL _ibU _ibV _idj _kKW'})
        if preco is not None:
            preco = preco.text.strip()
            time.sleep(1)

            empresa = soup.find('span',{'class':'codeshares-airline-names'})
            if empresa is not None:
                empresa = empresa.text.strip()
            else:
                empresa = None
            time.sleep(1)

            print(f'DIA: {x}/{mesIda}/{anoIda}')
            if preco:
                print(f'Preço: {preco}')
            if empresa:
                print(f'Empresa: {empresa}')
            print('-'*25)
            #time.sleep(1)
        else:
            preco = None

    print('*** FIM DA BUSCA ***')

#completo()
resumido()
time.sleep(5)
#resumido()