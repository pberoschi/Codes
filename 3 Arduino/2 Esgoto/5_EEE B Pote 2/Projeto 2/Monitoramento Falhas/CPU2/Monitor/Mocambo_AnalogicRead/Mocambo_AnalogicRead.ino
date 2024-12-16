
// Envio para o sheets e TELEGRAM / TRIFASICO
#include <HTTPClient.h>
#include <WiFi.h>
#include "string.h"

int intervaloLEIT = 2000;
int IntervaloSEND = 0;

#define ledPin 2
int x;
// const char* ssid     = "Embasa USA-M";     // your network SSID (name of wifi network)
// const char* password = "Sup0rt3!@#";       // your network password
const char* ssid     = "ELEVATORIOESGOTOSUL";
const char* password = "87654321";

char *server = "script.google.com";        // Server URL
char *GScriptId1 = "AKfycbxML2q1d-k_IloUnM-ByIyXa8u20JgFRltF8A00xPgvWJekrFJyB_TSLUyIGBT2hwOO"; //planilha teste               
const int httpsPort = 443;
WiFiClientSecure client;

WiFiClientSecure secured_client;
WiFiUDP ntpUDP;

// Leitura Analogica NIVEL 
#define ANALOG_PIN_0 36 
int analog_value = 0;
int read_percent = 0;
float ref_percent = 100;
int adc_intervals = 4095;


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
  Serial.print("IP address: ");
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
  // // Testes com numeros aleatórios     
  // int read_percent_R         = random(0,100);
  // int analog_value_R         = random(0,4095);
  // read_percent = read_percent_R * (ref_percent / adc_intervals);
  // analog_value = analog_value_R;
  // read_percent = int(read_percent);

  read_percent = analogRead(ANALOG_PIN_0) * (ref_percent / adc_intervals);
  analog_value = analogRead(ANALOG_PIN_0);
  read_percent = int(read_percent);

  Serial.println("Leitura de Nível enviada");
  delay(100);
  // Serial.println(read_percent);
  // Serial.println(analog_value);
  
  Serial.println("Chamando a função >>> Google Sheets <<<");

  HTTPClient http;
  String url = String("https://script.google.com") + "/macros/s/" + GScriptId1 + "/exec?" 
                + "value20="    + read_percent
                + "&value21="   + analog_value;

  Serial.print("Making a request");
  http.begin(url.c_str()); //Specify the URL and certificate
  http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
  int httpCode = http.GET();
  String payload;
  if (httpCode > 0) { //Check for the returning code
    payload = http.getString();
    Serial.println(httpCode);
    Serial.println(payload);
  }
  else {
    Serial.println("Error on HTTP request");
  }
  http.end();

  delay(1000);

}  









    













