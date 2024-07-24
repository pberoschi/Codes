#https://www.youtube.com/watch?v=TERKvqfySYI&t=1067s

import pyautogui as py
import time
from datetime import datetime
import shutil
import telepot
from time import sleep


#Monitor GRANGE
x1=170
y1=850
x2=480
y2=850

py.moveTo(x1, y1) 
sleep(2)
py.moveTo(x2, y2)
sleep(1) 


def wdo():

    RGBwdo = list(py.pixel(x1,y1))
    RGBwdo = str(RGBwdo[2])

    if RGBwdo == '80':
        bot = telepot.Bot('5026686955:AAHvm0rJOf-_nSCi8sOHYVMhY8zPCBEd73k')
        bot.sendMessage(984798692, f'>> WDO COMPRA DiDi<<')
        print('WDO COMPRA')
    elif RGBwdo == '48':
        bot = telepot.Bot('5026686955:AAHvm0rJOf-_nSCi8sOHYVMhY8zPCBEd73k')
        bot.sendMessage(984798692, f'>> WDO VENDA DiDi<<')
        print('WDO VENDA')

def win():

    #Verde = py.pixelMatchesColor(510, 136, (17, 152, 80))
    #Vermelho = py.pixelMatchesColor(510, 136, (204, 48, 48))
    #RGB = list(py.pixel(514, 139))
    RGBwin = list(py.pixel(x2,y2))
    RGBwin = str(RGBwin[2])

    if RGBwin == '80':
        bot = telepot.Bot('5026686955:AAHvm0rJOf-_nSCi8sOHYVMhY8zPCBEd73k')
        bot.sendMessage(984798692, f'>> WIN COMPRA DiDi<<')
        print('WIN COMPRA')
    elif RGBwin == '48':
        bot = telepot.Bot('5026686955:AAHvm0rJOf-_nSCi8sOHYVMhY8zPCBEd73k')
        bot.sendMessage(984798692, f'>> WIN VENDA DiDi<<')
        print('WIN VENDA')

while True:
     # HORARIO DAS OPERAÇÕES
    agora = datetime.now()
    agora1 = str(agora)
    agoraRes = agora1[11:16]

    #STOP = list(py.pixel(x=-51, y=494))
    #STOP = str(STOP[2])

    if ('09:00' < agoraRes < '17:30'):
        wdo()
        sleep(1)
        # win()
        sleep(60)
    else:
        print('Fora do Horário')
        sleep(60)
    
