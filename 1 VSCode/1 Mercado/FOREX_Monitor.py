# from telethon import TelegramClient,sync,events
# from time import sleep
# import requests
# # import Forex_AUT_V3
# # import Forex_AUT_V4
# import Forex_AUT_V5

# api_id = int(23880109)
# api_hash = '374ee8f5211028d42c4d9fcb9ae85b6a'
# sessao = 'repassar'

# grupo1 = int(1001923939251) # Grupo Main
# grupo2 = int(1001831102829) # Madrugada
# grupo3 = int(1001295875336) # Pra Cima Traders
# grupo4 = int(6135423460) # Grupo Home (testes)

# destino = int(6372818731)


# def main():
#     try: 
#         print('Monitoramento iniciado...')
#         client = TelegramClient(sessao,api_id,api_hash)
#         @client.on(events.NewMessage(chats = [grupo1]))
        
#         async def enviar_mensagem(event):
#             await client.send_message(destino,event.raw_text)
#         client.start()
#         client.run_until_disconnected()
#         # Forex_AUT_V3
#         # Forex_AUT_V4
#         Forex_AUT_V5

#     except:
#         print('Reiniciando...')
#         return


# main()



