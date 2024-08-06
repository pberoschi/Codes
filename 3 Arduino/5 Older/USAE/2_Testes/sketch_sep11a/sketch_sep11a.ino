
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

  x = random(39, 51);
  delay(100);

  if (mySerial.available())
    Serial.write(mySerial.read());

{
  mySerial.println("AT");
  delay(1000);
  mySerial.println("AT+CBC");
  delay(1000);
  mySerial.println("AT+CSQ");
  delay(1000);
  mySerial.println("AT+CPIN?"); //entre com o PIN
  delay(1000);
  mySerial.println("AT+CREG?"); //registro na rede
  delay(1000);
  mySerial.println("AT+CGATT?"); //rede GPRS
  delay(1000);
  mySerial.println("AT+CIPSHUT"); //Desativar contexto GPRS PDP
  delay(1000);
  mySerial.println("AT+CIPSTATUS");   //Consulta do status atual da conexão
  delay(2000);
  mySerial.println("AT+CIPMUX=0");  //Iniciar conexão multi-IP
  delay(2000);
  ShowSerialData();

  mySerial.println("AT+CSTT=\"zap.vivo.com.br\",\"vivo\",\"vivo\"");
  delay(1000);
  ShowSerialData();

  mySerial.println("AT+CIICR"); //Ative a conexão sem fio com GPRS ou CSD
  delay(3000);
  ShowSerialData();

  mySerial.println("AT+CIFSR"); //Obter endereço IP local
  delay(2000);
  ShowSerialData();

  mySerial.println("AT+CIPSPRT=0"); // Definir prompt de '>' quando o módulo envia dados
  delay(3000);
  ShowSerialData();

  mySerial.println("AT+CIPSTART=\"TCP\",\"maker.ifttt.com\",\"80\"");
  delay(6000);
  ShowSerialData();

  mySerial.println("AT+CIPSEND");   //envio dados via TCP ou UDP
  delay(4000);
  ShowSerialData();

  //String str="GET http://api.thingspeak.com/update?api_key=KTQXXXXXXXXXXXXX&field1=" + String(temp);
  String str = "GET http://api.thingspeak.com/update?api_key=CDDCN1GVVSOPBBMB&field1=" + String(x);
  //String str="/forms/d/e/1FAIpQLSfdJMZiPLLmkjtN0yNxUrJOF6w5JQ2IKDjdsVYAFG7QAgLd9g/formResponse?ifq&entry.1719005345=36";
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
  while (mySerial.available() != 0)
    Serial.write(mySerial.read());

}
