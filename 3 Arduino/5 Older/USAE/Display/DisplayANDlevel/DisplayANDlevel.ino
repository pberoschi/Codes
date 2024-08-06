
#include <Arduino.h>
#include <TM1637Display.h>
#include <Ultrasonic.h>
Ultrasonic ultrassom(8,7);

#define CLK 4
#define DIO 5

TM1637Display display(CLK, DIO);

float distancia;
float Sensor_Sistema;
float sistema;
int medicao = 9;



void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(medicao, OUTPUT);
  digitalWrite(medicao, HIGH);
}

void loop() {


/*
  Serial.print(sistema);
  Serial.println(" % Nível Bateria Sistema");
  Serial.print(Sensor_Sistema);
  Serial.println(" Leitura do Sensor Sistema");
  Serial.println("");
*/

  Sensor_Sistema = analogRead(A0); 
  sistema = 100*(Sensor_Sistema-512)/353;
  display.setBrightness(0);                        //0 mais baixo e 7 mais alto
  display.showNumberDec(sistema, false);
  delay(2500);
  display.setBrightness(0);                        //0 mais baixo e 7 mais alto
  display.showNumberDec(Sensor_Sistema, false);
  delay(2500);
     

  distancia = ultrassom.Ranging(CM);
  Serial.print(distancia);
  Serial.println(" cm");
//  Serial.println("");
//  Serial.print(sistema);
//  Serial.println(" leitura sensor");
//  Serial.println("");
  delay(500);
  
}





 /////
 
