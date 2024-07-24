#https://www.youtube.com/watch?v=TERKvqfySYI&t=1067s

#https://www.youtube.com/watch?v=TERKvqfySYI&t=1067s

import pyautogui as py
import time
from datetime import datetime
import shutil
import telepot
from time import sleep

x1 = 1659
y1 = 149

#py.moveTo(-1835,122) #compra e venda
py.moveTo(x1, y1) #compra e venda

# --------------------------------------------------------------------------------- #
# Enviando imediatamente MSG de atual posição
RGB = list(py.pixel(x1, y1))
RGB = str(RGB[2])

def wdo4R():
    
    filename = 'Negocios_wdo4R.txt'
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

    s=open('Negocios_wdo4R.txt', 'r', encoding="utf8")
    try:
        o=open('Negocios_wdo4R2.txt','r', encoding="utf8")
    except:
        shutil.copy('Negocios_wdo4R.txt', 'Negocios_wdo4R2.txt')
        o=open('Negocios_wdo4R2.txt','r', encoding="utf8")

    dadoS = s.read()
    dadoO = o.read()

    try:
        if dadoS != dadoO:
            if dadoS == '80':
                bot = telepot.Bot('6372818731:AAFZXRVBq90-ufHCiTc5l_Mqj0ozYXHEV7o')
                #bot.sendMessage(984798692, f'WDO_10R >> COMPRA <<')
                bot.sendMessage(984798692, f'WDO_4R >> COMPRA <<')
                print('COMPRA')
            elif dadoS == '48':
                bot = telepot.Bot('6372818731:AAFZXRVBq90-ufHCiTc5l_Mqj0ozYXHEV7o')
                #bot.sendMessage(984798692, f'WDO_10R >> VENDA <<')
                bot.sendMessage(984798692, f'WDO_4R >> VENDA <<')
                print('VENDA')
    except:
         bot = telepot.Bot('6372818731:AAFZXRVBq90-ufHCiTc5l_Mqj0ozYXHEV7o')
         bot.sendMessage(984798692, f'Falha no código, mas ainda funcionando. É bom conferir!')
         
         return
    
    s.close()
    o.close()

    shutil.copy('Negocios_wdo4R.txt', 'Negocios_wdo4R2.txt')
    #print('.')

while True:
     # HORARIO DAS OPERAÇÕES
        wdo4R()
        sleep(2)
