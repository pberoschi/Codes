#include <Arduino.h>
#include <TM1637Display.h>
#include <Ultrasonic.h>
Ultrasonic ultrassom(8,7); // trig(8) echo(7)


#define CLK 4
#define DIO 5

TM1637Display display(CLK, DIO);


float distancia;
//float calc1;
//float calc2;
//float calc3;
//float calc4;
 
 void setup() {
 Serial.begin(9600);
  }
 
 void loop()
 {
   distancia = ultrassom.Ranging(CM);
   
   //calc1 = (6*2.54/100);
   //calc2 = distancia/100; 
   //calc3 = pow(calc2, 1.5);
   //calc4 = calc1*calc3*2200;
   
   Serial.print(distancia);
   Serial.println(" cm");
   //Serial.print(calc4);      
   //Serial.println(" l/h");
   Serial.println("");
   delay(2500);

  display.setBrightness(0x0f);                     //Define o brilho do display
  display.showNumberDec(distancia, false);         //Mostra o valor no display
  
}

   
