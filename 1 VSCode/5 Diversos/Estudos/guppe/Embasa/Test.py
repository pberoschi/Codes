import csv

with open('dados_industriais_escrito.csv', 'w', newline='') as file:
    writer = csv.writer(file)

    writer.writerow(["Pressao", "Temperatura", "Umidade"])
    writer.writerow([15.6, 20.1, 30.3])
    writer.writerow([16.3, 19.8, 27.1])
    writer.writerow([15.3, 20.2, 28.3])
    writer.writerow([16.1, 20.5, 27.7])
    writer.writerow([15.8, 19.7, 29.3])