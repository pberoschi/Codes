//Include required libraries
#include "WiFi.h"
#include <HTTPClient.h>


int NivelEEE = 23;


// WiFi credentials
const char* ssid = "Embasa USA-M";         // change SSID
const char* password = "Sup0rt3!@#";    // change password


// Google script ID and required credentials
String GOOGLE_SCRIPT_ID = "AKfycbwuqXXnL-1rsg3_U-OIYVtvyfmYsi1fqG9HvmfNvSvTlibxoTL1BiiYNLismnuycpXueg";    // change Gscript ID

#define ledPin 2
int x;

void setup() {
  pinMode(NivelEEE, OUTPUT);
  ledcAttachPin(NivelEEE, 0);//Atribuimos o pino 23 ao canal 0.
  ledcSetup(0, 1000, 10);//Atribuimos ao canal 0 a frequencia de 1000Hz com resolucao de 10bits.

  pinMode(ledPin , OUTPUT);
  digitalWrite(ledPin, LOW);

  delay(1000);
  Serial.begin(115200);
  delay(1000);

  // connect to WiFi
  Serial.println();
  Serial.print("Connecting to wifi: ");
  Serial.println(ssid);
  Serial.flush();
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

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
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = "https://script.google.com/macros/s/" + GOOGLE_SCRIPT_ID + "/exec?read";
    // Serial.println("Making a request");
    http.begin(url.c_str()); //Specify the URL and certificate
    http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
    int httpCode = http.GET();
    String payload;
    
    if (httpCode > 0) { //Check for the returning code     
            
      payload = http.getString();
      // Serial.println(httpCode);
      Serial.println();
      Serial.print("Leitura de Nível: ");
      Serial.println(payload);

      int payload2 = payload.toInt();
      int payloadCONV = (payload2*1023)/100;
      float tensaoCONV = ((payload2*3.3)/1023)*10;

      Serial.print("Leitura Analógica: ");
      Serial.println(payloadCONV);

      Serial.print("Tensão DC: ");
      Serial.print(tensaoCONV);
      Serial.println(" vdc");

      ledcWrite(0,payloadCONV);

    }
    else {
      Serial.println("Error on HTTP request");
    }
    http.end();
  }
  delay(1000);
}