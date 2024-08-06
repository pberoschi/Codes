int sensor_pin = 4; //NodeMCU On Board LED D7
int board_led = 2; //NodeMCU On Board LED D0


void setup(){
  Serial.begin(115200);

  pinMode(sensor_pin, INPUT);
  pinMode(board_led, OUTPUT); 
  // pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){

int sum = 0;
int pacote[5] = {};
int sensorVib = 0;

  for (int i = 0; i <= 4; i++) {
    int sensorVib = digitalRead(sensor_pin);
    pacote[i] = {sensorVib};
    Serial.println(pacote[i]);
    sum += pacote[i];
    sleep(1);
  }

 float media = sum / 5;
 Serial.print("Média de 5: ");
 Serial.println(media);   


// Serial.println("Reiciciando o ciclo");   
sleep(1);















}