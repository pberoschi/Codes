
import requests
import pandas as pd
import telepot
from bs4 import BeautifulSoup
from selenium import webdriver
from time import sleep
from selenium.webdriver.chrome.options import Options



def metodo1 ():
    url = 'https://palaciodosleiloes.com.br/site/leilao.php'
    option = Options()
    option.headless = True
    # driver = webdriver.Chrome(options=option)     # NAVEGADOR OFF
    driver = webdriver.Chrome()                  # NAVEGADOR ON
    driver.get(url)
    html = driver.page_source
    soup = BeautifulSoup(html, 'html.parser')
    teste = soup.find('h3')
    
    driver.close()

    print(teste)


def metodo2():
    url = 'https://www.vipleiloes.com.br/Veiculos/ListarVeiculos?Enderecos=BA&Cidades=CAMA%c3%87ARI&TipoVeiculos=2'
    r = requests.get(url)
    soup = BeautifulSoup(r.content, 'html.parser')

    matriz = soup.find('div',{'class':'itm-body'})
    marca = matriz.find('h4',{'class':'itm-name'}).get_text().strip()
    valor = matriz.find('h3',{'class':'itm-value'}).get_text().strip()
    dataLeilao = matriz.find_all('p',{'class':'itm-start'})[1].get_text().strip()
    dataLeilao2 = dataLeilao.find('i')
    
    
    print(marca)
    print(valor)
    print(dataLeilao)




# metodo1()
metodo2()