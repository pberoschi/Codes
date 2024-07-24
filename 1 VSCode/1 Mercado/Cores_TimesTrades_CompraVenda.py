#https://www.youtube.com/watch?v=TERKvqfySYI&t=1067s

import pyautogui as py
import time
from datetime import datetime
import shutil
import telepot
from time import sleep

sleep(2)
xC,yC=1849,110
compraX,compraY = 1637,644
vendaX,vendaY = 1815,644


py.moveTo(xC,yC) #compra e venda
sleep(2)
py.moveTo(compraX,compraY) #Stop nas operações do dia
sleep(1)
py.moveTo(vendaX,vendaY)
sleep(1)
# print(py.pixel(xC,yC))

def zeragem():
    try:
        filename = 'Negocios.txt'
        f =open(filename, "w")

        f.write('1000') 
        f.close()

    except:
        return



def win():
    try:

        filename = 'Negocios.txt'
        f =open(filename, "w")

        #Verde = py.pixelMatchesColor(510, 136, (17, 152, 80))
        #Vermelho = py.pixelMatchesColor(510, 136, (204, 48, 48))
        #RGB = list(py.pixel(514, 139))
        RGB = list(py.pixel(xC,yC))
        RGB = str(RGB[1])

        #print(RGB)
        f.write(RGB) 
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
            if dadoS == '128':
                # bot = telepot.Bot('5026686955:AAHvm0rJOf-_nSCi8sOHYVMhY8zPCBEd73k')
                # bot.sendMessage(-1001778706191, f'Win_21R >> COMPRA <<')
                print('COMPRA')
                py.moveTo(vendaX,vendaY)
                py.click(vendaX,vendaY)
                # sleep()
                # zeragem()

            elif dadoS == '0':
                # bot = telepot.Bot('5026686955:AAHvm0rJOf-_nSCi8sOHYVMhY8zPCBEd73k')
                # bot.sendMessage(-1001778706191, f'Win_21R >> VENDA <<')
                print('VENDA')
                py.moveTo(compraX,compraY)
                py.click(compraX,compraY) 
                # zeragem()   

        s.close()
        o.close()

        shutil.copy('Negocios.txt', 'Negocios2.txt')
        #print('.')

    except:
        return
        print('Reiniciando')

# while True:
#      # HORARIO DAS OPERAÇÕES
#     agora = datetime.now()
#     agora1 = str(agora)
#     agoraRes = agora1[11:16]

#     STOP = list(py.pixel(1865,685))
#     STOP = str(STOP[2])

#     if ('11:58' < agoraRes < '16:30') and STOP != '255':
#         win()
#         sleep(2)

#     elif STOP == '255':
#         bot = telepot.Bot('5026686955:AAHvm0rJOf-_nSCi8sOHYVMhY8zPCBEd73k')
#         bot.sendMessage(-1001778706191, f'Win_21R >> ENCERRANDO TODAS AS OPERAÇÕES POR HOJE!<<')
#         print('ENCERRANDO TODAS AS OPERAÇÕES POR HOJE!')
#         sleep(86400)
    
while True:
    win()