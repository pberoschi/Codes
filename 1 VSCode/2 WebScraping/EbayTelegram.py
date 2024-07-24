from bs4 import BeautifulSoup
import requests
import pandas as pd


#url = 'https://www.ebay.com/sch/175672/i.html?_from=R40&_nkw=surface+pro&LH_BIN=1&LH_ItemCondition=3000&_udhi=350&rt=nc&LH_PrefLoc=2'                  # 0 a 350
#url = 'https://www.ebay.com/sch/175672/i.html?_from=R40&_nkw=surface%20pro&LH_BIN=1&LH_ItemCondition=3000&_udhi=350&LH_PrefLoc=2&rt=nc&_udlo=100'       # 100 a 350
url = 'https://www.ebay.com/sch/177/i.html?_from=R40&_nkw=surface%20pro&LH_BIN=1&LH_ItemCondition=3000&_udhi=1000&LH_PrefLoc=2&_udlo=50&rt=nc'

r = requests.get(url)
soup = BeautifulSoup(r.content, 'html.parser')

matriz = soup.find_all('li', {'class':'s-item'})

for item in matriz:
  titulo = item.find('h3',{'class':'s-item__title'})
  preco = item.find('div',{'class':'s-item__detail s-item__detail--primary'})
  link = item.find('a','s-item__link')

  if (preco):
    preco = preco.text
    #preco = preco.replace(',','')
    preco = preco[3:6]
    preco = float(preco)
    #print(preco)


#print(len(titulo))

    if (titulo):
        if (preco) > 200 and preco < 2000:
            #print(len(titulo))
            print(titulo.text)
            print(preco)
            print(link['href'])
            print('-'*50)          

