#define TINY_GSM_MODEM_SIM800 //Tipo de modem que estamos usando
#include <TinyGsmClient.h>
#include <PubSubClient.h>
#include <SoftwareSerial.h>
#include <String.h>
#include <math.h>


SoftwareSerial SerialGSM(7, 8);
TinyGsm modemGSM(SerialGSM);
TinyGsmClient gsmClient(modemGSM);
TinyGsmClientSecure client(modemGSM);


String textFix = "GET /forms/d/e/1FAIpQLSdbhYz8EwM4jECp3OCtt4KmJUeK4LbgZ82uKr3_TebA9rr1-w/formResponse?ifq&entry.313146852=";
const int trigPin = 3;
const int echoPin = 2;
long duration;
float distance;
float cent;
float q;
float p;

int aberturaParshall = 0.3058;         // Garganta da calha em metro;



void setup()
{
  Serial.begin(115200);

}


void loop()
{


  distance = 16;
  q = 2.2 * aberturaParshall;
  p = pow (distance, 1.5) * q;

  
  

  Serial.println(q);
  Serial.print(p);
  Serial.println(" l/s");
  delay(50000);

}
