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

def sorteioInstagram():
    abrindo_instagram("peterberoschi", "johnny321@", "https://www.instagram.com/p/C3Yia2SvWF7/")

    if os.path.isfile("seguidores.txt"):
        print("Arquivo de Seguidores já carregado...")
    else:
        pegar_seguidores("filipedeschamps")

    comentandoPost()

def abrindo_instagram(username,password, url):
    print("Abrindo Instagram...")
    # driver.get("https://www.instagram.com/")
    sleep(10)
    print("Fazendo Login no Instagram...")
    driver.find_element("xpath",'/html/body/div[2]/div/div/div[2]/div/div/div[1]/section/main/article/div[2]/div[1]/div[2]/form/div/div[1]/div/label/input').send_keys(username)
    sleep(2)
    driver.find_element("xpath",'/html/body/div[2]/div/div/div[2]/div/div/div[1]/section/main/article/div[2]/div[1]/div[2]/form/div/div[2]/div/label/input').send_keys(password)
    sleep(2)
    driver.find_element("xpath",'/html/body/div[2]/div/div/div[2]/div/div/div[1]/section/main/article/div[2]/div[1]/div[2]/form/div/div[3]').click()
    sleep(10)
    print("Negando Solicitação de Segurança Instagram...")
    driver.find_element("xpath",'/html/body/div[2]/div/div/div[2]/div/div/div[1]/div[1]/div[2]/section/main/div/div/div/div/div').click()
    sleep(5)
    print("Ignorando pedido de 'ativar notificações'")
    driver.find_element("xpath",'/html/body/div[3]/div[1]/div/div[2]/div/div/div/div/div[2]/div/div/div[3]/button[2]').click()

    print("Acessando o Post do sorteio...")
    # driver.get(url)

def pegar_seguidores(usuario):
    L = instaloader.Instaloader()
    L.login('peterberoschi', 'johnny321@')
    profile = instaloader.Profile.from_username(L.context, usuario)

    print(f"Salvando Seguidores de {usuario}...")
    #Salvando Seguidores em Arquivo .TXT
    file = open("seguidores.txt", "a+")
    for followee in profile.get_followers():
        username = "@" + followee.username
        file.write(username + "\n")

    file.close()

def comentandoPost():
    z = 0
    while 1 == 1:
        driver.get("https://www.instagram.com/p/C3Yia2SvWF7/")
        cmt = driver.find_element("xpath",'/html/body/div[2]/div/div/div[2]/div/div/div[1]/div[1]/div[2]/section/main/div/div[1]/div/div[2]/div/div[4]/section/div/form/div/textarea').click()
        comment = lendo_arquivo()
        py.write(comment, interval=0.40)
        # driver.find_element_by_xpath('//*[@id="react-root"]/section/main/div/div[1]/article/div[3]/section[3]/div/form/textarea').send_keys(' ')
        # sleep(10)
        # driver.find_element_by_xpath('//*[@id="react-root"]/section/main/div/div[1]/article/div[3]/section[3]/div/form/textarea').send_keys(Keys.ENTER)
        # sleep(10)
        # driver.find_element_by_xpath('//*[@id="react-root"]/section/main/div/div[1]/article/div[3]/section[3]/div/form/textarea').send_keys(Keys.ENTER)
        # z += 1
        # print(f"{z}")
        # sleep(60)

def lendo_arquivo():
    with open("seguidores.txt", "r") as file:
        allText = file.read()
        words = list(map(str, allText.split()))
        return random.choice(words)

sorteioInstagram()




























# from selenium import webdriver as wb
# from selenium.webdriver.common.keys import Keys
# from time import sleep
# import instaloader
# import random
# import os.path

# # driver = webdriver.Chrome(r"C:\Users\Windows\Downloads\chromedriver_win32 (1)\chromedriver.exe")
# driver = wb.Firefox(executable_path="C:\Program Files\geckodriver\geckodriver.exe")

# def sorteioInstagram():
#     abrindo_instagram("higorgranero", "Higor18671999", "https://www.instagram.com/p/CPB1FSOjNBE/")

#     if os.path.isfile("seguidores.txt"):
#         print("Arquivo de Seguidores já carregado...")
#     else:
#         pegar_seguidores("filipedeschamps")

#     comentandoPost()

# def abrindo_instagram(username,password, url):
#     print("Abrindo Instagram...")
#     driver.get("https://www.instagram.com/")
#     sleep(2)
#     print("Fazendo Login no Instagram...")
#     driver.find_element_by_xpath("//input[@name=\"username\"]").send_keys(username)
#     driver.find_element_by_xpath("//input[@name=\"password\"]").send_keys(password)
#     driver.find_element_by_xpath("//button[@type=\"submit\"]").click()
#     sleep(10)
#     print("Negando Solicitação de Segurança Instagram...")
#     driver.find_element_by_xpath("//button[text()='Not Now']").click()
#     sleep(5)
#     print("Acessando o Post do sorteio...")
#     driver.get(url)

# def pegar_seguidores(usuario):
#     L = instaloader.Instaloader()
#     L.login('higorgraneroo', 'Higor1867')
#     profile = instaloader.Profile.from_username(L.context, usuario)

#     print(f"Salvando Seguidores de {usuario}...")
#     #Salvando Seguidores em Arquivo .TXT
#     file = open("seguidores.txt", "a+")
#     for followee in profile.get_followers():
#         username = "@" + followee.username
#         file.write(username + "\n")

#     file.close()

# def comentandoPost():
#     z = 0
#     while 1 == 1:
#         cmt = driver.find_element_by_xpath('//*[@id="react-root"]/section/main/div/div[1]/article/div[3]/section[3]/div/form/textarea')
#         cmt.click()
#         comment = lendo_arquivo()
#         driver.find_element_by_xpath('//*[@id="react-root"]/section/main/div/div[1]/article/div[3]/section[3]/div/form/textarea').send_keys(comment)
#         driver.find_element_by_xpath('//*[@id="react-root"]/section/main/div/div[1]/article/div[3]/section[3]/div/form/textarea').send_keys(' ')
#         sleep(10)
#         driver.find_element_by_xpath('//*[@id="react-root"]/section/main/div/div[1]/article/div[3]/section[3]/div/form/textarea').send_keys(Keys.ENTER)
#         sleep(10)
#         driver.find_element_by_xpath('//*[@id="react-root"]/section/main/div/div[1]/article/div[3]/section[3]/div/form/textarea').send_keys(Keys.ENTER)
#         z += 1
#         print(f"{z}")
#         sleep(60)

# def lendo_arquivo():
#     with open("seguidores.txt", "r") as file:
#         allText = file.read()
#         words = list(map(str, allText.split()))
#         return random.choice(words)

# sorteioInstagram()