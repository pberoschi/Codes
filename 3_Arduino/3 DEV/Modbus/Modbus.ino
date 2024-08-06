//https://www.youtube.com/watch?v=fq3PWvwqA4Y&t=353s











// #include "Connection.h"
#include <ModbusRtu.h>
#include <HardwareSerial.h>


uint16_t au16data[16];

/**
 * u8id       : id - 0 para modo master, ou 1 a 247 para modo escravo
 * u8serno    : porta de comunicação
 * u8txenpin  : pino de controle Tx/Rx da placa. 0 quando não houver (controle automático)
*/
Modbus master (0,1,0);  //Modo Master, porta serial, sem pino de controle TX,Rx

modbus_t telegram[1];   // array para o telegrama do Modbus





void setup(void) 
{
  Serial.begin(115200); // iniciar a serial

  master.begin (&Serial2, 19200);         // inicia a modbus comm a serial e baud rate
  Serial2.begin(19200, SERIAL_8E1);       // reconfigura a serial para o padrão do inversor: 19200bps, paridade par, 1 bit stop
  master.setTimeOut(1000);                // tempo limite para resposta

  // connect_wifi();                         // conecta a WiFi

}




void loop(void) 
{
  delay(3000);

  if(check_msg() == 1)             // nova solicitação recebida?
  {
    uint8_t u8state;                // status

    u8state = 0;                    // limpa registrador
    while(u8state < 2)              // enquanto não passar por todas etapas, fica no loop
    {
      switch(u8state)
      {
          case 0:
                  telegram[0].u8id        = 1;          //endereço do escravo
                  telegram[0].u8fct       = 3;          // código de função para ler registradores
                  telegram[0].u16RegAdd   = 0x31D9;     // endereço de inicio de leitura
                  telegram[0].u16CoilsNo  = 4;          // numero dos registradores a serem lidos
                  telegram[0].au16reg     = au16data;   // ponteiro para vetor de memoria
                  master.query(telegram[0]);            // envia a solicitação ao escravo
                  u8state++;
                  break;

          case 1:
                  master.poll();              // checa se recebeu retorno da solicitação
                  if(master.getState() == COM_IDLE) 
                  {
                    if(master.getTimeOutState () == 1) strcpy(bserial, "Sem resposta do servidor");
                    else
                    {
                      uint8_t index;

                      index = sprintf(bserial, "Pot: %d%% \n", au16data[0]);                            // potencia do motor em %
                      index += sprintf(&bserial[index], "In: %2.1fA \n", (float)au16data[1]/10);        // corrente em A
                      index += sprintf(&bserial[index], "Fs: %2.1fHz \n", (float)au16data[2]/10);
                      sprintf(&bserial[index], "Vr: %3.1fV", (float)au16data[3]/10);                    // tensão 
                    }
                    send_msg();
                    u8state++;      // Limpa o registrador para iniciar o ciclo
                  }
                  break;
          }   
      }
    }
}




