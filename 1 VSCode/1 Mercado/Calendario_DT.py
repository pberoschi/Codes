import requests
from bs4 import BeautifulSoup
from time import sleep
from datetime import datetime
import telepot
import pyautogui as py


# URL da página com o calendário DayTrade
url = "https://br.investing.com/economic-calendar/"
response = requests.get(url)
soup = BeautifulSoup(response.content, "html.parser")
tabela = soup.find_all('tr',class_="js-event-item")

# Em preparação, verifica posicionamento do mouse
x,y = 1778,23
py.moveTo(x, y)
sleep(3)

# Mostrando no início da execução quais serão as notícias de alto impacto
print('\n>>> Buscando no site INVESTING as notícias de hoje <<<\n')
for item in tabela: 
      if (item.find('td',title='Volatilid. Esperada Alta')):
            # bot e id para envio ao Telegram
            bot = telepot.Bot('6372818731:AAFZXRVBq90-ufHCiTc5l_Mqj0ozYXHEV7o')
            chat_id = 984798692

            # Extraindo dados da página web
            hora = item.find('td',class_="first left time js-time").text.strip()
            pais = item.find('td',class_='left flagCur noWrap').text.strip()
            titulo = item.find('a').text.strip()

            #Listar as notícias depois das 09:00
            if (hora >= '09:00') and (pais == 'USD'):     
                  print(f'Notícia de ALTO IMPACTO ({hora}): *** {titulo} ***')
                  bot.sendMessage(chat_id, f'Notícia de ALTO IMPACTO ({hora}):\n-{titulo}')
      # else:
      #       print('Sem notícias de ALTO IMPACTO para hoje')
                       
def ver():
      for item in tabela: 
            if (item.find('td',title='Volatilid. Esperada Alta')):
                  # Extraindo dados da página web
                  hora = item.find('td',class_="first left time js-time").text.strip()
                  pais = item.find('td',class_='left flagCur noWrap').text.strip()
                  titulo = item.find('a').text.strip()

                  #Listar as notícias depois das 09:00
                  if (hora >= '09:00') and (pais == 'USD'):     

                        # Atualizando sempre a hora ATUAL do sistema
                        now = datetime.now()
                        horaSistema = str(f'{now.hour}:{now.minute}')

                        # Criar alarme 1 MIN ANTES da Notícia
                        hora_agora = int(hora[0:2])
                        minuto_agora = int(hora[3:5])
                        horaAtual = (f'{hora_agora}:{minuto_agora}')
                        minuto_Start = minuto_agora - 1
                        horaStart = (f'{hora_agora}:{minuto_Start}')
                        # print(f'Hora do Sistema: {horaSistema}')
                        # print(f'Hora da Notícia: {hora}')
                        # print(f'Hora do Start: {horaStart}')
                        
                        if horaSistema == horaStart:
                        # if horaSistema == '13:36':                              
                              desl()
                              sendTele()
                              

def desl():  
      # print (f'Hora Atual: {horaAtual}')
      print('- Função DESL acionada. Acionando PAUSA/ZERAGEM nas operações')
      py.click(x,y)

def sendTele():
      print('- Função sendTele acionada')
      bot = telepot.Bot('6372818731:AAFZXRVBq90-ufHCiTc5l_Mqj0ozYXHEV7o')
      chat_id = 984798692

      bot.sendMessage(chat_id, f'>>> NOTÍCIAS DE ALTO IMPACTO. \nPausando as operações <<<')

x = 0
while True:
      ver()
      sleep(60)
      x = x+1
      print(f'tempo em execução: {x} minutos')


                 



           


