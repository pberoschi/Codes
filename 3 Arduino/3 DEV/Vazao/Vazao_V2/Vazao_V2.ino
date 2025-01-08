#define LED_BUILTIN 2
#define SENSOR  23 //27

const int rele1   = 22;
// const int rele2   = 23;
const int buzzer  = 26;
const int ledPin  = 2; 

long currentMillis = 0;
long previousMillis = 0;
int interval = 1000;
boolean ledState = LOW;
float calibrationFactor = 4.5;
volatile byte pulseCount;
byte pulse1Sec = 0;
float flowRate;
unsigned int flowMilliLitres;
unsigned long totalMilliLitres;

void IRAM_ATTR pulseCounter()
{
  pulseCount++;
}

void setup()
{
  Serial.begin(115200);

  pinMode(LED_BUILTIN, OUTPUT);
  // pinMode(SENSOR, INPUT_PULLUP);
  pinMode(SENSOR, INPUT);

  pinMode(rele1,OUTPUT);
  // pinMode(rele2,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(ledPin,OUTPUT);

  digitalWrite(rele1, LOW);
  // digitalWrite(rele2, LOW);
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);

  pulseCount = 0;
  flowRate = 0.0;
  flowMilliLitres = 0;
  totalMilliLitres = 0;
  previousMillis = 0;

  attachInterrupt(digitalPinToInterrupt(SENSOR), pulseCounter, FALLING);
}

void loop()
{
  currentMillis = millis();
  if (currentMillis - previousMillis > interval) {
    
    pulse1Sec = pulseCount;
    pulseCount = 0;

    // HÁ OBSERVAÇÕES AQUI  //
    flowRate = ((1000.0 / (millis() - previousMillis)) * pulse1Sec) / calibrationFactor;
    previousMillis = millis();

    // HÁ OBSERVAÇÕES AQUI  //
    flowMilliLitres = (flowRate / 60) * 1000;
    totalMilliLitres += flowMilliLitres;

    // Serial.print("Taxa de Fluxo: ");
    // Serial.print(int(flowRate));  // Print the integer part of the variable
    // Serial.print("L/min");
    // Serial.print("\t");       // Print tab space

    // Print the cumulative total of litres flowed since starting
    Serial.print("Quantidade de Líquido de Saída: ");
    Serial.print(totalMilliLitres);
    Serial.print("mL / ");
    Serial.print(totalMilliLitres / 1000);
    Serial.println("L");

    if (totalMilliLitres >= 1900) {
      out1();

    }
  }
}


void out1() {
  // --> PISCADAS PAPAI <-- //
  // for (int p=0; p<=10; p++) {
  //   digitalWrite(ledPin, HIGH);
  //   delay(200);
  //   digitalWrite(ledPin, LOW);
  //   delay(200);
  // }
 
  
  // digitalWrite(rele1, HIGH);
  // delay(5000);
  // digitalWrite(rele1, LOW);

  digitalWrite(ledPin, HIGH);
  delay(5000);
  digitalWrite(ledPin, LOW);
  
  totalMilliLitres = 0;
}








