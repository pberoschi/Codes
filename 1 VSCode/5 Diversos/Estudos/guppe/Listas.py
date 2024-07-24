'''
num = 24
if num in lista4:
    print(f'Encontrei o número {num}')
else:
    print(f'Infelizmente não encontrei o número {num}')




letra = 'a'
if letra in lista2:
    print('Encontrei')
else:
    print('Não encontrei nada')


print(lista5)
lista5.sort()
print(lista5)

print(lista1.count(89))
print(lista5.count('n'))


print(lista1)
lista1.insert(76)
print(lista1)
print(len(lista1))


aluno = 'johnny gomes barbosa filho'
print(aluno)
aluno2 = aluno.split()
print(aluno2)

________________________________________________________________________________
carrinho = []
produto = ''

while produto != 'sair':
    print("Adicione um produto no carrinho ou digite 'SAIR' se desejar sair")
    produto = input()
    if produto != 'sair':
        carrinho.append(produto)

for produto in carrinho:
    print(produto)
print('Agradecemos a preferência. Volte sempre!')

______________________________________________
print(lista1[1::2])

print(sum(lista1))
print(max(lista1))
print(min(lista1))
print(len(lista1))

_______________________________________________________

'''

type([])
nome = ['johnny', 'bala']
lista1 = [1, 3, 5, 89, 45, 89, 56, 34, 21]
lista2 = ['j','o','h','n','n','y']
lista3 = []
lista4 = list(range(11))
lista5 = list('johnny bala')


listaNOVA = lista1.copy()
print(listaNOVA)

listaNOVA.append(345)

print(lista1)
print(listaNOVA)






