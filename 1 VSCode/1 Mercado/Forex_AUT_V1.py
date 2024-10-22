import sys
from time import sleep
import telepot 
from telepot.loop import MessageLoop
import MetaTrader5 as mt5
import time

#if not mt5.initialize(login=50717088, server="ICMarketsSC-Demo", password=""):
if not mt5.initialize(login=82491017, server="MetaQuotes-Demo", password="V+1dHiKp"):
    print("initialize() failed, error code =",mt5.last_error())
    quit()

def OrdemCompra(entrada,tp,sl):   
    symbol = 'XAUUSD'
    lot = 0.1
    request = {
        "action": mt5.TRADE_ACTION_PENDING,
        "symbol": symbol,
        "volume": lot,
        "type": mt5.ORDER_TYPE_BUY_LIMIT,
        "price": entrada,
        "sl": sl,
        "tp":tp,
        "magic": 234000,
        "comment": "Compra via python",
        "type_time": mt5.ORDER_TIME_GTC,
        "type_filling": mt5.ORDER_FILLING_RETURN,
    }
    mt5.order_send(request)
    print("Compra via python executada")


def OrdemVenda(entrada,tp,sl):
    symbol = 'XAUUSD'
    lot = 0.1
    request = {
        "action": mt5.TRADE_ACTION_PENDING,
        "symbol": symbol,
        "volume": lot,
        "type": mt5.ORDER_TYPE_SELL_LIMIT,
        "price": entrada,
        "sl": sl,
        "tp":tp,
        "magic": 234000,
        "comment": "Venda via python",
        "type_time": mt5.ORDER_TIME_GTC,
        "type_filling": mt5.ORDER_FILLING_RETURN,
    }
    mt5.order_send(request)
    print("Venda via python executada")


def handle(msg):
    content_type, chat_type, chat_id = telepot.glance(msg)  
    try:      
        if content_type == 'text':        
            modo = (msg['text'])

            teste = modo.split()

            if teste[1] == 'buy':
                ativo1   = teste[0]
                ativo1   = f'{ativo1}USD'.upper()
                lado    = teste[1]
                entrada = float(teste[2])
                entrada = round(entrada,2)
                alvo    = float(teste[3])
                alvo    = round(alvo,2)
                stop    = float(teste[4])
                stop    = round(stop,2)

                print(f'Ativo: {ativo1}')
                print(f"Lado: {lado}")
                print(f"Entrada: {entrada}")
                print(f"Alvo: {alvo}")
                print(f"Stop: {stop}""\n")

                OrdemCompra(ativo1,entrada,alvo,stop)
    
            elif teste[1] == 'sell':
                ativo1   = teste[0]
                ativo1   = f'{ativo1}USD'.upper()
                lado    = teste[1]
                entrada = float(teste[2])
                entrada = round(entrada,2)
                alvo    = float(teste[3])
                alvo    = round(alvo,2)
                stop    = float(teste[4])
                stop    = round(stop,2)

                print(f'Ativo: {ativo1}')
                print(f"Lado: {lado}")
                print(f"Entrada: {entrada}")
                print(f"Alvo: {alvo}")
                print(f"Stop: {stop}""\n")

                OrdemVenda(ativo1,entrada,alvo,stop)

    except:
        print("Sem entrada válida. Retornando e aguardando próxima entrada""\n")
        return


bot = telepot.Bot('00000')
MessageLoop(bot, handle).run_as_thread()
print ('Listening ...')


# Keep the program running.
while 1:
    sleep(10)








