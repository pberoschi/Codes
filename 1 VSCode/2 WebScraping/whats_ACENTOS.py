import pyautogui as py
import pyperclip as pc
from time import sleep
import pyperclip as pc
import random

x = random.randint(1,3)

tempo1 = 2
tempo2 = 7
pcHomeAbrir = ''
pcHomeFechar = ''
pcWorkAbrir = ''
pcWorkFechar = ''

#Abrir navegador 
#py.click(152,746)           # PC WORK
py.click(384, 1062)          # PC HOME
sleep(3)


#digitar WhatsappWeb 
#py.click(319,64) 
py.click(201,51)            # PC HOME
sleep(tempo1) 
py.typewrite('https://web.whatsapp.com\n') 
sleep(35)

#alternar()

def jussa():
    msgJussa1 = 'E aí mama? Tudo bem?'
    msgJussa2 = 'Bom dia mainha? Como vão as coisas por aí?'
    msgJussa3 = 'Bom dia Jussi. Já acordou? Tudo bem?'

    if x == 1:
        pc.copy(msgJussa1)
    if x == 2:
        pc.copy(msgJussa2)
    if x == 3:
        pc.copy(msgJussa3)
    #print(x)
    #py.click(80,274)
    py.click(365,293)
    py.typewrite('Jussa',interval=0.3) 
    py.press('enter') 
    sleep(tempo1) 
    py.hotkey('ctrl','v')
    sleep(2)
    py.press('enter')
def familiaIrmas():
    irmasFamilia = ['sheila vianna','shirley vianna','shai vianna']
        #print(x)
    for item in irmasFamilia:
        x = random.randint(1,3)
        msgFamilia1 = 'E aí meu bem? Tudo bem?'
        msgFamilia2 = 'E aí amore? Tudo certo por aí?'
        msgFamilia3 = 'E aí meu amor? Tudo bem contigo?'
        if x == 1:
            pc.copy(msgFamilia1)
        if x == 2:
            pc.copy(msgFamilia2)
        if x == 3:
            pc.copy(msgFamilia3)
        
        py.click(80,274)
        py.typewrite(item,interval=0.3) 
        py.press('enter') 
        sleep(tempo1) 
        py.hotkey('ctrl','v')
        sleep(2)
        #py.press('enter') 
def irmaos():
    irmaoslist = []
    msgirmaos1 = 'Bom dia meu irmão. Tudo bem?'
    msgirmaos2 = 'Bom dia meu prezado. Como vai?'
    msgirmaos3 = 'Bom dia mano. Tudo certo?'
    if x == 1:
        pc.copy(msgirmaos1)
    if x == 2:
        pc.copy(msgirmaos2)
    if x == 3:
        pc.copy(msgirmaos3)
    #print(x)
    for item in irmaoslist:
        py.click(80,274)
        py.typewrite(item,interval=0.3) 
        py.press('enter') 
        sleep(tempo1) 
        py.hotkey('ctrl','v')
        sleep(2)
        #py.press('enter')
def irmas():
    irmaslist = [
        'ana lucia',
        'da paz',
        'ane roberto',
        'leda oeste'
    ]
    for item in irmaslist:
        x = random.randint(1,3)
        msgirmas1 = 'Bom dia minha querida irmã. Tudo bem?'
        msgirmas2 = 'Olá bom dia minha amiga. Como vai?'
        msgirmas3 = 'Bom dia minha querida irmã. Como vão todos aí?'
        if x == 1:
            pc.copy(msgirmas1)
        if x == 2:
            pc.copy(msgirmas2)
        if x == 3:
            pc.copy(msgirmas3)

        py.click(80,274)
        py.typewrite(item,interval=0.3) 
        py.press('enter') 
        sleep(tempo1) 
        py.hotkey('ctrl','v')
        sleep(2)
        #py.press('enter')
def amigos():
    amigoslist = [
        'osvaldo jr',
        'alirio',
        'misael',
        'dinho',
        'leandro teofilandia',
        'wilson oeste',
        'roberto ane'
        ]
    msgamigos1 = 'Bom dia meu amigo. Tudo bem?'
    msgamigos2 = 'Bom dia amigão. Como vai?'
    msgamigos3 = 'Bom dia meu amigo. Tudo certo por aí?'
    if x == 1:
        pc.copy(msgamigos1)
    if x == 2:
        pc.copy(msgamigos2)
    if x == 3:
        pc.copy(msgamigos3)
    #print(x)
    for item in amigoslist:
        py.click(80,274)
        py.typewrite(item,interval=0.3) 
        py.press('enter') 
        sleep(tempo1) 
        py.hotkey('ctrl','v')
        sleep(2)
        #py.press('enter')  
def jovensM():
    jovensMlist = []    

  
jussa()      
#familiaIrmas()
#irmaos()
#amigos()
#irmas()


# FECHAR NAVEGADOR
#py.click(1340,8)
py.click(1896,10)           #PC HOME
sleep(2)
py.press('enter')




'''
def alternar():
    py.keyDown('alt')
    py.press('tab')
    py.keyUp('alt')
'''