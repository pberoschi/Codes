#include <Arduino.h>
#include <WiFi.h>

const char* ssid = "nome_da_rede";
const char* password =  "senha_da_rede";

void setup() {
 Serial.begin(115200);
// delay(5);
 WiFi.begin(ssid, password);

 while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.println("Connecting to WiFi..");
 }
 Serial.println("Connected to the WiFi network");
}

void loop() {}