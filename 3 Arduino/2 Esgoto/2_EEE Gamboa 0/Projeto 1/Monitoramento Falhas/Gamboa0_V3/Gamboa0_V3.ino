//Comunicação como o TELEGRAM sem o envio de STATUS

#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

#define ledPin 2
#define NivelAlto 21//13
#define Extravasamento 22//4
#define FaltaEnergia 23//18
int x;
int buttonState = 0; 
int NAlto = 0;
int Extrav = 0;
int FEnergia = 0;

#define WIFI_SSID "Embasa USA-M"
#define WIFI_PASSWORD "Sup0rt3!@#"
#define BOT_TOKEN "5875114157:AAHahh0XbtDqGJhm6DH9cS2sjfHdZEEJgbo"
#define CHAT_ID "984798692"

WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);

void setup() {
  pinMode(ledPin , OUTPUT);
  digitalWrite(ledPin, LOW);

  //pinMode(buttonPin, INPUT);
  pinMode(NivelAlto, INPUT_PULLDOWN);
  pinMode(Extravasamento, INPUT_PULLDOWN);
  pinMode(FaltaEnergia, INPUT_PULLDOWN);

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
  x = 0;
  while (x < 10)
  {
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
    x = x+1;
  }
  bot.sendMessage(CHAT_ID, "Inicializando o monitoramento. Verificando STATUS da instalação", "");
}

void loop() 
{
  NAlto = digitalRead(NivelAlto);
  Extrav = digitalRead(Extravasamento);
  FEnergia = digitalRead(FaltaEnergia);

  if (NAlto == HIGH) {
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    bot.sendMessage(CHAT_ID, "EEE Gamboa 0: NIVEL ALTO", "");
    Serial.print("NIVEL ALTO");
    delay(10);
  }
  if (Extrav == HIGH) {
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    bot.sendMessage(CHAT_ID, "EEE Gamboa 0: EXTRAVASANDO", "");
    Serial.print("EXTRAVASANDO");
    delay(10);
    }
  if (FEnergia == HIGH) {
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    bot.sendMessage(CHAT_ID, "EEE Gamboa 0: FALTA DE ENERGIA", "");
    Serial.print("FALTA DE ENERGIA");
    delay(10);
  }
}



 


















