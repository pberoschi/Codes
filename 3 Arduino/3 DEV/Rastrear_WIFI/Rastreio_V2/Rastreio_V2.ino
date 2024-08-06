#include <WiFi.h>
#include <Wire.h>
#include "esp_wifi.h"


String maclist[64][3];
int listcount = 0;

String KnownMac[10][2] = {  // Coloque os dispositivos que você deseja que sejam reconhecidos
  //{"Will-Phone","E00AF656BA2D"},
  //{"Will-PC","E894Fffffff3"},
  {"MAC ESP32_2","A0B7654CA3CC"}
  
};

String defaultTTL = "60"; // Tempo máximo (segundos) decorrido antes que o dispositivo seja colocado offline

const wifi_promiscuous_filter_t filt={ //Idk what this does
    .filter_mask=WIFI_PROMIS_FILTER_MASK_MGMT|WIFI_PROMIS_FILTER_MASK_DATA
};

typedef struct { // or this
  uint8_t mac[6];
} __attribute__((packed)) MacAddr;

typedef struct { // ainda não sei muito sobre isso
  int16_t fctl;
  int16_t duration;
  MacAddr da;
  MacAddr sa;
  MacAddr bssid;
  int16_t seqctl;
  unsigned char payload[];
} __attribute__((packed)) WifiMgmtHdr;

#define maxCh 13 //max Channel -> US = 11, EU = 13, Japan = 14

int curChannel = 1;

void sniffer(void* buf, wifi_promiscuous_pkt_type_t type) { //É aqui que os pacotes acabam depois de serem cheirados
  wifi_promiscuous_pkt_t *p = (wifi_promiscuous_pkt_t*)buf; // Não sei o que essas 3 linhas fazem
  int len = p->rx_ctrl.sig_len;
  WifiMgmtHdr *wh = (WifiMgmtHdr*)p->payload;
  len -= sizeof(WifiMgmtHdr);
  if (len < 0){
    Serial.println("Received 0");
    return;
  }
  String packet;
  String mac;
  int fctl = ntohs(wh->fctl);
  for(int i=8;i<=8+6+1;i++){ // Isso lê os primeiros dois bytes do pacote. É aqui que você pode ler o pacote inteiro substituindo o "8+6+1" por "p->rx_ctrl.sig_len"
     packet += String(p->payload[i],HEX);
  }
  for(int i=4;i<=15;i++){ // Isso remove os bits de "mordida" da estatística e do final dos dados que queremos. Então só temos o endereço mac.
    mac += packet[i];
  }
  mac.toUpperCase();

  
  int added = 0;
  for(int i=0;i<=5;i++){ // verifica se o endereço MAC foi adicionado antes           //////////////////////////////////////////////
    if(mac == maclist[i][0]){
      maclist[i][1] = defaultTTL;
      if(maclist[i][2] == "OFFLINE1"){
        maclist[i][2] = "0";
      }
      added = 1;
    }
  }
  
  if(added == 0){ // Se for novo, adicione-o à matriz.
    maclist[listcount][0] = mac;
    maclist[listcount][1] = defaultTTL;
    //Serial.println(mac);
    listcount ++;
    //if(listcount >= 64){
    if(listcount >= 5){
      Serial.println("Too many addresses");
      listcount = 0;
    }
  }
}


//===== SETUP =====//
void setup() {

  /* start Serial */
  Serial.begin(115200);

  /* setup wifi */
  wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
  esp_wifi_init(&cfg);
  esp_wifi_set_storage(WIFI_STORAGE_RAM);
  esp_wifi_set_mode(WIFI_MODE_NULL);
  esp_wifi_start();
  esp_wifi_set_promiscuous(true);
  esp_wifi_set_promiscuous_filter(&filt);
  esp_wifi_set_promiscuous_rx_cb(&sniffer);
  esp_wifi_set_channel(curChannel, WIFI_SECOND_CHAN_NONE);
  
  Serial.println("starting!");
}

void purge(){ // This maanges the TTL
  for(int i=0;i<=63;i++){
    if(!(maclist[i][0] == "")){
      int ttl = (maclist[i][1].toInt());
      ttl --;
      if(ttl <= 0){
        Serial.println("OFFLINE2: " + maclist[i][0]);            /////////////////////////
        maclist[i][2] = "OFFLINE3";
        maclist[i][1] = defaultTTL;
      }else{
        maclist[i][1] = String(ttl);
      }
    }
  }
}

void updatetime(){ // Isso atualiza o tempo em que o dispositivo está online há
  //for(int i=0;i<=63;i++){
  for(int i=0;i<=5;i++){
    if(!(maclist[i][0] == "")){
      if(maclist[i][2] == "")maclist[i][2] = "0";
      if(!(maclist[i][2] == "OFFLINE4")){
          int timehere = (maclist[i][2].toInt());
          timehere ++;
          maclist[i][2] = String(timehere);
      }
      
      //Serial.println(maclist[i][0] + " : " + maclist[i][2]);                      ///////////////////////////////
      
    }
  }
}

void showpeople(){ // Isso verifica se o MAC está na lista calculada e, em seguida, o exibe no OLED e/ou o imprime em série.
  String forScreen = "";
  //for(int i=0;i<=63;i++){
  for(int i=0;i<=5;i++){
    String tmp1 = maclist[i][0];
    if(!(tmp1 == "")){
      for(int j=0;j<=9;j++){
        String tmp2 = KnownMac[j][1];
        if(tmp1 == tmp2){
          forScreen += (KnownMac[j][0] + " : " + maclist[i][2] + "\n");
          Serial.print(KnownMac[j][0] + " : " + tmp1 + " : " + maclist[i][2] + "\n -- \n");
          //Serial.println("VOLTOU...");                                                                           ///////////////////////////
        }
      }
    }
  }
  //update_screen_text(forScreen);
}

//===== LOOP =====//
void loop() {
    //Serial.println("Changed channel:" + String(curChannel));
    if(curChannel > maxCh){ 
      curChannel = 1;
    }
    esp_wifi_set_channel(curChannel, WIFI_SECOND_CHAN_NONE);
    delay(1000);
    updatetime();
    purge();
    showpeople();
    curChannel++;
    //delay(2000);
    
    
}

