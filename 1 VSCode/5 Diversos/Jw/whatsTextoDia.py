# _-*- coding: utf-8 -*-
import requests
import pyautogui as py
import pyperclip as pc
from bs4 import BeautifulSoup
from datetime import date as dt
from time import sleep

destino = 'Carlos'

hoje = dt.today()
hoje = str(hoje).replace('-','')
dia = hoje[6:8]
dia = dia.replace('0','')
mes = hoje[4:6]
mes = mes.replace('0','')
ano = hoje[0:4]

page = requests.get(f'https://wol.jw.org/pt/wol/h/r5/lp-t/{ano}/{mes}/{dia}')
soup = BeautifulSoup(page.content, 'html.parser')

data        = soup.find_all('h2')[1].get_text()
texto       = soup.find_all('p')[2].get_text()
comentario  = soup.find_all('p')[3].get_text()
texto       = (f'_*{texto}*_')
comentario  = (comentario)[0:200]
comentario  = (f'_{comentario} (...)_\n\nPara continuar a ler, acesse https://wol.jw.org/pt/wol/h/r5/lp-t')

# print(data)
# print(texto)
# print(comentario)
# print(f'{texto}\n')
# print(f'{comentario[0:200]} (...)\n')
# print(f'Para continuar a ler, acesse o site: https://wol.jw.org/pt/wol/h/r5/lp-t')

#ABRIR NAVEGADOR
py.click(611, 1062)          # PC HOME
sleep(5)

# DIGITAR WEB.WHATSAPP l
py.click(x=395, y=63)            # PC HOME 
sleep(3) 
py.typewrite('https://web.whatsapp.com\n') 
sleep(20)

# COPIAR TEXTO E COLAR
py.click(x=195, y=211)
# py.typewrite('grupo n',interval=0.5)
py.typewrite(destino,interval=0.4)
py.press('enter') 

py.click(x=204, y=348)
# py.typewrite('>>> *_TEXTO DO DIA_* <<<\n', interval=0.3)
# sleep(1)
pc.copy(data)
sleep(1)
py.hotkey('ctrl','v',interval=0.4)
sleep(1)
py.hotkey('shift','enter',interval=0.4)
py.hotkey('shift','enter',interval=0.4)
pc.copy(texto)
sleep(1)
py.hotkey('ctrl','v',interval=0.4)
sleep(2)

py.hotkey('shift','enter',interval=0.4)
py.hotkey('shift','enter',interval=0.4)
pc.copy(comentario)
sleep(1)
py.click(x=747, y=986)
py.hotkey('ctrl','v',interval=0.4)
sleep(2)
py.hotkey('enter')
sleep(2)

# # MARCAR COMO NÃO LIDO
# py.click(x=195, y=211)
# py.typewrite(destino,interval=0.4)
# py.press('enter')
# py.click(button='right',x=387,y=319)
# sleep(1)
# py.click(x=2697, y=481)
# sleep(2)


# # FECHAR
# py.hotkey('ctrl','f4')







