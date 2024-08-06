//https://www.efeitonerd.com.br/2022/10/teste-de-rede-com-ping-no-esp32.html
// Dividido em classes e implementado o RTC interno
// Monitoramento fulltime do telegram para intervenções a qq momento

#include <WiFi.h>
#include <ESP32Ping.h>
#include <UniversalTelegramBot.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>
#include <NTPClient.h> //https://github.com/taranais/NTPClient

// Initialize Telegram BOT
String BOTtoken = "6135423460:AAGvQYE39MHGyYtb4g78JpKl_Z4X279aUKc";  // your Bot Token (Get from Botfather)
String CHAT_ID = "984798692";
//String CHAT_ID = "-4005635677";

WiFiClientSecure clientTCP;
UniversalTelegramBot bot(BOTtoken, clientTCP);
WiFiUDP ntpUDP;
NTPClient ntp(ntpUDP);

// Checks for new messages every 1 second.
int botRequestDelay = 1000;
unsigned long lastTimeBotRan;

int x = 0;
int y = 0;
int w;
const int ledPin      = 2;
const int frentePin   = 22;
const int lateralPin  = 23;
const int gourmetPin  = 24;
bool ledState = LOW;

const char* ssid     = "Embasa USA-M";
const char* password = "Sup0rt3!@#";

const String datafull = "";
const int hora = 0;
const int minuto = 0;
const int segundo = 0;

#define INTERVAL 1000
const String STATS = "status";
const String HOUR = "hora";
uint32_t lastCheckTime = 0;

char* remoteHost = "www.google.com";                    //IP ou endereço web para realizar o ping
const IPAddress remote_ip1(192, 168, 0, 134);
const IPAddress remote_ip2(192, 168, 0, 121);


// Handle what happens when you receive new messages
void handleNewMessages(int numNewMessages) {
  Serial.println("handleNewMessages");
  Serial.println(String(numNewMessages));

  for (int i=0; i<numNewMessages; i++) {
    // Chat id of the requester
    String chat_id = String(bot.messages[i].chat_id);
    if (chat_id != CHAT_ID){
      bot.sendMessage(chat_id, "Unauthorized user", "");
      continue;
    }
    
    // Print the received message
    String text = bot.messages[i].text;
    Serial.println(text);

    String from_name = bot.messages[i].from_name;

    if (text == "/start") {
      String welcome = "Bem-vindo, " + from_name + ".\n";
      welcome += "Use os seguintes comandos para controlar sua iluminação: \n\n";
      
      welcome += "/lig_FRENTE para LIGAR a frente \n";
      welcome += "/desl_FRENTE para DESLIGAR a frente\n";

      welcome += "/lig_LATERAL para LIGAR a lateral \n";
      welcome += "/desl_LATERAL para DESLIGAR a lateral \n";

      welcome += "/lig_GOURMET para LIGAR a área gourmet \n";
      welcome += "/desl_GOURMET para DESLIGAR a área gourmet \n";

      welcome += "/status para verificar o estado da saída \n";
      bot.sendMessage(chat_id, welcome, "");
    }

    if (text == "/lig") {
      bot.sendMessage(chat_id, "A iluminação está LIGADA", "");
      // ledState = HIGH;
      // digitalWrite(ledPin, ledState);
      digitalWrite(frentePin, HIGH);
      digitalWrite(lateralPin, HIGH);
      digitalWrite(gourmetPin, HIGH);

    }
    
    if (text == "/desl") {
      bot.sendMessage(chat_id, "A iluminação está DESLIGADA", "");
      // ledState = LOW;
      // digitalWrite(ledPin, ledState);
      digitalWrite(frentePin, LOW);
      digitalWrite(lateralPin, LOW);
      digitalWrite(gourmetPin, LOW);
    }
    
    if (text == "/status") {
      if (digitalRead(ledPin)){
        bot.sendMessage(chat_id, "A iluminação está LIGADA", "");
      }
      else{
        bot.sendMessage(chat_id, "A iluminação está DESLIGADA", "");
      }


    }
  }
}

void setup() {
  pinMode(ledPin , OUTPUT);
  pinMode(frentePin, OUTPUT);
  pinMode(lateralPin, OUTPUT);
  pinMode(gourmetPin, OUTPUT);

  digitalWrite(ledPin, LOW);
  digitalWrite(frentePin, LOW);
  digitalWrite(lateralPin, LOW);
  digitalWrite(gourmetPin, LOW);

  Serial.begin(115200);
  delay(10);

  Serial.println();
  Serial.println("Connecting to WiFi"); 
  WiFi.begin(ssid, password);
  clientTCP.setCACert(TELEGRAM_CERTIFICATE_ROOT); 

  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("WiFi connected with ip ");  
  Serial.println(WiFi.localIP()); 
  
  for (int w=0; w<=10; w++) //Sinalização de conectado com sucesso
  {
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
  }
  
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
  ntp.begin();
  ntp.setTimeOffset(-10800);

}

void loop() { 
  if (millis() > lastTimeBotRan + botRequestDelay)  {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    while(numNewMessages) {
      Serial.println("got response");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
    lastTimeBotRan = millis();
  }

  ntp.update();
  const String datafull       = (ntp.getFormattedDate());
  const int hora              = (ntp.getHours());
  const int minuto            = (ntp.getMinutes());
  const int segundo           = (ntp.getSeconds());  
  // Serial.println(datafull);
  
  papai();
  delay(100);
  mamae();
  delay(100);
}

void papai() {
  if (Ping.ping(remote_ip1, 3)) {                  
    if (x == 0){
      Serial.println("JOHNNY ON");
      bot.sendMessage(CHAT_ID, "Papai ESTÁ em casa", "");
      x = 1;

      if ((hora >= 19) && (hora <= 4)) {
        iluminacao_tempo();
      }   
    }
    
  } else {
      if (x == 1){
      Serial.println("JOHNNY OFF");
      bot.sendMessage(CHAT_ID, "Papai NÃO ESTÁ em casa", "");
      x = 0;
      }
    }
  //Serial.println("_");
  delay(100);
}
  

void mamae() {
  if (Ping.ping(remote_ip2, 3)) {             
    if (y == 0){
      Serial.println("GRAZI ON");
      bot.sendMessage(CHAT_ID, "Mamãe ESTÁ em casa", "");
      y = 1;
    }
    
  } else {
      if (y == 1){
      Serial.println("GRAZI OFF");
      bot.sendMessage(CHAT_ID, "Mamãe NÃO ESTÁ em casa", "");
      y = 0;
      }
  }
}

