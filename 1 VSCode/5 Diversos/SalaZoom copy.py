import pyautogui as py
from time import sleep


def SalaEspera():
    admitir = py.locateCenterOnScreen(r'C:\\Users\\johnn\\Desktop\\Nova pasta\\Admitir.png')
    if admitir:
        py.click(admitir.x,admitir.y)
        py.moveTo(778,414)
        sleep(1)
        print("Pessoa ingressou na sala")
    else:
        py.moveTo(778,414)

def CoHost(): 
    coanfitriaoNOT = py.locateCenterOnScreen(r'C:\\Users\\johnn\\Desktop\\Nova pasta\\JohnnyCOTrue.png',confidence=0.9)
    coanfitriao = py.locateCenterOnScreen(r'C:\\Users\\johnn\\Desktop\\Nova pasta\\Johnny.png',confidence=0.7)

    mesaNOT = py.locateCenterOnScreen(r'C:\\Users\\johnn\\Desktop\\Nova pasta\\mesaCOTrue.jpg',confidence=0.9)
    mesa = py.locateCenterOnScreen(r'C:\\Users\\johnn\\Desktop\\Nova pasta\\mesa.jpg',confidence=0.8)
    #teste is True

    #if not coanfitriaoNOT:
    if not mesaNOT:
        #Buscar e nomear Coanfitrião
        #if coanfitriao: 
        if mesa: 
            # py.moveTo(coanfitriao.x,coanfitriao.y)
            py.moveTo(mesa.x,mesa.y)
            posicao1 = py.position()
            posicao1 = list(posicao1)
            # print(posicao1)
            # print(type(posicao1))
            xp1 = posicao1[0]
            yp1 = posicao1[1]
            x2p1 = xp1 + 230

            py.click(x2p1,yp1)

            posicao2 = py.position()
            posicao2 = list(posicao2)
            # print(posicao2)
            # print(type(posicao2))
            xp2 = posicao2[0]
            yp2 = posicao2[1]
            y2p2 = yp2 + 120

            py.click(xp2,y2p2)
            sleep(5)
            py.press('enter')
            sleep(1)
            py.moveTo(778,414)
            print("CoHost concluído")
            print("Encontrado")
    else:
        #print("Coanfitrião já nomeado")
        print("Mesa já como Coanfitrião")
    

while True:
    print("Novo Ciclo iniciando...")
    py.moveTo(1635,130)
    SalaEspera()
    sleep(1) 
    py.moveTo(1637,172)
    SalaEspera()
    sleep(1)  
    CoHost()
    sleep(10)













