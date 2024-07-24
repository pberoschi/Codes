from selenium import webdriver as wb
from selenium.webdriver.firefox.options import Options
from selenium.webdriver.common.keys import Keys
from time import sleep
import instaloader
import random
import os.path
import pyautogui as py


# driver = webdriver.Chrome(r"C:\Users\Windows\Downloads\chromedriver_win32 (1)\chromedriver.exe")
option = Options()
option.handless = True

# driver = wb.Firefox(options=option)     # OFFLINE
driver = wb.Firefox()                     # ONLINE


driver.get('https://pyautogui.readthedocs.io/en/latest/keyboard.html')
sleep(10)
driver.find_element("xpath",'//*[@id="rtd-search-form"]/input[1]').click()
sleep(5)
py.write('comment', interval=0.40)
sleep(5)
py.press('down')








