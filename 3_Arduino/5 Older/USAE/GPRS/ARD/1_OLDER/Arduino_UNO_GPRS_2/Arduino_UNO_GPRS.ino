#define TINY_GSM_MODEM_SIM800 //Tipo de modem que estamos usando
#include <TinyGsmClient.h>
#include <PubSubClient.h>
#include <SoftwareSerial.h>
#include <String.h>


SoftwareSerial SerialGSM(7, 8);
TinyGsm modemGSM(SerialGSM);
TinyGsmClient gsmClient(modemGSM);
TinyGsmClientSecure client(modemGSM);


String textFix = "GET /forms/d/e/1FAIpQLSdbhYz8EwM4jECp3OCtt4KmJUeK4LbgZ82uKr3_TebA9rr1-w/formResponse?ifq&entry.313146852=";


void setup()
{
  Serial.begin(115200);
  setupGSM(); //Inicializa e configura o modem GSM


}


void loop()
{

   if (client.connect("docs.google.com", 443) == 1)      //Tenta se conectar ao servidor do Google docs na porta 443 (HTTPS)

  {
    String toSend = textFix;                            //Atribuimos a String auxiliar na nova String que sera enviada
    toSend += random(0, 501);                           //Adicionamos um valor aleatorio
    //toSend += distance;
    toSend += "&submit=Submit HTTP/1.1";                //Completamos o metodo GET para nosso formulario.
    client.println(toSend);                             //Enviamos o GET ao servidor-
    client.println("Host: docs.google.com");            //-
    client.println();                                   //-
    client.stop();                                      //Encerramos a conexao com o servidor
    Serial.println("Dados enviados.");                  //Mostra no monitor que foi enviado
  }
  else
  {
    Serial.println("Erro ao se conectar");              //Se nao for possivel conectar no servidor, ira avisar no monitor.


  }
  delay(3000);
  return;

}


void setupGSM()
{

  SerialGSM.begin(9600);
  Serial.println("Setup GSM...");
  delay(3000);

  Serial.println(modemGSM.getModemInfo());

  if (!modemGSM.restart())
  {
    Serial.println("Restarting GSM Modem failed");
    delay(3000);
    //ESP.restart();
    return;
  }


  if (!modemGSM.waitForNetwork())
  {
    Serial.println("Failed to connect to network");
    delay(3000);
    //ESP.restart();
    return;
  }

  //Conecta à rede gprs (APN, usuário, senha)
  if (!modemGSM.gprsConnect("zap.vivo.com.br", "vivo", "vivo")) {
    //if (!modemGSM.gprsConnect("tim.br", "tim", "tim")) {
    Serial.println("GPRS Connection Failed");
    delay(3000);
    //ESP.restart();
    return;
  }

  Serial.println("Setup GSM Success");
}
