#include <SoftwareSerial.h>                           // Incluimos a livraria SoftwareSerial
SoftwareSerial mySerial(7, 8);                        // Declaramos os pinos RX(8) y TX(9) que vamos a usar
float temp=0.0;


//**********************************************************************************************************
void setup(){
//**********************************************************************************************************
Serial.begin(9600);                                               // Iniciamos a comunicação serie
mySerial.begin(9600);                                             // Iniciamos uma segunda comunicação serie
delay(1000);                                                      // Pausa de 1 segundo

}

//********************************************************************************************************
void loop(){
//********************************************************************************************************



temp=analogRead(A0);
temp=temp*0.4887;
delay(2000);
  start();

if (mySerial.available())                                    // Se a comunicação SoftwareSerial tem dados
  Serial.write(mySerial.read());                              // Obtemo-los por comunicação serie normal
}


void start()
{
 mySerial.println("AT");                                      // Ativamos a função de.................. 
 delay(100); 
  mySerial.println("AT+CBC");                                      // Ativamos a função de.................. 
 delay(100);
 mySerial.println("AT+CSQ");                                      // Ativamos a função de.................. 
 delay(200);


   
   
   
   
   while(mySerial.available()!=0)
    Serial.write(mySerial.read());
 
}


//**********************************************************************************************************
/*
// Função para o envio de um SMS
void EnviaSMS(){              
 mySerial.println("AT+CMGF=1");                 // Activamos a função de envio de SMS
 delay(100);                                    // Pequena pausa
 mySerial.println("AT+CMGS="+351XXXXXXXXX"");  // Definimos o número do destinatário em formato internacional
 delay(100);                                    // Pequena pausa
 mySerial.print("Olá Mundo!");                 // Definimos o corpo da mensagem
 delay(500);                                    // Pequena pausa
 mySerial.print(char(26));                      // Enviamos o equivalente a Control+Z 
 delay(100);                                    // Pequena pausa
 mySerial.println("");                          // Enviamos um fim de linha
 delay(100);                                    // Pequena pausa
}

*/
