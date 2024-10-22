# import tabula

# caminho = 'C:/Users/Johnny/Downloads/Fatura.pdf'

# lista_tabelas = tabula.read_pdf(caminho, pages="all")
# print(len(lista_tabelas))


import pandas as pd
import os.path


f = ("C:\\Users\\Johnny\\Documents\\1_DEV\\Codes\\1 VSCode\\5 Diversos\\Estudos\\Teste.xlsx")
    # pandas.read_excel(f)

df = pd.read_excel(f)

df.head()