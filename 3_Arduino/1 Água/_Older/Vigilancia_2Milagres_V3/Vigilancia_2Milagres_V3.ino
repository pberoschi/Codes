#include <NewPing.h>
 
#define TRIGGER_PIN  5
#define ECHO_PIN     18
#define MAX_DISTANCE 400
#define Alarme 23
int x;
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
 
void setup() {
  Serial.begin(115200);
  pinMode(Alarme, OUTPUT); // Sets the echoPin as an Input
  digitalWrite(Alarme, LOW);
}
 
void loop() {
  delay(50);
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm());
  Serial.println("cm");


  //if (((sonar.ping_cm()) < 130.00) and ((sonar.ping_cm()) > 30))
  if ((sonar.ping_cm()) < 80)
    {
  x=0;
  while (x < 2) {
  {
    digitalWrite(Alarme, HIGH);
    delay(50);
    digitalWrite(Alarme, LOW);
    delay(50);
    x=x+1;
  }
  }
} 
  //delay(1000);
}
