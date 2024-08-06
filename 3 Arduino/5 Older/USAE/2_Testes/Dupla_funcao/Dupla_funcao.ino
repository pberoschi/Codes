
#include <SoftwareSerial.h>
#include <String.h>

//SoftwareSerial mySerial(7, 8);
SoftwareSerial mySerial(2, 3);

long x;


void setup()
{
  mySerial.begin(9600);
  Serial.begin(9600);
}

void loop()
{

  x = random(45, 51);
  delay(100);
  Serial.begin(9600);
  Serial.print(x);
  Serial.println();
  Serial.println();

  int var = 0;

  if (x == 49)
  {

    while (var < 4) {

      Serial.begin(9600);
      while (!Serial);

      mySerial.begin(9600);
      delay(1000);

      Serial.println("Enviando SMS, um momento...");

      mySerial.write("AT+CMGF=1\r\n");
      delay(1000);

      mySerial.write("AT+CMGS=\"75991383134\"\r\n");
      delay(1000);

      mySerial.write("Nivel Alto Reservatorio Boa Vista");
      delay(1000);

      mySerial.write((char)26);
      delay(1000);

      Serial.println("Feito");

      delay(10000);

      var ++;

    }
  }
}
