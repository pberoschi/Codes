# # --- ORDENS PENDENTES --- #

# import sys
# from time import sleep
# import telepot
# from telepot.loop import MessageLoop
# import MetaTrader5 as mt5
# import time
# # import Forex_Espelho

# #if not mt5.initialize(login=50717088, server="ICMarketsSC-Demo", password=""):
# if not mt5.initialize(login=82491017, server="MetaQuotes-Demo", password="V+1dHiKp"):
#     print("initialize() failed, error code =",mt5.last_error())
#     quit()

# def OrdemCompra(entrada,tp,sl):   
#     symbol = 'XAUUSD'
#     lot = 0.1
#     request = {
#         "action": mt5.TRADE_ACTION_PENDING,
#         "symbol": symbol,
#         "volume": lot,
#         "type": mt5.ORDER_TYPE_BUY_LIMIT,
#         "price": entrada,
#         "sl": sl,
#         "tp":tp,
#         "magic": 234000,
#         "comment": "Compra via python",
#         "type_time": mt5.ORDER_TIME_GTC,
#         "type_filling": mt5.ORDER_FILLING_RETURN,
#     }
#     mt5.order_send(request)
#     print("Compra via python executada")


# def OrdemVenda(entrada,tp,sl):
#     symbol = 'XAUUSD'
#     lot = 0.1
#     request = {
#         "action": mt5.TRADE_ACTION_PENDING,
#         "symbol": symbol,
#         "volume": lot,
#         "type": mt5.ORDER_TYPE_SELL_LIMIT,
#         "price": entrada,
#         "sl": sl,
#         "tp":tp,
#         "magic": 234000,
#         "comment": "Venda via python",
#         "type_time": mt5.ORDER_TIME_GTC,
#         "type_filling": mt5.ORDER_FILLING_RETURN,
#     }
#     # mt5.order_send(request)
#     print("Venda via python executada")


# # AUTOMATICO MADRUGADA #
# def handle(msg):                                                            
#     content_type, chat_type, chat_id = telepot.glance(msg)  
#     try:      
#         if content_type == 'text':        
#             modo = (msg['text'])
#             # teste = modo.split()
#             # print(teste)          
            
#             teste = modo.replace('\n\n','\n')
#             teste = teste.split('\n')
#             # print(teste)
#             # print(teste[0])
#             # print(teste[1])
#             # print(teste[2])

#             # ativo
#             if teste[0]:
#                 ativo = teste[0].upper()
#                 ativo = ativo.split()
#                 ativo = ativo[0]
#                 print(f'Ativo: {ativo}') 

#             # direcao
#             if teste[0]:
#                 direcao = teste[0].upper()
#                 direcao = direcao.split()
#                 direcao = direcao[1]
#                 print(f'Direcao: {direcao}') 

#             # entrada
#             entrada = teste[0]
#             entrada = entrada[-4:]
#             entrada = float(entrada)
#             entrada = round(entrada,2)
#             print(f'Entrada: {entrada}')
   
#             # Loss
#             # if teste[1]:
#             loss = teste[1]
#             loss = loss[-4:]
#             loss = float(loss)
#             loss = round(loss,2)
#             print(f'Stop: {loss}')

            
#             # else:
#             #     print('Sem Loss conhecido...')
#             #     if direcao == 'BUY':
#             #         loss = entrada - 5
#             #         print(f'Stop: {loss}')
#             #     elif direcao == 'SELL':
#             #         loss == entrada + 5
#             #         print(f'Stop: {loss}')

#             # gain
#             # if teste[2]:
#             print(teste[2])
#             gain = teste[2]
#             gain = gain[-4:]
#             gain = float(gain)
#             gain = round(gain,2)
#             print(f'Gain: {gain}')
#             # else:
#             #     print('Sem Gain conhecido...')




                       
#             # if teste[0] == 'XAUUSD' and teste[1] == 'BUY':
#             #     compra()
#             # elif teste[0] == 'GOLD' and teste[1] == 'BUY':
#             #     compra()
#             # elif teste[0] == 'BUY' and teste[1] == 'GOLD':
#             #     compra()
#             # elif teste[0] == 'BUY' and teste[1] == 'XAUUSD':
#             #     compra()
                
                
                
                
    
#         # elif teste[1] == 'SELL':
#         #     lado        = teste[1]
#         #     entrada     = teste[3]
#         #     entrada     = entrada[-4:]
#         #     entrada     = float(entrada)
#         #     entrada     = round(entrada,2)
#         #     alvo        = float(teste[6])
#         #     alvo        = round(alvo,2)
#         #     stop        = float(teste[11])
#         #     stop        = round(stop,2)

#         #     print(f"Lado: {lado}")
#         #     print(f"Entrada: {entrada}")
#         #     print(f"Alvo: {alvo}")
#         #     print(f"Stop: {stop}""\n")

#         #     OrdemVenda(entrada,alvo,stop)
#         #     # print('Venda acionada')



#         # def compra():
#         #     lado        = teste[1]
#         #     entrada     = teste[4]
#         #     entrada     = entrada.replace('('," ")
#         #     entrada     = float(entrada)
#         #     entrada     = round(entrada,2)
#         #     alvo        = float(teste[6])
#         #     alvo        = round(alvo,2)
#         #     stop        = float(teste[11])
#         #     stop        = round(stop,2)

#         #     print(f"Lado: {lado}")
#         #     print(f"Entrada: {entrada}")
#         #     print(f"Alvo: {alvo}")
#         #     print(f"Stop: {stop}""\n")

#         #     OrdemCompra(entrada,alvo,stop)
#         #     # print('Compra acionada')       

#     except:
#         print("Sem entrada válida. Retornando e aguardando próxima entrada""\n")
#         return



# bot = telepot.Bot('0000')
# MessageLoop(bot, handle).run_as_thread()
# print ('Listening ...')


# # Keep the program running.
# while 1:
#     sleep(1)
#     # print('teste')










