
#include <SoftwareSerial.h>
#include <String.h>
 
SoftwareSerial mySerial(7, 8);
//SoftwareSerial mySerial(2, 3);

long x;


void setup()
{
  mySerial.begin(9600);  
  Serial.begin(9600);
 }
 
void loop()
{
      
 x=random(45,51);
 delay(100);
 Serial.begin(9600);
 Serial.print(x);
 Serial.println();     
 Serial.println();     

     
  //GPRS();
  //delay(60000);
  
  Serial.println();
  Serial.println();

if (x == 49){
  SMS_Alto();
  delay(10000);
}
if (x == 48){
  SMS_Baixo();
  delay(10000);
}
}
