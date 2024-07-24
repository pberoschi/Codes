import os
import cv2
import telebot

# Configurações do bot (substitua pelo seu token)
BOT_TOKEN = os.environ.get('BOT_TOKEN')
bot = telebot.TeleBot(BOT_TOKEN)

# Função para enviar mensagem de alerta
def send_alert():
    chat_id = 'SEU_CHAT_ID'  # Substitua pelo seu chat ID
    bot.send_message(chat_id, "🚨 Alerta! Um gato foi detectado na câmera externa!")

# Função para detectar gatos na imagem
def detect_cat(image_path):
    # Carrega o classificador pré-treinado para detecção de gatos
    cat_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalcatface.xml')

    # Carrega a imagem
    # image = cv2.imread(image_path)
    image = cv2.VideoCapture('rtsp://admin:embasa123@192.168.0.127:554/onvif1') 
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    # Detecta gatos na imagem
    cats = cat_cascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=5, minSize=(30, 30))

    # Se um gato for detectado, envie o alerta
    if len(cats) > 0:
        send_alert()

if __name__ == "__main__":
    # Caminho para a imagem capturada pela câmera
    image_path = "caminho/para/sua/imagem.jpg"
    detect_cat(image_path)
