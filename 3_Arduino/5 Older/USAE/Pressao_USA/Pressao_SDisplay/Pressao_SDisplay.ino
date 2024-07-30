#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include "RTClib.h"
#include "JeeLib.h"
#include "Narcoleptic.h"

RTC_DS1307 rtc;
const int chipSelect = 10;                                  //10 is default by shield, but normally on Pin 4
String timestring;
float pressure_mca;
float sensorVal;
int buz = 7;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup() {
  pinMode(A0, INPUT);
  pinMode(buz, OUTPUT);

  Serial.begin(115200);
  delay(3000);


  int start = 0;
  while (start < 3) {
    digitalWrite(buz, HIGH);
    delay(60);
    digitalWrite(buz, LOW);
    delay(60);
    start++;
  }


  // Inicializacao do Sistema com aviso sonoro de falha
  Serial.println("Inicializando cartao SD...");
  if (!SD.begin(chipSelect)) {
    Serial.println("Erro no cartao SD");
    tone(buz, 3000);
    delay(1000);
    noTone(buz);
    return;
  }
  Serial.println("Cartao inicializado");
  if (! rtc.begin()) {
    Serial.println("RTC nao encontrado");
    tone(buz, 500);
    delay(1000);
    noTone(buz);

  } else {
    Serial.println("Relogio RTC ajustado");
  }
  if (! rtc.isrunning()) {
    Serial.println("RTC nao esta configurado");
    tone(buz, 500);
    delay(1000);
    noTone(buz);
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop() {

  Sleepy::loseSomeTime(160);

  sensorVal = analogRead(A0);

  get_time();                                                           //Get time from RTC
  write_data();                                                         //Write value and Time to SD


  float voltage = (sensorVal * 5.0) / 1024.0;
  float pressure_pascal = (3.0 * ((float)voltage - 0.475)) * 1000000.0;                 //calibrate here
  float pressure_bar = pressure_pascal / 10e5;
  pressure_mca = pressure_bar * 10;

  Serial.println();

  for (byte i = 0; i < 180; ++i) {            // 15 min  de intervalo
    Sleepy::loseSomeTime(5000);
  }
  
  
  //Sleepy::loseSomeTime(5000);
  
  tone(buz, 2000);
  delay(100);
  noTone(buz);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void get_time() {                                           //Read Time from RTC
  DateTime now = rtc.now();
  timestring = now.day();
  timestring += "/";
  timestring += now.month();
  timestring += "/";
  timestring += now.year();
  timestring += ",";

  timestring += now.hour();
  timestring += ":";
  timestring += now.minute();
  timestring += ":";
  timestring += now.second();
  Serial.println();

}

void write_data() {                                                      //Escrever no SD card

  String dataString = timestring + "," + pressure_mca;
  File dataFile = SD.open("DADOS.txt", FILE_WRITE);                    // nome do arquivo (até 8 caracteres)
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    Serial.println(dataString);

  }
  else {
    Serial.println("Erro ao escrever arquivo .txt");
    tone(buz, 3000);
    delay(1000);
    noTone(buz);
  }
}
