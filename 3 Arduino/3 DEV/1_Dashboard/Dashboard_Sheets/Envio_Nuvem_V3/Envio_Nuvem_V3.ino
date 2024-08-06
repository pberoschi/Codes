// -> https://www.crescerengenharia.com/post/aprenda-como-usar-o-esp32-para-publicar-dados-no-google-sheets

#include <HTTPClient.h>
#include <WiFi.h>
#include "string.h"

#define ledPin 2
int x;
const char* ssid     = "Embasa USA-M";     // your network SSID (name of wifi network)
const char* password = "Sup0rt3!@#"; // your network password
char *server = "script.google.com";  // Server URL
char *GScriptId = "AKfycbyZjSA6UNPOh0n8qLYa-vynd1YAYfOgf-PgYTp8FC1CQICqR0qioNnAPuArrSlDOj2PCA"; //planilha teste               
const int httpsPort = 443;
WiFiClientSecure client;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin , OUTPUT);
  digitalWrite(ledPin, LOW); 

  //connect_wifi();
  Serial.print("Connecting to wifi: ");
  Serial.println(ssid);
  Serial.flush();
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(WiFi.status());
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  //Sinalizacao de conexao OK
  x = 0;
  while (x < 10)
  {
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
    x = x+1;
  }
}

void loop() {
 //disableCore0WDT();
 enviarMedicao();
 }

