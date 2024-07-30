//https://www.efeitonerd.com.br/2021/04/data-e-hora-no-esp32-ntp.html

#include <NTPClient.h> //https://github.com/taranais/NTPClient
#include <WiFi.h>

const char ssid[] = "Embasa USA-M";
const char password[] = "Sup0rt3!@#";
const String datafull = "";
const int hora = 0;
const int minuto = 0;
const int segundo = 0;

WiFiUDP ntpUDP;
NTPClient ntp(ntpUDP);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.print("Conectando no WiFi..");
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println("\nConectado!\n");

  ntp.begin();
  //GMT em segundos
  // +1 = 3600
  // +8 = 28800
  // -1 = -3600
  // -3 = -10800 (BRASIL)
  ntp.setTimeOffset(-10800);

}

void loop() {
  horario();
  //delay(10000);

}