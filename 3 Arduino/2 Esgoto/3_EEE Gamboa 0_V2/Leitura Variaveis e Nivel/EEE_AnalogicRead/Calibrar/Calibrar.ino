//Analog Input 
#define ANALOG_PIN_0 36 
int analog_value = 0;

float read_percent = 0;
float ref_percent = 100;
float adc_intervals = 4095;


void setup()
{
Serial.begin(115200);
delay(1000); // give me time to bring up serial monitor
Serial.println("ESP32 Analog IN Test"); 
}
 
void loop()
{
read_percent = analogRead(ANALOG_PIN_0) * (ref_percent / adc_intervals);
analog_value = analogRead(ANALOG_PIN_0);

Serial.print("Percentual: "); 
Serial.println(read_percent);
Serial.print("Leitura Analógica: ");
Serial.println(analog_value);
delay(1000); 
}



