import pandas as pd

url_dados = 'https://github.com/alura-cursos/imersaodados3/blob/main/dados/dados_experimentos.zip?raw=true'

dados = pd.read_csv(url_dados, compression = 'zip')

#print(dados)

#print(dados['tempo'].unique())

print(dados['tratamento'].value_counts())