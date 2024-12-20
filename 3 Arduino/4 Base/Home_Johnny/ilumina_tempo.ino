void iluminacao_tempo() {
  // Serial.print("Modo Alegria Papai...");
  for (int p=0; p<=10; p++)
  {
    // digitalWrite(PlateralPin, HIGH);
    // delay(500);
    // digitalWrite(PlateralPin, LOW);
    // delay(500);

    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);
  }

  // Serial.print("Saindo do Modo Alegria...");
  digitalWrite(PlateralPin, HIGH);
  digitalWrite(gourmetPin, HIGH);
  // digitalWrite(ledPin, HIGH);


  delay(36000);

  digitalWrite(PlateralPin, LOW);
  digitalWrite(gourmetPin, LOW);
  // digitalWrite(ledPin, LOW);

}