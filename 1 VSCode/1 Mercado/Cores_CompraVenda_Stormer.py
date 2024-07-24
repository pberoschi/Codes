#https://www.youtube.com/watch?v=TERKvqfySYI&t=1067s

import pyautogui as py
from datetime import datetime
import telepot
from time import sleep

py.moveTo(114,880) #compra e venda
sleep(2)
#py.moveTo(115,389) #Stop nas operações do dia
#sleep(2)
#py.moveTo(115,430)
#sleep(2)

# ----------------------------------------------------------------------------------- #
def win():
    
    imped1 = list(py.pixel(114,880))
    imped1 = str(imped1[2])


    if imped1 == '80':
        bot = telepot.Bot('1827005235:AAGr4ss18HkJo11QKjBYBG-TqnKLv79Ph6Q')
        bot.sendMessage(984798692, f'>> Perda de TOPO: POSSÍVEL COMPRA <<')
        print('Perda de TOPO: POSSÍVEL COMPRA')
    elif imped1 == '48':
        bot = telepot.Bot('1827005235:AAGr4ss18HkJo11QKjBYBG-TqnKLv79Ph6Q')
        bot.sendMessage(984798692, f'>> Perda de FUNDO: POSSÍVEL VENDA <<')
        print('Perda de FUNDO: POSSÍVEL VENDA')


while True:
     # HORARIO DAS OPERAÇÕES
    agora = datetime.now()
    agora1 = str(agora)
    agoraRes = agora1[11:16]

    if ('08:59' < agoraRes < '18:00'):
        win()
        sleep(600)
    

