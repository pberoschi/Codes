import pytesseract
from time import sleep
import PIL.ImageGrab
import pyautogui as py
from datetime import datetime

pytesseract.pytesseract.tesseract_cmd = r'C:\Program Files\Tesseract-OCR\tesseract'


    
# Capture a região especificada
# Defina as coordenadas da região que você deseja capturar
left = 390
top = 910
right = 450
bottom = 940

snapshot = PIL.ImageGrab.grab(bbox=(left, top, right, bottom))

# Salve a imagem capturada
compra = snapshot.save('C:\\Users\\johnn\\Desktop\\Nova pasta\\Mercado\\Venda_WIN.png')
imagem = pytesseract.image_to_string(r'C:\\Users\\johnn\\Desktop\\Nova pasta\\Mercado\\Venda_WIN.png')

print(imagem)


# elif sell < 50:
#     print('Compra')
#     print(sell)
#     py.click(1791,654)





# while True:
#  # HORARIO DAS OPERAÇÕES
#     agora = datetime.now()
#     agora1 = str(agora)
#     agoraRes = agora1[11:16]

#     #OBTENDO horário
#     left = 670
#     top = 460
#     right = 715
#     bottom = 490

    # # Capture a região especificada
    # snapshot = PIL.ImageGrab.grab(bbox=(left, top, right, bottom))

    # # Salve a imagem capturada
    # snapshot.save('C:\\Users\\johnn\\Desktop\\Nova pasta\\Mercado\\relogio.png')
    # imagemREL = pytesseract.image_to_string(r'C:\\Users\\johnn\\Desktop\\Nova pasta\\Mercado\\relogio.png')
    # relogio = imagemREL[-6:-1]
    # #print(relogio)

    # if relogio == "00:22" and ('08:58' < agoraRes < '09:10'):
    # #if relogio == "26:40" and ('09:00' < agoraRes < '18:00'):
    #     win()
    #     sleep(0.5)
    #     wdo()
    #     sleep(0.1)
    # else:
    #     print(relogio)

