import requests
from bs4 import BeautifulSoup
import time
import csv
import shutil
import sys
import telepot



url = 'https://www.jw.org/pt/Novidades'
site = 'www.jw.org'
r = requests.get(url)
soup = BeautifulSoup(r.content, 'html.parser')

todos_elementos = soup.find_all('div', attrs={'class':'synopsis'})

filename = "c:\\users\\johnn\\PycharmProjects\\jw.org\\noticiasJW.csv"
f =open(filename, "w")
#headers = "DATA;NOTICIA;LINK\n"
#f.write(headers)

bot = telepot.Bot('1591788137:AAFXANf-i5DYCCFJMuEe5cCjP1X7-I1WwPM')

amount = 0
data = []
news = []
link = []

for elemento in todos_elementos:
  data = elemento.find('p',{'class':'meta'}).text.strip()
  news = elemento.find('h3').text.strip()
  link = 'https://www.jw.org' + elemento.find('a')['href']
  amount = amount +1
  data2 = str(data)
  news2 = str(news)
  link2 = str(link)
  f.write(data2 + ';' + news2 + ';' + link2 + '\n')
   

print(amount)
f.close()



s=open('c:\\users\\johnn\\PycharmProjects\\jw.org\\noticiasJW.csv')
try:
    o=open('c:\\users\\johnn\\PycharmProjects\\jw.org\\noticiasJW2.csv')
except:
    shutil.copy('c:\\users\\johnn\\PycharmProjects\\jw.org\\noticiasJW.csv', 'c:\\users\\johnn\\PycharmProjects\\WebScraping\\noticiasJW2.csv')
    o=open('c:\\users\\johnn\\PycharmProjects\\jw.org\\noticiasJW2.csv')


lista1 = set(s)
lista2 = set(o)

diferenca = lista1 - lista2
print(len(diferenca))
print('-'*30)

listadif = str(diferenca)
#listadif = listadif.split(';')

'''
data_ = listadif[0]
noti = str(listadif[1])
sit = listadif[2]
calc = len(sit) - 4
site2 = sit[0:calc]
'''

envio = []

for item in listadif:
    data_ = item[0]
    envio.append(data_)
    noti = str(listadif[1])
    sit = item[2]
    calc = len(sit) - 4
    site2 = sit[0:calc]
    envio.append(site2)


print(envio)


s.close()
o.close()


'''
if len(diferenca) > 0:
    bot.sendMessage(984798692, envio)


#shutil.copy('c:\\users\\johnn\\PycharmProjects\\jw.org\\noticiasJW.csv', 'c:\\users\\johnn\\PycharmProjects\\jw.org\\noticiasJW2.csv')



n = 0

while True:
    time.sleep(3600)
    bot.sendMessage(984798692, listadif)
    n += 1
'''