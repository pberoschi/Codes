#https://www.youtube.com/watch?v=TERKvqfySYI&t=1067s

import pyautogui as py
import time
from datetime import datetime
import shutil
import telepot
from time import sleep

x1 = 3646
y1 = 822

x2 = 3646
y2 = 500

#py.moveTo(-1835,122) #compra e venda
py.moveTo(x1, y1) #compra e venda
sleep(1)
py.moveTo(x2, y2) #compra e venda

# --------------------------------------------------------------------------------- #
# Enviando imediatamente MSG de atual posição
RGB11 = list(py.pixel(x1, y1))
RGB1 = str(RGB11[2])
print(RGB1)

RGB22 = list(py.pixel(x2, y2))
RGB2 = str(RGB22[2])
print(RGB2)

def ativo1():
    
    filename = 'Negocios_cruzam.txt'
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

    s=open('Negocios_cruzam.txt', 'r', encoding="utf8")
    try:
        o=open('Negocios_cruzam2.txt','r', encoding="utf8")
    except:
        shutil.copy('Negocios_cruzam.txt', 'Negocios_cruzam2.txt')
        o=open('Negocios_cruzam2.txt','r', encoding="utf8")

    dadoS = s.read()
    dadoO = o.read()

    try:
        if dadoS != dadoO:
            if dadoS == '80':
            # if dadoS == '128':
                bot = telepot.Bot('6372818731:AAFZXRVBq90-ufHCiTc5l_Mqj0ozYXHEV7o')
                #bot.sendMessage(984798692, f'WDO_10R >> COMPRA <<')
                bot.sendMessage(-4048406255, f'SETUP Jair >> COMPRA <<')
                print(f'COMPRA / {RGB}')
            elif dadoS == '48':
            # elif dadoS == '0':
                bot = telepot.Bot('6372818731:AAFZXRVBq90-ufHCiTc5l_Mqj0ozYXHEV7o')
                #bot.sendMessage(984798692, f'WDO_10R >> VENDA <<')
                bot.sendMessage(-4048406255, f'SETUP Jair >> VENDA <<')
                print(f'VENDA / {RGB}')
            elif dadoS == '255':
                bot = telepot.Bot('6372818731:AAFZXRVBq90-ufHCiTc5l_Mqj0ozYXHEV7o')
                #bot.sendMessage(984798692, f'WDO_10R >> VENDA <<')
                #bot.sendMessage(984798692, f'CRUZAMENTO_MMs >> ZERADO <<')
                print('ZERADO')
    except:
         bot = telepot.Bot('6372818731:AAFZXRVBq90-ufHCiTc5l_Mqj0ozYXHEV7o')
         bot.sendMessage(984798692, f'Falha no código, mas ainda funcionando. É bom conferir!')
         
         return
    
    s.close()
    o.close()

    shutil.copy('Negocios_cruzam.txt', 'Negocios_cruzam2.txt')
    #print('.')

def ativo2():
    
    filename = 'Negocios_cruzam_2.txt'
    f =open(filename, "w")

    #Verde = py.pixelMatchesColor(510, 136, (17, 152, 80))
    #Vermelho = py.pixelMatchesColor(510, 136, (204, 48, 48))
    #RGB = list(py.pixel(514, 139))
    RGB2 = list(py.pixel(x2, y2))
    RGB2 = str(RGB2[2])

    #print(RGB)
    f.write(RGB2) 
    f.close()

    # >>> COMPARAÇÃO <<< #

    s=open('Negocios_cruzam_2.txt', 'r', encoding="utf8")
    try:
        o=open('Negocios_cruzam2_2.txt','r', encoding="utf8")
    except:
        shutil.copy('Negocios_cruzam_2.txt', 'Negocios_cruzam2_2.txt')
        o=open('Negocios_cruzam2_2.txt','r', encoding="utf8")

    dadoS = s.read()
    dadoO = o.read()

    try:
        if dadoS != dadoO:
            if dadoS == '80':
            # if dadoS == '128':
                bot = telepot.Bot('6372818731:AAFZXRVBq90-ufHCiTc5l_Mqj0ozYXHEV7o')
                #bot.sendMessage(984798692, f'WDO_10R >> COMPRA <<')
                bot.sendMessage(-4048406255, f'>> Estocastico FUNDO 1 <<')
                print(f'FUNDO 1 / {RGB2}')
            elif dadoS == '48':
            # elif dadoS == '0':
                bot = telepot.Bot('6372818731:AAFZXRVBq90-ufHCiTc5l_Mqj0ozYXHEV7o')
                #bot.sendMessage(984798692, f'WDO_10R >> VENDA <<')
                bot.sendMessage(-4048406255, f'>> Estocastico TOPO 1 <<')
                print(f'TOPO 1 / {RGB2}')
            elif dadoS == '255':
                bot = telepot.Bot('6372818731:AAFZXRVBq90-ufHCiTc5l_Mqj0ozYXHEV7o')
                #bot.sendMessage(984798692, f'WDO_10R >> VENDA <<')
                #bot.sendMessage(984798692, f'CRUZAMENTO_MMs >> ZERADO <<')
                # print('ZERADO')
    except:
         bot = telepot.Bot('6372818731:AAFZXRVBq90-ufHCiTc5l_Mqj0ozYXHEV7o')
         bot.sendMessage(984798692, f'Falha no código de TOPOS/FUNDOS, mas ainda funcionando. É bom conferir!')
         
         return
    
    s.close()
    o.close()

    shutil.copy('Negocios_cruzam_2.txt', 'Negocios_cruzam2_2.txt')
    #print('.')

while True:
     # HORARIO DAS OPERAÇÕES
        ativo1()
        sleep(1)
        ativo2()
        sleep(1)

