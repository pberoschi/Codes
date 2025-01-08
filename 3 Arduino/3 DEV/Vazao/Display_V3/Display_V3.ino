// VAZAO MOSTRADA NO DISPLAY 18650

#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <Wire.h>
#include "SSD1306Wire.h"

// Dados PINAGEM
#define LED_BUILTIN 2
#define SENSOR  22 //27

const int agua    = 25;
const int prod1   = 27;
// const int buzzer  = 26;
// const int ledPin  = 2; 

//Dados INTERNET
const char *ssid         = "Embasa USA-M";
const char *password     = "Sup0rt3!@#";

//Dados Display
SSD1306Wire display(0x3c, 5, 4);  

// Dados Medidor Vazao
long currentMillis = 0;
long previousMillis = 0;
int interval = 1000;
boolean ledState = LOW;
float calibrationFactor = 4.5;
volatile byte pulseCount;
byte pulse1Sec = 0;
float flowRate;
unsigned int flowMilliLitres;
unsigned long totalMilliLitres;

// int resumo = 0;

void IRAM_ATTR pulseCounter() {
  pulseCount++;
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  // pinMode(SENSOR, INPUT);
  pinMode(SENSOR, INPUT_PULLDOWN);
  pinMode(agua,OUTPUT);
  pinMode(prod1,OUTPUT);
  // pinMode(buzzer,OUTPUT);
  // pinMode(ledPin,OUTPUT);
  digitalWrite(prod1, LOW);
  // digitalWrite(ledPin, LOW);

  pulseCount = 0;
  flowRate = 0.0;
  flowMilliLitres = 0;
  totalMilliLitres = 0;
  previousMillis = 0;
  
  attachInterrupt(digitalPinToInterrupt(SENSOR), pulseCounter, FALLING);
  
  WiFi.begin ( ssid, password );
  // Wait for connection
  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 10 );
    // papai();
  }
  display.init();
  display.flipScreenVertically();
  display.setContrast(255);

  telaInicial();
  graficos();
  ProgressBar();
  InicioCiclo();
}

void loop() { 
  
  flow();
  // out1();
  // papai();
  // embasa();
  // ip(); 
}

void flow() {
  currentMillis = millis();

  if (currentMillis - previousMillis > interval) {    
    pulse1Sec = pulseCount;
    pulseCount = 0;

    // HÁ OBSERVAÇÕES AQUI  //
    flowRate = ((1000.0 / (millis() - previousMillis)) * pulse1Sec) / calibrationFactor;
    previousMillis = millis();

    // HÁ OBSERVAÇÕES AQUI  //
    flowMilliLitres = (flowRate / 60) * 1000;
    totalMilliLitres += flowMilliLitres;

    // INFORMÇÃO NA SERIAL: Print the cumulative total of litres flowed since starting
    // Serial.print("Quantidade de Líquido de Saída: ");
    // Serial.print(totalMilliLitres);
    // Serial.print("mL / ");
    // Serial.print(totalMilliLitres / 1000);
    // Serial.println("L");
   

    // MOSTRAR NO DISPLAY 18650 //
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_CENTER_BOTH);
    display.setFont(ArialMT_Plain_16);

    display.print("Totalizador: \n");
    display.print(totalMilliLitres);
    display.print(" mL / ");
    
    display.print(totalMilliLitres / 1000);
    display.print(" L ");

    display.display();
    // delay(2000);

    if (totalMilliLitres >= 1900) {
      digitalWrite(agua, LOW);
      produto1();
      InicioCiclo();
      digitalWrite(agua,HIGH);

    }
  }  
}
void produto1() {
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_CENTER_BOTH);
  display.setFont(ArialMT_Plain_16);

  display.print("Dosando Cloro\nAguarde... ");
  digitalWrite(prod1, HIGH);
  delay(5000);
  digitalWrite(prod1, LOW);
  display.display();  
  delay(1000);
  totalMilliLitres = 0;

}
void InicioCiclo() {
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_CENTER_BOTH);
  display.setFont(ArialMT_Plain_16);
  display.print("Iniciando Ciclo");
  delay(2000);
  display.display();
}
void embasa()  {
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_CENTER_BOTH);
  display.setFont(ArialMT_Plain_24);
  display.drawString(display.getWidth() / 2, display.getHeight() / 2, "EMBASA\n");
  display.display();
  delay(2000);
}
void ip()  {
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_CENTER_BOTH);
  display.setFont(ArialMT_Plain_16);
  display.drawString(display.getWidth() / 2, display.getHeight() / 2, "USAM\n" + WiFi.localIP().toString());
  display.display();
  delay(2000);
}
void telaInicial() {
  //Apaga o display
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  //Seleciona a fonte
  display.setFont(ArialMT_Plain_24);
  display.drawString(63, 10, "RHODES ");

  display.setTextAlignment(TEXT_ALIGN_CENTER);
  //Seleciona a fonte
  display.setFont(ArialMT_Plain_16);
  display.drawString(63, 35, "Soluções ");

  display.display();
  delay(5000);
}
void graficos() {
  display.clear();
  //Desenha um quadrado
  display.drawRect(12, 12, 30, 30);
  //Desenha um quadrado cheio
  display.fillRect(20, 20, 35, 35);
  //Desenha circulos
  for (int i = 1; i < 8; i++)
  {
    display.setColor(WHITE);
    display.drawCircle(92, 32, i * 3);
  }
  display.display();
}
void ProgressBar() {
  for (int counter = 0; counter <= 100; counter++)
  {
    display.clear();
    display.setFont(ArialMT_Plain_16);
    //Desenha a barra de progresso
    display.drawProgressBar(0, 32, 120, 10, counter);
    //Atualiza a porcentagem completa
    display.setTextAlignment(TEXT_ALIGN_CENTER);
    display.drawString(64, 15, String(counter) + "%");
    display.display();
    delay(10);
  }
}
// void papai() {
//   //--> PISCADAS PAPAI <-- //
//   for (int p=0; p<=10; p++) {
//     digitalWrite(ledPin, HIGH);
//     delay(200);
//     digitalWrite(ledPin, LOW);
//     delay(200);
//   }
// }








