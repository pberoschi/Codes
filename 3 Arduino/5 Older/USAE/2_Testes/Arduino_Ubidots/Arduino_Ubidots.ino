#define TINY_GSM_MODEM_SIM800 //Tipo de modem que estamos usando
#include <TinyGsmClient.h>
#include <PubSubClient.h>
//#include <SimpleDHT.h>
//#include <TFT_eSPI.h>
#include <SPI.h>



#include <SoftwareSerial.h>
SoftwareSerial SerialAT(7, 8); // RX, TX



//Token de usuário que pegamos no Ubidots
#define TOKEN "BBFF-hlEF97XzTkjGpavlWhKUI8uQ2zHgIy" 

//Tópico onde vamos postar os dados de temperatura e umidade (esp32_gprs é o nome do dispositivo no Ubidots)
#define TOPIC "/v1.6/devices/ard_gprs" 

//id do dispositivo que pegamos no painel do Ubidots
#define DEVICE_ID "5f5a1a671d847243b5af3edf" 

//URL do MQTT Server
#define MQTT_SERVER "mqtt://things.ubidots.com"

//Porta padrão do MQTT
#define MQTT_PORT 1883 

//Intervalo entre os envios e refresh da tela
#define INTERVAL 10000

//Canal serial que vamos usar para comunicarmos com o modem. Utilize sempre 1
//SoftwareSerial SerialAT(7, 8);
//HardwareSerial Serial1(1);

TinyGsm modemGSM(SerialGSM);
TinyGsmClient gsmClient(modemGSM);

//Cliente MQTT, passamos a url do server, a porta
//e o cliente GSM
PubSubClient client(MQTT_SERVER, MQTT_PORT, gsmClient);

//Tempo em que o último envio/refresh foi feito
uint32_t lastTime = 0;

float humidity; //Variável onde iremos armazenar o valor da umidade
//float temperature; //Variável onde iremos armazenar o valor da temperatura

//SimpleDHT22 dht; //Objeto que realizará a leitura da umidade e temperatura

void setup() 
{
  Serial.begin(115200);
  //setupDisplay(); //Inicializa e configura o display
  setupGSM(); //Inicializa e configura o modem GSM
  connectMQTTServer(); //Conectamos ao mqtt server

  //Espera 2 segundos e limpamos o display
  //delay(2000);
  //display.fillScreen(TFT_BLUE);
  //display.setCursor(0, 0);
}

/*
void setupDisplay()
{
  display.init();
  display.setRotation(1);
  display.fillScreen(TFT_BLUE); //Limpa o display com a cor azul
  display.setTextColor(TFT_WHITE, TFT_BLUE); //Coloca o texto como branco com fundo azul
  display.setTextWrap(true, true);//Ativa quebra de linha
  display.setTextSize(1);
  display.setCursor(0, 0, 2); //Posicção x, y e fonte do texto
  display.println("Setup Display Complete");
}
*/
void setupGSM()
{
  //display.println("Setup GSM...");
  Serial.println("Setup GSM...");
  //Inicializamos a serial onde está o modem
//  SerialGSM.begin(9600, SERIAL_8N1, 4, 2, false);
  delay(3000);

  //Mostra informação sobre o modem
  Serial.println(modemGSM.getModemInfo());

  //Inicializa o modem
  if (!modemGSM.restart())
  {
    Serial.println("Restarting GSM Modem failed");
    delay(10000);
    modem.restart();
    return;
  }

  //Espera pela rede
  if (!modemGSM.waitForNetwork()) 
  {
    Serial.println("Failed to connect to network");
    delay(10000);
    modem.restart();
    return;
  }

  //Conecta à rede gprs (APN, usuário, senha)
  if (!modemGSM.gprsConnect("zap.vivo.com.br", "vivo", "vivo")) {
    display.println("GPRS Connection Failed");
    delay(10000);
    modem.restart();
    return;
  }

  Serial.println("Setup GSM Success");
}

void connectMQTTServer() {
  Serial.println("Connecting to MQTT Server...");
  //Se conecta ao device que definimos
  if (client.connect(DEVICE_ID, TOKEN, "")) {
    //Se a conexão foi bem sucedida
    Serial.println("Connected");
  } else {
    //Se ocorreu algum erro
    Serial.print("error = ");
    Serial.println(client.state());
    delay(10000);
    modem.restart();
  }
}

void loop() 
{
  //Faz a leitura da umidade e temperatura
  //readDHT(); 

  //Se desconectou do server MQTT
  if(!client.connected())
  {
    //Mandamos conectar
    connectMQTTServer();
  }

   //Tempo decorrido desde o boot em milissegundos
  unsigned long now = millis();

  //Se passou o intervalo de envio
  if(now - lastTime > INTERVAL)
  {
    //Publicamos para o server mqtt
    publishMQTT();
    //Mostramos os dados no display
    showDataOnDisplay();
    //Atualizamos o tempo em que foi feito o último envio
    lastTime = now;
  }
}
/*
void readDHT()
{
  float t, h;
  //Faz a leitura da umidade e temperatura e apenas atualiza as variáveis se foi bem sucedido
  if (dht.read2(DHT_PIN, &t, &h, NULL) == SimpleDHTErrSuccess)
  {
    temperature = t;
    humidity = h;
  }
}
*/
void publishMQTT()
{
  //Cria o json que iremos enviar para o server MQTT
  String msg = createJsonString();
  Serial.print("Publish message: ");
  Serial.println(msg);
  //Publicamos no tópico
  int status = client.publish(TOPIC, msg.c_str());
  Serial.println("Status: " + String(status));//Status 1 se sucesso ou 0 se deu erro
}

String createJsonString() 
{  
  String data = "{";
    if(!isnan(humidity) && !isnan(temperature))
    {
      data+="\"humidity\":";
      data+=String(humidity, 2);
      data+=",";
      data+="\"temperature\":";
      data+=String(temperature, 2);
    }
  data+="}";
  return data;
}

/*
void showDataOnDisplay()
{
  //Reseta a posição do cursor e mostra umidade e temperatura lidas
  display.setCursor(0, 0, 2);
  display.println("Humidity: " + String(humidity, 2));
  display.println("Temperature: " + String(temperature, 2));
}
*/
