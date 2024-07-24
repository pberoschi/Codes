nome = 'Geek University'
nome2 = 'johnny bala souza'
lista = [1, 3, 5, 7, 9]
numeros = range(1, 10)

for letra in nome:
    print(letra)

for numero in lista:
    print(numero)


for numero in range(1, 10):
    print(numero)


for valor in enumerate(nome2):
    print(valor)


qtd = int(input('Quantas vezes rodar o loop? '))

for n in range(1, qtd+1):
    print(f'imprimindo {n}')

for letra in nome:
    print(letra, end='' )

# tabela com emojis: https://apps.timwhitlock.info/emoji/tables/unicode
for _ in range(3):
    for num in range(1, 11):
        print('\U0001f602' * num)
