#include <ModbusMaster.h>

#define MAX485_RE_NEG  19

ModbusMaster node;
 

uint8_t deviceID = 1;
uint8_t resultMain;
String c, texto;
String ID, REGISTER, VALUE;
 
void preTransmission() {
  digitalWrite(MAX485_RE_NEG, HIGH);
}
 
void postTransmission() {
  digitalWrite(MAX485_RE_NEG, LOW);
}
 
void setup() {

  Serial.begin(115200);  // to write modbus
  Serial2.begin(9600, SERIAL_8N1, 16, 17); // pino 0 = RX, 14 = TX
 
  pinMode(MAX485_RE_NEG, OUTPUT);
  digitalWrite(MAX485_RE_NEG, LOW);

  node.preTransmission(preTransmission);
  node.postTransmission(postTransmission);

}
void loop() {
  while (Serial.available() > 0) {
 
    // Slave ID: ID 0-2 > ID1
    // Slave Register: 3-6 > 0005
    // Slave Register Value: 7-11 > 1000
 
    c = (char)Serial.read();  // read from serial monitor
 
    if (c == ":") {
      break;
    }
    else {
      texto += c; // texto = texto + c;
    }
    ID = texto.substring(2, 3);            // pega o número de ID enviado pela serial
    REGISTER = texto.substring(3, 7);      // pega o endereço da varíavel que recebera a escrita ex: No inv delta ms300 a control word é 2000H
    VALUE = texto.substring(7, 11);        // pega o valor q será escrito na variável Ex: o valor 0002H coloca o inv em RUN
    deviceID = 0;
          
  }

  switch (deviceID) {
 
    // Device ID imaginário - Serve apenas para enviar comandos ao Inversor via RS485
    case 0:
      node.begin(getInt(ID), Serial2);
      resultMain = node.writeSingleRegister(getInt(REGISTER), getInt(VALUE)); // para o inv delta a controlword é 2000H = 8192 decimal   value = 0002 run, = 0001 stop 
      
     // node.begin(1, mySerial);
     // resultMain = node.writeSingleRegister(0x2000, 2);
      
      deviceID = 1;
      texto = "";
      ID = "";
      REGISTER = "";
      VALUE = "";
      break;
 
    // Rotina que realiza a leitura dos dados pertinenetes ao inversor de frequencia
    case 1:
      // Modbus ID 1 - Inversor de Frequencia
           
      node.begin(deviceID, Serial2);
        
      node.idle(yield);
      delay(20);
      resultMain = node.readHoldingRegisters(0x2103 - 1, 4); // Realiza a leitura do registrador 9 ate 14 (0x0E)
      delay(20);
      
                                                                           
      if (resultMain == node.ku8MBSuccess) {
        Serial.print("ID1 Freq. de Comando ");
        Serial.println(node.getResponseBuffer(0x00)); // Apanha o dado alocado na posição 0 do buffer
        Serial.print("ID1 Freq. de Saída ");
        Serial.println(node.getResponseBuffer(0x01)); // Apanha o dado alocado na posição 1 do buffer
        Serial.print("ID1 Tensão do Barramento ");
        Serial.println(node.getResponseBuffer(0x03));
        
      } else {
        Serial.print("ID1MSGN");
        Serial.println("Falha de comunicacao");
      }

      delay(1000);

      
      deviceID = 1;
      break;
  }
  delay(45);
}
 
// Função que realiza a conversão de um caracter em ASCII para numero inteiro
int getInt(String texto) {
  int temp = texto.length() + 1;
  char buffer[temp];
  texto.toCharArray(buffer, temp);
  int num = atoi(buffer);
  return num;
}