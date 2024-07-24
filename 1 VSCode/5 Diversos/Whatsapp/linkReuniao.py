import pyautogui as py
import time
from bs4 import BeautifulSoup
import requests
#from datetime import datetime
from selenium.webdriver.firefox.options import Options
from selenium import webdriver as wb
import pywhatkit
import keyboard
#import os


arquivo = open('C:\\Users\\johnn\\PycharmProjects\\1_PRONTOS\\Whatsapp\\linkReuniao.txt', 'r', encoding="utf8")
link = arquivo.read()
link = link.split(';')


#contato = input(f'Qual é o contato? ')
contato = 'Arquivos'

#py.PAUSE = 0.5
#py.press('winleft')
#py.write('whats')
#py.PAUSE = 0.5
#py.press('enter')
#time.sleep(20)
py.click(79,113)
py.write(contato, interval=0.40)
py.click(62, 242)
time.sleep(5)
#py.write(msg, interval=0.25)
keyboard.write(link)
time.sleep(1)
py.press('enter')
time.sleep(5)
#py.click(937,15)

arquivo.close()
print('Fim do código')