
#include <SoftwareSerial.h>
#include <String.h>
 
SoftwareSerial mySerial(7, 8);

boolean pin2=LOW,pin3=LOW,pin4=LOW,pin5=LOW,pin6=LOW; 
float temp=0.0;

void setup()
{
  mySerial.begin(9600);  
  Serial.begin(9600);    
   
  delay(10);
}
 
void loop()
{
      temp=analogRead(A0);
      temp=temp*0.4887;  
      delay(2);          
      Send2Pachube();
   
  if (mySerial.available())
    Serial.write(mySerial.read());
}
void Send2Pachube()
{
  mySerial.println("AT");
  delay(10);
  mySerial.println("AT+CBC");
  delay(10);
  mySerial.println("AT+CSQ");
  delay(10);
  mySerial.println("AT+CPIN?");
  delay(10);
  mySerial.println("AT+CREG?");
  delay(10);
  mySerial.println("AT+CGATT?");
  delay(10);
  mySerial.println("AT+CIPSHUT");
  delay(10);
  mySerial.println("AT+CIPSTATUS");
  delay(20);
  mySerial.println("AT+CIPMUX=0");
  delay(20);

  mySerial.println("AT+CSTT=\"zap.vivo.com.br\",\"vivo\",\"vivo\"");
  delay(10);

  mySerial.println("AT+CIICR");//bring up wireless connection
  delay(30);
  
  mySerial.println("AT+CIFSR");//get local IP adress
  delay(200);
  
  mySerial.println("AT+CIPSPRT=0");
  delay(300);

}
  
 /* 
  mySerial.println("AT+CIPSTART=\"TCP\",\"docs.google.com\",\"443\"");
  delay(6000);
  ShowSerialData();
  
  mySerial.println("AT+CIPSEND");//begin send data to remote server
  delay(4000);
  ShowSerialData();
  
  //String str="GET http://api.thingspeak.com/update?api_key=KTQXXXXXXXXXXXXX&field1=" + String(temp);
  String str="GET http://api.thingspeak.com/update?api_key=CDDCN1GVVSOPBBMB&field1=10";
  mySerial.println(str);//begin send data to remote server
  delay(4000);
  ShowSerialData();
  
  mySerial.println((char)26);//sending
  delay(5000);//waitting for reply, important! the time is base on the condition of internet 
  
  mySerial.println();
  ShowSerialData();
  
  mySerial.println("AT+CIPSHUT");//close the connection
  delay(100);
  ShowSerialData();
} 
*/
void ShowSerialData()
{
  while(mySerial.available()!=0)
    Serial.write(mySerial.read());
}
