//Include required libraries
#include "WiFi.h"
#include <HTTPClient.h>


// WiFi credentials
const char* ssid = "Embasa USA-M";         // change SSID
const char* password = "Sup0rt3!@#";    // change password


// Google script ID and required credentials
String GOOGLE_SCRIPT_ID = "AKfycbwuqXXnL-1rsg3_U-OIYVtvyfmYsi1fqG9HvmfNvSvTlibxoTL1BiiYNLismnuycpXueg";    // change Gscript ID
void setup() {
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
      Serial.print("Leitura de Nível: ");
      Serial.println(payload);
    }
    else {
      Serial.println("Error on HTTP request");
    }
    http.end();
  }
  delay(1000);
}