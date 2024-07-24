import requests
from bs4 import BeautifulSoup

# URL da página de notícias da BBC Brasil
url = "https://www.bbc.com/portuguese"

# Faz a requisição HTTP para obter o conteúdo da página
response = requests.get(url)

# Analisa o conteúdo HTML da página usando BeautifulSoup
soup = BeautifulSoup(response.content, "html.parser")

# Encontra os elementos que contêm as manchetes e os links
# manchetes = soup.find_all("h3", class_="bbc-pam0zn e47bds20")
# links = soup.find_all('a')


print(soup)

# links = soup.find_all('a', 'class=focusIndicatorInvert bbc-wa21ga e5ztwxl0')

# print(links)


# # Exibe as manchetes e os links na tela
# print("Principais manchetes do mundo na BBC Brasil:")
# for i, (manchete, link) in enumerate(zip(manchetes, links), start=1):
#     print(f"{i}. {manchete.text.strip()}")
#     print(f"   Link: https://www.bbc.com{link['href']}")

 

# Se quiser salvar as manchetes em um arquivo, descomente as linhas abaixo:
# with open("manchetes_bbc.txt", "w", encoding="utf-8") as file:
#     for manchete, link in zip(manchetes, links):
#         file.write(f"{manchete.text.strip()}\n")
#         file.write(f"Link: {link['href']}\n")

# Lembre-se de instalar as bibliotecas requests e beautifulsoup4:
# pip install requests beautifulsoup4