// https://blog.eletrogate.com/esp32-cam-acessado-remotamente-com-ngrok/
// ngrok http --basic-auth="adm:12345678" 192.168.0.122:8880 --authtoken 2OPtxD1OmnygwUpc0ZDlxGc2GK9_5HNhyekcncJtA322zLKy7


#include <WiFi.h>
#include <WebServer.h>
#include <WiFiClient.h>
#include "src/OV2640.h"      // Arquivos da biblioteca OV2640

// Selecione o modelo da camera
//#define CAMERA_MODEL_WROVER_KIT
//#define CAMERA_MODEL_ESP_EYE
//#define CAMERA_MODEL_M5STACK_PSRAM
//#define CAMERA_MODEL_M5STACK_WIDE
#define CAMERA_MODEL_AI_THINKER

#include "camera_pins.h"     // Arquivo com os pinos

#define SSID1 "Embasa USA-M"
#define PWD1 "Sup0rt3!@#"

OV2640 cam;                  // Instanciação da classe OV2640

WebServer server(8880);      // Porta do endereco do ESP32

// Dados para o protocolo HTTP (HTTP_header(cabeçalho), HTTP_boundary(Limite de cada parte) e HTTP_contentType(Tipo de conteudo))
const char HTTP_header[] = "HTTP/1.1 200 OK\r\n" \
                           "Access-Control-Allow-Origin: *\r\n" \
                           "Content-Type: multipart/x-mixed-replace; boundary=123456789000000000000987654321\r\n";
const char HTTP_boundary[] = "\r\n--123456789000000000000987654321\r\n";
const char HTTP_contentType[] = "Content-Type: image/jpeg\r\nContent-Length: ";
const int headerLen = strlen(HTTP_header);
const int boundaryLen = strlen(HTTP_boundary);
const int cntLen = strlen(HTTP_contentType);

/**
 * @brief FUNCAO QUE RECEBE A REQUISICAO GET E EXECUTA O CLIENT MOSTRANDO O VIDEO
 */
void handleStream(void)
{
  char buf[32];
  int dataSize;

  WiFiClient client = server.client();

  client.write(HTTP_header, headerLen);      // Escreve no cliente o header e seu tamanho
  client.write(HTTP_boundary, boundaryLen);  // Escreve no cliente o boundary e seu tamanho

  while (true)
  {
    if (!client.connected()) break;
    cam.run();                       // Starta a camera
    dataSize = cam.getSize();                // Atibui o tamanho dos dados da camera para dataSize
    client.write(HTTP_contentType, cntLen);  // Escreve no cliente o tipo de conteudo e seu tamanho
    sprintf(buf, "%d\r\n\r\n", dataSize);    // Formata o dataSize e salva no buffer
    client.write(buf, strlen(buf));          // Escreve no cliente o buffer e seu tamanho
    client.write((char *)cam.getfb(), dataSize); // Escreve no cliente o video capturado
    client.write(HTTP_boundary, boundaryLen);    // Escreve no cliente o boundary e seu tamanho fechando o protocolo HTTP
  }
}

/**
 * @brief FUNCAO QUE RECEBE A REQUISICAO GET NOT FOUND E PRINTA UMA MENSAGEM
 */
void handlePageNotFound()
{
  String mensagem = "Server em execucao!\n\n";  // String com a mensagem para imprimir na tela
  mensagem.concat(F("URI: "));     // Concatena a string URI na string mensagem
  mensagem.concat(server.uri());   // Imprime a URI
  mensagem.concat(F("\nMetodo: "));
  mensagem.concat((server.method() == HTTP_GET) ? "GET" : "POST");  // Verifica se foi uma requisicao GET ou POST
  mensagem.concat(F("\nArgumentos: "));
  mensagem.concat(server.args());  // Imprime os argumentos
  mensagem.concat(F("\n"));
  server.send(200, "text/plain", mensagem); // Envia para o navegador
}

/**
 * @brief FUNCAO SETUP
 */
void setup()
{
  Serial.begin(115200);

  // Configuracoes de GIPOS da camera
  camera_config_t configuracao;
  configuracao.ledc_channel = LEDC_CHANNEL_0;
  configuracao.ledc_timer = LEDC_TIMER_0;
  configuracao.pin_d0 = Y2_GPIO_NUM;
  configuracao.pin_d1 = Y3_GPIO_NUM;
  configuracao.pin_d2 = Y4_GPIO_NUM;
  configuracao.pin_d3 = Y5_GPIO_NUM;
  configuracao.pin_d4 = Y6_GPIO_NUM;
  configuracao.pin_d5 = Y7_GPIO_NUM;
  configuracao.pin_d6 = Y8_GPIO_NUM;
  configuracao.pin_d7 = Y9_GPIO_NUM;
  configuracao.pin_xclk = XCLK_GPIO_NUM;
  configuracao.pin_pclk = PCLK_GPIO_NUM;
  configuracao.pin_vsync = VSYNC_GPIO_NUM;
  configuracao.pin_href = HREF_GPIO_NUM;
  configuracao.pin_sscb_sda = SIOD_GPIO_NUM;
  configuracao.pin_sscb_scl = SIOC_GPIO_NUM;
  configuracao.pin_pwdn = PWDN_GPIO_NUM;
  configuracao.pin_reset = RESET_GPIO_NUM;
  configuracao.xclk_freq_hz = 20000000;
  configuracao.pixel_format = PIXFORMAT_JPEG;

  // Definicao do formato do video, selecione um framesize
  if(psramFound()){  //  Verifica se a camera suportar PSRAM
    configuracao.frame_size = FRAMESIZE_VGA; // FRAMESIZE_ + QVGA|CIF|VGA|SVGA|XGA|SXGA|UXGA
                                             // Quantidade de pixels que irá compor a imagem.
                                             // Pode ser reduzido para aumentar o framerate.
                                             // Opções: VGA, CIF, QVGA, UXGA, SXGA, XGA, SVGA
    configuracao.jpeg_quality = 9;   // Define o fator de compressão da imagem, 0-63 numero menor significa maior qualidade
    configuracao.fb_count = 2;
  } else {
    configuracao.frame_size = FRAMESIZE_CIF;
    configuracao.jpeg_quality = 12;
    configuracao.fb_count = 1;
  }

  cam.init(configuracao);            // Inicializacao da camera com as configuracoes
  sensor_t * sensorConfig = esp_camera_sensor_get();
  sensorConfig->set_hmirror(sensorConfig, 1);        // Espelhamento horizontal 0 = Desabilita , 1 = Habilita
  sensorConfig->set_vflip(sensorConfig, 1);          // Espelhamento vertical  0 = Desabilita , 1 = Habilita
  
  // Secao do WiFi
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID1, PWD1);
  
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(F("."));
  }
  
  Serial.println(F("WiFi conectado"));
  Serial.println(WiFi.localIP());
  Serial.print(F("Link do Stream: http://"));
  Serial.print(WiFi.localIP());
  
  server.on("/", HTTP_GET, handleStream);
  server.onNotFound(handlePageNotFound);
  server.begin();
}

/**
 * @brief FUNCAO DE LOOP
 */
void loop()
{
  server.handleClient();
}
