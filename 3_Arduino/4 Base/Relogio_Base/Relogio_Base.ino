#include <NTPClient.h>
#include <WiFi.h> // for WiFi shield
#include <WiFiUdp.h>

const char *ssid     = "Embasa USA-M";
const char *password = "Sup0rt3!@#";

WiFiUDP ntpUDP;
NTPClient ntp(ntpUDP);

void setup(){
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.println ( "." );
  }
  ntp.begin();
  ntp.setTimeOffset(-10800); //-10800 Formato Brasil
}

void loop() {
  ntp.update();
  // Serial.println(ntp.getFormattedDate());
  Serial.println(ntp.getFormattedTime());
  // Serial.println(ntp.getHours());
  // Serial.println(ntp.getMinutes());
  // Serial.println(ntp.getSeconds());
  // Serial.println(ntp.getDay());

  delay(5000);
}
