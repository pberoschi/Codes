from urllib.request import urlopen
from bs4 import BeautifulSoup

#html = urlopen('http://www.jw.org/pt/novidades/')
#html = urlopen('http://www.pythonscraping.com/pages/warandpeace.html')
html = urlopen('http://www.pythonscraping.com/pages/page3.html')

bs = BeautifulSoup(html.read(), 'html.parser')

#nameList = bs.find_all('span', {'class':'green'})
#nameList = bs.find_all(['h1','h2','h3','h4','h5','h6'])
#nameList = bs.find_all('span', {'class':{'green', 'red'}})
#nameList = bs.find_all(text='the prince')
#nameList = bs.div.find_all('img')
#nameList = bs.div.find(id='content')

for child in bs.find('table',{'id':'giftList'}).children:
    print(child)



#print(nameList.get_text())
#print(len(nameList))
#for name in nameList:
    #print(name.get_text())
 #   print(name)
