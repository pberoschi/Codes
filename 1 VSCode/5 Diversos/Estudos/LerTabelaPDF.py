import tabula

caminho = 'C:/Users/Johnny/Downloads/Fatura.pdf'

lista_tabelas = tabula.read_pdf(caminho, pages="all")
print(len(lista_tabelas))