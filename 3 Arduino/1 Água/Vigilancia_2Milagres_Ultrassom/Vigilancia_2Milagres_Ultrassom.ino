#include <NewPing.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
#include <NTPClient.h> //https://github.com/taranais/NTPClient
 
#define TRIGGER_PIN  5
#define ECHO_PIN     18
#define MAX_DISTANCE 200
#define Alarme 23
#define ledPin 2
int x;
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

const String datafull = "";
const int hora = 0;
const int minuto = 0;
const int segundo = 0;

#define INTERVAL 1000
const String STATS = "status";
const String HOUR = "hora";
uint32_t lastCheckTime = 0;

#define WIFI_SSID "Embasa USA-M"
#define WIFI_PASSWORD "Sup0rt3!@#"
#define BOT_TOKEN "5875114157:AAHahh0XbtDqGJhm6DH9cS2sjfHdZEEJgbo"
//#define CHAT_ID "984798692"
#define CHAT_ID "-1001435698283"

WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);
WiFiUDP ntpUDP;
NTPClient ntp(ntpUDP);

 
void setup() {
  Serial.begin(115200);
  pinMode(Alarme, OUTPUT); // Sets the echoPin as an Input
  digitalWrite(Alarme, LOW);
  pinMode(ledPin , OUTPUT);
  digitalWrite(ledPin, LOW);


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

  bot.sendMessage(CHAT_ID, "Iniciando o monitoramento." , "");
  delay(1000);
  //handleStatus(CHAT_ID);

}
 
void loop() {
  delay(50);
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm());
  Serial.println("cm");


  //if (((sonar.ping_cm()) < 130.00) and ((sonar.ping_cm()) > 30))
  if ((sonar.ping_cm()) < 20)
    {
      x=0;
      while (x < 2) {
      {
        digitalWrite(Alarme, HIGH);
        delay(50);
        digitalWrite(Alarme, LOW);
        delay(50);
        x=x+1;
      }
  }
  bot.sendMessage(CHAT_ID, "*** EEAT 2 Milagres *** \nALARME DE INTRUSÃO", "");
  Serial.println("ALARME DE INTRUSÃO");
  delay(3000);
} 

}
