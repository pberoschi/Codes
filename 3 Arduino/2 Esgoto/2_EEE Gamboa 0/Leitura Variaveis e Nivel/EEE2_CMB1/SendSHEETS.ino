void sheets()
{    
//--------------------------------------------------> FASE R <--------------------------------------------------

  PZEM004Tv30 pzemR(Serial1, R_RX1, R_TX1); 
  
  int tensao_R      = pzemR.voltage();
  int corrente_R    = pzemR.current();
  int potencia_R    = pzemR.power();                    // ---> LEITURA DIRETA DO TRANSDUTOR <---
  int consumo_R     = pzemR.energy();
  int frequencia_R  = pzemR.frequency();
  int fp_R          = pzemR.pf() / 100.0;

    // Print the values to the Serial console
    Serial.print("Tensão_R: ");        Serial.print(tensao_R);           Serial.println("V");
    Serial.print("Corrente_R: ");      Serial.print(corrente_R);         Serial.println("A");
    Serial.print("Potencia_R: ");      Serial.print(potencia_R);         Serial.println("W");
    Serial.print("Consumo_R: ");       Serial.print(consumo_R,3);        Serial.println("kWh");
    Serial.print("Frequencia_R: ");    Serial.print(frequencia_R, 1);    Serial.println("Hz");
    Serial.print("FP_R: ");            Serial.println(fp_R);

  Serial.println();
  delay(100);

  // ------------------------------------------------------ (TESTES // Gerador de números aleatórios)-------//    
  // int tensao_R         = random(380,400);
  // int corrente_R       = random(80,98);
  // int potencia_R       = random(5500,7800);              
  // int consumo_R        = random(1080,1098);
  // int frequencia_R     = random(57,60);
  // float fp_R           = random(92,98) / 100.0;

  //  Serial.println("Dados FASE R enviados");
  //  delay(100);
  // -------------------------------------------------------------------------------------------------------// 


//--------------------------------------------------> FASE S <--------------------------------------------------

  PZEM004Tv30 pzemS(Serial1, S_RX2, S_TX2); 
  
  int tensao_S      = pzemS.voltage();
  int corrente_S    = pzemS.current();
  int potencia_S    = pzemS.power();                    // ---> LEITURA DIRETA DO TRANSDUTOR <---
  int consumo_S     = pzemS.energy();
  int frequencia_S  = pzemS.frequency();
  int fp_S          = pzemS.pf() / 100.0;

    // Print the values to the Serial console
    Serial.print("Tensão_S: ");        Serial.print(tensao_S);           Serial.println("V");
    Serial.print("Corrente_S: ");      Serial.print(corrente_S);         Serial.println("A");
    Serial.print("Potencia_S: ");      Serial.print(potencia_S);         Serial.println("W");
    Serial.print("Consumo_S: ");       Serial.print(consumo_S,3);        Serial.println("kWh");
    Serial.print("Frequencia_S: ");    Serial.print(frequencia_S, 1);    Serial.println("Hz");
    Serial.print("FP_S: ");            Serial.println(fp_S);

  Serial.println();
  delay(100);

  // ------------------------------------------------------ (TESTES // Gerador de números aleatórios)-------//    
  // int tensao_S         = random(380,400);
  // int corrente_S       = random(80,98);
  // int potencia_S      = random(5500,7800);       
  // int consumo_S        = random(1080,1098);
  // int frequencia_S     = random(57,60);
  // float fp_S           = random(92,98) / 100.0;
    
  //  Serial.println("Dados FASE S enviados");
  //  delay(100);
  // -------------------------------------------------------------------------------------------------------// 

//--------------------------------------------------> FASE T <--------------------------------------------------

  PZEM004Tv30 pzemT(Serial1, T_RX3, T_TX3); 
  
  int tensao_T      = pzemT.voltage();
  int corrente_T    = pzemT.current();
  int potencia_T    = pzemT.power();                    // ---> LEITURA DIRETA DO TRANSDUTOR <---
  int consumo_T     = pzemT.energy();
  int frequencia_T  = pzemT.frequency();
  int fp_T          = pzemT.pf() / 100.0;

    // Print the values to the Serial console
    Serial.print("Tensão_T: ");        Serial.print(tensao_T);           Serial.println("V");
    Serial.print("Corrente_T: ");      Serial.print(corrente_T);         Serial.println("A");
    Serial.print("Potencia_T: ");      Serial.print(potencia_T);         Serial.println("W");
    Serial.print("Consumo_T: ");       Serial.print(consumo_T,3);        Serial.println("kWh");
    Serial.print("Frequencia_T: ");    Serial.print(frequencia_T, 1);    Serial.println("Hz");
    Serial.print("FP_T: ");            Serial.println(fp_T);

  Serial.println();
  delay(100);

  // ------------------------------------------------------ (TESTES // Gerador de números aleatórios)-------//    
  // int tensao_T         = random(380,400);
  // int corrente_T       = random(80,98);
  // int potencia_T       = random(5500,7800);             
  // int consumo_T        = random(1080,1098);
  // int frequencia_T     = random(57,60);
  // float fp_T           = random(92,98) / 100.0;
    
  //  Serial.println("Dados FASE T enviados");
  //  delay(100);
  // -------------------------------------------------------------------------------------------------------// 


// -------------------------------------------- ENVIO PARA O SHEETS --------------------------------------------- 
  HTTPClient http;
  String url = String("https://script.google.com") + "/macros/s/" + GScriptId + "/exec?" 
                + "value1="  + tensao_R 
                + "&value2=" + corrente_R 
                + "&value3=" + potencia_R
                + "&value4=" + consumo_R
                + "&value5=" + frequencia_R
                + "&value6=" + fp_R 

                + "&value7="   + tensao_S 
                + "&value8="  + corrente_S
                + "&value9="  + potencia_S
                + "&value10=" + consumo_S
                + "&value11=" + frequencia_S
                + "&value12=" + fp_S

                + "&value13="  + tensao_T 
                + "&value14=" + corrente_T 
                + "&value15=" + potencia_T
                + "&value16=" + consumo_T
                + "&value17=" + frequencia_T
                + "&value18=" + fp_T;

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
