void alea_testes()
{    
  // ------------------------------------------------------ (TESTES // Gerador de números aleatórios)-------//    
  int tensao_R         = random(200,202);
  int corrente_R       = random(80,98);

   Serial.println(tensao_R);
  //  delay(100);
  

// -------------------------------------------- ENVIO PARA O SHEETS --------------------------------------------- 
  HTTPClient http;
  String url = String("https://script.google.com") + "/macros/s/" + GScriptId + "/exec?" 
                + "value1="  + tensao_R
                + "&value2=" + corrente_R; 
              

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
