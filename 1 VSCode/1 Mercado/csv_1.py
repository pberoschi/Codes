import csv
ficheiro = open('C:\\Users\\johnn\\Desktop\\listaProntaCSV.csv', 'r')

bandas = ficheiro.readlines()

for banda in bandas:
    banda = f'*{banda}*'.rstrip('\n')
    print(banda.strip('\n'))

ficheiro.close
#rstrip('\\n')