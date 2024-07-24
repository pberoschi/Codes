import requests
from bs4 import BeautifulSoup
import pandas as pd
from selenium import webdriver
from time import sleep
from selenium.webdriver.chrome.options import Options

#%config IPCompleter.greedy=True

tempoBusca = 15

option = Options()
option.headless = True

navegador = webdriver.Firefox()                       #NAVEGADOR ON
#navegador = webdriver.Chrome(options=option)          #NAVEGADOR OFF

#navegador = webdriver.Chrome()                       #NAVEGADOR ON
#navegador = webdriver.Chrome(options=option)          #NAVEGADOR OFF

navegador.get('https://pacotes.123milhas.com/produto/voos-para-lisboa-passagem-aerea/?utm_source=CrossSell+-+Banner&utm_medium=site&utm_campaign=CrossSell+PROMO+-+Banner+Destaque+Pesquisa+Voo&attribute_pa_origem=&attribute_pa_origem=sao-paulo&_gl=1*12ichey*_ga*MTQ1NDAzMTM3Mi4xNjU3ODkwNDMz*_ga_GB7T6W6M2F*MTY1Nzg5MDQzMy4xLjEuMTY1Nzg5MDU2NS42MA..')
sleep(5)

for x in range(1,14):
    # >>>>> Origem: São Paulo
    #navegador.find_element_by_xpath('/html/body/div[1]/main/div/div/div[2]/div/section[6]/div[2]/div/div/section/div/div[3]/div/div[2]/div/form/table/tbody/tr[1]/td[2]/div/select/option[7]').click()
    sleep(5)
    # >>>>> Período (data)
    navegador.find_element_by_xpath(f'/html/body/div[1]/main/div/div/div[2]/div/section[6]/div[2]/div/div/section/div/div[3]/div/div[2]/div/form/table/tbody/tr[2]/td[2]/div/select/option[{x}]').click()
    sleep(5)

    tabela = navegador.find_element_by_xpath('//*[@id="product-91328"]/div/section[6]/div[2]/div/div/section/div/div[3]/div/div[2]')
    html_content = tabela.get_attribute('outerHTML')
    soup = BeautifulSoup(html_content, 'html.parser')
    table = soup.find(name='table')

    preco = soup.find('span',{'class':'price'})
    if preco:
        preco = preco.text.split()
        precoCheio = preco[1]
        precoDesc = preco[3]
        
        print(x)
        #print(f'Valor Real: R$ {precoCheio}')
        print(f'Valor Desconto: R$ {precoDesc}\n')
    else:
        print('')

navegador.close()