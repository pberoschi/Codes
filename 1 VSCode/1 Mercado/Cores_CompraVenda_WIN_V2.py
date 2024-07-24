#https://www.youtube.com/watch?v=TERKvqfySYI&t=1067s

import pyautogui as py
import time
from datetime import datetime
import shutil
import telepot
from time import sleep

py.moveTo(x=1869, y=555) #Cores na janela do VirtualBot

def win():
    
    filename = 'Negocios.txt'
    f =open(filename, "w")

    #Verde = py.pixelMatchesColor(510, 136, (17, 152, 80))
    #Vermelho = py.pixelMatchesColor(510, 136, (204, 48, 48))
    #RGB = list(py.pixel(514, 139))
    RGB1 = list(py.pixel(x=1869, y=555))
    RGB1 = str(RGB1[0])

    RGB2 = list(py.pixel(x=1869, y=555))
    RGB2 = str(RGB2[1])
    
    RGB3 = list(py.pixel(x=1869, y=555))
    RGB3 = str(RGB3[2])


    #print(RGB)
    f.write(RGB1 + "," + RGB2 + "," + RGB3) 
    f.close()

    # >>> COMPARAÇÃO <<< #

    s=open('Negocios.txt', 'r', encoding="utf8")
    try:
        o=open('Negocios2.txt','r', encoding="utf8")
    except:
        shutil.copy('Negocios.txt', 'Negocios2.txt')
        o=open('Negocios2.txt','r', encoding="utf8")

    dadoS = s.read()
    dadoO = o.read()

    if dadoS != dadoO:
        if dadoS == '0,255,0':
            #bot = telepot.Bot('5026686955:AAHvm0rJOf-_nSCi8sOHYVMhY8zPCBEd73k')
            #bot.sendMessage(-1001778706191, f'Win_20R >> COMPRA <<')
            bot = telepot.Bot('1827005235:AAGr4ss18HkJo11QKjBYBG-TqnKLv79Ph6Q')
            bot.sendMessage(984798692, f'WIN_20R >> COMPRA <<')
            print('COMPRA')

        elif dadoS == '255,0,0':
            #bot = telepot.Bot('5026686955:AAHvm0rJOf-_nSCi8sOHYVMhY8zPCBEd73k')
            #bot.sendMessage(-1001778706191, f'Win_20R >> VENDA <<')
            bot = telepot.Bot('1827005235:AAGr4ss18HkJo11QKjBYBG-TqnKLv79Ph6Q')
            bot.sendMessage(984798692, f'WIN_20R >> VENDA <<')
            print('VENDA')

        #elif dadoS == '0,0,0':
            #bot = telepot.Bot('5026686955:AAHvm0rJOf-_nSCi8sOHYVMhY8zPCBEd73k')
            #bot.sendMessage(-1001778706191, f'Win_20R >> SAIA IMEDIATAMENTE DE POSIÇÃO E AGUARDE O PRÓXIMO SINAL <<')
            #bot = telepot.Bot('1827005235:AAGr4ss18HkJo11QKjBYBG-TqnKLv79Ph6Q')
            #bot.sendMessage(984798692, f'WIN_20R >> SAIA IMEDIATAMENTE DE POSIÇÃO E AGUARDE O PRÓXIMO SINAL <<')
            #print('SAIA IMEDIATAMENTE DE POSIÇÃO E AGUARDE O PRÓXIMO SINAL')
            
        elif dadoS == '255,0,255':
            #bot = telepot.Bot('5026686955:AAHvm0rJOf-_nSCi8sOHYVMhY8zPCBEd73k')
            #bot.sendMessage(-1001778706191, f'Win_20R >> ENCERRANDO TODAS AS OPERAÇÕES POR HOJE! <<')
            bot = telepot.Bot('1827005235:AAGr4ss18HkJo11QKjBYBG-TqnKLv79Ph6Q')
            bot.sendMessage(984798692, f'WIN_20R >> ENCERRANDO TODAS AS OPERAÇÕES POR HOJE! <<')
            print('ENCERRANDO TODAS AS OPERAÇÕES POR HOJE!')
            sleep(864000)

    s.close()
    o.close()

    shutil.copy('Negocios.txt', 'Negocios2.txt')
    #print('.')

while True:
     # HORARIO DAS OPERAÇÕES
    agora = datetime.now()
    agora1 = str(agora)
    agoraRes = agora1[11:16]

    #STOP = list(py.pixel(x=-51, y=494))
    #STOP = str(STOP[2])

    if ('11:00' < agoraRes < '18:00'):
        win()
        sleep(2)
    