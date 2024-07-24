for numero in range(1, 11):
    if numero == 6:
        break
    else:
        print(numero)
print('saiu do loop')



# print(f"Seja muito bem-vindo {nome.title()}. No nosso sistema, consta que você em {2020 - idade}!")

senha = input('Cadastre sua senha ')
print(f'A senha {senha} foi cadastrada com sucesso!')

while True:
    acesso = input('Digite SENHA, para ENTRAR no sistema: ')
    if acesso == senha:
        print('ACESSO LIBERADO!')
        break



