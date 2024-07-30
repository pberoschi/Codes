
int buz = 11;


void setup() {
  pinMode (buz, OUTPUT);

  int start = 0;

  while (start < 3)
  {
    /*
    tone(buz,1000);
    delay(50);
    tone(buz, 1000);
    delay(50);
    noTone(buz);
    //delay(1000);
    */
    
    digitalWrite(buz, HIGH);
    delay(60);
    digitalWrite(buz, LOW);
    delay(60);
    start++;

  }
}

void loop() {

  //digitalWrite(buz, HIGH);
  //delay(1000);


}
