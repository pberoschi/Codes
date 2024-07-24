import pyautogui as py
from time import sleep

x,y=549,685
# py.moveTo(x,y)
sleep(1)
nRGB = list(py.pixel(x,y))
print(nRGB)

def compra():

    compra = py.locateCenterOnScreen(r'C:\\Users\\johnn\\Desktop\\Nova pasta\\Mercado\\compra.jpg',confidence=0.9)
    posVazia = py.locateCenterOnScreen(r'C:\\Users\\johnn\\Desktop\\Nova pasta\\Mercado\\posicaoVazia.jpg',confidence=0.9)

    if compra:
        if posVazia:
            #py.click(x=1761, y=367)
            py.press('f5')
            sleep(1)
            print("Compra enviada")
        else:
            print("Compra em andamento")
    else:
            #print("Sem COMPRA detectada")
            print(".")
    

def venda():
    venda = py.locateCenterOnScreen(r'C:\\Users\\johnn\\Desktop\\Nova pasta\\Mercado\\venda.jpg',confidence=0.9)
    posVazia = py.locateCenterOnScreen(r'C:\\Users\\johnn\\Desktop\\Nova pasta\\Mercado\\posicaoVazia.jpg',confidence=0.9)

    if venda:
        if posVazia:
            #py.click(x=1836, y=367)
            py.press('f6')
            sleep(1)
            print("Venda enviada")
        else:
            print("Venda em andamento")
    else:
        #print("Sem VENDA detectada")
        print(".")




# while True:
#     compra()
#     #sleep(1)
#     # venda()




# posicao = py.position()
# print(posicao)







