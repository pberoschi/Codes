void teleg()
{    
//--------------------------------------------------> FASE R <--------------------------------------------------

  PZEM004Tv30 pzemR(Serial1, R_RX1, R_TX1); 
  
  int   tensao_R      = pzemR.voltage();
  float corrente_R    = pzemR.current();
  float potencia_R    = pzemR.power();                    // ---> LEITURA DIRETA DO TRANSDUTOR <---
  float consumo_R     = pzemR.energy();
  int   frequencia_R  = pzemR.frequency();
  float fp_R          = pzemR.pf() / 100.0;

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
  // -------------------------------------------------------------------------------------------------------//
  
  String(a_R) = String("*** DADOS DA EEE BG04 ***\n\n>>> FASE R <<<\n- Tensão: ");
  String(b_R) = String(tensao_R);
  String(c_R) = String(" VCA");

  String(d_R) = String("\n- Corrente: ");
  String(e_R) = String(corrente_R);
  String(f_R) = String(" A");

  String(g_R) = String("\n- Potencia: ");
  String(h_R) = String(potencia_R);
  String(i_R) = String(" W");

  String(j_R) = String("\n- Consumo: ");
  String(l_R) = String(consumo_R);
  String(m_R) = String(" kWh");

  String(n_R) = String("\n- Frequencia: ");
  String(o_R) = String(frequencia_R);
  String(p_R) = String(" Hz");

  String(q_R) = String("\n- FP: ");
  String(r_R) = String(fp_R);
  String(s_R) = String("\n ");

  String(fase_R) = a_R + b_R + c_R 
            + d_R + e_R + f_R 
            + g_R + h_R + i_R
            + j_R + l_R + m_R 
            + n_R + o_R + p_R 
            + q_R + r_R + s_R;


//--------------------------------------------------> FASE S <--------------------------------------------------

  PZEM004Tv30 pzemS(Serial1, S_RX2, S_TX2); 
  
  int   tensao_S      = pzemS.voltage();
  float corrente_S    = pzemS.current();
  float potencia_S    = pzemS.power();                    // ---> LEITURA DIRETA DO TRANSDUTOR <---
  float consumo_S     = pzemS.energy();
  int   frequencia_S  = pzemS.frequency();
  float fp_S          = pzemS.pf() / 100.0;

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

  String(a_S) = String("\n>>> FASE S <<<\n- Tensão: ");
  String(b_S) = String(tensao_S);
  String(c_S) = String(" VCA");

  String(d_S) = String("\n- Corrente: ");
  String(e_S) = String(corrente_S);
  String(f_S) = String(" A");

  String(g_S) = String("\n- Potencia: ");
  String(h_S) = String(potencia_S);
  String(i_S) = String(" W");

  String(j_S) = String("\n- Consumo: ");
  String(l_S) = String(consumo_S);
  String(m_S) = String(" kWh");

  String(n_S) = String("\n- Frequencia: ");
  String(o_S) = String(frequencia_S);
  String(p_S) = String(" Hz");

  String(q_S) = String("\n- FP: ");
  String(r_S) = String(fp_S);
  String(s_S) = String("\n ");

  String(fase_S) = a_S + b_S + c_S 
            + d_S + e_S + f_S 
            + g_S + h_S + i_S
            + j_S + l_S + m_S 
            + n_S + o_S + p_S 
            + q_S + r_S + s_S;


//--------------------------------------------------> FASE T <--------------------------------------------------

  PZEM004Tv30 pzemT(Serial1, T_RX3, T_TX3); 
  
  int   tensao_T      = pzemT.voltage();
  float corrente_T    = pzemT.current();
  float potencia_T    = pzemT.power();                    // ---> LEITURA DIRETA DO TRANSDUTOR <---
  float consumo_T     = pzemT.energy();
  int   frequencia_T  = pzemT.frequency();
  float fp_T          = pzemT.pf() / 100.0;

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
  
  String(a_T) = String("\n>>> FASE T <<<\n- Tensão: ");
  String(b_T) = String(tensao_T);
  String(c_T) = String(" VCA");

  String(d_T) = String("\n- Corrente: ");
  String(e_T) = String(corrente_T);
  String(f_T) = String(" A");

  String(g_T) = String("\n- Potencia: ");
  String(h_T) = String(potencia_T);
  String(i_T) = String(" W");

  String(j_T) = String("\n- Consumo: ");
  String(l_T) = String(consumo_T);
  String(m_T) = String(" kWh");

  String(n_T) = String("\n- Frequencia: ");
  String(o_T) = String(frequencia_T);
  String(p_T) = String(" Hz");

  String(q_T) = String("\n- FP: ");
  String(r_T) = String(fp_T);
  //String(s_T) = String("\n ");

  String(fase_T) = a_T + b_T + c_T 
                + d_T + e_T + f_T 
                + g_T + h_T + i_T
                + j_T + l_T + m_T 
                + n_T + o_T + p_T 
                + q_T + r_T;

// -------------------------------------------- ENVIO PARA O TELEGRAM --------------------------------------------- 
   
  Serial.print("Connecting to Wifi SSID ");
  Serial.print(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  secured_client.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root certificate for api.telegram.org
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.print("\nWiFi connected. IP address: ");
  Serial.println(WiFi.localIP());

  Serial.print("Retrieving time: ");
  configTime(0, 0, "pool.ntp.org"); // get UTC time via NTP
  time_t now = time(nullptr);
  while (now < 24 * 3600)
  {
    Serial.print(".");
    delay(100);
    now = time(nullptr);
  }
  Serial.println(now);
  x = 0;
  while (x < 10)
  {
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
    x = x+1;
  }

  ntp.begin();
  ntp.setTimeOffset(-10800);


  //  ----> RESUMO <---- //
  String(resumo) = fase_R + fase_S + fase_T;
  bot.sendMessage(CHAT_ID,resumo,"");

  Serial.println("Dados enviados para o TELEGRAM");



  // -----> SAINDO DO MODO TELEGRAM <----- //
  Serial.begin(115200);
  Serial.println("Saindo do modo TELEGRAM");

  pinMode(ledPin , OUTPUT);
  digitalWrite(ledPin, LOW); 

  //connect_wifi();
  Serial.print("Connecting to wifi: ");
  Serial.println(ssid);
  Serial.flush();
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(WiFi.status());
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  
  //Sinalizacao de conexao OK
  x = 0;
  while (x < 10)
  {
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
    x = x+1;
  }
  Serial.println("Saída do Modo TELEGRAM com sucesso!");



}
