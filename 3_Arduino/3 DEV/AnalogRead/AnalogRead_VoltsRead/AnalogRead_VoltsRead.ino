// Envio para o sheets e TELEGRAM / TRIFASICO
#include <PZEM004Tv30.h>
#include <HTTPClient.h>
#include <WiFi.h>
#include "string.h"

#define ledPin 2              

int x;
const char* ssid     = "Embasa USA-M";     // your network SSID (name of wifi network)
const char* password = "Sup0rt3!@#";       // your network password
// const char* ssid     = "E.E.E";
// const char* password = "GAMBOA-0";

char *server = "script.google.com";        // Server URL
char *GScriptId1 = "AKfycby_lpNpKvxaUHXzJdYF9Jz-zvJRuXYWNhPzFv-9MPm49dvs8OgSJs2IvY-T9n92IMIR"; //planilha teste               
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


// Leitura Tensao  
int R_RX1 = 16;
int R_TX1 = 17;



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

  PZEM004Tv30 pzemR(Serial1, R_RX1, R_TX1);

}

void loop() {
  // Testes com numeros aleatórios     
  int read_percent_R         = random(0,100);
  int analog_value_R         = random(0,4095);
  read_percent = read_percent_R * (ref_percent / adc_intervals);
  analog_value = analog_value_R;
  read_percent = int(read_percent);

  // read_percent = analogRead(ANALOG_PIN_0) * (ref_percent / adc_intervals);
  // analog_value = analogRead(ANALOG_PIN_0);
  // read_percent = int(read_percent);

  delay(100);
  // Serial.println(read_percent);
  // Serial.println(analog_value);
  // Serial.println("Leitura de Nível enviada");
  



   //--------------------------------------------------> FASE R <--------------------------------------------------

  // PZEM004Tv30 pzemR(Serial1, R_RX1, R_TX1); 
  
  // int tensao_R      = pzemR.voltage();
  // int corrente_R    = pzemR.current();
  // int potencia_R    = pzemR.power();                    // ---> LEITURA DIRETA DO TRANSDUTOR <---
  // int consumo_R     = pzemR.energy();
  // int frequencia_R  = pzemR.frequency();
  // int fp_R          = pzemR.pf() / 100.0;

  // // Print the values to the Serial console
  // Serial.print("Tensão_R: ");        Serial.print(tensao_R);           Serial.println("V");
  // Serial.print("Corrente_R: ");      Serial.print(corrente_R);         Serial.println("A");
  // Serial.print("Potencia_R: ");      Serial.print(potencia_R);         Serial.println("W");
  // Serial.print("Consumo_R: ");       Serial.print(consumo_R,3);        Serial.println("kWh");
  // Serial.print("Frequencia_R: ");    Serial.print(frequencia_R, 1);    Serial.println("Hz");
  // Serial.print("FP_R: ");            Serial.println(fp_R);

  // Serial.println();
  // delay(100);

  // ------------------------------------------------------ (TESTES // Gerador de números aleatórios)-------//    
  int tensao_R         = random(380,400);
  // int corrente_R       = random(80,98);
  // int potencia_R       = random(5500,7800);              
  // int consumo_R        = random(1080,1098);
  // int frequencia_R     = random(57,60);
  // float fp_R           = random(92,98) / 100.0;

   Serial.println("Dados FASE R enviados");
   delay(100);
  // -------------------------------------------------------------------------------------------------------// 




  

  HTTPClient http;
  String url = String("https://script.google.com") + "/macros/s/" + GScriptId1 + "/exec?" 
                + "value45="    + read_percent
                + "&value46="   + analog_value
                + "&value47="   + tensao_R;

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









    













