# print('Qual é o seu nome?')
# nome = input()

nome = input('Qual seu nome? ')

# print('Qual é a sua idade?')
# idade = input()

# idade = input('Qual é a sua idade? ')

idade = int(input('Qual é a sua idade? '))


# print('Seja bem-vindo(a) {0}, {1} anos'.format(nome.upper(), idade))

# print(f'Seja muito bem-vindo {nome.title()}. No nosso sistema, consta que você tem {idade} anos!')

# print(f'Seja muito bem-vindo {nome.title()}. No nosso sistema, consta que você em {2020 - int (idade)}!')

print(f"Seja muito bem-vindo {nome.title()}. No nosso sistema, consta que você em {2020 - idade}!")
