int sensor_pin = 4; //NodeMCU On Board LED D7
int board_led = 2; //NodeMCU On Board LED D0


void setup(){
  Serial.begin(115200);

  pinMode(sensor_pin, INPUT);
  pinMode(board_led, OUTPUT); 
  // pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){

  int val_digital = digitalRead(sensor_pin);
  

   if(val_digital) {


     Serial.println(val_digital);
    //  Serial.print("\t");
    //  Serial.println("Earthquake");

     digitalWrite (board_led, HIGH);
     sleep(0.5);

   }

digitalWrite (board_led, LOW);
  
}