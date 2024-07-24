# Selenium com Google Chrome
#https://www.youtube.com/watch?v=_ZDBVeqyK6g
#https://www.youtube.com/watch?v=y7OhuSGBt8o&t=1127s

from selenium import webdriver
from webdriver_manager.chrome import ChromeDriverManager
import time


driver = webdriver.Chrome(ChromeDriverManager().install())
driver.get('https://br.investing.com/portfolio/?portfolioID=YmViNTFnMGQ3ZDsxNWQ4PQ%3D%3D')
time.sleep(10)
#driver.quit()


#open_selenium()