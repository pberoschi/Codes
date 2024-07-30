void setup() {
  Serial.begin(115200);


}
void loop() {
char dado;

if
  (Serial.available()){
     
    dado = Serial.read();
    Serial.print(dado);
  }


}
