import pytesseract
import PIL.ImageGrab
import pyautogui as py
from time import sleep

pytesseract.pytesseract.tesseract_cmd = r'C:\Program Files\Tesseract-OCR\tesseract'

tempo1 = 0.5
tempo2 = 1
tempo3 = 3
# <<<<<<< HEAD
xmin,ymin = 370,918               # PC WORK
# # xmin,ymin = 295,904                 # PC HOME
# =======
# # xmin,ymin = 370,931               # PC WORK
# xmin,ymin = 295,927                 # PC HOME
# >>>>>>> d045d29b9e7ff6328959eb06a00a3522b891bc25

py.moveTo(xmin,ymin)

def dadosTrab ():
    try:
        # Defina as coordenadas da região que você deseja capturar
        left = 825
        top = 405
        right = left + 63
        bottom = top + 30

        snapshot = PIL.ImageGrab.grab(bbox=(left, top, right, bottom))
        snapshot = snapshot.convert('L') 
        # snapshot.show()                                  # converte em CINZA

        # Salve a imagem capturada
        snapshot.save('C:\\Users\\Johnny\\Pictures\Diversos\\bktestes.jpg')
            
        imagem = pytesseract.image_to_string(r'C:\\Users\\Johnny\\Pictures\\Diversos\\bktestes.jpg', config='--psm 7')
        fatorLucro = imagem.replace(',','')
        fatorLucro = int(fatorLucro)
        # print(imagem.strip())
        # print(fatorLucro)
        # print(imagem)
        if fatorLucro >= 100:
            print(f'Fator Lucro: {fatorLucro}')
    except:
        print('Falha! Reiniciando...')
        return

def dadosCasa ():
    try:
        # Defina as coordenadas da região que você deseja capturar
        left = 865
        top = 622
        right = left + 63
        bottom = top + 25

        snapshot = PIL.ImageGrab.grab(bbox=(left, top, right, bottom))
        snapshot = snapshot.convert('L') 
        # snapshot.show()                                  # converte em CINZA

        # Salve a imagem capturada
        snapshot.save('C:\\Users\\Johnn\\Pictures\Diversos\\bktestes.jpg')
            
        imagem = pytesseract.image_to_string(r'C:\\Users\\Johnn\\Pictures\\Diversos\\bktestes.jpg', config='--psm 7')
        fatorLucro = imagem.replace(',','')
        fatorLucro = int(fatorLucro)
        # print(imagem.strip())
        # print(fatorLucro)
        # print(imagem)
        if fatorLucro >= 110:
            print(f'Fator Lucro: {fatorLucro}')
    except:
        print('Falha! Reiniciando...')
        return
    
def AreaCaptura ():

    # Defina as coordenadas da região que você deseja capturar
    left = 865
    top = 622
    right = left + 63
    bottom = top + 25

    snapshot = PIL.ImageGrab.grab(bbox=(left, top, right, bottom))
    snapshot = snapshot.convert('L') 
    snapshot.show()                                  # converte em CINZA

    # Salve a imagem capturada
    snapshot.save('C:\\Users\\Johnn\\Pictures\Diversos\\bktestes.jpg')
        
    imagem = pytesseract.image_to_string(r'C:\\Users\\Johnn\\Pictures\\Diversos\\bktestes.jpg', config='--psm 7')
    

py.click(xmin,ymin)
py.moveTo(500,90)

x = 0
while x <= 30:
    print(f'Tempo: {x}')
    py.press('up')

    # py.press('f12')
    py.click(392,101)
    sleep(1)

    dadosTrab() 
    # dadosCasa()
    # AreaCaptura()
    # print('')




    x = x+1

# AreaCaptura()