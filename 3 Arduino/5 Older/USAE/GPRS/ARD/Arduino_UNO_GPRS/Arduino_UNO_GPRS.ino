#define TINY_GSM_MODEM_SIM800 //Tipo de modem que estamos usando
#include <TinyGsmClient.h>
#include <PubSubClient.h>
#include <SoftwareSerial.h>
#include <String.h>
#include <math.h>


SoftwareSerial SerialGSM(7, 8);
TinyGsm modemGSM(SerialGSM);
TinyGsmClient gsmClient(modemGSM);
TinyGsmClientSecure client(modemGSM);


String textFix = "GET /forms/d/e/1FAIpQLSdbhYz8EwM4jECp3OCtt4KmJUeK4LbgZ82uKr3_TebA9rr1-w/formResponse?ifq&entry.313146852=";
const int trigPin = 3;
const int echoPin = 2;
long duration;
float distance;
float q;
float p;
float aberturaParshall = 0.3058;                // Garganta da calha em metro;




void setup()
{
  Serial.begin(115200);
  setupGSM(); //Inicializa e configura o modem GSM
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}




void loop()
{

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  //teste = duration * (0.035 / 2);
  distance = 82 - (duration * 0.035 / 2);
  q = 2.2 * aberturaParshall;
  p = pow (distance, 1.5) * q;



  if (client.connect("docs.google.com", 443) == 1)      //Tenta se conectar ao servidor do Google docs na porta 443 (HTTPS)

  {
    String toSend = textFix;                            //Atribuimos a String auxiliar na nova String que sera enviada
    toSend += p;
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
    return;
  }


  if (!modemGSM.waitForNetwork())
  {
    Serial.println("Failed to connect to network");
    delay(3000);
    return;
  }

  //Conecta à rede gprs (APN, usuário, senha)
  //if (!modemGSM.gprsConnect("zap.vivo.com.br", "vivo", "vivo")) {
  if (!modemGSM.gprsConnect("tim.br", "tim", "tim")) {
    //if (!modemGSM.gprsConnect("timbrasil.br", "tim", "tim")) {
    Serial.println("GPRS Connection Failed");
    delay(3000);
    return;
  }

  Serial.println("Setup GSM Success");
}
