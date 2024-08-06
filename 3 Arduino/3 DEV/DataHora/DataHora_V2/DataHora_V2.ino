//https://www.efeitonerd.com.br/2021/04/data-e-hora-no-esp32-ntp.html

#include <NTPClient.h> //https://github.com/taranais/NTPClient
#include <WiFi.h>

const char ssid[] = "Embasa USA-M";
const char password[] = "Sup0rt3!@#";

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
  if (ntp.update()) {
    Serial.print("DATA/HORA: ");
    Serial.println(ntp.getFormattedDate());

    Serial.print("HORARIO: ");
    Serial.println(ntp.getFormattedTime());

    Serial.print("HORA: ");
    Serial.println(ntp.getHours());

    Serial.print("MINUTOS: ");
    Serial.println(ntp.getMinutes());

    Serial.print("SEGUNDOS: ");
    Serial.println(ntp.getSeconds());

    Serial.print("DIA DA SEMANA (0=domingo): ");
    Serial.println(ntp.getDay());

    Serial.print("EPOCH TIME (Segundos desde 01/01/1970): ");
    Serial.println(ntp.getEpochTime());

    Serial.println();

  } else {
    Serial.println("!Erro ao atualizar NTP!\n");
  }
  delay(10000);
}