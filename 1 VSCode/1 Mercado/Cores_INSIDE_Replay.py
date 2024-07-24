# REPLAY INSIDES

import pyautogui as py
import time
from datetime import datetime
import shutil
import telepot
from time import sleep

#py.moveTo(-1835,122) #compra e venda
py.moveTo(x=91, y=676)  #compra e venda

# --------------------------------------------------------------------------------- #
# Enviando imediatamente MSG de atual posição
RGB = list(py.pixel(x=91, y=676))
RGB = str(RGB[2])

def ins():
    
    filename = 'Negocios_INSIDE.txt'
    f =open(filename, "w")

    #Verde = py.pixelMatchesColor(510, 136, (17, 152, 80))
    #Vermelho = py.pixelMatchesColor(510, 136, (204, 48, 48))
    #RGB = list(py.pixel(514, 139))
    RGB = list(py.pixel(x=91, y=676))
    RGB = str(RGB[2])

    #print(RGB)
    f.write(RGB) 
    f.close()

    # >>> COMPARAÇÃO <<< #

    s=open('Negocios_INSIDE.txt', 'r', encoding="utf8")
    try:
        o=open('Negocios_INSIDE2.txt','r', encoding="utf8")
    except:
        shutil.copy('Negocios_INSIDE.txt', 'Negocios_INSIDE2.txt')
        o=open('Negocios_INSIDE2.txt','r', encoding="utf8")

    dadoS = s.read()
    dadoO = o.read()

    if dadoS != dadoO:
        if dadoS == '49':
            bot = telepot.Bot('1827005235:AAGr4ss18HkJo11QKjBYBG-TqnKLv79Ph6Q')
            bot.sendMessage(984798692, f'>> INSIDE <<')
            print('INSIDE')

    s.close()
    o.close()

    shutil.copy('Negocios_INSIDE.txt', 'Negocios_INSIDE2.txt')
    #print('.')

while True:
    ins()
    sleep(2)

