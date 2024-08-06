#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

#define ledPin 2
#define buttonPin 4
int buttonState = 0; 

#define WIFI_SSID "Embasa USA-M"
#define WIFI_PASSWORD "Sup0rt3!@#"
#define BOT_TOKEN "5875114157:AAHahh0XbtDqGJhm6DH9cS2sjfHdZEEJgbo"
#define CHAT_ID "984798692"

WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);

void setup() {
  pinMode(ledPin , OUTPUT);
  digitalWrite(ledPin, LOW);

  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, LOW);

  Serial.begin(115200);
  Serial.println();

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
  bot.sendMessage(CHAT_ID, "Inicializando o monitoramento", "");
}

void loop() 
{
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    //digitalWrite(ledPin, HIGH);
    delay(10);
    bot.sendMessage(CHAT_ID, "EEE Gamboa 0 Extravasando", "");
    delay(10);
    Serial.print(buttonState);
  } else {
    digitalWrite(ledPin, LOW);
    delay(10);
    Serial.print(buttonState);
  }
}


 


















