#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"
#include "esp_camera.h"
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
#include <NTPClient.h> //https://github.com/taranais/NTPClient

const char* ssid = "Embasa USA-M";
const char* password = "Sup0rt3!@#";
//const char* ssid = "EET2";
//const char* password = "35452328";

// Initialize Telegram BOT
String BOTtoken = "5875114157:AAHahh0XbtDqGJhm6DH9cS2sjfHdZEEJgbo";  // your Bot Token (Get from Botfather)
//String CHAT_ID = "984798692";
//String CHAT_ID = "-1001435698283";
String CHAT_ID = "-4096352251";


// #define INTERVAL 1000
// const String STATS = "status";
// const String HOUR = "hora";
// uint32_t lastCheckTime = 0;

WiFiClientSecure clientTCP;
UniversalTelegramBot bot(BOTtoken, clientTCP);
WiFiUDP ntpUDP;
NTPClient ntp(ntpUDP);


//Checks for new messages every 1 second.
int botRequestDelay = 1000;
unsigned long lastTimeBotRan;


void handleNewMessages(int numNewMessages) {
  Serial.print("Handle New Messages: ");
  Serial.println(numNewMessages);

  // Checagem de Usuarios autorizados a interagir com o sistema
  for (int i = 0; i < numNewMessages; i++) {
    String chat_id = String(bot.messages[i].chat_id);
    if (chat_id != CHAT_ID){
      //bot.sendMessage(chat_id, "Unauthorized user", "");
      bot.sendMessage(chat_id, "Tente novamente", "");
      Serial.print("Sem Acesso");
      continue;
    }
    
    // Print the received message
    String text = bot.messages.text;
    Serial.println(text);
    
    String from_name = bot.messages[i].from_name;
    if (text == "/start") {
      String welcome = "Bem-vindo, " + from_name + "\n";
      welcome += "Use os comandos abaixo para interagir com o sistema de vigilância:\n";
      welcome += "/foto : tira uma foto\n";
      welcome += "/flash : aciona o FLASH interno\n";
      bot.sendMessage(CHAT_ID, welcome, "");
    }
    }
    }
void setup() {
  // Init Serial Monitor
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.mode(WIFI_STA);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  clientTCP.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root certificate for api.telegram.org
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  bot.sendMessage(CHAT_ID, "Sistema liberado para funcionamento!", ""); 

}
void loop() {

  if (millis() > lastTimeBotRan + botRequestDelay)  {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    while (numNewMessages) {
      Serial.println("got response");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
    lastTimeBotRan = millis();
  }
 
  uint32_t now = millis();
  if (now - lastCheckTime > INTERVAL) 
  {
    lastCheckTime = now;
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    handleNewMessages(numNewMessages);
  }
}