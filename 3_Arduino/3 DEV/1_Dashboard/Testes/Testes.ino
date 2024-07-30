// Comunicação como o TELEGRAM com o envio de STATUS e adaptado a USAM
// Acrescentado Teste de comunicação a cada hora (hora/hora)
// Portas disponíveis: 4//18//19//14//22//23//25//26//32//33

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

  // pinMode(Extravasamento, INPUT_PULLDOWN);
  // pinMode(FalhaCMB1, INPUT_PULLDOWN);
  // pinMode(FalhaCMB2, INPUT_PULLDOWN);
  // pinMode(FalhaContNivel, INPUT_PULLDOWN);
  // pinMode(FaltaEnergia, INPUT_PULLDOWN);
  // pinMode(GeradorON, INPUT_PULLDOWN);
  // pinMode(RodandoSeca, INPUT_PULLDOWN);
  // pinMode(TesteSistema, INPUT_PULLDOWN);
  // pinMode(AlertaNivelAlto, INPUT_PULLDOWN);

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
  ntp.setTimeOffset(-10800);

  // bot.sendMessage(CHAT_ID, "Iniciando o monitoramento. \nVerificando STATUS da instalação GAMBOA 0." , "");
  // delay(1000);
  //handleStatus(CHAT_ID);
  }

void loop() 
{
  //bot.sendMessage(CHAT_ID, ">>> EEE GAMBOA 0 <<<", "");
 
  //Enviando variáveis da Instalação
  // >>> FASE R <<<
  int tensao_R         = random(380,400);
  int corrente_R       = random(80,98);
  int potencia_R       = random(5500,7800);              
  int consumo_R        = random(1080,1098);
  int frequencia_R     = random(57,60);
  float fp_R           = random(92,98) / 100.0;

  String(a_R) = String("- Tensão: ");
  String(b_R) = String(tensao_R);
  String(c_R) = String(" VCA");

  String(d_R) = String("\n- Corrente: ");
  String(e_R) = String(corrente_R);
  String(f_R) = String(" A");

  String(g_R) = String("\n- Potencia: ");
  String(h_R) = String(potencia_R);
  String(i_R) = String(" W");

  String(j_R) = String("\n- Consumo: ");
  String(l_R) = String(consumo_R);
  String(m_R) = String(" kWh");

  String(n_R) = String("\n- Frequencia: ");
  String(o_R) = String(frequencia_R);
  String(p_R) = String(" Hz");

  String(q_R) = String("\n- FP: ");
  String(r_R) = String(fp_R);


  //String(a) = a_R + b_R + c_R + d_R + e_R + f_R + g_R + h_R + i_R + j_R + l_R + m_R + n_R + o_R + p_R + q_R + r_R;
  String(a) = a_R + b_R + c_R 
            + d_R + e_R + f_R 
            + g_R + h_R + i_R
            + j_R + l_R + m_R 
            + n_R + o_R + p_R 
            + q_R + r_R;


  //String(i) = a + b + c;
  bot.sendMessage(CHAT_ID, ">>> FASE R <<<\n" + a, "");

  delay(30000);
}
















