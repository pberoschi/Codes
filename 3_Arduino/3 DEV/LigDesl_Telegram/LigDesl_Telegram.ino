// https://randomnerdtutorials.com/telegram-control-esp32-esp8266-nodemcu-outputs/

#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>   // Universal Telegram Bot Library written by Brian Lough: https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot
#include <ArduinoJson.h>
//Bibliotecas do Relógio
#include <NTPClient.h>
#include <WiFiUdp.h>

const char* ssid = "Embasa USA-M";
const char* password = "Sup0rt3!@#";

// Initialize Telegram BOT
#define BOTtoken "6135423460:AAGvQYE39MHGyYtb4g78JpKl_Z4X279aUKc"  // your Bot Token (Get from Botfather)
#define CHAT_ID "984798692"

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);
WiFiUDP ntpUDP;
NTPClient ntp(ntpUDP);

// Checks for new messages every 1 second.
int botRequestDelay = 1000;
unsigned long lastTimeBotRan;

const int ledPin = 2;
bool ledState = LOW;

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
      // String welcome = "Bem-vindo, " + from_name + ".\n";
      ntp.update();
      String welcome = ntp.getFormattedDate() + ".\n\n";
      welcome += "Bem-vindo, " + from_name + ".\n";
      welcome += "Use os seguintes comandos para controlar suas saídas: \n\n";
      welcome += "/led_on para LIGAR \n";
      welcome += "/led_off para DESLIGAR \n";
      welcome += "/state para verificar o estado da saída \n";
      bot.sendMessage(chat_id, welcome, "");
    }

    if (text == "/led_on") {
      bot.sendMessage(chat_id, "LED state set to ON", "");
      ledState = HIGH;
      digitalWrite(ledPin, ledState);
    }
    
    if (text == "/led_off") {
      bot.sendMessage(chat_id, "LED state set to OFF", "");
      ledState = LOW;
      digitalWrite(ledPin, ledState);
    }
    
    if (text == "/state") {
      if (digitalRead(ledPin)){
        bot.sendMessage(chat_id, "LED is ON", "");
      }
      else{
        bot.sendMessage(chat_id, "LED is OFF", "");
      }
    }
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);
  
  // Connect to Wi-Fi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  // #ifdef ESP32
    client.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root certificate for api.telegram.org
  // #endif
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  // Print ESP32 Local IP Address
  Serial.println(WiFi.localIP());

  //Relógio e Data
  ntp.begin();
  ntp.setTimeOffset(-10800); //-10800 Formato Brasil
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
}