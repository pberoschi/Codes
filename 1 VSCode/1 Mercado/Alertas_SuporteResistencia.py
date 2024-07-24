import pytesseract
from time import sleep
import PIL.ImageGrab
import pyautogui as py
from datetime import datetime
import telepot

pytesseract.pytesseract.tesseract_cmd = r'C:\Program Files\Tesseract-OCR\tesseract'

#Teste posicoes TELA GRANDE
horizontal      = 570 
vertical        = 990
#py.moveTo(horizontal,vertical)

# #Teste posicoes TELA PEQUENA
# horizontal      = 1870 
# vertical        = 10

def localizarTelaGrande():
    top     = vertical
    left    = horizontal
    bottom  = top + 300 #21
    right   = left + 300 #55
    # Capture a região especificada
    snapshot = PIL.ImageGrab.grab(bbox=(left, top, right, bottom))
    #snapshot = snapshot.convert("L") #convertendo em escala de cinza
    # Salve a imagem capturada
    snapshot.save('C:\\Users\\johnn\\Desktop\\Nova pasta\\Mercado\\leituraClose.png')

    config = r'--oem 3 --psm 6'
    imagem = pytesseract.image_to_string(r'C:\\Users\\johnn\\Desktop\\Nova pasta\\Mercado\\leituraClose.png',config=config)
    print(imagem)
    sleep(60)

def test():
    top     = vertical
    left    = horizontal
    bottom = top + 21
    right = left + 55
    # Capture a região especificada
    snapshot = PIL.ImageGrab.grab(bbox=(left, top, right, bottom))
    snapshot = snapshot.convert("L") #convertendo em escala de cinza
    # Salve a imagem capturada
    snapshot.save('C:\\Users\\johnn\\Desktop\\Nova pasta\\Mercado\\leituraClose.png')

    config = r'--oem 3 --psm 6'
    imagem = pytesseract.image_to_string(r'C:\\Users\\johnn\\Desktop\\Nova pasta\\Mercado\\leituraClose.png',config=config)
    #print(imagem)
        
    try:
        posicao = imagem.replace(" ","")
        posicao = posicao[:2]
        posicao = int(posicao)
        print(posicao)

        if  posicao != '':
            #envio de alertas
            bot = telepot.Bot('6372818731:AAFZXRVBq90-ufHCiTc5l_Mqj0ozYXHEV7o')
            bot.sendMessage(984798692, f'>> ALERTA DE PREÇO <<')
            print(f'Alerta de preço')
            sleep(10)
            py.click(873,954) # Zerar histórico
            sleep(2)
            py.press('enter')
            print("Histórico Zerado")
            sleep(1)


    except:
        #print("Houve falha no código")
        return

while True:
     test()
     sleep(1)

     #localizarTelaGrande()
     

