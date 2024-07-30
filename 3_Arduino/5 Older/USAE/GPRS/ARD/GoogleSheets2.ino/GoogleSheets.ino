void googlesheets() {


  
  
  if (vazao <= 100) {

    
    if (client.connect("docs.google.com", 443) == 1)
    {
      String toSend = textFix;
      toSend += "entry.655168320=";
      toSend += vazao;
      toSend += "&";
      toSend += "entry.953075015=";
      toSend += batMCU;
      toSend += "&";
      toSend += "entry.573564729=";
      toSend += batMOD;
      toSend += "&submit=Submit HTTP/1.1";

      client.println(toSend);
      client.println("Host: docs.google.com");
      client.println();
      client.stop();
      Serial.println("Dados enviados.");
    }
    else
    {
      Serial.println("Erro ao se conectar");
    }

    delay(5000);
  }
}
