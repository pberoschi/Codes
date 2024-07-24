import pytesseract
from time import sleep
import PIL.ImageGrab
import pyautogui as py
from datetime import datetime
import telepot

pytesseract.pytesseract.tesseract_cmd = r'C:\Program Files\Tesseract-OCR\tesseract'

##Valor limite de perda
vlpG = int(50)
vlpL = vlpG * (-1)

# Pausar + Zerar posiçoes
# clicar 3 pontinhos
x1 = 1900
y1 = 174
#clicar em pausar
x11 = 1784
y11 = 305

# Executar (reinciar operação)
x2 = 1813
y2 = 353

#Teste posicoes
py.click(x1,y1)
sleep(2)
py.moveTo(x11,y11)

#Leitura dos valores da posicao
top = 161
left =975
bottom = top + 20
right = left + 60

snapshot = PIL.ImageGrab.grab(bbox=(left, top, right, bottom))
snapshot = snapshot.convert("L") #convertendo em escala de cinza
# Salve a imagem capturada
snapshot.save('C:\\Users\\johnn\\Desktop\\Nova pasta\\Mercado\\posAberta.png')

def test():
    top = 161
    left =975
    bottom = top + 20
    right = left + 60
    # Capture a região especificada
    snapshot = PIL.ImageGrab.grab(bbox=(left, top, right, bottom))
    snapshot = snapshot.convert("L") #convertendo em escala de cinza

    # Salve a imagem capturada
    snapshot.save('C:\\Users\\johnn\\Desktop\\Nova pasta\\Mercado\\posAberta.png')

    config = r'--oem 3 --psm 6'
    imagem = pytesseract.image_to_string(r'C:\\Users\\johnn\\Desktop\\Nova pasta\\Mercado\\posAberta.png',config=config)
    
    try:
        posicao = imagem.replace(" ","")
        posicao = posicao.replace(",00","")
        posicao = posicao.strip()
        posicao = posicao[2:]
        posicao = posicao.replace(",","")
        posicao = int(posicao)
        print(posicao)

    except:
        print("Houve falha no código")
        return
    
    if posicao < vlpL:
        #envio de alertas
        bot = telepot.Bot('6372818731:AAFZXRVBq90-ufHCiTc5l_Mqj0ozYXHEV7o')
        bot.sendMessage(984798692, f'>> ALERTA << FALHA NA AUTOMAÇÃO')
    
    if posicao > vlpG:
        #envio de alertas
        bot = telepot.Bot('6372818731:AAFZXRVBq90-ufHCiTc5l_Mqj0ozYXHEV7o')
        bot.sendMessage(984798692, f'Falha na automação, mas a FAVOR')

        # print('ENCERRAR OPERAÇÃO!')
        # # Pausar + Zerar posições
        # py.click(x1,y1)
        # sleep(2)
        # py.click(x11,y11)
        # sleep(2)
        # py.press('enter')
        # sleep(3)

        # # Executar (reiniciar)
        # py.move(x1,y1)
        # sleep(2)
        # py.click(x1,y1)
        # sleep(5)
        # #py.click(x2,y2)
        # print("Reiniciando as operações")



while True:
    test()
    sleep(1)




# # while True:
# #  # HORARIO DAS OPERAÇÕES
# #     agora = datetime.now()
# #     agora1 = str(agora)
# #     agoraRes = agora1[11:16]

# #     #OBTENDO horário
# #     left = 800
# #     top = 150
# #     right = 1080
# #     bottom = 230

# #     if relogio == "00:22" and ('08:58' < agoraRes < '09:10'):
# #     #if relogio == "26:40" and ('09:00' < agoraRes < '18:00'):
# #         win()
# #         sleep(0.5)
# #     else:
# #         print(relogio)

