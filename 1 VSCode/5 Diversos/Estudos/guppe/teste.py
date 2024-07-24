#import urllib
#import urllib.request
#import urlopen
import requests



url = 'http://www.saude.ba.gov.br/noticias/'
#open = urllib.request.urlopen(html)
#html = urlopen('https://www.jw.org')

#print(html)
#print(open)

page = requests.get(url)
print(page)



