void message()
{
if (millis() > lastTimeChecked + delayBetweenChecks)  {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    if (numNewMessages) {
      Serial.println("got response");
      handleNewMessages(numNewMessages);
    }
    lastTimeChecked = millis();
    if (lightTimerActive && millis() > lightTimerExpires) {
      lightTimerActive = false;
      digitalWrite(LED_PIN, LOW);
    }
  } 

}
