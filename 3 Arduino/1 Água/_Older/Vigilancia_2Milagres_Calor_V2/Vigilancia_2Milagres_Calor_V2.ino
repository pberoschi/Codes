int ledPin = 4;              
int inputPin = 13;            
int pirState = LOW;             
int val = 0;    
int x;

void setup() {
  pinMode(ledPin, OUTPUT);      
  pinMode(inputPin, INPUT);     
  Serial.begin(115200);
  digitalWrite(ledPin, LOW);
} 
void loop(){
  val = digitalRead(inputPin);    
  if (val == HIGH)  
  {            
    //digitalWrite(ledPin, HIGH); 
    alarme(); 
    Serial.println("Movimento Detectado!");
    delay(1000); 
  }
  else 
  {
    digitalWrite(ledPin, LOW); 
    //Serial.println("Sem Movimento!");  
  }
}
  
void alarme(){
x=0;
while (x < 2)
{
  digitalWrite(ledPin, HIGH);
  delay(50);
  digitalWrite(ledPin, LOW);
  delay(50);
  x = x+1;
}
}