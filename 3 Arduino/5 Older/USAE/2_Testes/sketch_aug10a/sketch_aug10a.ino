
int led = 13;
int x = 0;
int var = 0;

void setup() {


}

void loop() {
  x = random(0, 11);


  if (x == 49)   {

    while (var < 4) {

      digitalWrite(led, HIGH);
      delay(1000);

      var ++;

    }
  }
}
