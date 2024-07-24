import pytesseract
from time import sleep
import PIL.ImageGrab
# import pyautogui as py
from datetime import datetime
from time import sleep
import telepot
from random import randint

bot = telepot.Bot('6372818731:AAFZXRVBq90-ufHCiTc5l_Mqj0ozYXHEV7o')
chat_id = 984798692

pytesseract.pytesseract.tesseract_cmd = r'C:\Program Files\Tesseract-OCR\tesseract'

preco1 = int(input('Entre com o valor UP a ser monitorado: '))
preco2 = int(input('Entre com o valor DOWN a ser monitorado: '))

print('EM EXECUÇÃO...')
def wdo():
    try: 
        # HORARIO DAS OPERAÇÕES
        agora = datetime.now()
        agora1 = str(agora)
        agoraRes = agora1[11:16]


        #OBTENDO O PRINT DA BARRA
        # Defina as coordenadas da região que você deseja capturar
        left = 140
        top = 80
        right = left + 72
        bottom = top + 25

        # Capture a região especificada
        snapshot = PIL.ImageGrab.grab(bbox=(left, top, right, bottom))

        # Salve a imagem capturada
        snapshot.save('C:\\Users\\Johnny\\Pictures\Diversos\\screenshot_WDO.jpg')
            
        imagem = pytesseract.image_to_string(r'C:\\Users\\Johnny\\Pictures\Diversos\\screenshot_WDO.jpg')
        imagem = imagem.replace('.','')
        imagem = imagem.replace(',','')

        #TRANSFORMANDO IMAGEM EM NÚMERO
        # preco = randint(0,9)
        # preco = int(imagem[-4:-3])
        preco = int(imagem[:-3])
        # print(preco)

        if (preco == preco1) or (preco == preco2):
            print('ALERTA')
            print(agoraRes)
            # print(preco)
            resumoMSG = (imagem + agoraRes)
            bot.sendMessage(chat_id, resumoMSG)
            sleep(60)
        # else:
        #     print('.')

    except:
        print('Falha na execução. Retornando...')
        return



while True:
    wdo()
    sleep(1)



#  # HORARIO DAS OPERAÇÕES
#     agora = datetime.now()
#     agora1 = str(agora)
#     agoraRes = agora1[11:16]

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

