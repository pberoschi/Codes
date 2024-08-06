
#include <SoftwareSerial.h>
#include <String.h>

SoftwareSerial mySerial(7, 8);
//SoftwareSerial mySerial(2, 3);

const int trigPin = 3;
const int echoPin = 2;
long duration;
int distance;

void setup()
{

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  mySerial.begin(9600);
  Serial.begin(9600);

}

void loop()
{

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  //distance= duration*0.034/2;
  distance = duration * 0.035 / 2;

  Serial.print("Distancia: ");
  Serial.println(distance);



  if (mySerial.available())
    Serial.write(mySerial.read());

  //mySerial.println("AT");
  //delay(1000);
  //mySerial.println("AT+CBC");
  //delay(1000);
  //mySerial.println("AT+CSQ");
  //delay(1000);

  //mySerial.println("AT+CPIN?"); //entre com o PIN
  //delay(500);

  mySerial.println("AT+CREG?"); //registro na rede
  delay(500);

  mySerial.println("AT+CGATT?"); //rede GPRS
  delay(500);

  mySerial.println("AT+CIPSHUT"); //Desativar contexto GPRS PDP
  delay(500);

  mySerial.println("AT+CIPSTATUS");   //Consulta do status atual da conexão
  delay(500);

  mySerial.println("AT+CIPMUX=0");  //Iniciar conexão multi-IP
  delay(500);

  ShowSerialData();
  mySerial.println("AT+CSTT=\"zap.vivo.com.br\",\"vivo\",\"vivo\"");
  delay(500);

  ShowSerialData();
  mySerial.println("AT+CIICR"); //Ative a conexão sem fio com GPRS ou CSD
  delay(2000);

  ShowSerialData();
  mySerial.println("AT+CIFSR"); //Obter endereço IP local
  delay(500);

  ShowSerialData();
  mySerial.println("AT+CIPSPRT=0"); // Definir prompt de '>' quando o módulo envia dados
  delay(500);

  ShowSerialData();
  mySerial.println("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",\"80\"");
  delay(2000);

  ShowSerialData();
  mySerial.println("AT+CIPSEND");   //envio dados via TCP ou UDP
  delay(1000);

  ShowSerialData();
  String str = "GET http://api.thingspeak.com/update?api_key=CDDCN1GVVSOPBBMB&field1=" + String(distance);
  mySerial.println(str);//begin send data to remote server
  delay(1000);

  ShowSerialData();
  mySerial.println((char)26);   //sending
  //delay(5000);                  //waitting for reply, important! the time is base on the condition of internet
  delay(3000);                  //waitting for reply, important! the time is base on the condition of internet

  mySerial.println();

  ShowSerialData();
  mySerial.println("AT+CIPSHUT");           //close the connection
  delay(500);

  ShowSerialData();
  //delay(5000);                             // 1 min: 60.000 / 5 min: 300.000 / 10 min: 600.000


}

void ShowSerialData()
{
  while (mySerial.available() != 0)
    Serial.write(mySerial.read());

}
