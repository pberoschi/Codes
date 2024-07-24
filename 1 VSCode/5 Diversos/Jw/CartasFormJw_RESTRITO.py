import requests
import time
from bs4 import BeautifulSoup
from selenium.webdriver.firefox.options import Options
from selenium import webdriver as wb
#from webdriver_manager.chrome import ChromeDriverManager
import time
import telepot
import pyautogui as py

tempo1 = 20
tempo2 = 20
bot = telepot.Bot('1591788137:AAFXANf-i5DYCCFJMuEe5cCjP1X7-I1WwPM')

url = "https://my.jw.org/home/pt/login"

'''
# NAVEGADOR CHROME
url = "https://my.jw.org/home/pt/login"
driver = webdriver.Chrome(ChromeDriverManager().install())
driver.get(url)
'''

# NAVEGADOR FIREFOX
option = Options()
option.headless = True
# driver = wb.Firefox(executable_path="C:\Program Files\geckodriver\geckodriver.exe", options=option)    # NAVEGADOR OFFLINE 
driver = wb.Firefox(executable_path="C:\Program Files\geckodriver\geckodriver.exe")                     # NAVEGADOR ONLINE
driver.get(url)
print('Abrindo navegador')

usuario = 'barbosajohnny@jwpub.org'
passwordJohnny = 'Claudia08TJ'
password21 = '0516'
password31 = 'palio'

print('Nome de Usuário')
time.sleep(tempo1)
usuarioName = driver.find_element_by_xpath('//*[@id="username"]')
usuarioName.click()
usuarioName.clear()
usuarioName.send_keys(usuario)
time.sleep(2)
proximo = driver.find_element_by_xpath('//*[@id="submit-button"]')
proximo.click()
time.sleep(tempo1)

print('Senha da conta')
password = driver.find_element_by_xpath('//*[@id="passwordInput"]')
password.click()
password.clear()
password.send_keys(passwordJohnny)
time.sleep(2)
loginClick = driver.find_element_by_xpath('//*[@id="submitButton"]')
loginClick.click()
time.sleep(tempo2)

# 0516
print('Número secreto')
password2 = driver.find_element_by_xpath('//*[@id="form.04b70d80-c216-41cf-815a-9b96eed7b4c0"]') 
password2.click()
password2.clear()
password2.send_keys(password21)
time.sleep(2)

# Palio
print('Palavra secreta')
password2 = driver.find_element_by_xpath('//*[@id="form.fd61bfcf-df1a-4d14-bc39-759eb2b8094b"]')
password2.click()
password2.clear()
password2.send_keys(password31)
time.sleep(2)

# Próximo
print('Entrando na área restrita')
#proximo = driver.find_element_by_xpath('/html/body/app-root/ptrn-site/section/section/main/app-security-questions/app-login/div/section/app-challenge/app-questions-challenge/form/div[4]/ptrn-button/button/ptrn-translate')
#proximo = driver.find_element_by_xpath('/html/body/app-root/ptrn-site/section/section/main/app-security-questions/div/section/app-questions-challenge/form/div[4]/ptrn-button/button/ptrn-translate')
proximo = driver.find_element_by_xpath('/html/body/app-root/ptrn-site/section/section/main/app-security-questions-container/app-security-questions/div/section/app-questions-challenge/form/div[4]/ptrn-button/button')
proximo.click()
time.sleep(tempo1)



# Escolhendo o Domiínio (Congregação)
print('Escolhendo Domínio Congregação')
cong = driver.find_element_by_xpath('/html/body/app-root/ptrn-site/section/section/main/app-home-container/app-home/div/section/app-domains/dl/dd[1]/a')
cong.click()
time.sleep(tempo1)


# Documentos
print('Clique Documentos')
# documentos = driver.find_element_by_xpath('/html/body/section/div[2]/nav/section[3]/header/h1/a')
# documentos.click()
driver.get('https://apps.jw.org/T_E8973298-2C9A-440C-B302-AC3ACC60EC57_DOCUMENTS')
time.sleep(tempo1)

# CARTAS
print('Verificando cartas')
import pandas as pd
driver.get('https://apps.jw.org/T_E8973298-2C9A-440C-B302-AC3ACC60EC57_VIEWLETTER')
html = driver.page_source

soup = BeautifulSoup(html, 'html.parser')
#print(soup)

buscaNOT = soup.find('p',{'class':'not-found'})

if (buscaNOT):
    mensagem = buscaNOT.text.strip().upper()
    #print(mensagem)
    bot.sendMessage(984798692, f'Site JW.org (Cartas): \n{mensagem}')
else:
    cartas = soup.find('div',{'class':'wikiPreview'})
    
    for item in soup.find('div',{'class':'wikiPreview'}):
        titulo = item.find('h4')
        descricao = item.find('ul')
        
        if (titulo):
            tituloSend = titulo.text.strip().upper()
            #print(f'>>> {tituloSend} <<<')
        if (descricao):
            descricaoSend = descricao.text.strip()
            #print(descricaoSend)
        #print('-'*100)
        bot.sendMessage(984798692, f'Site JW.org (NOVAS Cartas): \n{tituloSend} + \n{descricaoSend}')
print('CARTAS - OK')

# FORMULÁRIOS
print('Verificando Formulários')
driver.get('https://apps.jw.org/T_E8973298-2C9A-440C-B302-AC3ACC60EC57_VIEWFORM')
html = driver.page_source

soup = BeautifulSoup(html, 'html.parser')
#print(soup)

buscaNOT = soup.find('p',{'class':'not-found'})

if (buscaNOT):
    mensagem = buscaNOT.text.strip().upper()
    #print(buscaNOT.text.strip().upper())
    bot.sendMessage(984798692, f'Site JW.org (Formulários): \n{mensagem}')
else:
    cartas = soup.find('div',{'class':'wikiPreview'})
    
    for item in soup.find('div',{'class':'wikiPreview'}):
        titulo = item.find('h4')
        descricao = item.find('ul')
        
        if (titulo):
            tituloSend = titulo.text.strip().upper()
            #print(f'>>> {tituloSend} <<<')
        if (descricao):
            descricaoSend = descricao.text.strip()
            #print(descricaoSend)
        #print('-'*100)
        bot.sendMessage(984798692, f'Site JW.org (NOVAS Formulários): \n{tituloSend} + \n{descricaoSend}')
print('FORMULÁRIOS - OK')
time.sleep(2)
print('')
print('Finalizando e fechando')
time.sleep(60)
driver.close()
time.sleep(1)
py.hotkey('alt','f4')