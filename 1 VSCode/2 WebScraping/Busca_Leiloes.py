
import requests
import pandas as pd
import telepot
from bs4 import BeautifulSoup
from selenium import webdriver
from time import sleep
from selenium.webdriver.chrome.options import Options

# url = 'https://www.palaciodosleiloes.com.br/site/?categoria_pesquisa=1&subcategoria_pesquisa=2&local_pesquisa=2'
# option = Options()
# driver = webdriver.Chrome(options=option)     # NAVEGADOR OFF
# driver.get(url)
# html = driver.page_source
# soup = BeautifulSoup(html, 'html.parser')
# driver.find_element("xpath",'//*[@id="div_lotes"]/div/div[10]/span[2]').click()
# sleep(50)
# driver.close()
# driver.find_element("xpath",'/html/body/div[2]/div/div/div[2]/div/div/div[1]/section/main/article/div[2]/div[1]/div[2]/form/div/div[3]').click()


def metodo1 ():
    url = 'https://www.palaciodosleiloes.com.br/site/?categoria_pesquisa=1&subcategoria_pesquisa=2&local_pesquisa=2'
    option = Options()
    # option.headless = True
    driver = webdriver.Chrome(options=option)     # NAVEGADOR OFF
    # driver = webdriver.Chrome()                  # NAVEGADOR ON
    driver.get(url)
    html = driver.page_source
    # sleep(5)
    # driver.find_element("xpath",'//*[@id="div_lotes"]/div/div[21]/span[2]').click()
    # print("Clicado em Exibir todos")
    # sleep(5)
    soup = BeautifulSoup(html, 'html.parser')
    base = soup.find_all('div',{'col-md-3 pl-2 pr-1 cp'})
    driver.close()

    for item in base:
        veiculo =   item.find('div',{'quebraln mt-3 mb-0 h6'}).text
        ano =       item.find('div',{'my-0 h6 mb-2'}).text
        estado =    item.find('div',{'mt-0 small'}).next_element.text
        local =     item.find('div',{'mt-0 small'}).next_element.next_element.text
        data =      item.find('div',{'inf small'}).next_element.next_element.text
        ref =       item.find('div',{'inf small'}).next_element.next_element.next_element.next_element.next_element.next_element.next_element.next_element.next_element.next_element.next_element.next_element.text
        valor =     item.find('div',{'h3 mt-3 text-center'}).next_element.next_element.next_element.next_element.text

        print(f'Veiculo: {veiculo}')
        print(f'Ano: {ano}')
        print(f'Situacao: {estado}')
        print(f'Local: {local}')
        print(f'Data: {data}')
        print(f'Ref: {ref}')
        print(f'Valor: {valor}')

        print('-'*45)





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




metodo1()
# metodo2()