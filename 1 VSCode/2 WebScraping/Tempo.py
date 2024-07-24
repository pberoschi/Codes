import requests
import time
from bs4 import BeautifulSoup
from selenium.webdriver.firefox.options import Options
from selenium import webdriver as wb
import telepot

bot = telepot.Bot('1591788137:AAFXANf-i5DYCCFJMuEe5cCjP1X7-I1WwPM')

def g1():
    url = 'https://g1.globo.com/previsao-do-tempo/ba/santo-antonio-de-jesus.ghtml'

    option = Options()
    option.headless = True
    driver = wb.Firefox(executable_path="C:\Program Files\geckodriver\geckodriver.exe", options=option)            # NAVEGADOR OFFLINE 
    #driver = wb.Firefox(executable_path="C:\Program Files\geckodriver\geckodriver.exe")                             # NAVEGADOR ONLINE
    driver.get(url)
 
    bot.sendMessage(984798692,
    'Previsão do tempo para HOJE (G1):' '\n'
    'Máxima: '+ driver.find_element_by_xpath('/html/body/div[2]/div[4]/div[1]/div[2]/div[4]/div[1]').text + '\n' 
    'Mínima: '+ driver.find_element_by_xpath('/html/body/div[2]/div[4]/div[1]/div[2]/div[4]/div[2]').text  + '\n'
    'Chuva: '+ driver.find_element_by_xpath('/html/body/div[2]/div[4]/div[1]/div[3]/div/div[1]/div[1]/span[3]').text + '\n' '\n'

    'Previsão do tempo para AMANHÃ (G1):' '\n'
    'Máxima: '+ driver.find_element_by_xpath('/html/body/div[2]/div[4]/div[3]/div[1]/div/div[1]/div[1]/div[1]/span[3]').text + '\n' 
    'Mínima: '+ driver.find_element_by_xpath('/html/body/div[2]/div[4]/div[3]/div[1]/div/div[1]/div[1]/div[1]/span[4]').text  + '\n'
    )
    driver.quit()


def INPE():
    url = 'http://tempo.cptec.inpe.br/ba/santo-antonio-de-jesus'

    option = Options()
    option.headless = True
    driver = wb.Firefox(executable_path="C:\Program Files\geckodriver\geckodriver.exe", options=option)            # NAVEGADOR OFFLINE 
    #driver = wb.Firefox(executable_path="C:\Program Files\geckodriver\geckodriver.exe")                             # NAVEGADOR ONLINE
    driver.get(url)

    bot.sendMessage(984798692,
    'Previsão do tempo para HOJE (INPE):' '\n'
    'Máxima: '+ driver.find_element_by_xpath('//*[@id="bloco-previsao"]/div[1]/div[3]/div[1]/span[2]').text + '\n' 
    'Mínima: '+ driver.find_element_by_xpath('//*[@id="bloco-previsao"]/div[1]/div[3]/div[1]/div').text  + '\n'
    'Chuva: '+ driver.find_element_by_xpath('//*[@id="bloco-previsao"]/div[1]/div[3]/div[2]/div').text + '\n' '\n'

    'Previsão do tempo para AMANHÃ (INPE):' '\n'
    'Máxima: '+ driver.find_element_by_xpath('//*[@id="bloco-previsao"]/div[2]/div[3]/div[1]/span[2]').text + '\n' 
    'Mínima: '+ driver.find_element_by_xpath('//*[@id="bloco-previsao"]/div[2]/div[3]/div[1]/div').text  + '\n'
    'Chuva: '+ driver.find_element_by_xpath('//*[@id="bloco-previsao"]/div[2]/div[3]/div[2]/div').text
    )
    driver.quit()


g1()
INPE()

