/*
#include <SoftwareSerial.h>
#include <String.h>
SoftwareSerial mySerial(7, 8);

long x;


//boolean pin2=LOW,pin3=LOW,pin4=LOW,pin5=LOW,pin6=LOW; 
//float temp=0.0;


void setup()
{
  mySerial.begin(9600);  
  Serial.begin(9600);
  
  //pinMode(2,INPUT);
  //pinMode(3,INPUT);
  //pinMode(4,INPUT);
  //pinMode(5,INPUT);  
  //pinMode(6,INPUT);  
  //delay(1000);
}
 
void loop()
{
      
 x=random(45,50);
 delay(100);     
      
      
//temp=analogRead(A0);
//temp=temp*0.4887;  
//delay(2);          

//void Send2Pachube();
   
  if (mySerial.available())
    Serial.write(mySerial.read());
//}


//void Send2Pachube()
//{
  mySerial.println("AT");
  delay(1000);
  mySerial.println("AT+CBC");
  delay(1000);
  mySerial.println("AT+CSQ");
  delay(1000);
  mySerial.println("AT+CPIN?");
  delay(1000);
  mySerial.println("AT+CREG?");
  delay(1000);
  mySerial.println("AT+CGATT?");
  delay(1000);
  mySerial.println("AT+CIPSHUT");
  delay(1000);
  mySerial.println("AT+CIPSTATUS");
  delay(2000);
  mySerial.println("AT+CIPMUX=0");
  delay(2000);
  ShowSerialData();
  
  mySerial.println("AT+CSTT=\"zap.vivo.com.br\",\"vivo\",\"vivo\"");
  delay(1000);
  ShowSerialData();

  mySerial.println("AT+CIICR");
  delay(3000);
  ShowSerialData();
  
  mySerial.println("AT+CIFSR");
  delay(2000);
  ShowSerialData();
  
  mySerial.println("AT+CIPSPRT=0");
  delay(3000);
  ShowSerialData();
  
  mySerial.println("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",\"80\"");
  delay(6000);
  ShowSerialData();
  
  mySerial.println("AT+CIPSEND");
  delay(4000);
  ShowSerialData();
  
  //String str="GET http://api.thingspeak.com/update?api_key=KTQXXXXXXXXXXXXX&field1=" + String(temp);
  String str="GET http://api.thingspeak.com/update?api_key=CDDCN1GVVSOPBBMB&field1=" + String(x);
  mySerial.println(str);//begin send data to remote server
  delay(4000);
  ShowSerialData();
  
  mySerial.println((char)26);   //sending
  delay(5000);                  //waitting for reply, important! the time is base on the condition of internet 
  
  mySerial.println();
  ShowSerialData();
  
  mySerial.println("AT+CIPSHUT");           //close the connection
  delay(3000);
  ShowSerialData();

  delay(300000);                             // 1 min: 60.000 / 5 min: 300.000 / 10 min: 600.000 

  // 60.000: 02"50
} 

void ShowSerialData()
{
  while(mySerial.available()!=0)
    Serial.write(mySerial.read());

}




*/
