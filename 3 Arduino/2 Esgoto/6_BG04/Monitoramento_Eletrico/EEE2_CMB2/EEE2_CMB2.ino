
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
// const char* ssid     = "Embasa USA-M";     // your network SSID (name of wifi network)
// const char* password = "Sup0rt3!@#";       // your network password
// const char* ssid     = "Galaxy";     // your network SSID (name of wifi network)
// const char* password = "43215678";       // your network password
const char* ssid     = "ILHOTA/0";     // your network SSID (name of wifi network)
const char* password = "ILHOTA-0";       // your network password
char *server = "script.google.com";        // Server URL
//char *GScriptId = "AKfycbzbqkAso7d__JfhwxLiIh5PHZRoCB9tFjLhLIYXvbqTZ23DhecSOtCxUfq7481uFP8ajA"; //planilha teste   
char *GScriptId = "AKfycbzJlu4MV5HRD-eTHU_pyDdakLJbfVOn7D43vRP6EuBgbbR1VKfhj5utvwsO-0I27N0Yyg"; //planilha teste             
const int httpsPort = 443;
WiFiClientSecure client;


// ---> Envio TELEGRAM <--- //
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

//#define WIFI_SSID "E.E.E"
//#define WIFI_PASSWORD "GAMBOA-0"
#define WIFI_SSID "Embasa USA-M"
#define WIFI_PASSWORD "Sup0rt3!@#"

//#define BOT_TOKEN "5875114157:AAHahh0XbtDqGJhm6DH9cS2sjfHdZEEJgbo"
//#define CHAT_ID "984798692"
//#define CHAT_ID "-1001851643135"
#define BOT_TOKEN "6365824444:AAHQ2esU_ggjNyClx7FudZ4IEVJzH4fs5gM"
#define CHAT_ID "-4096352251"

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










