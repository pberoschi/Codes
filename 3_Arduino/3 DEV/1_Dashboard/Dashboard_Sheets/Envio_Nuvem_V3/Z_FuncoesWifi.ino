void enviarMedicao()
{
  int tensao = random(380,400);
  int corrente = random(80,98);
  int potencia = random(5500,7800);
   
  HTTPClient http;

  String url = String("https://script.google.com") + "/macros/s/" + GScriptId + "/exec?" + "value1=" + tensao + "&value2=" + corrente + "&value3=" + potencia;
  
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
