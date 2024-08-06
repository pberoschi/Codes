void SMS_Baixo()
{
  Serial.begin(9600);
  while(!Serial);
   
  mySerial.begin(9600);
  delay(1000);
   
  Serial.println("Enviando SMS, um momento...");
   
  mySerial.write("AT+CMGF=1\r\n");
  delay(1000);
 
  mySerial.write("AT+CMGS=\"75991383134\"\r\n");
  delay(1000);
   
    mySerial.write("Nivel Baixo Reservatorio Boa Vista");
  delay(1000);
   
  mySerial.write((char)26);
  delay(1000);
     
  Serial.println("Feito");
  
}
