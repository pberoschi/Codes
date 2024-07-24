#https://www.youtube.com/watch?v=TERKvqfySYI&t=1067s

import pyautogui as py
import time
from datetime import datetime
import shutil
import telepot
from time import sleep

#py.moveTo(995, 157)

def run():
    
    filename = 'Negocios.txt'
    f =open(filename, "w")

    #Verde = py.pixelMatchesColor(510, 136, (17, 152, 80))
    #Vermelho = py.pixelMatchesColor(510, 136, (204, 48, 48))
    #RGB = list(py.pixel(514, 139))
    #ibov = list(py.pixel(251, 127))
    #ibov = str(ibov[2])
    
    win = list(py.pixel(x=1706, y=185))
    win = str(win[2])
    
    vale = list(py.pixel(x=966, y=190))
    vale = str(vale[2])
    
    #print(RGB)
    #f.write(ibov + "," + win + "," + vale)
    f.write(win + "," + vale)
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
    #print(type(dadoS))

    #print(dadoS)
    #print(dadoO)

    if dadoS != dadoO:
        if dadoS == '80,80':
            #print('Compra')
            bot = telepot.Bot('5026686955:AAHvm0rJOf-_nSCi8sOHYVMhY8zPCBEd73k')
            bot.sendMessage(-1001778706191, f'Win_25R >> COMPRA <<')
            print('COMPRA')
        elif dadoS == '48,48':
           #print('Venda')
            bot = telepot.Bot('5026686955:AAHvm0rJOf-_nSCi8sOHYVMhY8zPCBEd73k')
            bot.sendMessage(-1001778706191, f'Win_25R >> VENDA <<')
            print('VENDA')
        else:
            bot = telepot.Bot('5026686955:AAHvm0rJOf-_nSCi8sOHYVMhY8zPCBEd73k')
            bot.sendMessage(-1001778706191, f'SAIR DE POSIÇÃO E AGUARDAR PRÓXIMA ENTRADA')
            print('SAIR DE POSIÇÃO E AGUARDAR PRÓXIMA ENTRADA')
       

    s.close()
    o.close()

    shutil.copy('Negocios.txt', 'Negocios2.txt')
    #print('.')

while True:
     # HORARIO DAS OPERAÇÕES
    agora = datetime.now()
    agora1 = str(agora)
    agoraRes = agora1[11:16]

    if ('09:58' < agoraRes < '17:30'):
        run()
        sleep(2)