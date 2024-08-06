#include <Arduino.h>
#include <TM1637Display.h>
#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include "RTClib.h"

#define CLK 4
#define DIO 5
TM1637Display display(CLK, DIO);


RTC_DS1307 rtc;
const int chipSelect = 10;                                  //10 is default by shield, but normally on Pin 4
int interval = 20;                                           //?????? Tempo para escrita no Cartao SD ?????
long timer;
String timestring;
float mvalue;
float pressure_mca;
float sensorVal;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup() {
  pinMode(A0, INPUT);

  Serial.begin(9600);
  delay(1000);

/*
  Serial.println("Inicializando cartao SD...");
  if (!SD.begin(chipSelect)) {
    Serial.println("Erro no cartao SD");
    return;
  }
  Serial.println("Cartao inicializado");
  if (! rtc.begin()) {
    Serial.println("RTC nao encontrado");
  } else {
    Serial.println("Relogio RTC ajustado");
  }
  if (! rtc.isrunning()) {
    Serial.println("RTC nao esta configurado");
  }
*/  
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loop() {
  sensorVal = analogRead(A0);

/*
  if ((timer + interval * 1000) < millis()) {
    timer = millis();
    get_logvalue();                                                       //Get your value
    get_time();                                                           //Get time from RTC
    write_data();                                                         //Write value and Time to SD
*/

    float voltage = (sensorVal * 5.0) / 1024.0;
    //Serial.print(voltage);
    //Serial.print(" volts");
    //Serial.println("");
    float pressure_pascal = (3.0 * ((float)voltage - 0.475)) * 1000000.0;                 //calibrate here        float pressure_pascal = (3.0 * ((float)voltage - 0.475)) * 1000000.0;                 //calibrate here
    float pressure_bar = pressure_pascal / 10e5;
    pressure_mca = pressure_bar * 10;
    //Serial.print(pressure_bar);
    //Serial.print(" bars  ");
    //Serial.println("");
    Serial.print (pressure_mca);
    Serial.print (" mca");
    Serial.println();

/*
    display.setBrightness(0);                                                               //0 mais baixo e 7 mais alto
    display.showNumberDec(pressure_mca, false);


    //delay(300000);                                                 //Intervalo para gravação no SD (60k - 1 min)

  }
  */

  delay(2000);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void get_logvalue() {
  //mvalue = pressure_mca;
}

void get_time() { //Read Time from RTC
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
  //Serial.println(timestring);
}

void write_data() {                                                                   //Escrever no SD card

  String dataString = timestring + "," + pressure_mca;
  File dataFile = SD.open("TESTUSA.txt", FILE_WRITE);                                // nome do arquivo (até 8 caracteres)
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    Serial.println(dataString);

  }
  else {
    Serial.println("Erro ao escrever arquivo .txt");
  }
}
