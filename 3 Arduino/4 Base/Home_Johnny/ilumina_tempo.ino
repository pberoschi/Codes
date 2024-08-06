void iluminacao_tempo() {

  for (int p=0; p<=10; p++)
  {
    digitalWrite(PlateralPin, HIGH);
    delay(800);
    digitalWrite(PlateralPin, LOW);
    delay(800);
  }

  digitalWrite(PlateralPin, HIGH);
  digitalWrite(gourmetPin, HIGH);

  delay(36000);

  digitalWrite(PlateralPin, LOW);
  digitalWrite(gourmetPin, LOW);

}