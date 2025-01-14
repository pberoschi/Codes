
// Envio para o sheets e TELEGRAM / TRIFASICO

#include <PZEM004Tv30.h>
#include <HTTPClient.h>
#include <WiFi.h>
#include "string.h"

int R_RX1 = 16;
int R_TX1 = 17;
int S_RX2 = 22;
int S_TX2 = 23;
int T_RX3 = 12;
int T_TX3 = 14;
int intervaloLEIT = 2000;
int IntervaloSEND = 0;


#define ledPin 2
int x;
const char* ssid     = "Embasa USA-M";
const char* password = "Sup0rt3!@#";
// const char* ssid     = "E.E.E";
// const char* password = "GAMBOA-0";
char *server = "script.google.com";        // Server URL  
char *GScriptId = "AKfycby_lpNpKvxaUHXzJdYF9Jz-zvJRuXYWNhPzFv-9MPm49dvs8OgSJs2IvY-T9n92IMIR";          
const int httpsPort = 443;
WiFiClientSecure client;


// ---> Envio TELEGRAM <--- //
#define WIFI_SSID ssid
#define WIFI_PASSWORD password
//#define BOT_TOKEN "5875114157:AAHahh0XbtDqGJhm6DH9cS2sjfHdZEEJgbo"
//#define CHAT_ID "984798692"
//#define CHAT_ID "-1001851643135"
#define BOT_TOKEN "6365824444:AAHQ2esU_ggjNyClx7FudZ4IEVJzH4fs5gM"
#define CHAT_ID "-4096352251"

#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
#include <NTPClient.h> //https://github.com/taranais/NTPClient

const String datafull = "";
const int hora = 0;
const int minuto = 0;
const int segundo = 0;

#define INTERVAL 1000
const String STATS = "status";
const String HOUR = "hora";
uint32_t lastCheckTime = 0;

WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);
WiFiUDP ntpUDP;
NTPClient ntp(ntpUDP);
// --- --- //


void setup() {
    Serial.begin(115200);

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
  Serial.print("IP address: ");
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
  
  ntp.begin();
  ntp.setTimeOffset(-10800);
}

void loop() {

    const String datafull = (ntp.getFormattedDate());
    const int hora = (ntp.getHours());
    const int minuto = (ntp.getMinutes());
    const int segundo = (ntp.getSeconds());   
    
    if (ntp.update()) {
        if ((minuto == IntervaloSEND) && (segundo < 8)){
        //if (minuto == IntervaloSEND){
        Serial.println("Chamando a função >>> TELEGRAM <<<");
        //teleg();
        //delay(500);
      
      } else {
        Serial.println("Chamando a função >>> Google Sheets <<<");
        sheets();
        //delay(500);
      }    
    }
}











