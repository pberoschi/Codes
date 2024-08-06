#include <WiFi.h>
#include <WiFiClientSecure.h>

WiFiClientSecure client;

String textFix = "GET /forms/d/e/1FAIpQLScX15NwADIkvL0lkIj8otwjuVpC6pfQ9_DF-TkubiTLMMrvcQ/formResponse?ifq&";
float batMCU;
float batMOD;
float vazao;



void setup()
{
  Serial.begin(115200);//Inicia a comunicacao serial
  WiFi.begin("House_Tec", "claudia2014");//Conecta na rede
  delay(2000);//Espera um tempo para se conectar no WiFi



}
void loop()
{
  vazao = random(0, 300);
  batMCU = random(2.5, 4.5);
  batMOD = random(3, 4.5);



googlesheets();
//EnvioMedia();

}
