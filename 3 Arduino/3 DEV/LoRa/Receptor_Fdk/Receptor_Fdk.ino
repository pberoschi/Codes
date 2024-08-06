// COM 4
#include "heltec.h" //inclui a biblioteca da Heltec
#define DisplayEstado true //define se o display estará ou não ativo
#define LoRaEstado true //define se o rádio LoRa estará ou não ativo
#define SerialEstado true //define se a Serial do módulo estará ou não disponível 
			// (Baud Rate padrão 115200)
#define AmplificadorDePotencia true // define se o amplificador de potência PABOOST estará ou não ativo
#define BandaDeTransmissao 433E6 //define a frequência média de transmissão: 868E6, 915E6
#define pinBomba 22 //pino usado para acionar o motor da bomba
#define pinAquecedor 23 //pino usado para acionar o aquecedor
#define pinHolofote 17 //pino usado para acionar o holofote

void setup()
{
  //define os pino como saída
  pinMode(pinBomba, OUTPUT);
  pinMode(pinAquecedor, OUTPUT);
  pinMode(pinHolofote, OUTPUT);
  //os pinos são ajustados para nível alto logo no início
  //porque o módulo de relés tem lógica invertida
  digitalWrite(pinBomba, HIGH);
  digitalWrite(pinAquecedor, HIGH);
  digitalWrite(pinHolofote, HIGH);
//inicia o ESP WiFi LoRa 32 da Heltec
  Heltec.begin(DisplayEstado, LoRaEstado, SerialEstado, AmplificadorDePotencia, BandaDeTransmissao);
  SetupLoRa(); //faz os ajustes do rádio LoRa
  delay(100);
  //Sinaliza o fim dos ajustes
  Heltec.display -> clear();
  Heltec.display -> drawString(0, 0, "Setup concluído!");
  Heltec.display -> drawString(0, 10, "Aguardando dados...");
  Heltec.display -> display();
}

void loop()
{
  //verifica a chegada dos dados
  RecebeDados();
}

void SetupLoRa()
{
  LoRa.setSpreadingFactor(12); //define o fator de espalhamento
  LoRa.setSignalBandwidth(250E3); //define a largura de banda
  LoRa.setCodingRate4(5); //define o Codding Rate
  LoRa.setPreambleLength(6); //define o comprimento do preâmbulo
  LoRa.setSyncWord(0x12); //define a palavra de sincronização
  //LoRa.disableCrc(); //desabilita o CRC
  LoRa.crc(); //ativa o CRC
}

void RecebeDados()
{
  // tenta analisar o pacote
  int packetSize = LoRa.parsePacket();
  if (packetSize)  // se o pacote não tiver tamanho zero
  {
    //matriz para armazenamento dos estados
    byte Dados[3];
    // Lê o pacote
    while (LoRa.available())
    {
      Dados[0] = LoRa.read(); //estado do motor da bomba
      Dados[1] = LoRa.read(); //estado do aquecedor
      Dados[2] = LoRa.read(); //estado do holofote
    }
    //os dados são convertidos para booleanos e invertidos
    digitalWrite(pinBomba, !bool(Dados[0]));
    digitalWrite(pinAquecedor, !bool(Dados[1]));
    digitalWrite(pinHolofote, !bool(Dados[2]))
    //Sinaliza os dados recebidos e o RSSI no display
    Heltec.display -> clear();
    Heltec.display -> drawString(0, 0, "Bomba: " + String(Dados[0]));
    Heltec.display -> drawString(0, 10, "Aquecedor: " + String(Dados[1]));
    Heltec.display -> drawString(0, 20, "Holofote: " + String(Dados[2]));
    Heltec.display -> drawString(0, 30, "RSSI: " + String(LoRa.packetRssi()));
    Heltec.display -> display();
    //Sinaliza os dados recebidos e o RSSI na serial
    Serial.println("Bomba: " + String(Dados[0]));
    Serial.println("Aquecedor: " + String(Dados[1]));
    Serial.println("Holofote: " + String(Dados[2]));
    Serial.println("RSSI: " + String(LoRa.packetRssi()));
  }
}
   