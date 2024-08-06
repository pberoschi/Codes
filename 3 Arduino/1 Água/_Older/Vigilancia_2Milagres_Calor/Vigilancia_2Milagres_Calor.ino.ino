//https://linuxhint.com/esp32-pir-motion-sensor-arduino-ide/


#define timeSeconds 1
const int led = 4;   /*GPIO PIN 4 defined for LED*/
const int PIR_Out = 13; /*GPIO pin 13 for PIR out*/
unsigned long Current_Time = millis();  /*variable defined for storing millis values*/
unsigned long Previous_Trig = 0;
boolean Starting_Time = false;

void IRAM_ATTR detectsMovement() {   /*check for motion*/
  Serial.println("MOTION DETECTED");
  digitalWrite(led, HIGH);   /*Turn ON LED if condition is true*/
  Starting_Time = true;
  Previous_Trig = millis();
}
void setup() {
  Serial.begin(115200); /*baud rate for serial communication*/
  pinMode(PIR_Out, INPUT_PULLUP); /*PIR motion sensor mode defined*/
  /*PIR is configured in RISING mode, set motion sensor pin as output*/
  attachInterrupt(digitalPinToInterrupt(PIR_Out), detectsMovement, RISING);
  pinMode(led, OUTPUT);  /*set LED to LOW*/
  digitalWrite(led, LOW);
}
void loop() {
  Current_Time = millis(); /*store current time*/
  if(Starting_Time && (Current_Time - Previous_Trig > (timeSeconds*1000))) { /*Time interval after which LED will turn off*/
   Serial.println("MOTION STOPPED");  /*Prints motion stopped if no motion detected*/
    digitalWrite(led, LOW);  /*Set LED to LOW if condition is false*/
    Starting_Time = false;  
  }
}