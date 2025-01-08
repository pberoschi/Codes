#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <Wire.h>
#include "SSD1306Wire.h"

const char *ssid         = "Embasa USA-M";
const char *password     = "Sup0rt3!@#";

SSD1306Wire display(0x3c, 5, 4);  

void setup() {
  WiFi.begin ( ssid, password );

  // Wait for connection
  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 10 );
  }

  display.init();
  display.flipScreenVertically();
  display.setContrast(255);
}

void loop() {
  embasa();
  ip(); 
}




void embasa()  {
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_CENTER_BOTH);
  display.setFont(ArialMT_Plain_24);
  display.drawString(display.getWidth() / 2, display.getHeight() / 2, "EMBASA\n");
  display.display();
  delay(2000);

}



void ip()  {
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_CENTER_BOTH);
  display.setFont(ArialMT_Plain_16);
  display.drawString(display.getWidth() / 2, display.getHeight() / 2, "USAM\n" + WiFi.localIP().toString());
  display.display();
  delay(2000);

}












