void setupGSM()
{

  SerialGSM.begin(9600);

  Serial.println("Setup GSM...");
  delay(3000);

  Serial.println(modemGSM.getModemInfo());
  

  if (!modemGSM.restart())
  {
    Serial.println("Restarting GSM Modem failed");
    delay(3000);
    return;

  }


  if (!modemGSM.waitForNetwork())
  {
    Serial.println("Failed to connect to network");
    delay(3000);
    return;

  }


  //if (!modemGSM.gprsConnect("zap.vivo.com.br", "vivo", "vivo")) {
  if (!modemGSM.gprsConnect("tim.br", "tim", "tim")) {
    //if (!modemGSM.gprsConnect("timbrasil.br", "tim", "tim")) {
    Serial.println("GPRS Connection Failed");
    delay(3000);
    return;
  }

  Serial.println("Setup GSM Success");



}
