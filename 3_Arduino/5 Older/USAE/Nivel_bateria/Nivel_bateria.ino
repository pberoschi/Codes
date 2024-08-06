
#include <Arduino.h>
#include <TM1637Display.h>


#define CLK 4
#define DIO 5

TM1637Display display(CLK, DIO);

float sensorValue;
int percent;




void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {

  Serial.print(percent);
  Serial.println(" % Bateria");
  Serial.print(sensorValue);
  Serial.println(" Leitura sensor");
  sensorValue = analogRead(A0);
  //percent = (sensorValue*100)/353;
  percent = 100*(sensorValue-512)/353;
  delay(2000);
  Serial.println("");

  display.setBrightness(0);                        //0 mais baixo e 7 mais alto
  display.showNumberDec(A0, false);   

  
}
