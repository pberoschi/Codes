void handleStatus(String chatId)
{
  bot.sendMessage(chatId, ">>> EEE BG04 <<<", "");
  String message = "";
  //Verifica se o relê está ligado ou desligado e gera a mensagem de acordo
  if(FCMB1 == HIGH) //A lógica do nosso relê é invertida
  {
    message += "- CMB1: LIGADO\n";
  }
  else
  {
    message += "- CMB1: PARADO\n";
  }

  if(FCMB2 == HIGH) //A lógica do nosso relê é invertida
  {
     message += "- CMB2: LIGADO\n";
  }
  else
  {
    message += "- CMB2: PARADO\n";
  }
    
  if(GeradorON == HIGH) //A lógica do nosso relê é invertida
  {
    message += "- GMG: LIGADO\n";
  }
  else
  {
    message += "- GMG: PARADO\n";
  }

  //Envia a mensagem para o contato
  bot.sendMessage(chatId, message, "");

  //Enviando variáveis da Instalação
  // >>> TENSÃO <<<
  int tensao = random(380,440);
  String(a) = String("- Tensão de Linha: ");
  String(b) = String(tensao);
  String(c) = String(" VCA");
  String(d) = a + b + c;
  bot.sendMessage(chatId, d, "");

  // >>> CORRENTE <<<
  int corrente = random(40,60);
  String(e) = String("- Corrente: ");
  String(f) = String(corrente);
  String(g) = String(" A");
  String(h) = e + f + g;
  bot.sendMessage(chatId, h, "");
}
