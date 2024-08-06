
float tensao = 0;
float corrente = 0;
float tensaoFinal = 0;
float correnteFinal = 0;
int correnteInst[1000];
int tensaoInst[1000];
long contaFinal = 0;
long tempoEnvio = 0;


void Task1code( void * pvParameters ) {


  for (;;) {

    long ti, tf, acumTensao = 0, acumCorrente = 0;
    ti = micros();
    long conta = 0;

    while (micros() - ti < 16667)
    {
      tensaoInst[conta] = analogRead(36);
      correnteInst[conta] = analogRead(39);

      acumTensao = acumTensao + tensaoInst[conta];
      acumCorrente = acumCorrente + correnteInst[conta];

      conta++;


    }


    long mediaTensao = acumTensao / conta;
    long mediaCorrente = acumCorrente / conta;


    acumTensao = 0;
    acumCorrente = 0;

    for (int i = 0; i < conta; i++)
    {
      long aux = tensaoInst[i] - mediaTensao;
      acumTensao = acumTensao + ( aux * aux);

      long aux2 = correnteInst[i] - mediaCorrente;
      acumCorrente = acumCorrente + ( aux2 * aux2);

    }

    tensao = (sqrt(acumTensao / conta) / 1.97) - 6;
    corrente = (sqrt(acumCorrente / conta) / 28.89) - 0.13;

    contaFinal++;
    tensaoFinal = ((tensaoFinal * (contaFinal - 1)) + tensao) / contaFinal;// ValorMedio VM = VM(n-1) * N-1 + Vi / N;
    correnteFinal = ((correnteFinal * (contaFinal - 1)) + corrente) / contaFinal;

  }
}
