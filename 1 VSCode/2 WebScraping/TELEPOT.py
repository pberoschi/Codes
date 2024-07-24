#https://www.youtube.com/watch?v=2TCkaJdcicQ&t=264s

import telepot

mensagem = '2021-04-05;Por que é bom fazer atividades criativas?;https://www.jw.org/pt/ensinos-biblicos/familia/atividades-criativas/'

# bot alertas_SupResBOT:
#bot = telepot.Bot('5026686955:AAHvm0rJOf-_nSCi8sOHYVMhY8zPCBEd73k')
#bot.sendMessage(984798692, mensagem) 

# grupo Operações_2
bot = telepot.Bot('5026686955:AAHvm0rJOf-_nSCi8sOHYVMhY8zPCBEd73k')
bot.sendMessage(-1001778706191, f'ESTRATÉGIA ROMPIMENTO 1H: COMPRA PARA >> {mensagem} <<')


info = bot.getUpdates()



print(info)