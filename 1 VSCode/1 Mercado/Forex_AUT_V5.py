


# --- ORDENS A MERCADO e PENDENTES- CONTA ZERO MARKETS-- #

import sys
from time import sleep
import telepot
from telepot.loop import MessageLoop
import MetaTrader5 as mt5
import time
# import Forex_Espelho

Gain = int(3)
Loss = int(3)

# BUSCAR DADOS SENSIVEIS EM ARQUIVO TXT #
dados = open('C:\\Users\\johnn\\Google Drive\\Pessoal\\1_Programacao\\Python Scripts\\Dados\\ZeroMarkets_dados.txt', 'r', encoding='utf-8')
leitura = dados.readlines()
login       = int(leitura[0])
server      = leitura[1]
password    = leitura[2]
dados.close()


# bot = telepot.Bot('0000000')
bot = telepot.Bot('000000')
chat_id = 984798692

#if not mt5.initialize(login=50717088, server="ICMarketsSC-Demo", password=""):
if not mt5.initialize(path="C:\\Program Files\\Zero Markets MetaTrader 5 Terminal\\terminal64.exe",login=135022988, server="ZeroMarkets-Demo-1", password=password):
# if not mt5.initialize(login=135022402, server="ZeroMarkets-Demo-1", password=""):
    print("initialize() failed, error code =",mt5.last_error())
    quit()

def CompraMercado():    
    symbol = 'XAUUSD.r'
    lot = 0.01
    price = mt5.symbol_info_tick(symbol).ask
    desviation = 1
    request = {
        "action": mt5.TRADE_ACTION_DEAL,
        "symbol": symbol,
        "volume": lot,
        "type": mt5.ORDER_TYPE_BUY,
        "price": price,
        "sl": price - Loss,
        "tp":price + Gain,
        "magic": 234000,
        "comment": "Compra via python",
        "type_time": mt5.ORDER_TIME_DAY,
        # "type_filling": mt5.ORDER_FILLING_RETURN,
        "type_filling": mt5.ORDER_FILLING_IOC,
    }
    result = mt5.order_send(request) 
    result
    print(result.comment)

    if result.comment == 'Requote':
        print('Ordem não-executada. Fazendo nova tentativa...')
        tele('Ordem não-executada. Fazendo nova tentativa...')
        tele(result.comment)
        CompraMercado()
    else:
        print('COMPRA executada com sucesso')     
        # bot.sendMessage(chat_id, f'COMPRA A MERCADO de XAUUSD executada com sucesso')
        tele('COMPRA A MERCADO de XAUUSD executada com sucesso via python')    

        sleep(180)


def VendaMercado():
    symbol = 'XAUUSD.r'
    lot = 0.01
    price=mt5.symbol_info_tick(symbol).bid
    request = {
        "action": mt5.TRADE_ACTION_DEAL,
        "symbol": symbol,
        "volume": lot,
        "type": mt5.ORDER_TYPE_SELL,
        "price": price,
        "sl": price + Loss,
        "tp":price - Gain,
        "magic": 234000,
        "comment": "Venda via python",
        "type_time": mt5.ORDER_TIME_DAY,
        # "type_filling": mt5.ORDER_FILLING_RETURN,
        "type_filling": mt5.ORDER_FILLING_IOC,
    }
    result = mt5.order_send(request)
    print(result.comment) 
    result

    if result.comment == 'Requote':
        print('Ordem não-executada. Fazendo nova tentativa...')
        tele('Ordem não-executada. Fazendo nova tentativa...')
        tele(result.comment)
        VendaMercado()
    else:
        print('VENDA executada com sucesso')
        # bot.sendMessage(chat_id, f'VENDA A MERCADO de XAUUSD executada com sucesso')
        tele('VENDA A MERCADO de XAUUSD executada com sucesso via python')
        
        sleep(180)
        

def CompraPendente(entrada):    
    symbol = 'XAUUSD.r'
    lot = 0.01
    price = entrada
    price = price + 2
    desviation = 1
    request = {
        "action": mt5.TRADE_ACTION_PENDING,
        "symbol": symbol,
        "volume": lot,
        "type": mt5.ORDER_TYPE_BUY_LIMIT,
        "price": price,
        "sl": price - Loss,
        "tp":price + Gain,
        "magic": 234000,
        "comment": "Compra via python",
        "type_time": mt5.ORDER_TIME_DAY,
        # "type_filling": mt5.ORDER_FILLING_RETURN,
        "type_filling": mt5.ORDER_FILLING_IOC,
    }
    result = mt5.order_send(request) 
    # print(result.comment)
    result

    # if result.comment == 'Requote':
    if result.comment != 'Request executed':
        print('Ordem PENDENTE não-executada. Fazendo nova tentativa...')
        tele('Ordem PENDENTE não-executada. Fazendo nova tentativa...')
        tele(result.comment)
        sleep(5)
        
        # CompraMercado()
        CompraPendente(entrada)

    else:
        print('COMPRA PENDENTE executada com sucesso')     
        # bot.sendMessage(chat_id, f'COMPRA PENDENTE de XAUUSD executada com sucesso')
        tele('COMPRA PENDENTE de XAUUSD executada com sucesso via python')
        
        # sleep(180)


def VendaPendente(entrada):
    symbol = 'XAUUSD.r'
    lot = 0.01
    price=entrada
    price = price - 2
    request = {
        "action": mt5.TRADE_ACTION_PENDING,
        "symbol": symbol,
        "volume": lot,
        "type": mt5.ORDER_TYPE_SELL_LIMIT,
        "price": price,
        "sl": price + Loss,
        "tp":price - Gain,
        "magic": 234000,
        "comment": "Venda via python",
        "type_time": mt5.ORDER_TIME_DAY,
        # "type_filling": mt5.ORDER_FILLING_RETURN,
        "type_filling": mt5.ORDER_FILLING_IOC,
    }
    result = mt5.order_send(request) 
    print(result.comment)
    result

    # if result.comment == 'Requote':
    if result.comment != 'Request executed':
        print('Ordem PENDENTE não-executada. Fazendo nova tentativa...')
        tele('Ordem PENDENTE não-executada. Fazendo nova tentativa...')
        tele(result.comment)
        sleep(5)

        # VendaMercado()
        VendaPendente(entrada)

    else:
        print('VENDA PENDENTE executada com sucesso')
        # bot.sendMessage(chat_id, f'VENDA PENDENTE de XAUUSD executada com sucesso')
        tele('VENDA PENDENTE de XAUUSD executada com sucesso via python')
        
        sleep(180)

def tele(mensagem):
    bot.sendMessage(chat_id,mensagem)

# AUTOMATICO MADRUGADA #
def handle(msg):                                                            
    content_type, chat_type, chat_id = telepot.glance(msg)  
    try:      
        if content_type == 'text':        
            modo = (msg['text'])
            # print(f'Modo: {modo}')
            # teste = modo.split()
            # print(f'Modo: {modo}')

            if modo.count('\n') == 0:
                teste = modo.split()
                teste[0] = teste[0].upper()
                teste[1] = teste[1].upper()
                # print(teste[0],teste[1])

                # >>> --- COMPRAS --- <<<

                if teste[0] == 'GOLD' and teste[1] == 'BUY':
                    # CompraMercado() 
                    print('Acionado a compra A MERCADO') 

                elif teste[0] == 'BUY' and teste[1] == 'GOLD':
                    # CompraMercado() 
                    print('Acionado a compra A MERCADO')
                
                elif teste[0] == 'XAUUSD' and teste[1] == 'BUY':
                    # CompraMercado() 
                    print('Acionado a compra A MERCADO')

                elif teste[0] == 'BUY' and teste[1] == 'XAUUSD':
                    # CompraMercado() 
                    print('Acionado a compra A MERCADO')



                # >>> --- VENDAS --- <<<

                elif teste[0] == 'GOLD' and teste[1] == 'SELL':
                    # VendaMercado() 
                    print('Acionado a venda A MERCADO') 

                elif teste[0] == 'SELL' and teste[1] == 'GOLD':
                    # VendaMercado() 
                    print('Acionado a venda A MERCADO')

                elif teste[0] == 'XAUUSD' and teste[1] == 'SELL':
                    # VendaMercado() 
                    print('Acionado a venda A MERCADO') 

                elif teste[0] == 'SELL' and teste[1] == 'XAUUSD':
                    # VendaMercado() 
                    print('Acionado a venda A MERCADO')



            else:
                # teste = modo.uuper()
                teste = modo.split('\n\n')
                # print(f'teste: {teste}')

                teste1 = teste[0].split()
                ativo = teste1[0].upper()
                lado = teste1[1].upper()

                testeIN = teste[0].split('-')
                testeIN = testeIN[1]
                testeIN = testeIN[0:]
                testeIN = float(testeIN)
                testeIN = round(testeIN,2)
                entrada = testeIN
                # print(ativo,lado,entrada)
                # print(f'teste1: {testeIN}')

                # --- COMPRAS ---

                if ativo == 'GOLD' and lado== 'BUY':
                    bot.sendMessage(chat_id, f'Preço IN: {entrada}')
                    print(f'Preço IN: {entrada}')
                    CompraPendente(testeIN)
                    print('Acionado a compra PENDENTE')                     

                elif ativo == 'BUY' and lado== 'GOLD':
                    bot.sendMessage(chat_id, f'Preço IN: {entrada}')
                    print(f'Preço IN: {entrada}') 
                    CompraPendente(testeIN)
                    print('Acionado a compra PENDENTE')
                     
                elif ativo == 'XAUUSD' and lado== 'BUY':
                    bot.sendMessage(chat_id, f'Preço IN: {entrada}')
                    print(f'Preço IN: {entrada}')
                    CompraPendente(testeIN)
                    print('Acionado a compra PENDENTE') 

                elif ativo == 'BUY' and lado== 'XAUUSD':
                    bot.sendMessage(chat_id, f'Preço IN: {entrada}')
                    print(f'Preço IN: {entrada}')
                    CompraPendente(testeIN)
                    print('Acionado a compra PENDENTE')

                
                # --- VENDAS ---#

                elif ativo == 'GOLD' and lado== 'SELL':
                    bot.sendMessage(chat_id, f'Preço IN: {entrada}')
                    print(f'Preço IN: {entrada}')
                    VendaPendente(testeIN)
                    print('Acionado a venda PENDENTE')  

                elif ativo == 'SELL' and lado== 'GOLD':
                    bot.sendMessage(chat_id, f'Preço IN: {entrada}')
                    print(f'Preço IN: {entrada}')
                    VendaPendente(testeIN)
                    print('Acionado a compra PENDENTE') 

                elif ativo == 'XAUUSD' and lado== 'SELL':
                    bot.sendMessage(chat_id, f'Preço IN: {entrada}')
                    print(f'Preço IN: {entrada}')
                    VendaPendente(testeIN)
                    print('Acionado a venda PENDENTE') 

                elif ativo == 'SELL' and lado== 'XAUUSD':
                    bot.sendMessage(chat_id, f'Preço IN: {entrada}')
                    print(f'Preço IN: {entrada}')
                    VendaPendente(testeIN)
                    print('Acionado a compra PENDENTE')


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









