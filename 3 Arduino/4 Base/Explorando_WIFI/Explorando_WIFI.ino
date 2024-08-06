#include <WiFi.h>

const char *ssid = "Embasa USA-M";
const char *password = "Sup0rt3!@#";

// Lista de IPs a serem testados
IPAddress ips[255];
int currentIpIndex = 0;

// Lista de portas a serem testadas
int portas[] = {80, 443, 22};

void setup() {
  Serial.begin(19200);
  delay(10);

  Serial.println("Conectando ao WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  scanner();

  // Aguardar antes de repetir o teste
  delay(5000);
}

void scanner() {
  if (currentIpIndex >= 255) {
    // Resetar o índice para começar de novo
    currentIpIndex = 0;
  }

  // Extrair os três primeiros octetos do endereço IP
  byte firstThreeOctets[3];
  IPAddress localIP = WiFi.localIP();
  for (int i = 0; i < 3; i++) {
    firstThreeOctets[i] = localIP[i];
  }

  // Criar o IPAddress com base nos três primeiros octetos e no último octeto variável
  IPAddress ipToTest(firstThreeOctets[0], firstThreeOctets[1], firstThreeOctets[2], currentIpIndex);

  for (int j = 0; j < sizeof(portas) / sizeof(portas[0]); j++) {
    WiFiClient client;
    if (client.connect(ipToTest, portas[j])) {
      Serial.printf("Conectado a %s na porta %d\n", ipToTest.toString().c_str(), portas[j]);
      client.stop();
    } else {
      Serial.printf("Falha na conexão a %s na porta %d\n", ipToTest.toString().c_str(), portas[j]);
    }
  }

  // Incrementar o índice para o próximo IP na próxima chamada
  currentIpIndex++;
}