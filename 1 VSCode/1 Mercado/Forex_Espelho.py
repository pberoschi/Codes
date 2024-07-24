from telethon import TelegramClient,sync,events
from time import sleep
import requests
import Forex_AUT_V2

api_id = '23880109'
api_hash = '374ee8f5211028d42c4d9fcb9ae85b6a'
sessao = 'repassar'
grupo = int(6135423460) # Grupo Home (testes)
# grupo = int(1001831102829) #Madrugada
# grupo = int(1001923939251)


def obter_chats():
    client = TelegramClient(sessao,api_id,api_hash)
    client.start()
    dialogs = client.get_dialogs()

    for dialog in dialogs:
        print('------------------')
        if dialog.id < 0:
            print(f'Grupo: {dialog.title}')
            print(f'id: {dialog.id}')

        else:
            print(f'Nome: {dialog.title}')
            print(f'id: {dialog.id}')
    print('-------------------------')

    client.disconnect()

def main():
    try: 
        print('Monitoramento iniciado...')
        client = TelegramClient(sessao,api_id,api_hash)
        @client.on(events.NewMessage(chats = [grupo]))
        
        async def enviar_mensagem(event):
            await client.send_message(6372818731,event.raw_text)
        client.start()
        client.run_until_disconnected()


    except:
        print('Reiniciando...')
        return
    
# main()
obter_chats()
