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

# Teste de posicao de click
py.moveTo(x=78, y=561)
sleep(1)
py.moveTo(x=176, y=561)
sleep(1)
# py.moveTo(x=576, y=568)


preco1 = int(input('Qual o preco?: '))
direcao = input('Qual a ponta? COMPRA(C) ou VENDA(V): ').upper()
print('EM EXECUÇÃO...')

def wdo():
    try: 
        # HORARIO DAS OPERAÇÕES
        agora = datetime.now()
        agora1 = str(agora)
        agoraRes = agora1[11:16]

        # ----------------- Capture a região PRECO ----------------- #
        # Defina as coordenadas da região que você deseja capturar
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
        print(f'Alvo: {preco1} - {direcao.upper()}')
        print(f'Atual: {preco}')

        # ----------------- Capture a região POSICAO ----------------- #
        left = 185
        top = 722
        right = left + 40
        bottom = top + 28

        # Capture a região especificada
        snapshot2 = PIL.ImageGrab.grab(bbox=(left, top, right, bottom))
        snapshot2 = snapshot2.convert('L')                                    # converte em CINZA

        # Salve a imagem capturada
        snapshot2.save('C:\\Users\\Johnny\\Pictures\Diversos\\posicao_WDO.jpg')
        posicao = pytesseract.image_to_string(r'C:\\Users\\Johnny\\Pictures\Diversos\\posicao_WDO.jpg', config='--psm 6')
        # posicao = posicao.strip()
        # print(posicao)

        # ----------------- ----------------- ----------------- 



        if (preco == preco1) and (direcao == 'C') and (posicao == ''):
            print('COMPRA')
            py.click(x=78, y=561)
            print(agoraRes)
            # print(preco)
            # resumoMSG = (imagem + agoraRes)
            # bot.sendMessage(chat_id, resumoMSG)
            print('Aguardando RESET MANUAL')
            sleep(60000)
        # else:
        #     print('.')
            
        if (preco == preco1) and (direcao == 'V') and (posicao == ''):
            print('VENDA')
            py.click(x=176, y=561)
            print(agoraRes)
            # print(preco)
            # resumoMSG = (imagem + agoraRes)
            # bot.sendMessage(chat_id, resumoMSG)
            print('Aguardando RESET MANUAL')
            sleep(60000)

        # else:
        #     print('.')

    except:
        # print('Falha na execução. Retornando...')
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

