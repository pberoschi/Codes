//Config-----------------------------------------------------------
const char* ssid        = "insira-aqui-o-nome-da-sua-rede-wifi";
const char* password    = "insira-aqui-a-senha-da-sua-rede-wifi";
 
 
const char* GScriptId   = "insira-aqui-o-seu-id-do-google-scripts";
//-----------------------------------------------------------------
 
 
String payload_base =  "{\"command\": \"append_row\", \"sheet_name\": \"Sheet1\", \"values\": ";
String payload = "";
 
const char* host        = "script.google.com";
const int   httpsPort   = 443;
String      url         = String("/macros/s/") + GScriptId + "/exec?cal";
 
 
//WiFi----------------------
//#include <WiFi.h>
#include <ESP8266WiFi.h>
#include "HTTPSRedirect.h"
 
 
//Objects----------------------------------
HTTPSRedirect* client = nullptr;
//-----------------------------------------
 
 
//Control Variables------------------------
int value0 = 0;
int value1 = 0;
int value2 = 0;
//-----------------------------------------
 
 
void setup()
{
  Serial.begin(115200);
 
  //WiFi Setup
  Serial.print("Conectando ao WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED){ Serial.print("."); delay(500); }
  Serial.println("[OK]");
 
  //HTTPS Redirect Setup
  client = new HTTPSRedirect(httpsPort);
  client->setInsecure();
  client->setPrintResponseBody(true);
  client->setContentTypeHeader("application/json");
  Serial.print("Conectando ao Google...");
 
  bool flag = false;
  for (int i=0; i<5; i++)
  { 
    int retval = client->connect(host, httpsPort);
    if (retval == 1)
    {
       flag = true;
       Serial.println("[OK]");
       break;
    }
    else
      Serial.println("[Error]");
  }
  if (!flag)
  {
    Serial.print("[Error]");
    Serial.println(host);
    return;
  }
  delete client;
  client = nullptr;
}
 
void loop()
{
  value0 ++;
  value1 = analogRead(0);
  value2 = value1/1023*3.3;
 
  static bool flag = false;
  if (!flag)
  {
    client = new HTTPSRedirect(httpsPort);
    client->setInsecure();
    flag = true;
    client->setPrintResponseBody(true);
    client->setContentTypeHeader("application/json");
  }
  if (client != nullptr) { if (!client->connected()){ client->connect(host, httpsPort); } }
  else { Serial.println("[Error]"); }
   
  payload = payload_base + "\"" + value0 + "," + value1 + "," + value2 + "\"}";
   
  Serial.println("Enviando...");
  if(client->POST(url, host, payload)){ Serial.println(" [OK]"); }
  else { Serial.println("[Error]"); }
   
  delay(10000);  
}