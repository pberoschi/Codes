#-------------------------------------------------------------------------------------
#-------------------------------------------------------------------------------------

import PIL.ImageGrab
from time import sleep

#Defina as coordenadas da região que você deseja capturar


def wdo():
    # COMPRA Nome 
    leftCN = 380
    topCN = 445
    rightCN = 480
    bottomCN = 470

    # # COMPRA Quantidade 
    leftCQ = 470
    topCQ = 445
    rightCQ = 540
    bottomCQ = 470

    # VENDA Nome 
    leftVN = 760
    topVN = 445
    rightVN = 845
    bottomVN = 470

    # # VENDA Quantidade 
    leftVQ = 700
    topVQ = 445
    rightVQ = 770
    bottomVQ = 470


    # # Capture a região especificada
    snapshotCN = PIL.ImageGrab.grab(bbox=(leftCN, topCN, rightCN, bottomCN))
    snapshotCQ = PIL.ImageGrab.grab(bbox=(leftCQ, topCQ, rightCQ, bottomCQ))
    # snapshotVN = PIL.ImageGrab.grab(bbox=(leftVN, topVN, rightVN, bottomVN))
    # snapshotVQ = PIL.ImageGrab.grab(bbox=(leftVQ, topVQ, rightVQ, bottomVQ))

    # # Salve a imagem capturada
    snapshotCN.save('compraNome.png')
    snapshotCQ.save('compraQuant.png')
    # snapshotVN.save('vendaNome.png')
    # snapshotVQ.save('vendaQuant.png')



    #-------------------------------------------------------------------------------------
    #-------------------------------------------------------------------------------------

    # https://stackoverflow.com/questions/50951955/pytesseract-tesseractnotfound-error-tesseract-is-not-installed-or-its-not-i

    import pytesseract

    pytesseract.pytesseract.tesseract_cmd = r'C:\\Program Files\\Tesseract-OCR\\tesseract'

    compraNome = pytesseract.image_to_string(r'C:\\Users\\johnn\\Google Drive\\Pessoal\\1_Programacao\\Python Scripts\\Nuvem\\compraNome.png')
    compraQuant = pytesseract.image_to_string(r'C:\\Users\\johnn\\Google Drive\\Pessoal\\1_Programacao\\Python Scripts\\Nuvem\\compraQuant.png')
    # vendaNome = pytesseract.image_to_string(r'C:\\Users\\johnn\\Google Drive\\Pessoal\\1_Programacao\\Python Scripts\\Nuvem\\vendaNome.png')
    # vendaQuant = pytesseract.image_to_string(r'C:\\Users\\johnn\\Google Drive\\Pessoal\\1_Programacao\\Python Scripts\\Nuvem\\vendaQuant.png')
    print(compraNome.strip())
    print(compraQuant.strip())
    # print(vendaNome)
    # print(vendaQuant)

while True:
    wdo()
    sleep(1)
