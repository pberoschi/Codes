void alea_nivel(){
  
  // Testes com numeros aleatórios     
  int read_percent_R         = random(0,100);
  int analog_value_R         = random(0,4095);
  read_percent = read_percent_R * (ref_percent / adc_intervals);
  analog_value = analog_value_R;
  read_percent = int(read_percent);


  Serial.println("Leitura de Nível enviada");
  delay(100);
  // Serial.println(read_percent);
  // Serial.println(analog_value);
  

  HTTPClient http;
  String url = String("https://script.google.com") + "/macros/s/" + GScriptId_nivel + "/exec?" 
                + "value20="    + read_percent
                + "&value21="   + analog_value;

  Serial.print("Making a request");
  http.begin(url.c_str()); //Specify the URL and certificate
  http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
  int httpCode = http.GET();
  String payload;
  if (httpCode > 0) { //Check for the returning code
    payload = http.getString();
    Serial.println(httpCode);
    Serial.println(payload);
  }
  else {
    Serial.println("Error on HTTP request");
  }
  http.end();

}