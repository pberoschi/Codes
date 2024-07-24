import sys
from time import sleep
import telepot
from telepot.loop import MessageLoop



def OrdemCompra():
    print ('Compra acionada. Aguarde resultado')

    

def OrdemVenda():
    print ('Venda acionada. Aguarde resultado')





def handle(msg):
    content_type, chat_type, chat_id = telepot.glance(msg)
    # content_type = telepot.glance(msg)

    if content_type == 'text':        
        modo = (msg['text'])
        print(modo)

        lado = modo[0]
        alvo = modo[2:9]
        stop = modo[10:17]

        print(f'Lado: {lado}')
        print(f"Alvo: {alvo}")
        print(f"Stop: {stop}")

        if lado == 'B':
            OrdemCompra()

        if lado == "S":
            OrdemVenda()

    print('*** >>> ------ <<< ***')



bot = telepot.Bot('6372818731:AAFZXRVBq90-ufHCiTc5l_Mqj0ozYXHEV7o')
MessageLoop(bot, handle).run_as_thread()
print ('Listening ...')


# Keep the program running.
while 1:
    sleep(10)








