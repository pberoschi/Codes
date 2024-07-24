import requests
import time
from bs4 import BeautifulSoup
from selenium.webdriver.firefox.options import Options
from selenium import webdriver as wb
from selenium import webdriver
from webdriver_manager.chrome import ChromeDriverManager
import time


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
#driver = wb.Firefox(executable_path="C:\Program Files\geckodriver\geckodriver.exe", options=option)            # NAVEGADOR OFFLINE 
driver = wb.Firefox(executable_path="C:\Program Files\geckodriver\geckodriver.exe")                             # NAVEGADOR ONLINE
driver.get(url)



usuario = 'barbosajohnny@jwpub.org'
passwordJohnny = 'Claudia08TJ'
password21 = '0516'
password31 = 'palio'


time.sleep(2)
usuarioName = driver.find_element_by_id('form.userName')
usuarioName.click()
usuarioName.clear()
usuarioName.send_keys(usuario)
time.sleep(2)
#proximo = driver.find_element_by_class_name('field__checkbox-label')
proximo = driver.find_element_by_xpath('/html/body/app-root/ptrn-site/section/section/main/app-username/app-username-form/section/div/div/div[2]/article/form/ptrn-button/button')
proximo.click()
time.sleep(2)

password = driver.find_element_by_xpath('//*[@id="passwordInput"]')
password.click()
password.clear()
password.send_keys(passwordJohnny)
time.sleep(2)
loginClick = driver.find_element_by_xpath('//*[@id="submitButton"]')
loginClick.click()
time.sleep(7)

# 0516
password2 = driver.find_element_by_xpath('//*[@id="form.04b70d80-c216-41cf-815a-9b96eed7b4c0"]') 
password2.click()
password2.clear()
password2.send_keys(password21)
time.sleep(2)

# Palio
password2 = driver.find_element_by_xpath('//*[@id="form.fd61bfcf-df1a-4d14-bc39-759eb2b8094b"]')
password2.click()
password2.clear()
password2.send_keys(password31)
time.sleep(2)

# Próximo
proximo = driver.find_element_by_xpath('/html/body/app-root/ptrn-site/section/section/main/app-security-questions/app-login/div/section/app-challenge/app-questions-challenge/form/div[4]/ptrn-button/button/ptrn-translate')
proximo.click()
time.sleep(5)

# Documentos
documentos = driver.find_element_by_xpath('/html/body/app-root/ptrn-site/section/section/main/app-home-container/app-home/div/div/div/ul/li[2]/article/ul/li[1]/a')
documentos.click()
time.sleep(15)

# Formularios
formularios = driver.find_element_by_xpath('/html/body/section/div[2]/nav/section[3]/ul[2]/li[1]/a').click()
time.sleep(15)


# Escrever esboços
esbocos = driver.find_element_by_xpath('//*[@id="txtWikiSearch"]').send_keys('esboços')
time.sleep(15)
pesquisar = driver.find_element_by_xpath('/html/body/section/div[2]/main/div[2]/form[1]/fieldset/div[2]/div[2]/input[1]').click()


# selecionar tabela discursos
tabela = driver.find_element_by_xpath('/html/body/section/div[2]/main/div[2]/form[1]/div[2]/table[2]/tbody/tr[2]/td/div/table/tbody')
html_content = tabela.get_attribute('outerHTML')
soup = BeautifulSoup(html_content, 'html.parser')

table = soup.find_all('tr')[1:]

'''
for item in table:
    numero = item.find('a', target='_blank').text
    tema = item.find('td').text
    print(numero)
    print(tema)
    print('-'*50)

'''

for unidade in table:
    for item in unidade:
        if item:
            print(item)
