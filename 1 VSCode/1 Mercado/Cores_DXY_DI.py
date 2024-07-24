#https://www.youtube.com/watch?v=TERKvqfySYI&t=1067s

import pyautogui as py
import time
from datetime import datetime
import shutil
import telepot
from time import sleep

#Monitor Pequeno
DIx = 125
DIy = 181
DXYx = 111
DXYy = 504
WDOx = 129
WDOy = 828


# py.moveTo(DIx, DIy)
# sleep(1)
# py.moveTo(DXYx, DXYy)
# sleep(1)
# py.moveTo(WDOx, WDOy)
# sleep(1)

def wdo():
    
    filename = 'NegociosDI.txt'
    f =open(filename, "w")

    #Verde = py.pixelMatchesColor(510, 136, (17, 152, 80))
    #Vermelho = py.pixelMatchesColor(510, 136, (204, 48, 48))
    #RGB = list(py.pixel(514, 139))
    RGB1 = list(py.pixel(DIx, DIy))
    RGB1 = str(RGB1[2])

    RGB2 = list(py.pixel(DXYx, DXYy))
    RGB2 = str(RGB2[2])

    RGB3 = list(py.pixel(WDOx, WDOy))
    RGB3 = str(RGB3[2])


    #print(RGB)
    f.write(RGB1 + "," + RGB2 + "," + RGB3) 
    f.close()


    # >>> COMPARAÇÃO <<< #

    s=open('NegociosDI.txt', 'r', encoding="utf8")
    try:
        o=open('NegociosDI2.txt','r', encoding="utf8")
    except:
        shutil.copy('NegociosDI.txt', 'NegociosDI2.txt')
        o=open('NegociosDI2.txt','r', encoding="utf8")

    dadoS = s.read()
    dadoO = o.read()

    if dadoS != dadoO:
        if dadoS == '80,80,80':
            #bot = telepot.Bot('5026686955:AAHvm0rJOf-_nSCi8sOHYVMhY8zPCBEd73k')
            #bot.sendMessage(-1001778706191, f'Win_20R >> COMPRA <<')
            bot = telepot.Bot('6372818731:AAFZXRVBq90-ufHCiTc5l_Mqj0ozYXHEV7o')
            bot.sendMessage(984798692, f'WDO_DXY >> COMPRA <<')
            print('COMPRA')

        elif dadoS == '48,48,48':
            #bot = telepot.Bot('5026686955:AAHvm0rJOf-_nSCi8sOHYVMhY8zPCBEd73k')
            #bot.sendMessage(-1001778706191, f'Win_20R >> VENDA <<')
            bot = telepot.Bot('6372818731:AAFZXRVBq90-ufHCiTc5l_Mqj0ozYXHEV7o')
            bot.sendMessage(984798692, f'WDO_DXY >> VENDA <<')
            print('VENDA')


    s.close()
    o.close()

    shutil.copy('NegociosDI.txt', 'NegociosDI2.txt')
    #print('.')

while True:
    #HORARIO DAS OPERAÇÕES
    agora = datetime.now()
    agora1 = str(agora)
    agoraRes = agora1[11:16]

    if ('09:00' < agoraRes < '18:00'):
        wdo()
        sleep(1)