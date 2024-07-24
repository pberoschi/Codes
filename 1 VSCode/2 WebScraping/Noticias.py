from bs4 import BeautifulSoup
import requests


response = requests.get('https://www1.folha.uol.com.br/ultimas-noticias/')
content = response.content
site = BeautifulSoup(content, 'html.parser')


#html da notícia
noticias = site.find_all('div', attrs={'class': 'c-newslist'})
#print(noticias.prettify())


for noticia in noticias:
    for item in noticia.find_all('h2',{'class':'c-headline__title'}),('p',{'class':'c-headline__standfirst'}):
        print(item)
        #print(titulo.text)
        #subtitulo = noticia.find('p',{'class':'c-headline__standfirst'})
        #print(subtitulo.text.strip())
        #print(link['href'])
        



