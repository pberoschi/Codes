#define BLYNK_PRINT Serial    
//#include <SPI.h>
//#include <Ethernet.h>
#include <BlynkSimpleSIM800.h>
#include <SimpleTimer.h>

SimpleTimer timer;

#define echoPin 5 // Echo Pin
#define trigPin 4 // Trigger Pin

long duration, distance; 

void RepeatTask()
{

 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 
 distance = duration/58.2;

 Serial.println(distance);
}

void setup() {
 Serial.begin(9600);
 Blynk.begin(auth);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 timer.setInterval(1000, RepeatTask);
}

BLYNK_READ(V8);
{
Blynk.virtualWrite(8,distance);// virtualpin 8 distance
}

void loop() {
  Blynk.run(); // Initiates Blynk
  timer.run(); // Initiates SimpleTimer
}
