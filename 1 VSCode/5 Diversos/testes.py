from selenium import webdriver as wb
from selenium.webdriver.firefox.options import Options
from selenium.webdriver.common.keys import Keys
from time import sleep
import instaloader
from random import randint
import os.path
import pyautogui as py

# # driver = webdriver.Chrome(r"C:\Users\Windows\Downloads\chromedriver_win32 (1)\chromedriver.exe")
# option = Options()
# option.handless = True

# driver = wb.Firefox(option)                     # ONLINE

# driver.get('https://www.jw.org/pt')
# sleep(5)

# # driver.find_element("xpath",'/html/body/div[1]/div/div/button[1]').click()
# driver.find_element('xpath',"//*[contains(text(), 'Aceitar')]").click()
# sleep(5)

# driver.find_element('xpath',"//*[contains(text(), 'Veja a resposta')]").click()
# sleep(5)


# try:
#     driver.find_element('xpath',"//*[contains(text(), 'Veja a resposta')]").click()
#     print('achei')

# except:
#     print('Não achei nada parecido. Voltando a página anterior')
#     driver.back()

# sleep(60)



x = 0
while x < (randint(3,10)):
    print('Teste')
    sleep(3)
    x = x+1




















# import random
# import os.path
# import pyautogui as py



# with open("seguidores.txt", "r") as file:
#     allText = file.read()
#     words = list(map(str, allText.split()))
#     # return random.choice(words)
#     wordALE = random.choice(words)

#     send = py.write(wordALE, interval=0.40) 




