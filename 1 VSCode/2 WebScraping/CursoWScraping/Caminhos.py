import os
import os.path


lista1 = os.listdir('d:\Arquivos_2020')
lista2 = os.listdir('c:\\Users\\johnn\\Documents\\Python\\teste')
listaSoma = lista1 + lista2

#for a in os.listdir('d:\Arquivos_2020'):
#    print(a)

arquivo = open('teste.txt', 'w')
arquivo.write(f'{listaSoma}')
arquivo.write('teste')
#arquivo.write(f'{lista1}')
arquivo.close()
print(len(listaSoma))















'''
cwd = os.getcwd()
print(cwd)
'''