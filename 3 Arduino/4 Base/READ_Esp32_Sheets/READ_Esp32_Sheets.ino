/*	Project : Read Google Spread Sheet Data from ESP32	*/
/*Refer following video for complete project : https://youtu.be/0LoeaewIAdY*/

#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include <Wire.h>

/********************************************************************************/
//Things to change
const char * ssid = "Embasa USA-M";
const char * password = "Sup0rt3!@#";
String GOOGLE_SCRIPT_ID = "AKfycbyGYeJcJfySa65ddHg_L5EmQ96UyvCTnmyURjkV4ZyZv_ZM6D4UbMFYjnXP0GOqETiMeA";

const int sendInterval = 5000; 
/********************************************************************************/

WiFiClientSecure secured_client;

void setup() {
  Serial.begin(115200);
  delay(10);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.println("Started");
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
Serial.println("Ready to go");
//testdrawstyles();
}

void loop() {
  spreadsheet_comm();
  delay(sendInterval);
}


void spreadsheet_comm(void) {
   HTTPClient http;
   String url="https://script.google.com/macros/s/"+GOOGLE_SCRIPT_ID+"/exec?read";
//   Serial.print(url);
	Serial.print("Making a request");
	http.begin(url.c_str()); //Specify the URL and certificate
  http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
	int httpCode = http.GET();
  String payload;
    if (httpCode > 0) { //Check for the returning code
        payload = http.getString();
        
        // Serial.println(httpCode);
        Serial.println(payload);

      }
    else {
      Serial.println("Error on HTTP request");
    }
	http.end();
}