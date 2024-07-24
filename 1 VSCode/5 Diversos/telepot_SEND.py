import sys
import time
import telepot
from telepot.loop import MessageLoop
from random import randint


def handle(msg):
    content_type, chat_type, chat_id = telepot.glance(msg)
    # content_type = telepot.glance(msg)

    if content_type == 'text':
        # bot.sendMessage(chat_id, msg['text'])
        # print(msg['text'])
        
        # preco = randint(0,9)
        preco = int((msg['text']))

        if (preco == 4930) or (preco == 4920):
            print('ALERTA')
            bot.sendMessage(chat_id, preco)
        # else:
        #     print('.')




bot = telepot.Bot('6372818731:AAFZXRVBq90-ufHCiTc5l_Mqj0ozYXHEV7o')
MessageLoop(bot, handle).run_as_thread()
print ('Listening ...')


# Keep the program running.
while 1:
    time.sleep(10)








