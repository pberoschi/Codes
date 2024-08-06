int leituras[5] = {0,256,512,768,1023};


void setup()
{
  
  Serial.begin(115200);
  // pinMode(23, OUTPUT);//Definimos o pino 23 como saída.
  pinMode(22, OUTPUT);//Definimos o pino 22 como saída.
  // pinMode(21, OUTPUT);//Definimos o pino 21 como saída.
  // pinMode(19, OUTPUT);//Definimos o pino 19 como saída.
  
  // ledcAttachPin(23, 0);//Atribuimos o pino 23 ao canal 0.
  // ledcSetup(0, 1000, 10);//Atribuimos ao canal 0 a frequencia de 1000Hz com resolucao de 10bits.
  // ledcWrite(0, 256);//Escrevemos um duty cycle de 25% no canal 0.

  ledcAttachPin(22, 1);//Atribuimos o pino 22 ao canal 1.
  ledcSetup(1, 1000, 10);//Atribuimos ao canal 1 a frequencia de 1000Hz com resolucao de 10bits.
  // ledcWrite(1, 512);//Escrevemos um duty cycle de 50% no canal 1.

  // ledcAttachPin(21, 2);//Atribuimos o pino 21 ao canal 2.
  // ledcSetup(2, 1000, 10);//Atribuimos ao canal 2 a frequencia de 1000Hz com resolucao de 10bits.
  // ledcWrite(2, 768);//Escrevemos um duty cycle de 75% no canal 2.

  // ledcAttachPin(19, 3);//Atribuimos o pino 19 ao canal 3.
  // ledcSetup(3, 1000, 10);//Atribuimos ao canal 3 a frequencia de 1000Hz com resolucao de 10bits.
  // ledcWrite(3, 1023);//Escrevemos um duty cycle de 100% no canal 3.
}
void loop()
{

for(int x = 0; x < 5; x = x+1){
  // ledcAttachPin(23, 0);//Atribuimos o pino 23 ao canal 0.
  // ledcSetup(0, 1000, 10);//Atribuimos ao canal 0 a frequencia de 1000Hz com resolucao de 10bits.
  ledcWrite(1, leituras[x]);
  
  Serial.println(x);
  delay(5000);

}


}