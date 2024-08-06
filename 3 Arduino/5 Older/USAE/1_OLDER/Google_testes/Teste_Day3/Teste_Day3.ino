#include <SoftwareSerial.h>                           // Incluimos a livraria SoftwareSerial
SoftwareSerial mySerial(2, 3);                        // Declaramos os pinos RX(8) y TX(9) que vamos a usar


//**********************************************************************************************************
void setup(){
//**********************************************************************************************************
Serial.begin(9600);                                               // Iniciamos a comunicação serie
mySerial.begin(9600);                                             // Iniciamos uma segunda comunicação serie
delay(1000);                                                      // Pausa de 1 segundo

////////////////////////////////////

 mySerial.println("AT+CBC");                                      // Ativamos a função de.................. 
 delay(1000);
 mySerial.println("AT+CSQ");                                      // Ativamos a função de.................. 
 delay(1000);
 //mySerial.println("AT+CIPMODE=0");
 //delay(2000);
 mySerial.println("AT+CIPMUX=0");
 delay(2000);
 //mySerial.println("AT+CGATT=1");
 //delay(2000);
 //mySerial.println("AT+CREG?");
 //delay(2000);
 //mySerial.println("AT+CGATT?");
 //delay(2000);
 //mySerial.println("AT+CSTT="zap.vivo.com.br","vivo","vivo"");
 //delay(2000);
 //mySerial.println("AT+CIICR");
 //delay(2000);
 //mySerial.println("AT+CIFSR");
 ////////////////////////////////////

 
}

//********************************************************************************************************
void loop(){
//********************************************************************************************************
if (mySerial.available()){                                    // Se a comunicação SoftwareSerial tem dados
  Serial.write(mySerial.read());                              // Obtemo-los por comunicação serie normal
} 
if (Serial.available()){                                      // Se a comunicação serie normal tem dados
  while(Serial.available()) {                                 // e enquanto tenha dados para mostrar 
    mySerial.write(Serial.read());                            // Obtemos pela comunicação SoftwareSerial
  }
  mySerial.println();                                         // Enviamos um fim de linha
}
 
}
