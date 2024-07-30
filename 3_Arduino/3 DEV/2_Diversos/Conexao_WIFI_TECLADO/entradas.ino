void entrada()
{
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    bot.sendMessage(CHAT_ID, "EEE Gamboa 0 Extravasando", "");
    delay(500);
  //} else {
    //digitalWrite(ledPin, LOW);
  //}
}
}
