//https://www.fernandok.com/2021/02/acionamento-remoto-via-esp32-lora.html


#include "Arduino.h" //inclui a biblioeca padrão Arduino.h
#include "heltec.h" //inclui a biblioteca da Heltec
#include "WiFi.h" //inclui a biblioteca WiFi
// Definições do rádio LoRa
#define DisplayEstado true //define se o display estará ou não ativo
#define LoRaEstado true //define se o rádio LoRa estará ou não ativo
#define SerialEstado true //define se a Serial do módulo estará ou não disponível (Baud Rate padrão 115200)
#define AmplificadorDePotencia true // define se o amplificador de potência PABOOST estará ou não ativo
#define BandaDeTransmissao 433E6 //define a frequência média de transmissão: 868E6, 915E6
// Definições do WiFi
#define SSid "Seu_SSID" //Identificador do serviço de rede WiFi
#define Senha "Sua senha" //Senha de acesso ao serviço WiFi
//Variáveis de estado dos controlados
bool EstadoBomba = 0;
bool EstadoAquecedor = 0;
bool EstadoHolofote = 0;
bool Atuar = false;
//inicia o servidor na porta 80
WiFiServer servidor(80);

void setup()
{
  //inicia os dispositivos do devKit da Heltec (DEVE SER INICIADO ANTES DE TUDO)
  Heltec.begin(DisplayEstado, LoRaEstado, SerialEstado, AmplificadorDePotencia, BandaDeTransmissao);
  Heltec.display->clear(); //Limpa qualquer mensagem inicial do display
  SetupWiFi(); //Configura a conexão Wifi
  SetupLoRa(); //Configura o rádio LoRa
  //Sinaliza o fim dos ajustes
  Heltec.display -> drawString(0, 40, "Setup concluído!");
  Heltec.display -> display();
  servidor.begin();// inicia o servidor 
  //informa ip no display
  Heltec.display -> drawString(0, 50, "Servidor: " + WiFi.localIP().toString());
  Heltec.display -> display();
  delay(1000);
}

void loop() 
{
  TrataRequisicao();//trata as requisições HTTP
  enviarPacote();//Envia as mensagens LoRa
}


void SetupWiFi()
{
  //inicio dos ajustes do conexão WiFi
  WiFi.disconnect(true); //Desconecta de uma possível conexão prévia
  delay(100);
  IPAddress ip(192, 168, 0, 119); // Definição de um IP fixo
  IPAddress gateway(192, 168, 0, 1); //Gateway da rede
  IPAddress subnet(255, 255, 255, 0); //Máscara de rede
  WiFi.mode(WIFI_STA); //Ajusta para o modo STATION
  WiFi.setAutoConnect(true); //Ativa a auto reconexão
  WiFi.config(ip, gateway, subnet); //Configura os endereços fixos
  WiFi.begin(SSid, Senha); //Informa o id do Serviço WiFi e a senha
  delay(100);
  byte count = 0; // Contador das tentativas de conexão
  
 while (WiFi.status() != WL_CONNECTED && count < 10)
  {
    count ++;
    delay(500);
    Heltec.display -> drawString(0, 0, "Conectando WiFi...");
    Heltec.display -> display();
  }
  if (WiFi.status() == WL_CONNECTED) //Se conseguiu conectar...
  {
    Heltec.display -> drawString(0, 10, "Conexão WiFi ok!");
    Heltec.display -> display();
    delay(100);
  }
  else // ... caso falhe a conexão
  {
    Heltec.display -> drawString(0, 10, "Falha na conexão!");
    Heltec.display -> display();
    delay(100);
    //pode aplicar um loop infinito ou reset AQUI;
  }
}

void SetupLoRa()
{
  //Sinaliza o início dos ajustes
  Heltec.display -> drawString(0, 20, "Configurando LoRa...");
  Heltec.display -> display();
  delay(100);
  LoRa.setSpreadingFactor(12); //define o fator de espalhamento
  LoRa.setSignalBandwidth(250E3); //define a largura de banda
  LoRa.setCodingRate4(5); //define o Codding Rate
  LoRa.setPreambleLength(6); //define o comprimento do preâmbulo
  LoRa.setSyncWord(0x12); //define a palavra de sincronização
  //LoRa.disableCrc(); //desabilita o CRC
  LoRa.crc(); //ativa o CRC
  //Sinaliza o fim dos ajustes do rádio LoRa
  Heltec.display -> drawString(0, 30, "LoRa configurado!");
  Heltec.display -> display();
  delay(100);
}

void TrataRequisicao()
{
  //cria um objeto "cliente" se há uma conexão disponível
  WiFiClient cliente = servidor.available();
  if (!cliente) return; //se não há cliente, retorna
  // se há um cliente, sinaliza no display
  Heltec.display -> clear();
  Heltec.display -> drawString(0, 0, "Servidor: " + WiFi.localIP().toString());
  Heltec.display -> drawString(0, 10, "Cliente conectado!");
  Heltec.display -> display();
  while (cliente.connected()) //executa enquanto houver conexão
  {
    if (cliente.available()) //se há uma requisição disponível
    {
      String req = cliente.readStringUntil('\r'); //Lê a requisição
     //A partir daqui, verificamos se a requisição possui
      //algum comando de ajuste de sinal
      if (req.indexOf("acao=0") != -1) //para o motor da bomba
      {
        Atuar = true; //enviar os dados para atuar
        EstadoBomba = !EstadoBomba;
      }
      else if (req.indexOf("acao=1") != -1)//para o aquecedor
      {
        Atuar = true; //enviar os dados para atuar
        EstadoAquecedor = !EstadoAquecedor;
      }
	else if (req.indexOf("acao=2") != -1)//para o holofote
      {
        Atuar = true; //enviar os dados para atuar
        EstadoHolofote = !EstadoHolofote;
      }
      else if (req.indexOf("acao=3") != -1)//desligar tudo
      {
        Atuar = true; //enviar os dados para atuar
        EstadoBomba = 0;
        EstadoAquecedor = 0;
        EstadoHolofote = 0;
      }
      else if (req.indexOf("acao=-1") != -1) //somente atualizar os dados
      {
        Atuar = true; //enviar os dados para atuar
        Serial.println("Atualizar estado");
      }
      else //nenhuma opção válida
      {
        Atuar = false; //sinaliza que não é para atuar
      }
      
//Este é o html que iremos retornar para o cliente
      String html =
  String html =
        "<html>"
        "<head>"
        "<meta name='viewport' content='width=device-width, initial-scale=1, user-scalable=no'/>"
        "<title>Controle WiFi / LoRa</title>"
        "<style>"
        "body{"
        "text-align: center;"
        "font-family: sans-serif;"
        "font-size:15px;"
        "padding: 25px;"
        "}"
        "p{"
        "color:#444;"
        "}"
        "button{"
        "font-size:15px;"
        "outline: none;"
        "border: 2px solid #1fa3ec;"
        "border-radius:18px;"
        "background-color:#FFF;"
        "color: #000;"
"padding: 5px 25px;"
        "}"
        "button:active{"
        "color: #fff;"
        "background-color:#1fa3ec;"
        "}"
        "button:hover{"
        "border-color:#0000ff;"
        "}"
        "</style>"
        "</head>"
        "<body>"
        "<H1>Controle WiFi / LoRa</H1>"
        "<H2>Selecione um comando:</H2>"
        "<p><a href='?acao=0'><button>Bomba</button></a>"
        "<a href='?acao=1'><button>Aquecedor</button></a>"
        "<a href='?acao=2'><button>Holofote</button></a>"
        "<a href='?acao=3'><button>Desligar tudo.</button></a></p>"
        "<p></p>"
        "<p></p>"
        "<p><a href='?acao=-1'><button>Atualizar estados.</button></a></p>"
        "<p></p>"
        "<H3>Bomba: " + String(EstadoBomba) + "</H3>"
        "<H3>Aquecedor: " + String(EstadoAquecedor) + "</H3>"
        "<H3>Holofote: " + String(EstadoHolofote) + "</H3>"
        "</body>"
        "</html>\r";

//Escreve o html no buffer que será enviado para o cliente
      cliente.print(html);
      //Envia os dados do buffer para o cliente
      cliente.flush();
    }
    //aguarda para que o trafego das informações seja concluído
    delay(20);
    //força a desconexão do cliente
    cliente.stop();
  }
  //sinaliza o IP do servidor no display
  Heltec.display -> clear();
  Heltec.display -> drawString(0, 0, "Servidor em:");
  Heltec.display -> drawString(0, 10, WiFi.localIP().toString());
  Heltec.display -> display();
}

void enviarPacote()
{
  if (!Atuar) return; //se não é para atuar, retorna
  //envia para a serialos dados que serão enviados pelo LoRo
  Serial.println("Enviando: " + String(EstadoBomba) + String(EstadoAquecedor) + String(EstadoHolofote));
  //Enviar pacote
  //inicia a montagem do pacote (parâmetro FALSE desativa o Header);
  LoRa.beginPacket();
  //enviando os estado um a um
  LoRa.write(EstadoBomba);
  LoRa.write(EstadoAquecedor);
  LoRa.write(EstadoHolofote);
  LoRa.endPacket(); // finaliza o pacote
  Atuar = false; //Sinaliza que já houve a atuação
}