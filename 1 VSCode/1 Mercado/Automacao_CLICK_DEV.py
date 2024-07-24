import pytesseract
from time import sleep
import PIL.ImageGrab
import pyautogui as py
from datetime import datetime
from time import sleep
# import telepot
from random import randint

# bot = telepot.Bot('6372818731:AAFZXRVBq90-ufHCiTc5l_Mqj0ozYXHEV7o')
# chat_id = 984798692

pytesseract.pytesseract.tesseract_cmd = r'C:\Program Files\Tesseract-OCR\tesseract'

print('EM EXECUÇÃO...')




p = 0
number = []

while p <= 10:
    left = 140
    top = 80
    right = left + 75
    bottom = top + 25

    snapshot = PIL.ImageGrab.grab(bbox=(left, top, right, bottom))
    snapshot = snapshot.convert('L')                                    # converte em CINZA

    # Salve a imagem capturada
    snapshot.save('C:\\Users\\Johnny\\Pictures\Diversos\\screenshot_WDO.jpg')
        
    imagem = pytesseract.image_to_string(r'C:\\Users\\Johnny\\Pictures\Diversos\\screenshot_WDO.jpg', config='--psm 6')
    imagem = imagem.replace('.','')
    imagem = imagem.replace(',','')

    # TRANSFORMANDO IMAGEM EM NÚMERO
    preco = int(imagem[:-3])
    preco = int(preco)
    print(preco)

    number.append(preco)
    p=p+1

print(number)

 


