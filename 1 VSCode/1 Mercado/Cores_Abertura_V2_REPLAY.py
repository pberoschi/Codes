# Usando as cores do VisualBot

import pytesseract
from time import sleep
import PIL.ImageGrab
import pyautogui as py
from datetime import datetime

WDOx = 909
# WDOy = 963        # Replay
WDOy = 961          
WINx = 1872
# WINy = 963        # Replay
WINy = 961

py.moveTo(WDOx,WDOy)
sleep(1)
# py.moveTo(827,654)    # Replay
py.moveTo(827,640)
sleep(1)
# py.moveTo(910,654)    # Replay
py.moveTo(910,640)
sleep(1)

py.moveTo(WINx,WINy)
sleep(1)
# py.moveTo(1793,654)   # Replay
py.moveTo(1793,640)
sleep(1)
# py.moveTo(1867,640) # Replay
py.moveTo(1867,640)



# def wdo():
#     nRGB = list(py.pixel(WDOx,WDOy))
#     RGB1 = str(nRGB[0])
#     RGB2 = str(nRGB[1])
#     RGB3 = str(nRGB[2])
#     RGB = (RGB1 + "," + RGB2 + "," + RGB3) 

#     compra = '0,128,0'
#     venda = '255,0,0'

#     if RGB == compra:
#         print('Compra')
#         #py.click(827,654)
#         #print(RGB)

#     elif RGB == venda:
#         print('Venda')
#         #py.click(910,654)
#         #print(RGB)

# def win():
#     nRGB = list(py.pixel(WINx,WINy))
#     RGB1 = str(nRGB[0])
#     RGB2 = str(nRGB[1])
#     RGB3 = str(nRGB[2])
#     RGB = (RGB1 + "," + RGB2 + "," + RGB3) 

#     compra = '0,128,0'
#     venda = '255,0,0'

#     if RGB == compra:
#         print('Compra')
#         #py.click(827,654)
#         #print(RGB)

#     elif RGB == venda:
#         print('Venda')
#         #py.click(910,654)
#         #print(RGB)


# while True:
#  # HORARIO DAS OPERAÇÕES
#     agora = datetime.now()
#     agora1 = str(agora)
#     agoraRes = agora1[11:16]
#     seconds = agora1[17:19]


# # ////////////////////////////////     AO VIVO    \\\\\\\\\\\\\\\\\\\\\\\\\\

#     #if seconds == "22" and ('08:58' < agoraRes < '09:10'):
#     if ('08:58' < agoraRes < '23:10'):
#         win()
#         sleep(0.5)
#         wdo()
#         sleep(0.5)
#     else:
#         print(f'{agoraRes}   {seconds}')
#         sleep(1)

# # /////////////////////////////////////////////////////////////////////////////////




# # ////////////////////////////////     REPLAY's    \\\\\\\\\\\\\\\\\\\\\\\\\\
#     #OBTENDO horário
#     left = 800
#     top = 150
#     right = 1080
#     bottom = 230

#     # Capture a região especificada
#     snapshot = PIL.ImageGrab.grab(bbox=(left, top, right, bottom))

#     # Salve a imagem capturada
#     snapshot.save('C:\\Users\\johnn\\Desktop\\Nova pasta\\Mercado\\relogio.png')
#     imagemREL = pytesseract.image_to_string(r'C:\\Users\\johnn\\Desktop\\Nova pasta\\Mercado\\relogio.png')
#     relogio = imagemREL[-6:-1]
#     #print(relogio)

#     if relogio == "00:22" and ('08:58' < agoraRes < '09:10'):
#     #if relogio == "26:40" and ('09:00' < agoraRes < '18:00'):
#         win()
#         sleep(0.5)
#         wdo()
#         sleep(0.1)
#     else:
#         print(relogio)
# # /////////////////////////////////////////////////////////////////////////////////



