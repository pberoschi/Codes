import pyautogui as py
import time
from datetime import datetime
import shutil
import telepot
from time import sleep

#Monitor GRANGE
x1=89
y1=824
x2=x1
y2=824

#py.moveTo(-1835,122) #compra e venda
py.moveTo(x1, y1)  #compra e venda

# --------------------------------------------------------------------------------- #
# Enviando imediatamente MSG de atual posição
RGB = list(py.pixel(x1, y1))
RGB = str(RGB[2])

def win20R():
    
    filename = 'Negocios_WIN_ADX.txt'
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

    s=open('Negocios_WIN_ADX.txt', 'r', encoding="utf8")
    try:
        o=open('Negocios_WIN_ADX2.txt','r', encoding="utf8")
    except:
        shutil.copy('Negocios_WIN_ADX.txt', 'Negocios_WIN_ADX2.txt')
        o=open('Negocios_WIN_ADX2.txt','r', encoding="utf8")

    dadoS = s.read()
    dadoO = o.read()

    if dadoS != dadoO:
        if dadoS == '80':
            bot = telepot.Bot('5026686955:AAHvm0rJOf-_nSCi8sOHYVMhY8zPCBEd73k')
            bot.sendMessage(984798692, f'WIN_20R >> COMPRA <<')
            print('COMPRA')
        elif dadoS == '48':
            bot = telepot.Bot('5026686955:AAHvm0rJOf-_nSCi8sOHYVMhY8zPCBEd73k')
            bot.sendMessage(984798692, f'WIN_20R >> VENDA <<')
            print('VENDA')

    s.close()
    o.close()

    shutil.copy('Negocios_WIN_ADX.txt', 'Negocios_WIN_ADX2.txt')
    #print('.')

while True:
     # HORARIO DAS OPERAÇÕES
        win20R()
        sleep(1)
