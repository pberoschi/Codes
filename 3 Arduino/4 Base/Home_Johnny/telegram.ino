// Handle what happens when you receive new messages
void handleNewMessages(int numNewMessages) {
  Serial.println("handleNewMessages");
  Serial.println(String(numNewMessages));

  for (int i=0; i<numNewMessages; i++) {
    // Chat id of the requester
    String chat_id = String(bot.messages[i].chat_id);
    if (chat_id != CHAT_ID){
      bot.sendMessage(chat_id, "Unauthorized user", "");
      continue;
    }
    
    // Print the received message
    String text = bot.messages[i].text;
    Serial.println(text);

    String from_name = bot.messages[i].from_name;

    if (text == "/start") {
      String welcome = "Bem-vindo, " + from_name + ".\n";
      welcome += "Use os seguintes comandos para controlar sua automação: \n\n";
      
      welcome += "/lf para LIGAR a frente \n";
      welcome += "/df para DESLIGAR a frente \n\n";

      welcome += "/ll1 para LIGAR a lateral PRINCIPAL \n";
      welcome += "/dl1 para DESLIGAR a lateral \n\n";

      welcome += "/ll2 para LIGAR a lateral 2 \n";
      welcome += "/dl2 para DESLIGAR a lateral 2 \n\n";

      welcome += "/lg para LIGAR a área gourmet \n";
      welcome += "/dg para DESLIGAR a área gourmet \n\n";

      welcome += "/lg para LIGAR toda a iluminação \n";
      welcome += "/dg para DESLIGAR toda a iluminação \n\n\n";

      welcome += "/status para verificar o estado das saídas \n";
      bot.sendMessage(chat_id, welcome, "");
    }

    if (text == "/lf") {
      bot.sendMessage(chat_id, "A iluminação da FRENTE está LIGADA", "");
      digitalWrite(frentePin, HIGH);
    }

    if (text == "/ll1") {
      bot.sendMessage(chat_id, "A iluminação da LATERAL PRINCIPAL está LIGADA", "");
      digitalWrite(PlateralPin, HIGH);
    }

    if (text == "/ll2") {
      bot.sendMessage(chat_id, "A iluminação da LATERAL 2 está LIGADA", "");
      digitalWrite(SlateralPin, HIGH);
    }

    if (text == "/lg") {
      bot.sendMessage(chat_id, "A iluminação da ÁREA GOURMET está LIGADA", "");
      digitalWrite(gourmetPin, HIGH);
    }




    if (text == "/df") {
      bot.sendMessage(chat_id, "A iluminação da FRENTE está DESLIGADA", "");
      digitalWrite(frentePin, LOW);
    }
    
    if (text == "/dl1") {
      bot.sendMessage(chat_id, "A iluminação da LATERAL PRINCIPAL está DESLIGADA", "");
      digitalWrite(PlateralPin, LOW);
    }

    if (text == "/dl2") {
      bot.sendMessage(chat_id, "A iluminação da LATERAL 2 está DESLIGADA", "");
      digitalWrite(SlateralPin, LOW);
    }

    if (text == "/dg") {
      bot.sendMessage(chat_id, "A iluminação da ÁREA GOURMET está DESLIGADA", "");
      digitalWrite(gourmetPin, LOW);
    }

    if (text == "/status") {
      if (digitalRead(frentePin)){
        bot.sendMessage(chat_id, "A iluminação da FRENTE está LIGADA", "");
      }
      else{
        bot.sendMessage(chat_id, "A iluminação da FRENTE está DESLIGADA", "");
      }

      if (digitalRead(PlateralPin)){
        bot.sendMessage(chat_id, "A iluminação da LATERAL PRINCIPAL está LIGADA", "");
      }
      else{
        bot.sendMessage(chat_id, "A iluminação da LATERAL PRINCIPAL está DESLIGADA", "");
      }

      if (digitalRead(SlateralPin)){
        bot.sendMessage(chat_id, "A iluminação da LATERAL 2 está LIGADA", "");
      }
      else{
        bot.sendMessage(chat_id, "A iluminação da LATERAL 2 está DESLIGADA", "");
      }

      if (digitalRead(gourmetPin)){
        bot.sendMessage(chat_id, "A iluminação da ÁREA GOURMET está LIGADA", "");
      }
      else{
        bot.sendMessage(chat_id, "A iluminação da ÁREA GOURMET está DESLIGADA", "");
      }
    }
  }
}