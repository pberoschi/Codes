void alea_testes()
{    
  // ------------------------------------------------------ (TESTES // Gerador de números aleatórios)-------//    
  int tensao_R         = random(380,400);
  int corrente_R       = random(80,98);
  int potencia_R       = random(5500,7800);              
  int consumo_R        = random(1080,1098);
  int frequencia_R     = random(57,60);
  float fp_R           = random(92,98) / 100.0;

   Serial.println("Dados FASE R enviados");
   delay(100);
  // -------------------------------------------------------------------------------------------------------// 

  // ------------------------------------------------------ (TESTES // Gerador de números aleatórios)-------//    
  int tensao_S         = random(380,400);
  int corrente_S       = random(80,98);
  int potencia_S      = random(5500,7800);       
  int consumo_S        = random(1080,1098);
  int frequencia_S     = random(57,60);
  float fp_S           = random(92,98) / 100.0;
    
   Serial.println("Dados FASE S enviados");
   delay(100);
  // -------------------------------------------------------------------------------------------------------// 

  // ------------------------------------------------------ (TESTES // Gerador de números aleatórios)-------//    
  int tensao_T         = random(380,400);
  int corrente_T       = random(80,98);
  int potencia_T       = random(5500,7800);             
  int consumo_T        = random(1080,1098);
  int frequencia_T     = random(57,60);
  float fp_T           = random(92,98) / 100.0;
    
   Serial.println("Dados FASE T enviados");
   delay(100);
  // -------------------------------------------------------------------------------------------------------// 

  // ------------------------------------------------------ (TESTES // Gerador de números aleatórios para o status dos CMB's)-------//
  
  int Bomba = 0;
  Bomba = random(0,3);
  Serial.println(Bomba);




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
                + "&value18=" + fp_T

                + "&value19=" + Bomba;


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
