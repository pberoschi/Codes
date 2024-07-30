void enviarMedicao()
{  
  //Print the custom address of the PZEM
  //Serial.print("Custom Address:");
  //Serial.println(pzem.readAddress(), HEX);

  // Read the data from the sensor

  int tensao = pzem.voltage();
  float corrente = pzem.current();
  float potenciaW = pzem.power();                    // ---> Números FRACIONADOS
  float energia = pzem.energy();
  int frequencia = pzem.frequency();
  float fp = pzem.pf() / 100.0;

  // // Check if the data is valid
  // if(isnan(tensao)){
  //     Serial.println("Error reading voltage");
  // } else if (isnan(corrente)) {
  //     Serial.println("Error reading current");
  // } else if (isnan(potenciaW)) {
  //     Serial.println("Error reading power");
  // } else if (isnan(energia)) {
  //     Serial.println("Error reading energy");
  // } else if (isnan(frequencia)) {
  //     Serial.println("Error reading frequency");
  // } else if (isnan(fp)) {
  //     Serial.println("Error reading power factor");
  //  } 

  // // ---------------------------------------------------------------------------------------------------//
  // else {

      // Print the values to the Serial console
      Serial.print("Voltage: ");      Serial.print(tensao);      Serial.println("V");
      Serial.print("Current: ");      Serial.print(corrente);      Serial.println("A");
      Serial.print("Power: ");        Serial.print(potenciaW);        Serial.println("W");
      Serial.print("Energy: ");       Serial.print(energia,3);     Serial.println("kWh");
      Serial.print("Frequency: ");    Serial.print(frequencia, 1); Serial.println("Hz");
      Serial.print("FP: ");           Serial.println(fp);

  //}

  Serial.println();
  delay(2000);

  // ---------------------------------------------------------------------------------------------------//    
  // int tensao = random(380,400);
  // int corrente = random(80,98);
  // int potenciaW = random(5500,7800);              // ----> TESTES --- (Gerador de números aleatórios)
  // int energia = random(1080,1098);
  // int frequencia = random(57,60);
  // float fp = random(92,98) / 100.0;
  // ---------------------------------------------------------------------------------------------------// 


  // ---------ENVIO PARA O SHEETS------------------------------------------------------------------------------------------// 

  HTTPClient http;

  String url = String("https://script.google.com") + "/macros/s/" + GScriptId + "/exec?" 
                + "value1=" + tensao 
                + "&value2=" + corrente 
                + "&value3=" + potenciaW
                + "&value4=" + energia
                + "&value5=" + frequencia
                + "&value6=" + fp; 

  Serial.print("Making a request");
  http.begin(url.c_str()); //Specify the URL and certificate
  http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
  int httpCode = http.GET();
  String payload;
  if (httpCode > 0) { //Check for the returning code
    payload = http.getString();

    Serial.println(httpCode);
    Serial.println(payload);
    //     testdrawstyles(payload);
    //if (httpCode == 200 or httpCode == 201) tempPing.Saida(0);
  }
  else {
    Serial.println("Error on HTTP request");
  }
  http.end();
  
}
