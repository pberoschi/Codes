// This example retrieves last value of a variable from the Ubidots API
// using TCP protocol.

/****************************************
 * Include Libraries
 ****************************************/
#include <Ubidots.h>

/****************************************
 * Define Constants
 ****************************************/
// Your GPRS credentials, if any
const char *APN = "zap.vivo.com.br";
const char *USER = "vivo";
const char *PASS = "vivo";
const char *TOKEN = "BBFF-hlEF97XzTkjGpavlWhKUI8uQ2zHgIy"; 
const char *DEVICE_LABEL = "5f5a1a671d847243b5af3edf"; 
const char *VARIABLE_LABEL = "ard_gprs";

Ubidots client(TOKEN,APN,USER,PASS);


/****************************************
 * Auxiliar Functions
 ****************************************/

// Put here your auxiliar functions

/****************************************
 * Main Functions
 ****************************************/

void setup() {
  Serial.begin(115200);
  client.setDebug(true); // Set true to make available debug messages
}

void loop() {
  float value = analogRead(A0);  // Reading analog pin A0
  client.add(VARIABLE_LABEL, value);  
  
  if(client.send()){
  	Serial.println("Data sent to Ubidots sucessfully!")
  }

  delay(5000);
}
