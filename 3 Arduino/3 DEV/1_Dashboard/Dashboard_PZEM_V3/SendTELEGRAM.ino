void send()
{
// }
//   void teste()
//   {
    int tensao = pzem.voltage();
    float corrente = pzem.current();
    float potenciaW = pzem.power();             // ---> Números FRACIONADOS
    float energia = pzem.energy();
    int frequencia = pzem.frequency();
    float fp = pzem.pf() / 100.0;

// ---------------------------------------------------------------------------------------------------//    
    // int tensao = random(380,400);
    // int corrente = random(80,98);
    // int potenciaW = random(5500,7800);              // ----> TESTES --- (Gerador de números aleatórios)
    // int energy = random(1080,1098);
    // int frequencia = random(57,60);
    // float fp = random(92,98) / 100.0;
  // ---------------------------------------------------------------------------------------------------// 


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
  //GMT em segundos
  // +1 = 3600
  // +8 = 28800
  // -1 = -3600
  // -3 = -10800 (BRASIL)
  ntp.setTimeOffset(-10800);


  // ----> TENSÃO <---- //
  String(t1) = String("- Tensão R: ");
  String(t2) = String(tensao);
  String(t3) = String(" Vca");
  String(t) = t1 + t2 + t3;
  //bot.sendMessage(CHAT_ID, t, "");

  // ----> CORRENTE <---- //
  String(c1) = String("- Corrente R: ");
  String(c2) = String(corrente);
  String(c3) = String(" CA");
  String(c) = c1 + c2 + c3;
  //bot.sendMessage(CHAT_ID, c, "");

// ----> POTENCIA W <---- //
  String(p1) = String("- Potência: ");
  String(p2) = String(corrente);
  String(p3) = String(" CA");
  String(p) = p1 + p2 + p3;
  //bot.sendMessage(CHAT_ID, p, "");

//  ----> RESUMO <---- //
  String(r) = t+c+p;
  bot.sendMessage(CHAT_ID,r,"");

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


