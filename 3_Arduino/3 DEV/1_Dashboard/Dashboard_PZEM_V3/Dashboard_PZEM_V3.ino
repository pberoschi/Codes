// Envio para o sheets e TELEGRAM / MONOFASICO

#include <PZEM004Tv30.h>
#include <HTTPClient.h>
#include <WiFi.h>
#include "string.h"

#if !defined(PZEM_RX_PIN) && !defined(PZEM_TX_PIN)
#define PZEM_RX_PIN 16
#define PZEM_TX_PIN 17
#endif

#if !defined(PZEM_SERIAL)
#define PZEM_SERIAL Serial2
#endif

#if defined(ESP32)
/*************************
 *  ESP32 initialization
 * ---------------------
 * 
 * The ESP32 HW Serial interface can be routed to any GPIO pin 
 * Here we initialize the PZEM on Serial2 with RX/TX pins 16 and 17
 */
PZEM004Tv30 pzem(PZEM_SERIAL, PZEM_RX_PIN, PZEM_TX_PIN);
#endif

#define ledPin 2
int x;
const char* ssid     = "Embasa USA-M";     // your network SSID (name of wifi network)
const char* password = "Sup0rt3!@#"; // your network password
char *server = "script.google.com";  // Server URL
char *GScriptId = "AKfycbzzUQ2-O0b29vqKspltbqEr0geiPLZ98tdzJL0wO3fBlmNlNcK-mFP2Io0UMClC60aM3A"; //planilha teste               
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
#define BOT_TOKEN "5875114157:AAHahh0XbtDqGJhm6DH9cS2sjfHdZEEJgbo"
//#define CHAT_ID "984798692"
#define CHAT_ID "-1001851643135"

WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);
WiFiUDP ntpUDP;
NTPClient ntp(ntpUDP);
// --- --- //


void setup() {
    // Debugging Serial port
    Serial.begin(115200);
    // Uncomment in order to reset the internal energy counter
    // pzem.resetEnergy()

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
  //GMT em segundos
  // +1 = 3600
  // +8 = 28800
  // -1 = -3600
  // -3 = -10800 (BRASIL)
  ntp.setTimeOffset(-10800);


}
void loop() {

    const String datafull = (ntp.getFormattedDate());
    const int hora = (ntp.getHours());
    const int minuto = (ntp.getMinutes());
    const int segundo = (ntp.getSeconds());   
    
    if (ntp.update()) {
       if ((minuto == 33) && (segundo < 8)){
        //Serial.println(datafull);
        //String(a) = String(hora);
        //String(b) = String(minuto);
        //Serial.println(a+b);
        Serial.println("Chamando a função >>> TELEGRAM <<<");
        //send();
        //delay(5000);
      

      } else {
        //Serial.println("!Erro ao atualizar NTP!\n");
        //Serial.println(datafull);
        //String(a) = String(hora);
        //String(b) = String(minuto);
        //Serial.println(a+b);
        Serial.println("Chamando a função >>> Google Sheets <<<");
        enviarMedicao();
        //delay(5000);
      }
    
    }

}











