#https://www.youtube.com/watch?v=TERKvqfySYI&t=1067s

import pyautogui as py
import time
from datetime import datetime
import shutil
import telepot
from time import sleep

x1=30
y1=460

x2=30
y2=748

py.moveTo(x1, y1) 
sleep(2)
py.moveTo(x2, y2)
sleep(1) 

def win():

    #Verde = py.pixelMatchesColor(510, 136, (17, 152, 80))
    #Vermelho = py.pixelMatchesColor(510, 136, (204, 48, 48))
    #RGB = list(py.pixel(514, 139))
    RGBwin = list(py.pixel(x1,y1))
    RGBwin = str(RGBwin[2])

    if RGBwin == '80':
        bot = telepot.Bot('1827005235:AAGr4ss18HkJo11QKjBYBG-TqnKLv79Ph6Q')
        bot.sendMessage(984798692, f'>> WIN COMPRA (ToposFundos) <<')
        print('WIN COMPRA')
    elif RGBwin == '48':
        bot = telepot.Bot('1827005235:AAGr4ss18HkJo11QKjBYBG-TqnKLv79Ph6Q')
        bot.sendMessage(984798692, f'>> WIN VENDA (ToposFundos) <<')
        print('WIN VENDA')

def wdo():

    RGBwdo = list(py.pixel(x2,y2))
    RGBwdo = str(RGBwdo[2])

    if RGBwdo == '80':
        bot = telepot.Bot('1827005235:AAGr4ss18HkJo11QKjBYBG-TqnKLv79Ph6Q')
        bot.sendMessage(984798692, f'>> WDO COMPRA (ToposFundos) <<')
        print('WDO COMPRA')
    elif RGBwdo == '48':
        bot = telepot.Bot('1827005235:AAGr4ss18HkJo11QKjBYBG-TqnKLv79Ph6Q')
        bot.sendMessage(984798692, f'>> WDO VENDA (ToposFundos) <<')
        print('WDO VENDA')


while True:
     # HORARIO DAS OPERAÇÕES
    agora = datetime.now()
    agora1 = str(agora)
    agoraRes = agora1[11:16]

    #STOP = list(py.pixel(x=-51, y=494))
    #STOP = str(STOP[2])

    if ('09:00' < agoraRes < '18:00'):
        win()
        sleep(1)
        wdo()
        sleep(30)
    
