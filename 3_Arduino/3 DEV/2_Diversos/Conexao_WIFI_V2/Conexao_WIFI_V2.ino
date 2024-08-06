//https://github.com/witnessmenow/Simple-Home-Automation-With-Telegram/blob/master/LedControl/LedControl.ino
#include <Arduino.h>
#include <WiFi.h>
//#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
#define CHAT_ID "984798692"

char ssid[] = "Embasa USA-M";         // your network SSID (name)
char password[] = "Sup0rt3!@#"; // your network password
#define TELEGRAM_BOT_TOKEN "5875114157:AAHahh0XbtDqGJhm6DH9cS2sjfHdZEEJgbo"

// This is the Wifi client that supports HTTPS
WiFiClientSecure client;
UniversalTelegramBot bot(TELEGRAM_BOT_TOKEN, client);

#define LED_PIN 2 // Same as D4 for Wemos
#define buttonPin 4
int buttonState = 0;  // variable for reading the pushbutton status

int delayBetweenChecks = 1000;
unsigned long lastTimeChecked;   //last time messages' scan has been done
unsigned long lightTimerExpires;
boolean lightTimerActive = false;

void setup() {
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
  pinMode(buttonPin, INPUT);

  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  client.setInsecure();
  bot.longPoll = 60;
}
void handleNewMessages(int numNewMessages) {
  for (int i = 0; i < numNewMessages; i++) {
    // If the type is a "callback_query", a inline keyboard button was pressed
    if (bot.messages[i].type ==  F("callback_query")) {
      String text = bot.messages[i].text;
      Serial.print("Call back button pressed with text: ");
      Serial.println(text);

      if (text == F("ON")) {
        digitalWrite(LED_PIN, HIGH);
        //bot.sendMessage(CHAT_ID, "EEE Extravasando", "");
      
      } else if (text == F("OFF")) {
        digitalWrite(LED_PIN, LOW);
      
      } else if (text.startsWith("TIME")) {
        text.replace("TIME", "");
        int timeRequested = text.toInt();
        
        digitalWrite(LED_PIN, HIGH);
        lightTimerActive = true;
        lightTimerExpires = millis() + (timeRequested * 1000 * 60);
      }
    } else {
      String chat_id = String(bot.messages[i].chat_id);
      String text = bot.messages[i].text;

      if (text == F("/start")) {
        bot.sendMessage(chat_id, "/options : returns the inline keyboard\n", "Markdown");

        buttonState = digitalRead(buttonPin);
      if (buttonState == HIGH) {
        digitalWrite(LED_PIN, HIGH);
        bot.sendMessage(CHAT_ID, "EEE Gamboa 0 Extravasando", "");
      } else {
        digitalWrite(LED_PIN, LOW);
  }
      }
    }
  }
}
void loop() {
     if (millis() > lastTimeChecked + delayBetweenChecks)  {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    if (numNewMessages) {
      Serial.println("got response");
      handleNewMessages(numNewMessages);
    }
    lastTimeChecked = millis();
    if (lightTimerActive && millis() > lightTimerExpires) {
      lightTimerActive = false;
      digitalWrite(LED_PIN, LOW);
    }
  }
}
