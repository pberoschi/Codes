import requests
import time
from bs4 import BeautifulSoup
from selenium.webdriver.firefox.options import Options
from selenium import webdriver as wb



#url = "https://my.jw.org/home/pt/login"
url = 'https://apps.jw.org/T_E8973298-2C9A-440C-B302-AC3ACC60EC57_VIEWFORM?selWikiCatID=0&txtWikiSearch=esbo%C3%A7os&selWikiModifiedOperator=%3E%3D&txtWikiModifiedDate=dd%2Fmm%2Faaaa&selWikiSort=0&selWikiType=FORM&chkWikiSearchForm=1&txtAction=WIKIVIEWERSEARCH&txtWikiDefaultSearch=0&txtListPage=1&txtDocAbstractView=0'


option = Options()
option.headless = True
#driver = wb.Firefox(executable_path="C:\Program Files\geckodriver\geckodriver.exe", options=option)            # NAVEGADOR OFFLINE 
driver = wb.Firefox(executable_path="C:\Program Files\geckodriver\geckodriver.exe")                             # NAVEGADOR ONLINE
driver.get(url)


'''
driver = wb.Firefox(executable_path="C:\Program Files\geckodriver\geckodriver.exe")                             # NAVEGADOR ONLINE
driver.get(url)

tabela = driver.find_element_by_xpath('/html/body/section/div[2]/main/div[2]/form[1]/div[2]/table[2]/tbody/tr[2]/td/div/table/tbody')
html_content = tabela.get_attribute('outerHTML')
soup = BeautifulSoup(html_content, 'html.parser')
table = soup.find(name='table')


for item in tabela:
    teste = item.find_element_by_xpath('/html/body/section/div[2]/main/div[2]/form[1]/div[2]/table[2]/tbody/tr[2]/td/div/table/tbody/tr[1]').text
    print(teste)

'''
