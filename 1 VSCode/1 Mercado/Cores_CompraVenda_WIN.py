#https://www.youtube.com/watch?v=TERKvqfySYI&t=1067s

import pyautogui as py
import time
from datetime import datetime
import shutil
import telepot
from time import sleep

py.moveTo(115,205) #compra e venda
sleep(2)
py.moveTo(1865,685) #Stop nas operações do dia

# --------------------------------------------------------------------------------- #
# Enviando imediatamente MSG de atual posição
RGB = list(py.pixel(115,205))
RGB = str(RGB[2])

if RGB == '80':
    bot = telepot.Bot('5026686955:AAHvm0rJOf-_nSCi8sOHYVMhY8zPCBEd73k')
    bot.sendMessage(-1001778706191, f'>> Iniciando o dia. Aguarde o horário e se posicione em >> COMPRA <<')
    print('Iniciando o dia. Aguarde o horário e se posicione em >> COMPRA <<'.upper())
elif RGB == '48':
    bot = telepot.Bot('5026686955:AAHvm0rJOf-_nSCi8sOHYVMhY8zPCBEd73k')
    bot.sendMessage(-1001778706191, f'Iniciando o dia. Aguarde o horário e se posicione em >> VENDA <<')
    print('Iniciando o dia. Aguarde o horário e se posicione em >> VENDA <<'.upper())
elif RGB == '255':
    bot = telepot.Bot('5026686955:AAHvm0rJOf-_nSCi8sOHYVMhY8zPCBEd73k')
    bot.sendMessage(-1001778706191, f'Iniciando o dia. Aguarde o horário e sinal de entrada')
    print('Iniciando o dia. Aguarde o horário e sinal de entrada'.upper())

# ----------------------------------------------------------------------------------- #

def win():
    
    filename = 'Negocios.txt'
    f =open(filename, "w")

    #Verde = py.pixelMatchesColor(510, 136, (17, 152, 80))
    #Vermelho = py.pixelMatchesColor(510, 136, (204, 48, 48))
    #RGB = list(py.pixel(514, 139))
    RGB = list(py.pixel(115,205))
    RGB = str(RGB[2])

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
        if dadoS == '80':
            bot = telepot.Bot('5026686955:AAHvm0rJOf-_nSCi8sOHYVMhY8zPCBEd73k')
            bot.sendMessage(-1001778706191, f'Win_21R >> COMPRA <<')
            print('COMPRA')
        elif dadoS == '48':
            bot = telepot.Bot('5026686955:AAHvm0rJOf-_nSCi8sOHYVMhY8zPCBEd73k')
            bot.sendMessage(-1001778706191, f'Win_21R >> VENDA <<')
            print('VENDA')
        elif dadoS == '255':
            bot = telepot.Bot('5026686955:AAHvm0rJOf-_nSCi8sOHYVMhY8zPCBEd73k')
            bot.sendMessage(-1001778706191, f'Win_21R >> SAIA IMEDIATAMENTE DE POSIÇÃO E AGUARDE O PRÓXIMO SINAL <<')
            print('SAIA IMEDIATAMENTE DE POSIÇÃO E AGUARDE O PRÓXIMO SINAL')

    s.close()
    o.close()

    shutil.copy('Negocios.txt', 'Negocios2.txt')
    #print('.')

while True:
     # HORARIO DAS OPERAÇÕES
    agora = datetime.now()
    agora1 = str(agora)
    agoraRes = agora1[11:16]

    STOP = list(py.pixel(1865,685))
    STOP = str(STOP[2])

    if ('11:58' < agoraRes < '16:30') and STOP != '255':
        win()
        sleep(2)

    elif STOP == '255':
        bot = telepot.Bot('5026686955:AAHvm0rJOf-_nSCi8sOHYVMhY8zPCBEd73k')
        bot.sendMessage(-1001778706191, f'Win_21R >> ENCERRANDO TODAS AS OPERAÇÕES POR HOJE!<<')
        print('ENCERRANDO TODAS AS OPERAÇÕES POR HOJE!')
        sleep(86400)