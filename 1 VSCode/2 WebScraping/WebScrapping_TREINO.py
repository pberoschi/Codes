
import requests
from bs4 import BeautifulSoup
from datetime import date as dt

hoje = dt.today()
hoje = str(hoje).replace('-','')
dia = hoje[6:8]
dia = dia.replace('0','')
mes = hoje[4:6]
mes = mes.replace('0','')
ano = hoje[0:4]

page = requests.get(f'https://wol.jw.org/pt/wol/h/r5/lp-t/{ano}/{mes}/{dia}')

soup = BeautifulSoup(page.content, 'html.parser')

texto       = soup.find_all('p')[2].get_text()
comentario  = soup.find_all('p')[3].get_text()

# teste = soup.find_all('em')[0].get_text()
# teste2 = soup.find('tabContent')

print(f'{texto}\n')
print(f'{comentario[0:200]} (...)\n')
print(f'Para continuar a ler, acesse o site: https://wol.jw.org/pt/wol/h/r5/lp-t')
















