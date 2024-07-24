
print(type({}))

paises = {'br': 'Brasil' , 'Eua': 'Estados Unidos' , 'py':'Paraguai'}
print(paises)
print(paises['py'])
print(paises['br'])
print(paises.get('Eua'))


'''
paises = {'br': 'Brasil' , 'Eua': 'Estados Unidos' , 'py':'Paraguai'}
pais = input('Qual é o país que deseja buscar? ')


    if pais:
        print(f'O {pais.title()} está em nosso banco de dados')
    else:
     print(f'Não encontrei o país {pais}')
'''