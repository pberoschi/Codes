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

const int ledPin  = 2;
int ligSist = 22;
bool ledState     = LOW;

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
      ntp.update();
      String welcome = ntp.getFormattedDate() + ".\n\n";
      welcome += "Bem-vindo, " + from_name + ".\n";
      welcome += "Use os seguintes comandos para controlar o sistema de Irrigação: \n\n";
      welcome += "/lig para LIGAR a irrigação\n";
      welcome += "/desl para DESLIGAR a irrigação\n";
      welcome += "/estado para verificar o estado da saída \n";
      bot.sendMessage(chat_id, welcome, "");
    }    

    if (text == "/lig"){
      bot.sendMessage(chat_id, "A Irrigação foi LIGADA", "");
      ledState = HIGH;
      digitalWrite(ledPin, ledState);
      digitalWrite(ligSist, HIGH);
    }
    
    if (text == "/desl"){
      bot.sendMessage(chat_id, "A Irrigação foi DESLIGADA", "");
      ledState = LOW;
      digitalWrite(ledPin, ledState);
      digitalWrite(ligSist, LOW);
      
    }
    
    if (text == "/estado") {
      if (digitalRead(ledPin)){
        bot.sendMessage(chat_id, "O Sistema está LIGADO", "");
      }
      else{
        bot.sendMessage(chat_id, "O Sistema está DESLIGADO", "");
      }
    }
  }
}

void tempo(){
  ntp.update();
  
  if (((ntp.getHours() == 9) && (ntp.getMinutes() == 0))                // HORÁRIO 1
    || ((ntp.getHours() == 17) && (ntp.getMinutes() == 0)))              // HORÁRIO 2
    {
    bot.sendMessage(CHAT_ID, "Irrigação foi LIGADA pelo horário estabelecido. Aguarde completar o ciclo", "");
    ledState = HIGH;
    digitalWrite(ledPin, ledState);
    digitalWrite(ligSist, HIGH);
    delay(60000);                                                         // TEMPO DA IRRIGAÇÃO LIGADA

    bot.sendMessage(CHAT_ID, "A Irrigação foi DESLIGADA.", "");
    ledState = LOW;
    digitalWrite(ledPin, ledState);
    digitalWrite(ligSist, LOW);
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(ledPin, OUTPUT);
  pinMode(ligSist, OUTPUT);

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

  for (int w=0; w<=10; w++) //Sinalização de conectado com sucesso
  {
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
  }

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
  tempo();

}