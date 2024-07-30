//Leitura de distância com o sensor HC-SR04
#include <Ultrasonic.h>
 Ultrasonic ultrassom(3,2); // define o nome do sensor(ultrassom)
//e onde esta ligado o trig(8) e o echo(7) respectivamente

float distancia;
float calc1;
float calc2;
float calc3;
float calc4;

 
// Esta função "setup" roda uma vez quando a placa e ligada ou resetada
 void setup() {
 Serial.begin(9600); //Habilita Comunicação Serial a uma taxa de 9600 bauds.
 
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
 }
