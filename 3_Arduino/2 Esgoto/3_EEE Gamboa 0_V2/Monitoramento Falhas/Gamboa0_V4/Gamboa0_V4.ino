//Comunicação como o TELEGRAM com o envio de STATUS

#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

#define ledPin 2
#define NivelAlto 21//13
#define Extravasamento 22//4
#define FaltaEnergia 23//18
int x;
int buttonState = 0; 
int NAlto = 0;
int Extrav = 0;
int FEnergia = 0;



#define RELAY_PIN 13//5
#define DHT_PIN 4
#define INTERVAL 1000
//Comandos aceitos
const String LIGHT_ON = "ligar a luz";
const String LIGHT_OFF = "desligar a luz";
const String CLIMATE = "clima";
const String STATS = "status";
const String START = "/start";
//Objeto que realiza a leitura da temperatura e umidade
//SimpleDHT22 dht;
//Estado do relê
int relayStatus = HIGH;
//Cliente para conexões seguras
//WiFiClientSecure client;
//Objeto com os métodos para comunicarmos pelo Telegram
//UniversalTelegramBot bot(BOT_TOKEN, client);
//Tempo em que foi feita a última checagem
uint32_t lastCheckTime = 0;





#define WIFI_SSID "Embasa USA-M"
#define WIFI_PASSWORD "Sup0rt3!@#"
#define BOT_TOKEN "5875114157:AAHahh0XbtDqGJhm6DH9cS2sjfHdZEEJgbo"
#define CHAT_ID "984798692"

WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);

void setup() {
  pinMode(ledPin , OUTPUT);
  digitalWrite(ledPin, LOW);

  //pinMode(buttonPin, INPUT);
  pinMode(NivelAlto, INPUT_PULLDOWN);
  pinMode(Extravasamento, INPUT_PULLDOWN);
  pinMode(FaltaEnergia, INPUT_PULLDOWN);

  Serial.begin(115200);
  Serial.println();

  Serial.print("Connecting to Wifi SSID ");
  Serial.print(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  secured_client.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root certificate for api.telegram.org
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.print("\nWiFi connected. IP address: ");
  Serial.println(WiFi.localIP());

  Serial.print("Retrieving time: ");
  configTime(0, 0, "pool.ntp.org"); // get UTC time via NTP
  time_t now = time(nullptr);
  while (now < 24 * 3600)
  {
    Serial.print(".");
    delay(100);
    now = time(nullptr);
  }
  Serial.println(now);
  x = 0;
  while (x < 10)
  {
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
    x = x+1;
  }
  bot.sendMessage(CHAT_ID, "Inicializando o monitoramento. \nVerificando STATUS da instalação", "");
}

void loop() 
{
  NAlto = digitalRead(NivelAlto);
  Extrav = digitalRead(Extravasamento);
  FEnergia = digitalRead(FaltaEnergia);

  if (NAlto == HIGH) {
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    bot.sendMessage(CHAT_ID, "EEE Gamboa 0: NIVEL ALTO", "");
    Serial.print("NIVEL ALTO");
    delay(10);
  }
  if (Extrav == HIGH) {
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    bot.sendMessage(CHAT_ID, "EEE Gamboa 0: EXTRAVASANDO", "");
    Serial.print("EXTRAVASANDO");
    delay(10);
    }
  if (FEnergia == HIGH) {
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    bot.sendMessage(CHAT_ID, "EEE Gamboa 0: FALTA DE ENERGIA", "");
    Serial.print("FALTA DE ENERGIA");
    delay(10);
  }
  //Tempo agora desde o boot
  uint32_t now = millis();
  //Se o tempo passado desde a última checagem for maior que o intervalo determinado
  if (now - lastCheckTime > INTERVAL) 
  {
    //Coloca o tempo de útlima checagem como agora e checa por mensagens
    lastCheckTime = now;
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    handleNewMessages(numNewMessages);
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void handleNewMessages(int numNewMessages)
{
  for (int i=0; i<numNewMessages; i++) //para cada mensagem nova
  {
    String chatId = String(bot.messages[i].chat_id); //id do chat 
    String senderId = String(bot.messages[i].from_id); //id do contato
    Serial.println("senderId: " + senderId); //mostra no monitor serial o id de quem mandou a mensagem    
    String text = bot.messages[i].text; //texto que chegou
    if (text.equalsIgnoreCase(START))
    {
      handleStart(chatId, bot.messages[i].from_name); //mostra as opções
    }
    else if (text.equalsIgnoreCase(LIGHT_ON))
    {
      handleLightOn(chatId); //liga o relê
    }
    else if(text.equalsIgnoreCase(LIGHT_OFF))
    {
     handleLightOff(chatId); //desliga o relê
    }
    else if (text.equalsIgnoreCase(STATS))
    {
      handleStatus(chatId); //envia mensagem com o estado do relê, temperatura e umidade
    }
    else
    {
      handleNotFound(chatId); //mostra mensagem que a opção não é válida e mostra as opções
    }
  }//for
}

void handleStart(String chatId, String fromName)
{
  //Mostra Olá e o nome do contato seguido das mensagens válidas
  String message = "<b>Olá " + fromName + ".</b>\n";
  message += getCommands();
  bot.sendMessage(chatId, message, "HTML");
}

String getCommands()
{
  //String com a lista de mensagens que são válidas e explicação sobre o que faz
  String message = "Os comandos disponíveis são:\n\n";
  message += "<b>" + LIGHT_ON + "</b>: Para ligar a luz\n";
  message += "<b>" + LIGHT_OFF + "</b>: Para desligar a luz\n";
  message += "<b>" + CLIMATE + "</b>: Para verificar o clima\n";
  message += "<b>" + STATS + "</b>: Para verificar o estado da luz e a temperatura";
  return message;
}
void handleLightOn(String chatId)
{
  //Liga o relê e envia mensagem confirmando a operação
  relayStatus = LOW; //A lógica do nosso relê é invertida
  digitalWrite(RELAY_PIN, relayStatus);  
  bot.sendMessage(chatId, "A luz está <b>acesa</b>", "HTML");
}

void handleLightOff(String chatId)
{
  //Desliga o relê e envia mensagem confirmando a operação 
  relayStatus = HIGH; //A lógica do nosso relê é invertida
  digitalWrite(RELAY_PIN, relayStatus);  
  bot.sendMessage(chatId, "A luz está <b>apagada</b>", "HTML");
}

void handleStatus(String chatId)
{
  String message = "";
  //Verifica se o relê está ligado ou desligado e gera a mensagem de acordo
  if(relayStatus == LOW) //A lógica do nosso relê é invertida
  {
    message += "A luz está acesa\n";
  }
  else
  {
    message += "A luz está apagada\n";
  }
  //Envia a mensagem para o contato
  bot.sendMessage(chatId, message, "");
}
void handleNotFound(String chatId)
{
  //Envia mensagem dizendo que o comando não foi encontrado e mostra opções de comando válidos
  String message = "Comando não encontrado\n";
  message += getCommands();
  bot.sendMessage(chatId, message, "HTML");
}


















