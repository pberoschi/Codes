


# --- ORDENS A MERCADO e PENDENTES--- #

import sys
from time import sleep
import telepot
from telepot.loop import MessageLoop
import MetaTrader5 as mt5
import time
# import Forex_Espelho

dados = open('C:\\Users\\johnn\\Google Drive\\Pessoal\\1_Programacao\\Python Scripts\\Dados\\ZeroMarkets_dados.txt', 'r', encoding='utf-8')
leitura = dados.readlines()

login       = int(leitura[0])
server      = leitura[1]
password    = leitura[2]

# print(f'Usuário: {usuario}'.strip())
# print(f'Senha: {senha}')


dados.close()



# exibimos dads sobre o pacote MetaTrader5
print("MetaTrader5 package author: ",mt5.__author__)
print("MetaTrader5 package version: ",mt5.__version__)
 
# estabelecemos a conexão com o terminal MetaTrader 5 para a conta especificada
if not mt5.initialize(path="C:\\Program Files\\Zero Markets MetaTrader 5 Terminal\\terminal64.exe",login=135022988, server="ZeroMarkets-Demo-1", password=password):
# if not mt5.initialize(path="C:\\Program Files\\Zero Markets MetaTrader 5 Terminal\\terminal64.exe",login=login, server=server, password=password):
    print("initialize() failed, error code =",mt5.last_error())
    quit()
 
# imprimimos informações sobre o estado da conexão, o nome do servidor e a conta de negociação
print(mt5.terminal_info())
# imprimimos informações sobre a versão do MetaTrader 5
print(mt5.version())
 
# concluímos a conexão ao terminal MetaTrader 5
mt5.shutdown()





