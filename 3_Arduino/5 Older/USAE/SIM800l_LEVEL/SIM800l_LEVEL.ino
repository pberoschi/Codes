
#define BLYNK_PRINT Serial
#define TINY_GSM_MODEM_SIM800
#include <TinyGsmClient.h>
#include <BlynkSimpleSIM800.h>
#include <Ultrasonic.h>
Ultrasonic ultrassom(8,7); // trig(8) e o echo(7) respectivamente

//long alarme = 11;

float distancia;
//float calc1;
//float calc2;
//float calc3;
//long calc4;


//long x;

char auth[] = "67lkiVEbch5A-2p_JoBbY-1H3Nl4wLUx";
char apn[]  = "zap.vivo.com.br";
char user[] = "vivo";
char pass[] = "vivo";


#define SerialAT Serial1
#include <SoftwareSerial.h>
SoftwareSerial SerialAT(2, 3);          // RX, TX
TinyGsm modem(SerialAT);
BlynkTimer timer;


void myTimerEvent()
{
  //Blynk.virtualWrite(V5, calc4);
  Blynk.virtualWrite(V6, distancia);
  //Blynk.virtualWrite(V7, x);
  //Blynk.virtualWrite(V8, alarme);
}


void setup()
{
  // Debug console
  Serial.begin(9600);
  delay(10);
  SerialAT.begin(57600);
  delay(3000);
  Serial.println("Initializing modem...");
  modem.restart();
  Blynk.begin(auth, modem, apn, user, pass);
  timer.setInterval(1000L, myTimerEvent);

  //pinMode (alarme, OUTPUT);
 
}

void loop()
{
  Blynk.run();
  timer.run(); 

  //x = random(45, 50);
  //delay(3000);

  //if (x == 49)  {
  //digitalWrite(alarme, HIGH);
  //delay(1500);
  //}  else  {
    //digitalWrite(alarme, LOW);


distancia = ultrassom.Ranging(CM);
   
   //calc1 = (6*2.54/100);
   //calc2 = distancia/100; 
   //calc3 = pow(calc2, 1.5);
   //calc4 = calc1*calc3*2200;
   
   Serial.print(distancia);
   Serial.println(" cm");
   //Serial.print(calc4);      
   //Serial.println(" l/h");
   //Serial.println("");
   //Serial.print(x);
   //Serial.println(" l/s");
   delay(2000);


    
  }

/*
   distancia = ultrassom.Ranging(CM);
   
   //calc1 = (6*2.54/100);
   //calc2 = distancia/100; 
   //calc3 = pow(calc2, 1.5);
   //calc4 = calc1*calc3*2200;
   
   Serial.print(distancia);
   Serial.println(" cm");
   //Serial.print(calc4);      
   //Serial.println(" l/h");
   //Serial.println("");
   //Serial.print(x);
   //Serial.println(" l/s");
   //delay(2500);


*/
