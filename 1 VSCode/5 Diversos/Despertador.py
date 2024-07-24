#https://academiahopper.com.br/como-trabalhar-com-data-e-hora-em-python/

import datetime as dt
import time

#print(dt.datetime.now())

hora_string = input("Que horas quer acordar? (hh:mm): ")

hora = int(hora_string.split(':')[0])
minuto = int(hora_string.split(':')[1])

def esta_na_hora(hora, minuto, hora_atual):
  if hora_atual.hour == hora and hora_atual.minute == minuto:
    return True
  return False


  dias_da_semana = dia_da_semana_string.split(' ')

  def processar_dias_da_semana(dias_da_semana_string):
    dias_da_semana = []
    for dia in dias_da_semana_string:
        if dia == "seg":
            dias_da_semana.append(0)
        if dia == "ter":
            dias_da_semana.append(1)
        if dia == "qua":
            dias_da_semana.append(2)
        if dia == "qui":
            dias_da_semana.append(3)
        if dia == "sex":
            dias_da_semana.append(4)
        if dia == "sab":
            dias_da_semana.append(5)
        if dia == "dom":
            dias_da_semana.append(6)

    return dias_da_semana

dia_da_semana_string = input("Que dias da semana? (seg ter qua qui sex sab dom): ")
dias_da_semana = dia_da_semana_string.split(' ')
dias_da_semana_int = processar_dias_da_semana(dias_da_semana)

def esta_no_dia_da_semana(dias_desejados, data_atual):
  if data_atual.weekday() in dias_desejados:
    return True
  return False

while True:
	# lógica para despertar
   time.sleep(60)

while True:
  now = datetime.datetime.now()

  if esta_na_hora(hora, minuto, now) and esta_no_dia_da_semana(dias_da_semana_int, now):
    print("ACORDAR")

  time.sleep(60)