import csv
import shutil
import telepot

import requests
from bs4 import BeautifulSoup
from time import sleep
from selenium.webdriver.chrome.options import Options

urljw = 'https://www.jw.org/pt/ultimos-artigos-destaque/'

headers = {'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/90.0.4430.212 Safari/537.36'}
r = requests.get(urljw, headers=headers)
soup = BeautifulSoup(r.content, 'html.parser')

main = soup.find_all("div", {'class':'syn-body lss'})

filename = "newsJW.csv"
f =open(filename, "w")

headers = "Titulo;Descricao;Endereco\n"
f.write(headers)

titulo = []
descricao = []
link = []


for item in main:
    titulo = item.find('h3').text.strip()
    descricao = item.find('p').text.strip()
    link = 'www.jw.org' + item.find('a')['href']
    
    f.write(titulo + ";" + descricao + ";" + link + "\n")
    
f.close()

def compare():
    s=open('newsJW.csv')
    try:
        o=open('newsJW2.csv')
    except:
        shutil.copy('newsJW.csv', 'newsJW2.csv')
        o=open('newsJW2.csv')

    csv_0 = csv.reader(s)
    csv_1 = csv.reader(o)

    list1= []
    list2= []

    for row in csv_0:
        list1.append(row[0])

    for row in csv_1:
        list2.append(row[0])

    diferenca = set(list1).difference(set(list2))
    print(diferenca)
    
    if diferenca != '':
        for item in diferenca:
            item = str(item)
            bot = telepot.Bot('1591788137:AAFXANf-i5DYCCFJMuEe5cCjP1X7-I1WwPM')
            bot.sendMessage(984798692, item)
            
    s.close()
    o.close()    
    
compare()
shutil.copy('newsJW.csv', 'newsJW2.csv')
print(f'\n\n>>> Fim do Script <<<')