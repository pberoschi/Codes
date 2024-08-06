#define TINY_GSM_MODEM_SIM800 //Tipo de modem que estamos usando
#include <TinyGsmClient.h>
#include <PubSubClient.h>
#include <SoftwareSerial.h>
#include <String.h>
#include <math.h>


String textFix = "GET /forms/d/e/1FAIpQLScX15NwADIkvL0lkIj8otwjuVpC6pfQ9_DF-TkubiTLMMrvcQ/formResponse?ifq&";

SoftwareSerial SerialGSM(7, 8);
TinyGsm modemGSM(SerialGSM);
TinyGsmClient gsmClient(modemGSM);
TinyGsmClientSecure client(modemGSM);


const int trigPin = 3;
const int echoPin = 2;
long duration;
float distance;
float q;
float p;
float aberturaParshall = 0.3058;                // Garganta da calha em metro;

//float batMCU = A0;
//float batMOD = A1;
//float vazao;

int resetPin = 12;



void setup()
{
  Serial.begin(115200);//Inicia a comunicacao serial
  setupGSM(); //Inicializa e configura o modem GSM
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(batMCU, INPUT);
  pinMode(batMOD, INPUT);

  digitalWrite(resetPin, HIGH);
  delay(200);
  
  pinMode(resetPin, OUTPUT);



}
void loop()
{
  /*
    vazao = random(0, 300);
    batMCU = random(2.5, 4.5);
    batMOD = random(3, 4.5);
  */

  //batMCU = analogRead(A0) * 0.0045828125;
  //batMOD = analogRead(A1) * 0.0045828125;
  Serial.print("Nivel A0 Bateria MCU: ");
  Serial.println(batMCU);
  delay(100);
  Serial.print("Nivel A1 Bateria MOD: ");
  Serial.println(batMOD);
  delay(100);


  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = 82 - (duration * 0.035 / 2);
  q = 2.2 * aberturaParshall;
  p = pow (distance, 1.5) * q;




  googlesheets();
  //EnvioMedia();


}
