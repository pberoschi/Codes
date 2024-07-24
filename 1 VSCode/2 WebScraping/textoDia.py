#import requests
#import time
#from bs4 import BeautifulSoup
#from datetime import datetime
from selenium.webdriver.firefox.options import Options
from selenium import webdriver as wb
import telepot
import pywhatkit
import keyboard




bot = telepot.Bot('1591788137:AAFXANf-i5DYCCFJMuEe5cCjP1X7-I1WwPM')

url = 'https://wol.jw.org/pt/wol/h/r5/lp-t'

option = Options()
option.headless = True
driver = wb.Firefox(executable_path="C:\Program Files\geckodriver\geckodriver.exe", options=option)            # NAVEGADOR OFFLINE 
#driver = wb.Firefox(executable_path="C:\Program Files\geckodriver\geckodriver.exe")                             # NAVEGADOR ONLINE
driver.get(url)




#textocompl = driver.find_element_by_xpath('//*[@id="dailyText"]/div[2]/div').text[0:200]                           # //*[@id="p87"]/em[1] ------ //*[@id="p87"] -------- //*[@id="p90"]
#textocompl = driver.find_element_by_xpath('//*[@id="dailyText"]/div[2]/div[2]').text[0:200]
textocompl = driver.find_element_by_xpath('//*[@id="section1"]/div').text[0:200]

bot.sendMessage(984798692,
'::: Texto do dia :::'.upper() + '\n' '\n' +
textocompl + '...' + '\n' '\n' '\n' '\n' +
'Para continuar a ler, clique no link abaixo para ser redirecionado ao site:' + '\n''\n' +
url
)
driver.quit()


def print_tela():
    comentario = driver.find_element_by_xpath('//*[@id="section1"]/div').text                                   #//*[@id="p88"]
    endereco = 'https://wol.jw.org/pt/wol/h/r5/lp-t'
    dia = driver.find_element_by_xpath('//*[@id="dailyText"]/div[2]/div/header').text                           #//*[@id="p86"]

    print(dia)
    print(texto)
    print(textobib)
    print(comentario[0:200])
    driver.quit()

def envio_individual():
    bot.sendMessage(984798692,
    '::: Texto do dia :::'.upper() + '\n' '\n' +
    '>>> ' + driver.find_element_by_xpath('//*[@id="dailyText"]/div[2]/div/header').text + ' <<<' + '\n''\n' +
    #'"' + driver.find_element_by_xpath('').text.upper() + '"' + '\n''\n' +
    driver.find_element_by_xpath('//*[@id="section1"]/div').text[0:200] + '...' + '\n' '\n' '\n' '\n' +
    'Para continuar a ler, clique no link abaixo para ser redirecionado ao site:' + '\n''\n' +
    url
    )
    driver.quit()

def whatsapp():
    '''
    endereco = 'https://wol.jw.org/pt/wol/h/r5/lp-t'
    contatos = ['+5575991143357', '+5575991383134']
    messagem = '.'
    #pywhatkit.sendwhatmsg(contatos, messagem, datetime.now().hour,datetime.now().minute + 1)
    #pywhatkit.sendwhatmsg('+5575991143357',
    pywhatkit.sendwhatmsg(contatos[0], 'Boa noite a todos', 21,52)
        
        'Texto do dia:' '\n' '\n' +
        '>>> ' + driver.find_element_by_xpath('//*[@id="p83"]').text + ' <<<' + '\n''\n' +
        '"' + driver.find_element_by_xpath('//*[@id="p84"]/em[1]').text.upper() + '" ' + driver.find_element_by_xpath('//*[@id="p84"]/a/em').text + '\n''\n' +
        driver.find_element_by_xpath('//*[@id="p85"]').text[0:150] + ' (((...continue lendo no site)))' + '\n' '\n' '\n' '\n' +
        'Para continuar a ler, clique no link abaixo para ser redirecionado ao site:' + '\n''\n' +
        endereco, 21,32)

    time.sleep(10)
    keyboard.press_and_release('ctrl + w')
    #time.sleep(60)

    '''
    