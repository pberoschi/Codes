# REPLAY INSIDES

import pyautogui as py
import time
from datetime import datetime
import shutil
import telepot
from time import sleep

# x = 89
x = 150
y = 907
py.moveTo(x, y)  #compra e venda
RGB = list(py.pixel(x, y))
RGB = str(RGB[2])
# print(RGB)


def ins():
    try:    
        filename = 'Negocios_Donchian.txt'
        f = open(filename, "w")

        RGB = list(py.pixel(x, y))
        RGB = str(RGB[2])

        #print(RGB)
        f.write(RGB) 
        f.close()

        # >>> COMPARAÇÃO <<< #

        s=open('Negocios_Donchian.txt', 'r', encoding="utf8")
        try:
            o=open('Negocios_Donchian2.txt','r', encoding="utf8")
        except:
            shutil.copy('Negocios_Donchian.txt', 'Negocios_Donchian2.txt')
            o=open('Negocios_Donchian2.txt','r', encoding="utf8")

        dadoS = s.read()
        dadoO = o.read()

        if dadoS != dadoO:
            if dadoS == '205':
                bot = telepot.Bot('6372818731:AAFZXRVBq90-ufHCiTc5l_Mqj0ozYXHEV7o')
                bot.sendMessage(984798692, f'>> COMPRA DONCHIAN <<')
                print('COMPRA DONCHIAN')

            if dadoS == '49':
                bot = telepot.Bot('6372818731:AAFZXRVBq90-ufHCiTc5l_Mqj0ozYXHEV7o')
                bot.sendMessage(984798692, f'>> VENDA DONCHIAN <<')
                print('VENDA DONCHIAN')


        s.close()
        o.close()

        shutil.copy('Negocios_Donchian.txt', 'Negocios_Donchian2.txt')
        #print('.')

    except:
        print('Reiniciando ciclo')
        return


while True:
    ins()
    sleep(2)

