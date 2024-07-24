from time import sleep
import telepot
from random import randint


bot = telepot.Bot('6372818731:AAFZXRVBq90-ufHCiTc5l_Mqj0ozYXHEV7o')
# chat_id = 984798692
# print(bot.getMe())


while 1:
    preco = randint(0,9)

    if (preco == 9) or (preco == 1):
        print('ALERTA')
        print(preco)
        # bot.sendMessage(chat_id, preco)
    else:
        print('.')

    sleep(1)















# MessageLoop(bot, handle).run_as_thread()
# print ('Listening ...')


# # Keep the program running.
# while 1:
#     time.sleep(10)








