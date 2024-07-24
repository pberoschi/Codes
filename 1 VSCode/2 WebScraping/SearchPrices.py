#https://www.youtube.com/watch?v=YKennHXZyJU



from bs4 import BeautifulSoup
import requests
import smtplib
import email.message
import time



url = 'https://www.brasiltronic.com.br/mobile/camera-sony-alpha-a6400-com-lente-16-50mm-f-35-56-lente-oss-p1329263'

headers = {"User-Agent": 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.114 Safari/537.36'}

site = requests.get(url, headers=headers)

soup = BeautifulSoup(site.content, 'html.parser')

title = soup.find('h1').get_text()
price = soup.find('strong', class_='sale-price').get_text().strip()

num_price = price[3:8]
num_price = num_price.replace('.','')
num_price = float(num_price)


def send_email():
    email_content = '''
        https://www.brasiltronic.com.br/mobile/camera-sony-alpha-a6400-com-lente-16-50mm-f-35-56-lente-oss-p1329263
    '''

    msg = email.message.Message()
    msg['Subject'] = 'Preço da câmera Sony a6400 baixou'

    msg['From'] = 'beroschi.peter'
    msg['To'] = 'beroschi.peter@gmail.com'
    password = 'johnny321@'
    msg.add_header('Content-Type', 'text/html')
    msg.set_payload(email_content)

    s = smtplib.SMTP('smtp.gmail.com: 587')
    s.starttls()
    s.login(msg['From'], password)
    s.sendmail(msg['From'], [msg['To']], msg.as_string())

    print('Sucesso ao enviar email')


if (num_price < 8000):
    send_email()










