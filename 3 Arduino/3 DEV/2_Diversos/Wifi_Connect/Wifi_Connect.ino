#if defined(ESP8266)
#include <ESP8266WiFi.h>        
#else
#include <WiFi.h>
#endif
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
//#include <SimpleDHT.h>
#define LED 2

//Pino onde está o Relê
#define RELAY_PIN 5
//Pino onde está o DHT22
#define DHT_PIN 4

//Intervalo entre as checagens de novas mensagens
#define INTERVAL 1000

//Token do seu bot. Troque pela que o BotFather te mostrar
#define BOT_TOKEN "000000000:XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"

//Troque pelo ssid e senha da sua rede WiFi
#define SSID "Embasa USA-M"
#define PASSWORD "Sup0rt3!@#"


//Comandos aceitos
const String LIGHT_ON = "ligar a luz";
const String LIGHT_OFF = "desligar a luz";
const String CLIMATE = "clima";
const String STATS = "status";
const String START = "/start";

//Objeto que realiza a leitura da temperatura e umidade
//SimpleDHT22 dht;

//Estado do relê
int relayStatus = HIGH;

//Cliente para conexões seguras
WiFiClientSecure client;
//Objeto com os métodos para comunicarmos pelo Telegram
UniversalTelegramBot bot(BOT_TOKEN, client);
//Tempo em que foi feita a última checagem
uint32_t lastCheckTime = 0;

//Quantidade de usuários que podem interagir com o bot
#define SENDER_ID_COUNT 2
//Ids dos usuários que podem interagir com o bot. 
//É possível verificar seu id pelo monitor serial ao enviar uma mensagem para o bot
String validSenderIds[SENDER_ID_COUNT] = {"012345678", "123456789"};




void setup()
{
  Serial.begin(115200);
  pinMode(LED,OUTPUT);


  //Inicializa o WiFi e se conecta à rede
  setupWiFi();

  //Coloca o pino do relê como saída e enviamos o estado atual
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, relayStatus);

}



void setupWiFi()
{
  Serial.print("Connecting to SSID: ");
  Serial.println(SSID);

  //Inicia em modo station e se conecta à rede WiFi
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASSWORD);

  //Enquanto não estiver conectado à rede
  while (WiFi.status() != WL_CONNECTED)
  //digitalWrite(LED,LOW);
  
  {
    Serial.print(".");
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    delay(500);
  }

  //Se chegou aqui está conectado
  Serial.println();
  Serial.println("Connected");
  digitalWrite(LED,HIGH);
}


void loop() {
  // put your main code here, to run repeatedly:

}
