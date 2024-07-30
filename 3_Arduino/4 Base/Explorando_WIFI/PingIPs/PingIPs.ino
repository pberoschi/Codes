//https://www.efeitonerd.com.br/2022/10/teste-de-rede-com-ping-no-esp32.html

#include <WiFi.h>
#include <ESP32Ping.h>
#include <UniversalTelegramBot.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>

// Initialize Telegram BOT
String BOTtoken = "6135423460:AAGvQYE39MHGyYtb4g78JpKl_Z4X279aUKc";  // your Bot Token (Get from Botfather)
String CHAT_ID = "984798692";
//String CHAT_ID = "-4005635677";

WiFiClientSecure clientTCP;
UniversalTelegramBot bot(BOTtoken, clientTCP);

int x = 0;
int y = 0;

const char* ssid     = "Embasa USA-M";
const char* password = "Sup0rt3!@#";

char* remoteHost = "www.google.com";                    //IP ou endereço web para realizar o ping
const IPAddress remote_ip1(192, 168, 0, 134);
const IPAddress remote_ip2(192, 168, 0, 139);

// String ListaIPs[] = { 
//   {"192, 168, 0, 139"},
//   {"192, 168, 0, 134"}
// };

void setup() {
  Serial.begin(115200);
  delay(10);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println("Connecting to WiFi");
  
  WiFi.begin(ssid, password);
  clientTCP.setCACert(TELEGRAM_CERTIFICATE_ROOT);            // Add root certificate for api.telegram.org
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("WiFi connected with ip ");  
  Serial.println(WiFi.localIP());

}

void loop() { 

  //Serial.print("\nPing em ");
  //Serial.println(remote_ip1);
  //Ping no remoteHost
  if (Ping.ping(remote_ip1, 3)) {                  //Parâmetros: (remoteHost, quantidade_pings (default=5))
    //Serial.print(Ping.averageTime());             //Retorna o tempo médio dos pings
    //Serial.println(" ms");
    if (x == 0){
      Serial.print("JOHNNY ON / ");
      Serial.println(remote_ip1);
      bot.sendMessage(CHAT_ID, "Papai ESTÁ em casa", "");
      x = 1;
    }
    
  } else {
      if (x == 1);{
      //Serial.println("Erro.");
      Serial.println("JOHNNY OFF");
      bot.sendMessage(CHAT_ID, "Papai NÃO ESTÁ em casa", "");
      x = 0;
      }
    
  }
  Serial.println("_");
  delay(100);
///////////////////////////////////////////////////////////////

  //Serial.print("\nPing em ");
  //Serial.println(remote_ip2);
  //Ping no remoteHost
  if (Ping.ping(remote_ip2, 3)) {             
    //Serial.print(Ping.averageTime());            
    //Serial.println(" ms");
    Serial.print("ESP32_2 ON / ");
    Serial.println(remote_ip2);
    // bot.sendMessage(CHAT_ID, "Mamãe ESTÁ em casa", "");
  } else {
    //Serial.println("Erro.");
    Serial.println("ESP32_2 OFF");
    // bot.sendMessage(CHAT_ID, "Mamãe SAIU de casa", "");
  }

  delay(2000);


Serial.println("_");
}
