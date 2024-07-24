import pytesseract
from time import sleep
import PIL.ImageGrab
import pyautogui as py
from datetime import datetime

pytesseract.pytesseract.tesseract_cmd = r'C:\Program Files\Tesseract-OCR\tesseract'

def wdo():
    #OBTENDO O PRINT DA BARRA
    # Defina as coordenadas da região que você deseja capturar
    left = 10
    top = 105
    right = 680
    bottom = 290

    # Capture a região especificada
    snapshot = PIL.ImageGrab.grab(bbox=(left, top, right, bottom))

    # Salve a imagem capturada
    snapshot.save('C:\\Users\\johnn\\Desktop\\Nova pasta\\Mercado\\screenshot_WDO.png')

    imagem = pytesseract.image_to_string(r'C:\\Users\\johnn\\Desktop\\Nova pasta\\Mercado\\screenshot_WDO.png')
    sell = imagem[-5:-1]
    sell = sell.strip("%")
    sell = int(sell)

    if sell > 50:
        print('Venda')
        print(sell)
        py.click(910,654)

    # elif sell == 50:
    #     print('Neutro')
    elif sell < 50:
        print('Compra')
        print(sell)
        py.click(827,654)

def win():
    #OBTENDO O PRINT DA BARRA
    # Defina as coordenadas da região que você deseja capturar
    left = 1200
    top = 105
    right = 1880
    bottom = 290

    # Capture a região especificada
    snapshot = PIL.ImageGrab.grab(bbox=(left, top, right, bottom))

    # Salve a imagem capturada
    snapshot.save('C:\\Users\\johnn\\Desktop\\Nova pasta\\Mercado\\screenshot_WIN.png')

    imagem = pytesseract.image_to_string(r'C:\\Users\\johnn\\Desktop\\Nova pasta\\Mercado\\screenshot_WIN.png')
    sell = imagem[-5:-1]
    sell = sell.strip("%")
    sell = int(sell)
    #print(sell)
    
    if sell > 50:
        print('Venda')
        print(sell)
        py.click(1870,654)


    elif sell < 50:
        print('Compra')
        print(sell)
        py.click(1791,654)


while True:
 # HORARIO DAS OPERAÇÕES
    agora = datetime.now()
    agora1 = str(agora)
    agoraRes = agora1[11:16]

    #OBTENDO horário
    left = 800
    top = 150
    right = 1080
    bottom = 230

    # Capture a região especificada
    snapshot = PIL.ImageGrab.grab(bbox=(left, top, right, bottom))

    # Salve a imagem capturada
    snapshot.save('C:\\Users\\johnn\\Desktop\\Nova pasta\\Mercado\\relogio.png')
    imagemREL = pytesseract.image_to_string(r'C:\\Users\\johnn\\Desktop\\Nova pasta\\Mercado\\relogio.png')
    relogio = imagemREL[-6:-1]
    #print(relogio)

    if relogio == "00:22" and ('08:58' < agoraRes < '09:10'):
    #if relogio == "26:40" and ('09:00' < agoraRes < '18:00'):
        win()
        sleep(0.5)
        wdo()
        sleep(0.1)
    else:
        print(relogio)

