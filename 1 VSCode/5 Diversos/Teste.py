import time
import telepot
from telepot.loop import MessageLoop


def handle(msg):
    content_type, chat_type, chat_id = telepot.glance(msg)

    if content_type == 'text':
        
        palavra = str((msg['text']))

        if (palavra != ""):
            print(palavra)
            bot.sendMessage(chat_id, palavra)



bot = telepot.Bot('6372818731:AAFZXRVBq90-ufHCiTc5l_Mqj0ozYXHEV7o')
MessageLoop(bot, handle).run_as_thread()
print ('Listening ...')


# Keep the program running.
while 1:
    time.sleep(10)