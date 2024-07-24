import pyautogui as py
import time
from bs4 import BeautifulSoup
import requests
#from datetime import datetime
from selenium.webdriver.firefox.options import Options
from selenium import webdriver as wb
import pywhatkit
import keyboard



contato = input(f'Qual é o contato? ')


# TEXTO DO DIA
url = 'https://wol.jw.org/pt/wol/h/r5/lp-t'

option = Options()
option.headless = True
driver = wb.Firefox(executable_path="C:\Program Files\geckodriver\geckodriver.exe", options=option)               # NAVEGADOR OFFLINE
# driver = wb.Firefox(executable_path="C:\Program Files\geckodriver\geckodriver.exe")                             # NAVEGADOR ONLINE
driver.get(url)

textocompl = driver.find_element_by_xpath('//*[@id="dailyText"]/div[2]').text[0:300]  # //*[@id="p87"]/em[1] ------ //*[@id="p87"] -------- //*[@id="p90"]

driver.quit()

py.PAUSE = 0.5
py.press('winleft')
py.write('whats')
py.PAUSE = 0.5
py.press('enter')
time.sleep(20)
py.click(79,113)
py.write(contato, interval=0.40)
py.click(62, 242)
time.sleep(5)
keyboard.write('_*TEXTO DO DIA*_' '\n')
keyboard.write(textocompl + ' _(...)_''\n')
keyboard.write('_Para continuar, clique e leia diretamente no site_ https://wol.jw.org/pt/wol/h/r5/lp-t' '\n')
time.sleep(1)
py.press('enter')
time.sleep(5)
py.click(937,15)


#print(f'texto: {textocompl}')
#print('Fim do código')