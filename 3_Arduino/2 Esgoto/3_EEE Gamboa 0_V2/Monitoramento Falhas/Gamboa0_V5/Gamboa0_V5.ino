//Comunicação como o TELEGRAM com o envio de STATUS e adaptado a USAM
//Portas disponíveis: 4//18//19//14//22//23//25//26//32//33

#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
#include <NTPClient.h> //https://github.com/taranais/NTPClient

#define ledPin 2
//#define nbuzzer 22
#define Extravasamento 4
#define FalhaCMB1 14
#define FalhaCMB2 18
#define FalhaContNivel 19
#define FaltaEnergia 23
#define GeradorON 25
#define RodandoSeca 26
#define TesteSistema 33
#define AlertaNivelAlto 32

int x;
//int buttonState = 0; 
int Extrav = 0;
int FCMB1 = 0;
int FCMB2 = 0;
int FCNIVEL = 0;
int FEnergia = 0;
int GERON = 0;
int RODSECA = 0;
int TESTESIS = 0;
int NAlto = 0;

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
//#define WIFI_SSID "Galaxy S20 FE 5G8EE7"
//#define WIFI_PASSWORD "bsvd9720"
#define BOT_TOKEN "5875114157:AAHahh0XbtDqGJhm6DH9cS2sjfHdZEEJgbo"
//#define CHAT_ID "984798692"
#define CHAT_ID "-1001851643135"

WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);
WiFiUDP ntpUDP;
NTPClient ntp(ntpUDP);

void setup() {
  pinMode(ledPin , OUTPUT);
  digitalWrite(ledPin, LOW);
  //pinMode(nbuzzer, OUTPUT);
  //digitalWrite(nbuzzer, LOW);

  pinMode(Extravasamento, INPUT_PULLDOWN);
  pinMode(FalhaCMB1, INPUT_PULLDOWN);
  pinMode(FalhaCMB2, INPUT_PULLDOWN);
  pinMode(FalhaContNivel, INPUT_PULLDOWN);
  pinMode(FaltaEnergia, INPUT_PULLDOWN);
  pinMode(GeradorON, INPUT_PULLDOWN);
  pinMode(RodandoSeca, INPUT_PULLDOWN);
  pinMode(TesteSistema, INPUT_PULLDOWN);
  pinMode(AlertaNivelAlto, INPUT_PULLDOWN);

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

  ntp.begin();
  //GMT em segundos
  // +1 = 3600
  // +8 = 28800
  // -1 = -3600
  // -3 = -10800 (BRASIL)
  ntp.setTimeOffset(-10800);

  bot.sendMessage(CHAT_ID, "Iniciando o monitoramento. \nVerificando STATUS da instalação GAMBOA 0." , "");
  delay(1000);
  //handleStatus(CHAT_ID);
  }

void loop() 
{
  Extrav = digitalRead(Extravasamento);
  FCMB1 = digitalRead(FalhaCMB1);
  FCMB2 = digitalRead(FalhaCMB2);
  FCNIVEL = digitalRead(FalhaContNivel);
  FEnergia = digitalRead(FaltaEnergia);
  GERON = digitalRead(GeradorON);
  RODSECA = digitalRead(RodandoSeca);
  TESTESIS = digitalRead(TesteSistema);
  NAlto = digitalRead(AlertaNivelAlto);

    if (Extrav == HIGH) {
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    bot.sendMessage(CHAT_ID, "*** EEE Gamboa 0 *** \nEXTRAVASANDO", "");
    //Serial.print("EXTRAVASANDO");
    delay(10);
    }
    if (FCMB1 == HIGH) {
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    bot.sendMessage(CHAT_ID, "*** EEE Gamboa 0 *** \nFALHA NO CMB 1", "");
    //Serial.print("FALHA NO CMB 1");
    delay(10);
    }
    if (FCMB2 == HIGH) {
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    bot.sendMessage(CHAT_ID, "*** EEE Gamboa 0 *** \nFALHA NO CMB 2", "");
    //Serial.print("FALHA NO CMB 2");
    delay(10);
    }
    if (FCNIVEL == HIGH) {
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    bot.sendMessage(CHAT_ID, "*** EEE Gamboa 0 *** \nFALHA NO CONTROLADOR DE NÍVEL", "");
    //Serial.print("FALHA NO CONTROLADOR DE NÍVEL");
    delay(10);
    }
    if (FEnergia == HIGH) {
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    bot.sendMessage(CHAT_ID, "*** EEE Gamboa 0 *** \nFALTA DE ENERGIA", "");
    //Serial.print("FALTA DE ENERGIA");
    delay(10);
    }
    if (GERON == HIGH) {
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    bot.sendMessage(CHAT_ID, "*** EEE Gamboa 0 *** \nGERADOR LIGADO", "");
    //Serial.print("GERADOR LIGADO");
    delay(10);
    }
    if (RODSECA == HIGH) {
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    bot.sendMessage(CHAT_ID, "*** EEE Gamboa 0 *** \nCMB RODANDO SECO", "");
    //Serial.print("CMB RODANDO SECO");
    delay(10);
    }
    if (TESTESIS == HIGH) {
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    bot.sendMessage(CHAT_ID, "*** EEE Gamboa 0 *** \nTESTE NO SISTEMA DE TELEMETRIA", "");
    //Serial.print("TESTE NO SISTEMA DE TELEMETRIA");
    delay(10);
    }
    if (NAlto == HIGH) {
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    bot.sendMessage(CHAT_ID, "*** EEE Gamboa 0 *** \nNÍVEL MUITO ALTO", "");
    //Serial.print("NÍVEL MUITO ALTO");
    delay(10);
    }
    
 
  uint32_t now = millis();
  if (now - lastCheckTime > INTERVAL) 
  {
    lastCheckTime = now;
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    handleNewMessages(numNewMessages);
  }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void handleNewMessages(int numNewMessages)
{
  for (int i=0; i<numNewMessages; i++) //para cada mensagem nova
  {
    String chatId = String(bot.messages[i].chat_id); //id do chat 
    String senderId = String(bot.messages[i].from_id); //id do contato
    Serial.println("senderId: " + senderId); //mostra no monitor serial o id de quem mandou a mensagem    
    String text = bot.messages[i].text; //texto que chegou
    if (text.equalsIgnoreCase(STATS))
    {
      handleStatus(chatId); //envia mensagem com o estado do relê, temperatura e umidade
    }
    if (text.equalsIgnoreCase(HOUR))
    {
      horario();
    }
  }
}
















