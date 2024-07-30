//https://www.efeitonerd.com.br/2022/10/teste-de-rede-com-ping-no-esp32.html
// Dividido em classes e implementado o RTC interno

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

int x = 0;
int y = 0;
int w;
#define ledPin 2

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


void setup() {
  pinMode(ledPin , OUTPUT);
  digitalWrite(ledPin, LOW);

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
void loop()
{ 
  const String datafull       = (ntp.getFormattedDate());
  const int hora              = (ntp.getHours());
  const int minuto            = (ntp.getMinutes());
  const int segundo           = (ntp.getSeconds());  
  
  Serial.println(datafull);
  
  papai();
  delay(100);
  mamae();
  delay(100);
}



void papai()
{
  if (Ping.ping(remote_ip1, 3)) {                  
    if (x == 0){
      Serial.println("JOHNNY ON");
      bot.sendMessage(CHAT_ID, "Papai ESTÁ em casa", "");
      x = 1;
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
  

void mamae()
{
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

