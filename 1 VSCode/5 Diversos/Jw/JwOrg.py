from bs4 import BeautifulSoup
import requests
import pandas as pd



url = 'https://www.jw.org/pt/Novidades'
site = 'www.jw.org'
r = requests.get(url)
soup = BeautifulSoup(r.content, 'html.parser')


#todos_elementos = soup.find_all('div', attrs={'class':'whatsNewItems'})
todos_elementos = soup.find_all('div', attrs={'class':'synopsis'})


listaNews = []

for elemento in todos_elementos:
  data = elemento.find('p',{'class':'meta'})
  news = elemento.find('h3')
  link = elemento.find('a')


  resumo = {
      'DATA':data.text.strip(),
      'NOTICIA':news.text.strip(),
      'LINK':'www.jw.org' + link['href']
    }

  listaNews.append(resumo)
  print('Salvando: ', resumo['NOTICIA'])
  

df = pd.DataFrame(listaNews)




