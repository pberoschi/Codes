from bs4 import BeautifulSoup
import requests
import telepot

bot = telepot.Bot('1591788137:AAFXANf-i5DYCCFJMuEe5cCjP1X7-I1WwPM')


url = 'http://tempo.cptec.inpe.br/ba/santo-antonio-de-jesus'
r = requests.get(url)
soup = BeautifulSoup(r.content, 'html.parser')
inpe = 'Probabilidade de ' + soup.find('div',{'class':'prob-color font-dados'}).text + ' de chuva para hoje (INPE)'
print(inpe)
  

url2 = 'https://g1.globo.com/previsao-do-tempo/ba/santo-antonio-de-jesus.ghtml'
r = requests.get(url2)
soup = BeautifulSoup(r.content, 'html.parser')
g1 = 'Probabilidade de ' + soup.find('span',{'class':'forecast-today-detail__item-value'}).text + ' de chuva para hoje (G1)'
print(g1)

bot.sendMessage(984798692, g1 + '\n' + inpe)
#print('FEITO')