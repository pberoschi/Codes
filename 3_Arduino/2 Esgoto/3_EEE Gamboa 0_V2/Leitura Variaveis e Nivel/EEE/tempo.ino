void horario(){
  const String datafull = (ntp.getFormattedDate());
  const int hora = (ntp.getHours());
  const int minuto = (ntp.getMinutes());
  const int segundo = (ntp.getSeconds());

if (ntp.update()) {
    //Serial.print("DATA/HORA: ");
    //Serial.println(ntp.getFormattedDate());
    //Serial.print("HORARIO: ");
    //Serial.println(ntp.getFormattedTime());
    //Serial.print("HORA: ");
    //Serial.println(ntp.getHours());
    //Serial.print("MINUTOS: ");
    //Serial.println(ntp.getMinutes());
    //Serial.print("SEGUNDOS: ");
    //Serial.println(ntp.getSeconds());
    //Serial.print("DIA DA SEMANA (0=domingo): ");
    //Serial.println(ntp.getDay());
    //Serial.print("EPOCH TIME (Segundos desde 01/01/1970): ");
    //Serial.println(ntp.getEpochTime());

    Serial.println(datafull);
    //Serial.print(hora);
    //Serial.print(":");
    //Serial.print(minuto);
    //Serial.print(":");
    //Serial.print(segundo);
    //Serial.println();

    String(a) = String(hora);

    bot.sendMessage(CHAT_ID, "Horario Local:","");
    bot.sendMessage(CHAT_ID, datafull,"");
    //bot.sendMessage(CHAT_ID, a,"");


  } else {
    Serial.println("!Erro ao atualizar NTP!\n");
  }
  delay(1000);

}