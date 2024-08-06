/*

void EnvioMedia() {

  float accuml = 0;

  Serial.println("Levantando dados...");

  for (int x = 0; x < 10; x++)
  {
    vazao = random(0, 100);
    accuml = accuml + vazao;
    delay(1000);
  }

  float media = accuml / 10;

  Serial.print("Acumulado: ");
  Serial.println(accuml);
  Serial.print("Média: ");
  Serial.println(media);
  Serial.println();
  //delay(10000);


  if (media <= 50) {

    if (client.connect("docs.google.com", 443) == 1)
    {
      String toSend = textFix;
      toSend += "entry.655168320=";
      toSend += media;
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



*/
