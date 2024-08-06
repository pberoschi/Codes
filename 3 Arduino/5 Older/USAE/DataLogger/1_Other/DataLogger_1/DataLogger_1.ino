
//https://www.dobitaobyte.com.br/data-logger-shield-com-arduino/


#include "RTClib.h"
#include <SPI.h>
#include <SD.h>

RTC_DS1307 rtc;
File file;

byte cs_pin    = 10;
int start_time = 0;
int timeout    = 0;




void setup()
{
  start_time = millis();
  Serial.begin(115200);


  Serial.println("Inicializando cartao SD...");
  if (!SD.begin(cs_pin)){
    Serial.println("Failed!");
    return;
  }

  Serial.println("Cartao SD pronto.");
  Serial.println();

  //valida a inicialização
  if (!rtc.begin()){
    Serial.println("RTC nao encontrado!");
    while (1); //fica aqui pra sempre
  }
  if (!rtc.isrunning()){
    Serial.println("RTC com problemas!");

    rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); //Ajuste de data e hora na compilação, pela substituição das macros
    
    //rtc.adjust(DateTime(2020, 4, 3, 9, 50, 0));    //ajuste manual: DateTime(year, month, day, hour, minute, second)
  }
}

void loop(void)
{
  timeout = millis() - start_time;
  if (timeout > 10000){
    log("gravando dados...\n");
    start_time = millis();
  }
}

void log(char *msg){
  Serial.println("Loggin..");
  file = SD.open("data.log", FILE_WRITE);

  DateTime now = rtc.now();

  Serial.print(now.day(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.year(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.print(' ');
  Serial.print(msg);
//Serial.close();
  delay(2000);
  Serial.println("Done.");
}
