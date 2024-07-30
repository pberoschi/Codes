//https://www.youtube.com/watch?v=I82VSEn8hTA

#include <ModbusRtu.h>
#include <HardwareSerial.h>


uint16_t au16data[16];

Modbus master (0,1,0);  //Modo Master, porta serial 2, sem pino de controle TX,Rx
modbus_t telegram[1];   // array para o telegrama do Modbus




void setup() 
{
  Serial.begin(19200); // iniciar a serial/USB

  master.begin (19200);                   // inicia a modbus comm a serial e baud rate
  Serial2.begin(19200, SERIAL_8E1);       // reconfigura a serial para o padrão do inversor: 19200bps, paridade par, 1 bit stop
  master.setTimeOut(1000);                // tempo limite para resposta
}


void loop() 
{
  uint16_t tensao,corrente,frequencia;        // variaveis auxiliares
  uint8_t u8state = 0;                        // status

    while (u8state < 2)                       //enquanto não passar por todas as etapas, fica no loop
      {
        switch(u8state)
        {
          case 0:

            telegram[0].u8id        = 1;          //endereço do escravo
            telegram[0].u8fct       = 3;          // código de função para ler registradores
            telegram[0].u16RegAdd   = 0x03;          // endereço de inicio de leitura
            telegram[0].u16CoilsNo  = 3;          // numero dos registradores a serem lidos
            telegram[0].au16reg     = au16data;   // ponteiro para vetor de memoria
            master.query(telegram[0]);            // envia a solicitação ao escravo
            u8state++;
            break;

          case 1:

            master.poll();                          // checa se recebeu retorno da solicitação
            if(master.getState() == COM_IDLE)
            {
              if(master.getTimeOutState() == 1)
            { 
              Serial.println("Sem resposta do inversor");
              tensao        = 0;
              corrente      = 0;
              frequencia    = 0;
            }else
            {
              uint8_t index;

              frequencia = au16data[2];             //frequencia de saida
              corrente = au16data[0];               // corrente saida
              tensao   =  au16data[1]/1.42;          // tensao barramento CC convertida pra tensão de entrada
              
            }
            u8state++;                              // incrementa o registrador para iniciar o ciclo
            }
            break;
        }
     }

  Serial.println(tensao);
  Serial.println(corrente);
  Serial.println(frequencia);
  //delay(1000); 

}





