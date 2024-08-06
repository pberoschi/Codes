// More information at: https://www.aeq-web.com/
#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;

void setup () {
  while (!Serial);
  Serial.begin(9600);
  if (! rtc.begin()) {
    Serial.println("No RTC found");
    while (1);
  }
  if (! rtc.isrunning()) {
    Serial.println("RTC is not configured");
  }
  // Set Date and Time (Year, DAY, Month, Hour(24h), Minute, Second)
  //rtc.adjust(DateTime(2020, 03, 04, 13, 05, 00)); //Uncomment this line to set Date and Time
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

void loop () { // Get Date and Time

/*
  DateTime now = rtc.now();
  Serial.print(now.year(), DEC);
  Serial.print('-');
  Serial.print(now.month(), DEC);
  Serial.print('-');
  Serial.print(now.day(), DEC);
  Serial.print(" ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
  delay(3000);
  
*/



  DateTime now = rtc.now();
  
  Serial.print(now.day(), DEC);
  Serial.print("/");
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.year(), DEC);
  Serial.print(',');



  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
  delay(3000);







}



  
