#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int number;

void setup() { 
  lcd.begin(16, 2);
  pinMode(9,OUTPUT);
  analogWrite(9,130);
  Serial.begin(9600);

}

void loop() { 

  lcd.setCursor(1,0);
  lcd.print("GERANDO");
  lcd.setCursor(1,1);
  lcd.print("NUMEROS");
  lcd.setCursor(1,0);
  delay(2000);
  lcd.clear();
  delay(5000);
  /*
  Serial.println(number);
  number = random(56, 75);
  lcd.print(number);
  */
 
  }
