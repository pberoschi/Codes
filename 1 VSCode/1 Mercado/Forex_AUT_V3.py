# --- ORDENS A MERCADO --- #

import sys
from time import sleep
import telepot
from telepot.loop import MessageLoop
import MetaTrader5 as mt5
import time
# import Forex_Espelho

bot = telepot.Bot('6372818731:AAFZXRVBq90-ufHCiTc5l_Mqj0ozYXHEV7o')
chat_id = 984798692

#if not mt5.initialize(login=50717088, server="ICMarketsSC-Demo", password=""):
if not mt5.initialize(login=82491017, server="MetaQuotes-Demo", password="V+1dHiKp"):
# if not mt5.initialize(login=135022402, server="ZeroMarkets-Demo-1", password="Claudia123@"):
    print("initialize() failed, error code =",mt5.last_error())
    quit()

def CompraMercado():    
    symbol = 'XAUUSD'
    lot = 0.1
    price = mt5.symbol_info_tick(symbol).ask
    desviation = 1
    request = {
        "action": mt5.TRADE_ACTION_DEAL,
        "symbol": symbol,
        "volume": lot,
        "type": mt5.ORDER_TYPE_BUY,
        "price": price,
        "sl": price - 5,
        "tp":price + 5,
        "magic": 234000,
        "comment": "Compra via python",
        "type_time": mt5.ORDER_TIME_GTC,
        "type_filling": mt5.ORDER_FILLING_RETURN,
        # "type_filling": mt5.ORDER_FILLING_IOC,
    }
    result = mt5.order_send(request) 
    result

    if result.comment == 'Requote':
        print('Ordem não-executada. Fazendo nova tentativa...')
        CompraMercado()
    else:
        print('COMPRA executada com sucesso')     
        bot.sendMessage(chat_id, f'COMPRA de XAUUSD executada com sucesso')

    sleep(180)


def VendaMercado():
    symbol = 'XAUUSD'
    lot = 0.1
    price=mt5.symbol_info_tick(symbol).bid
    request = {
        "action": mt5.TRADE_ACTION_DEAL,
        "symbol": symbol,
        "volume": lot,
        "type": mt5.ORDER_TYPE_SELL,
        "price": price,
        "sl": price + 5,
        "tp":price - 5,
        "magic": 234000,
        "comment": "Venda via python",
        "type_time": mt5.ORDER_TIME_GTC,
        "type_filling": mt5.ORDER_FILLING_RETURN,
        # "type_filling": mt5.ORDER_FILLING_IOC,
    }
    result = mt5.order_send(request) 
    result

    if result.comment == 'Requote':
        print('Ordem não-executada. Fazendo nova tentativa...')
        VendaMercado()
    else:
        print('VENDA executada com sucesso')
        bot.sendMessage(chat_id, f'VENDA de XAUUSD executada com sucesso')

    sleep(180)
        

# AUTOMATICO MADRUGADA #
def handle(msg):                                                            
    content_type, chat_type, chat_id = telepot.glance(msg)  
    try:      
        if content_type == 'text':        
            modo = (msg['text'])
            # print(f'Modo: {modo}')
            teste = modo.split()
            teste[0] = teste[0].upper()
            teste[1] = teste[1].upper()
            # print(teste)
                       
            if teste[0] == 'GOLD' and teste[1] == 'BUY':
                CompraMercado()
                # print('Compra acionada')
    
            elif teste[0] == 'GOLD' and teste[1] == 'SELL':
                VendaMercado()
                # print('Venda acionada')

            elif teste[0] == 'XAUUSD' and teste[1] == 'BUY':
                CompraMercado()
                # print('Compra acionada')
    
            elif teste[0] == 'XAUUSD' and teste[1] == 'SELL':
                VendaMercado()
                # print('Venda acionada')

            elif teste[0] == 'BUY' and teste[1] == 'GOLD':
                CompraMercado()
                # print('Compra acionada')
    
            elif teste[0] == 'SELL' and teste[1] == 'GOLD':
                VendaMercado()
                # print('Venda acionada')

    except:
        print("Retornando e aguardando próxima entrada""")
        return



bot = telepot.Bot('6372818731:AAFZXRVBq90-ufHCiTc5l_Mqj0ozYXHEV7o')
MessageLoop(bot, handle).run_as_thread()
print ('Listening ...')

# VendaMercado()
# Keep the program running.
# while 1:
#     sleep(1)
    # print('teste')










