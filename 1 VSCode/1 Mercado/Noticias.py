import requests
from bs4 import BeautifulSoup


# url = (f'https://www.skyscanner.com.br/transporte/passagens-aereas/{cidSaida}/{cidDestino}/{ano}{mesIda}01/{ano}{mesVolta}01/?adultsv2=2&cabinclass=economy&childrenv2=&inboundaltsenabled=false&outboundaltsenabled=false&preferdirects=false&priceSourceId=&priceTrace=&qp_prevCurrency=BRL&qp_prevPrice=ReturnNoPrices&qp_prevProvider=ins_month&rtn=1')
# url = 'https://www.skyscanner.com.br/'
url = "https://www.bbc.com/portuguese"

response = requests.get(url)
soup = BeautifulSoup(response.content, "html.parser")

# noticias = soup.find_all('h3')
noticias = soup.find_all('h3',class_="bbc-pam0zn e47bds20")
# print(noticias)

for x in noticias:
    a = x.find('a').text
    # link = x.find(href=True)
    link = x.find('a',href=True)

    print(a)
    print(link['href'])
    print('')








































# def obtendoseguidores():
#     abrindo_instagram("gustavocorreia342", "gusta102030")

#     if os.path.isfile("seguidores.txt"):
#         print("Arquivo de Seguidores já carregado...")
#     else:
#         # pegar_seguidores("filipedeschamps")
#         pegar_seguidores("anitta")

#     print('Chamando Seguir...')
#     seguir()

#     # CLICAR em SAIR
#     driver.find_element('xpath','/html/body/div[2]/div/div/div[2]/div/div/div[1]/div[1]/div[1]/div/div/div/div/div[3]/span/div/a/div/div[1]/div/div/svg').click()

    
#     driver.find_element('xpath','/html/body/div[2]/div/div/div[2]/div/div/div[1]/div[1]/div[1]/div/div/div[1]/div/div[3]/span/div/a/div/div/div/div/svg').click()
#     /html/body/div[2]/div/div/div[2]/div/div/div[1]/div[1]/div[1]/div/div/div/div/div[3]/span/div/a/div/div[1]/div/div/svg



#     sleep(5)
#     driver.find_element('xpath',"//*[contains(text(), 'Sair')]").click()

# def abrindo_instagram(username,password):
#     tempoAle = randint(10,15)
#     print("Abrindo Instagram...")
#     driver.get('https://www.instagram.com/')
#     sleep(10)
#     print("Fazendo Login no Instagram...")
#     driver.find_element("xpath",'/html/body/div[2]/div/div/div[2]/div/div/div[1]/section/main/article/div[2]/div[1]/div[2]/form/div/div[1]/div/label/input').send_keys(username)
#     sleep(2)
#     driver.find_element("xpath",'/html/body/div[2]/div/div/div[2]/div/div/div[1]/section/main/article/div[2]/div[1]/div[2]/form/div/div[2]/div/label/input').send_keys(password)
#     sleep(2)
#     driver.find_element("xpath",'/html/body/div[2]/div/div/div[2]/div/div/div[1]/section/main/article/div[2]/div[1]/div[2]/form/div/div[3]').click()
#     sleep(10)

#     print("Negando Solicitação de Segurança Instagram...")
#     driver.find_element("xpath",'/html/body/div[2]/div/div/div[2]/div/div/div[1]/div[1]/div[2]/section/main/div/div/div/div/div').click()
#     sleep(tempoAle)
#     print("Ignorando pedido de 'ativar notificações'")
#     # driver.find_element("xpath",'/html/body/div[3]/div[1]/div/div[2]/div/div/div/div/div[2]/div/div/div[3]/button[2]').click()
#     driver.find_element('xpath',"//*[contains(text(), 'Agora não')]").click()
#     sleep(tempoAle)

#     print("Instagram aberto...")
    


# def seguir():
#      x = 0
#      a = randint(2,5)           # Numeros de seguidores a acrescentar nessa execução
#      while x < a:
#         print(f'Serão acrescentados agora {a} seguidores')       
#         with open("seguidores.txt", "r") as file:
#             allText = file.read()
#             words = list(map(str, allText.split()))
#             comment = random.choice(words)
        
#         sleep(randint(5,10))
#         # Pesquisar
#         driver.find_element("xpath",'/html/body/div[2]/div/div/div[2]/div/div/div[1]/div[1]/div[1]/div/div/div/div/div[2]/div[2]/span/div/a/div/div[2]/div/div/span/span').click()
#         sleep(randint(5,10))
#         py.write(comment, interval=0.40)
#         sleep(randint(5,10))
#         py.press('down')
#         sleep(randint(5,10))
#         py.press('enter')
#         sleep(randint(5,10))

#         # Pressionar Seguir se estiver disponível
#         seguir = driver.find_element('xpath',"//*[contains(text(), 'Seguir')]")

#         try:
#             seguir.click()
#             print('Feito! Já sou seguidor')
#             sleep(randint(10,15))
            
#             file.close
#             x = x+1

#         except:
#             print('Impossível. Já estou seguindo! Voltando a página e continuando o trabalho')
#             driver.back()
#             sleep(randint(5,10))
#             return

        

# def pegar_seguidores(usuario):
#     L = instaloader.Instaloader()
#     L.login('gustavocorreia342', 'gusta102030')
#     profile = instaloader.Profile.from_username(L.context, usuario)

#     print(f"Salvando Seguidores de {usuario}...")
#     #Salvando Seguidores em Arquivo .TXT
#     file = open("seguidores.txt", "a+")
#     for followee in profile.get_followers():
#         username = "@" + followee.username
#         file.write(username + "\n")

#     file.close()


# while True:
#     b = randint(120,300)
#     y = b/5
#     obtendoseguidores()
#     print('Próxima execução daqui a {y} minutos')
#     sleep(b)

































