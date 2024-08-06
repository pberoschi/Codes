

#define TINY_GSM_MODEM_SIM800
#include <TinyGsmClient.h>
#define SerialAT Serial1
#include <SoftwareSerial.h>
SoftwareSerial SerialAT(2, 3);          // RX, TX
TinyGsm modem(SerialAT);
TinyGsmClient client(modem);



/*
char auth[] = "67lkiVEbch5A-2p_JoBbY-1H3Nl4wLUx";
char apn[]  = "zap.vivo.com.br";
char user[] = "vivo";
char pass[] = "vivo";
*/

const char apn[]  = "zap.vivo.com.br";
const char gprsUser[] = "vivo";
const char gprsPass[] = "vivo";

const char server[] = "docs.google.com";
const char resource[] = "/TinyGSM/logo.txt";
const int  port = 443;


String textFix = "GET /forms/d/e/1FAIpQLSdOQUVZtL-V-mfbHP77TgORiNxHngh0mY29kehjl0m9xIULOw/formResponse?ifq&entry.276650337=";


void setup()
{
    Serial.begin(9600);                                             //Inicia a comunicacao serial
    delay(10);
  
    SerialAT.begin(57600);
    delay(3000);
    Serial.println("Initializing modem...");
    modem.restart();
   
}
 
 
void loop()
{
    if (client.connect("docs.google.com", 443) == 1)                  //Tenta se conectar ao servidor do Google docs na porta 443 (HTTPS)
    {
        String toSend = textFix;                                      //Atribuimos a String auxiliar na nova String que sera enviada
        toSend += random(40, 55);                                     //Adicionamos um valor aleatorio
        toSend += "&submit=Submit HTTP/1.1";                          //Completamos o metodo GET para nosso formulario.
 
        client.println(toSend);                                       //Enviamos o GET ao servidor-
        client.println("Host: docs.google.com");                      //-
        client.println();                                             //-
        client.stop();                                                //Encerramos a conexao com o servidor
        Serial.println("Dados enviados.");                            //Mostra no monitor que foi enviado
    }
    else
    {
        Serial.println("Erro ao se conectar");                         //Se nao for possivel conectar no servidor, ira avisar no monitor.
    }
 
    delay(5000);

}
