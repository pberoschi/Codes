// Envio para o sheets TRIFASICO

#include <PZEM004Tv30.h>
#include <HTTPClient.h>
#include <WiFi.h>
#include "string.h"
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>

// --- Leitura eletrica
int R_RX1 = 16;
int R_TX1 = 17;
int S_RX2 = 22;
int S_TX2 = 23;
int T_RX3 = 12;
int T_TX3 = 14;

int CMB1 = 25;
int CMB2 = 26;

#define ledPin 2
int x;
const char* ssid     = "Embasa USA-M";
const char* password = "Sup0rt3!@#"; 
char *GScriptId_elet = "AKfycbyHFmwcvGG_hrLkZPeDf_ihIDiOa0enNAKLj7neQkrPeP9CsjRFSr-xJ82m4SFSNjDC";         
char *GScriptId_nivel = "AKfycbyekxrXDfTf8CXXFULq-7YdWpydM_liA4zvQI9XRrLfj4PNPhEoLVWNaAsH9hkru_BfGg";
WiFiClientSecure client;
WiFiClientSecure secured_client;

// --- Leitura Analogica NIVEL 
#define ANALOG_PIN_0 36 
int analog_value = 0;
int read_percent = 0;
float ref_percent = 100;
int adc_intervals = 4095;


void setup() {
  Serial.begin(115200);

  pinMode(ledPin , OUTPUT);
  digitalWrite(ledPin, LOW);

  pinMode(CMB1, INPUT);
  digitalWrite(CMB1, LOW);
  pinMode(CMB2, INPUT);
  digitalWrite(CMB2, LOW);

 
  //connect_wifi();
  Serial.print("Connecting to wifi: ");
  Serial.println(ssid);
  Serial.flush();
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED)  {
    delay(500);
    Serial.print(WiFi.status());
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

 
  //Sinalizacao de conexao OK
  x = 0;
  while (x < 10)  {
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
    x = x+1;
  }
}

void loop() {
  // Serial.println("Chamando a função >>> Google Sheets <<<");
  elet();
  delay(100);
  nivel();

  // ALEATÓRIOS //
  // alea_elet();
  // delay(100);
  // alea_nivel();
}


