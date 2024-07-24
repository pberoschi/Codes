#dados = open('C:\\Users\\johnny\\Google Drive\\Pessoal\\Programacao\\Python Scripts\\dados.txt', 'r', encoding='utf-8')
dados = open('C:\\Users\johnn\\Google Drive\\Pessoal\\1_Programacao\\Python Scripts\\dados.txt', 'r', encoding='utf-8')
leitura = dados.readlines()

usuario = leitura[0]
senha = leitura[1]

print(f'Usuário: {usuario}'.strip())
print(f'Senha: {senha}')



dados.close()