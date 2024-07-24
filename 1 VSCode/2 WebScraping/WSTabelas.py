import requests
from bs4 import BeautifulSoup
import pandas as pd

headers = {
    'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/47.0.2526.106 Safari/537.36'}
url = 'https://www.transfermarkt.com.br/ligue-1/marktwerte/wettbewerb/FR1/pos//detailpos/0/altersklasse/alle'
r = requests.get(url, headers=headers)
soup = BeautifulSoup(r.content, 'html.parser')

#matriz = soup.find_all('tr', {'class': 'odd'})
#matriz2 = soup.find_all('tr', {'class': 'even'})
#print(matriz)


lista1 = []
for item in soup.find_all('tr', {'class': 'odd'}):
    resumo = {
        'jogador' : item.find('a', {'class': 'spielprofil_tooltip'}).text,
        'posicao' : item.find('table', {'class': 'inline-table'}).find('td').next_element.next_element.next_element.next_element.next_element.next_element.next_element.next_element.next_element.next_element.next_element.next_element.text.strip()
    }

    lista1.append(resumo)

lista2 = []
for item2 in soup.find_all('tr',{'class':'even'}):
    resumo2 = {
        'jogador' : item.find('a', {'class': 'spielprofil_tooltip'}).text,
        'posicao' : item.find('table', {'class': 'inline-table'}).find('td').next_element.next_element.next_element.next_element.next_element.next_element.next_element.next_element.next_element.next_element.next_element.next_element.text.strip()
      }

lista2.append(resumo2)

listageral = [lista1, lista2]

df = pd.DataFrame(lista1)

df.to_csv('teste.csv', encoding='UTF8')

'''
for item2 in soup.find('tr',{'class':'even'}):



    print(jogador.upper())
    print(f'-{posicao}-')
'''