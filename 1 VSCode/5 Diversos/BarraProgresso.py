# Importando as bibliotecas necessárias
import pyautogui
from PIL import Image, ImageOps

# Localizando a barra de progresso na tela
barra = pyautogui.locateOnScreen('barra.png') # barra.png é uma imagem da barra de progresso que você quer ler

# Verificando se a barra foi encontrada
if barra is not None:
    # Capturando uma imagem da região da barra
    imagem = pyautogui.screenshot(region=barra)
    # Convertendo a imagem para escala de cinza
    imagem = ImageOps.grayscale(imagem)
    # Obtendo os pixels da imagem
    pixels = list(imagem.getdata())
    # Calculando o número de pixels brancos (que representam o preenchimento da barra)
    brancos = pixels.count(255)
    # Calculando o número total de pixels da imagem
    total = len(pixels)
    # Calculando o percentual da barra
    percentual = round(brancos / total * 100, 2)
    # Exibindo o resultado
    print(f'A barra está {percentual}% preenchida.')
else:
    # Caso a barra não seja encontrada, exibir uma mensagem de erro
    print('Barra de progresso não encontrada.')