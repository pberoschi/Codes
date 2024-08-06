




void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}



void loop() {

int sum = 0;
int pacote[5] = {};
int sensorVib = 0;

// Criando lista aleatório para substituir leitura do sensor //
  for (int i = 0; i <= 4; i++) {
    int sensorVib = random(300,315);
    pacote[i] = {sensorVib};
    Serial.println(pacote[i]);

    sum += pacote[i];
  }

 int media = sum / 5;
 Serial.print("Média de 5: ");
 Serial.println(media);   


// Serial.println("Reiciciando o ciclo");   
sleep(5);

}
