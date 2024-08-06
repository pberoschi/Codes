void iluminacao_tempo() {
  digitalWrite(lateralPin, HIGH);
  digitalWrite(gourmetPin, HIGH);

  delay(300000);

  digitalWrite(lateralPin, LOW);
  digitalWrite(gourmetPin, LOW);

}