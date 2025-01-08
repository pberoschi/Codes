// #if defined(ESP8266)
// #include <ESP8266WiFi.h>
// #include <ESP8266mDNS.h>
// #elif defined(ESP32)
#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
// #endif

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

  // ArduinoOTA.begin();
  // ArduinoOTA.onStart([]() {
  //   display.clear();
  //   display.setFont(ArialMT_Plain_10);
  //   display.setTextAlignment(TEXT_ALIGN_CENTER_BOTH);
  //   display.drawString(display.getWidth() / 2, display.getHeight() / 2 - 10, "OTA Update");
  //   display.display();
  // });

  // ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
  //   display.drawProgressBar(4, 32, 120, 8, progress / (total / 100) );
  //   display.display();
  // });

  // ArduinoOTA.onEnd([]() {
  //   display.clear();
  //   display.setFont(ArialMT_Plain_10);
  //   display.setTextAlignment(TEXT_ALIGN_CENTER_BOTH);
  //   display.drawString(display.getWidth() / 2, display.getHeight() / 2, "Restart");
  //   display.display();
  // });

  // Align text vertical/horizontal center
  // display.setTextAlignment(TEXT_ALIGN_CENTER_BOTH);
  // display.setFont(ArialMT_Plain_16);
  // display.drawString(display.getWidth() / 2, display.getHeight() / 2, "Ready for OTA:\n" + WiFi.localIP().toString());
  // display.display();
}

void loop() {
  // ArduinoOTA.handle();
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












