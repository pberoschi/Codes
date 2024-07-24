import pyscreenshot 
import telepot

bot = telepot.Bot('6372818731:AAFZXRVBq90-ufHCiTc5l_Mqj0ozYXHEV7o')
chat_id = 984798692
# print(bot.getMe())


image = pyscreenshot.grab(bbox=(1, 50, 1150, 800)) 
# image = pyscreenshot.grab() 
# image.show() 
image.save("GeeksforGeeks.png") 


# bot.sendMessage(chat_id, 'teste')

# Enviando foto
# bot.sendPhoto(chat_id, 'https://i0.wp.com/casadospassaros.net/wp-content/uploads/2016/12/Papagaio-Verdadeiro.jpg')
bot.sendPhoto(chat_id, photo=open('C:\\Users\\Johnny\\Downloads\\testes\\GeeksforGeeks.png', 'rb'))