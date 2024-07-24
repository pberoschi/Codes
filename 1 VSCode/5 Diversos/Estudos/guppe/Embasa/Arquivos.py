
import os
import sys
#print(a, os.listdir('C:\\Users\\johnn\\Documents\\1_Teocracia\\'+a2))

'''
Cidades = next(os.walk("C:\\Users\\johnn\\Documents\\1_Teocracia"))[1]
#Cidades = next(os.walk("C:\\Users\\johnn\\Documents\\1_Teocracia")

for a in Cidades:
    #print(f'Pasta {a}: {len(a)} arquivos')
    print(a, len(os.listdir('C:\\Users\\johnn\\Documents\\1_Teocracia\\' + a)))
'''
'''

Cidades = next(os.walk("C:\\Users\\johnn\\Documents\\1_Teocracia"))[1]
#Cidades = next(os.walk("C:\\Users\\johnn\\Documents\\1_Teocracia")

arquivo = open('teste.txt', 'w')

for a in Cidades:
    #print(f'Pasta {a}: {len(a)} arquivos')
    mania = a, len(os.listdir('C:\\Users\\johnn\\Documents\\1_Teocracia\\' + a))
    arquivo.write(f'{mania}\n\n')
    print(mania)
arquivo.close()
'''

Cidades = next(os.walk("C:\\Users\\johnn\\Documents\\1_Teocracia"))[1]
Cidades2 = next(os.walk("C:\\Users\\johnn\\Documents\\1_Teocracia"))[2]
#del(Cidades[0:2])
teste2 = 'C:\\Users\\johnn\\Documents\\1_Teocracia\\'

'''
for aa in Cidades:
    for bb in ([f'\n{aa.upper()}'], (os.listdir(teste2 + aa))):
        for cc in bb:
           print(cc)
    #print(f'{aa}: {len(bb)} itens\n')
'''
arquivo = open('teste.txt', 'w')
for aa in Cidades:
    for bb in ([f'\n{aa.upper()}'], (os.listdir(teste2 + aa))):
        for cc in bb:
            arquivo.write(f'{cc}\n')
    arquivo.write(f'*** {aa}: {len(bb)} itens ***\n')
arquivo.close()


