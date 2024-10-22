# from selenium import webdriver as wb
# from selenium.webdriver.firefox.options import Options
# from selenium.webdriver.common.keys import Keys
# from time import sleep
# import pyautogui as py


# # driver = wb.Firefox(options=option)     # OFFLINE
# driver = wb.Firefox()                     # ONLINE
# driver.get("https://www.croxyproxy.com/")



# # driver.close()


import os #importa o módulo os

site = "https://www.youtube.com/watch?v=9Bw7dzMWeNw&t=55s"

# os.system("\"C:\Path\To\chrome.exe\" -incognito www.jw.org/pt") #chama o chrome.exe no modo anônimo e abre o site. 
os.system(f"\"C:\Program Files\Google\Chrome\Application\chrome.exe\" -incognito {site}") #chama o chrome.exe no modo anônimo e abre o site. 