# REPLAY INSIDES

import pyautogui as py
import time
from datetime import datetime
import shutil
import telepot
from time import sleep

#Monitor Pequeno
#x1=1991
#y1=249
#x2=x1
#y2=744

#Monitor GRANGE
x1=76
y1=291
x2=x1
y2=764

#py.moveTo(-1835,122) #compra e venda
#py.moveTo(x=91, y=676)  #compra e venda
py.moveTo(x1, y1)  #compra e venda
sleep(2)
py.moveTo(x2, y2)

def wdo(): 
    RGB = list(py.pixel(x1, y1))
    RGB = str(RGB[2])

    filename = 'Negocios_2mvWDO.txt'
    f =open(filename, "w")

    #Verde = py.pixelMatchesColor(510, 136, (17, 152, 80))
    #Vermelho = py.pixelMatchesColor(510, 136, (204, 48, 48))
    #RGB = list(py.pixel(514, 139))
    RGB = list(py.pixel(x1, y1))
    RGB = str(RGB[2])

    #print(RGB)
    f.write(RGB) 
    f.close()

    # >>> COMPARAÇÃO <<< #
    s=open('Negocios_2mvWDO.txt', 'r', encoding="utf8")
    try:
        o=open('Negocios_2mvWDO2.txt','r', encoding="utf8")
    except:
        shutil.copy('Negocios_2mvWDO.txt', 'Negocios_2mvWDO2.txt')
        o=open('Negocios_2mvWDO2.txt','r', encoding="utf8")

    dadoS = s.read()
    dadoO = o.read()

    if dadoS != dadoO:
        #if dadoS == '255': #Branco
        if dadoS != '255':   #Diferente Branco
            #bot = telepot.Bot('1827005235:AAGr4ss18HkJo11QKjBYBG-TqnKLv79Ph6Q')
            bot = telepot.Bot('5026686955:AAHvm0rJOf-_nSCi8sOHYVMhY8zPCBEd73k')
            bot.sendMessage(984798692, f'>> 2mv WDO (10R) <<')
            print('Sinal 2mv >> WDO <<')      

    s.close()
    o.close()

    shutil.copy('Negocios_2mvWDO.txt', 'Negocios_2mvWDO2.txt')
    #print('.')

def win():    
    RGB = list(py.pixel(x2, y2))
    RGB = str(RGB[2])

    filename = 'Negocios_2mvWIN.txt'
    f =open(filename, "w")

    #Verde = py.pixelMatchesColor(510, 136, (17, 152, 80))
    #Vermelho = py.pixelMatchesColor(510, 136, (204, 48, 48))
    #RGB = list(py.pixel(514, 139))
    RGB = list(py.pixel(x2, y2))
    RGB = str(RGB[2])

    #print(RGB)
    f.write(RGB) 
    f.close()

    # >>> COMPARAÇÃO <<< #
    s=open('Negocios_2mvWIN.txt', 'r', encoding="utf8")
    try:
        o=open('Negocios_2mvWIN2.txt','r', encoding="utf8")
    except:
        shutil.copy('Negocios_2mvWIN.txt', 'Negocios_2mvWIN2.txt')
        o=open('Negocios_2mvWIN2.txt','r', encoding="utf8")

    dadoS = s.read()
    dadoO = o.read()

    if dadoS != dadoO:
        #if dadoS == '255': #Branco
        if dadoS != '255':   #Diferente Branco
            #bot = telepot.Bot('1827005235:AAGr4ss18HkJo11QKjBYBG-TqnKLv79Ph6Q')
            bot = telepot.Bot('5026686955:AAHvm0rJOf-_nSCi8sOHYVMhY8zPCBEd73k')
            bot.sendMessage(984798692, f'>> 2mv WIN (20R) <<')
            print('Sinal 2mv >> WIN <<')

    s.close()
    o.close()

    shutil.copy('Negocios_2mvWIN.txt', 'Negocios_2mvWIN2.txt')
    #print('.')

while True:
    wdo()
    sleep(1)
    win()
    sleep(1)
    

