/*
 * Who's-at-home-sniffer with LED
 * Markus Opitz 2023
 * 
 */

// #include <Adafruit_NeoPixel.h>
// #define PIN_NEO_PIXEL  12   // pin NeoPixel
// #define MAX_PIXELS     10   // The number of LEDs
// Adafruit_NeoPixel NeoPixel(MAX_PIXELS, PIN_NEO_PIXEL, NEO_GRB + NEO_KHZ800);

#include "esp_wifi.h"


bool debugMode = false;
String macList[100][3]; //macList stores MAC, timer and channel [3] for up to 100 MACs [100]
String macList2[10][3] = {      //list of up to [10] users     name, MAC, rank=pixelnumber
  //  {"Harry","00:00:00:00:00:00", "0"},
  //  {"Sally","00:00:00:00:00:00", "1"},
  //  {"Laurel","00:00:00:00:00:00","2"},
  //  {"Hardy","00:00:00:00:00:00", "3"},      //  , between each user
   {"ESP32_2","A0:B7:65:4C:A3:CC", "4"}   //  no ,  after the last entry
};

// int pixel;

// define colors
// uint32_t blue = NeoPixel.Color(0,120,255);
// uint32_t lblue = NeoPixel.Color(0,255,255);
// uint32_t red = NeoPixel.Color(255,0,0);
// uint32_t dred = NeoPixel.Color(100,0,0);
// uint32_t green = NeoPixel.Color(100,200,0);
// uint32_t yellow = NeoPixel.Color(255,255,0);
// uint32_t white = NeoPixel.Color(255,255,255);
// uint32_t pink = NeoPixel.Color(255,0,100);
// uint32_t cyan = NeoPixel.Color(0,255,255);
// uint32_t orange = NeoPixel.Color(230,110,0);
// uint32_t violet = NeoPixel.Color(170,100,255); 
// uint32_t brown = NeoPixel.Color(153,76,0);
// uint32_t grey = NeoPixel.Color(10,10,10);


int maxMacs  =  sizeof macList  / sizeof macList[0];
int maxMacs2 =  sizeof macList2 / sizeof macList2[0];

int knownMacs = 0;
int channel = 1;
int timer = 60; // Set to 0 or less for infinite duration of entries

const wifi_promiscuous_filter_t filt={
    .filter_mask=WIFI_PROMIS_FILTER_MASK_MGMT|WIFI_PROMIS_FILTER_MASK_DATA
};

typedef struct { 
  uint8_t mac[6];
} __attribute__((packed)) MacAddr;

typedef struct { 
  int16_t fctl;
  int16_t duration;
  MacAddr da;
  MacAddr sa;
  MacAddr bssid;
  int16_t seqctl;
  unsigned char payload[];
} __attribute__((packed)) WifiMgmtHdr;

void sniffer(void* buf, wifi_promiscuous_pkt_type_t type) { 
  int channel1 = channel;
  wifi_promiscuous_pkt_t *p = (wifi_promiscuous_pkt_t*)buf;
  int len = p->rx_ctrl.sig_len;
  WifiMgmtHdr *wh = (WifiMgmtHdr*)p->payload;
  len -= sizeof(WifiMgmtHdr);
  if (len < 0) return;
  String packet;
  String mac;
  String info;
  int fctl = ntohs(wh->fctl);
  for(int i=0;i<=20;i++){ // i <=  len
     String hpay=String(p->payload[i],HEX);
     if(hpay.length()==1)hpay="0"+hpay;
     packet += hpay;
  }
  for(int i=10;i<=15;i++){ // extract MAC address 
     String hpay=String(p->payload[i],HEX);
     if(hpay.length()==1)hpay="0"+hpay;
     mac += hpay;
     if(i<15)mac+=":";
  }
  mac.toUpperCase();
  
  info="MAC = " + mac + " channel=" + channel1 + " in " + packet+"(...)";
  int added = 0;
  for(int i=0;i<=maxMacs;i++){ // check if MAC address is known
    if(mac == macList[i][0]){ // if the MAC address is known, reset the time remaining 
      macList[i][1] = String(timer);
      added = 1;
    }
  }
  if(added == 0){ // Add new entry to the array if added==0
    macList[knownMacs][0] = mac;
    macList[knownMacs][1] = String(timer);
    macList[knownMacs][2] = String(channel);
    if (debugMode == true) 
      Serial.println(info);
    else     
      Serial.printf("\r\n%d MACs detected.\r\n",knownMacs);
    knownMacs ++;
    if(knownMacs > maxMacs){
      Serial.println("Warning: MAC overflow");
      knownMacs = 0;
    }
  }
}

void updateTimer(){ // update time remaining for each known device
  for(int i=0;i<maxMacs;i++){
    if(!(macList[i][0] == "")){
      int newTime = (macList[i][1].toInt());
      if(macList[i][2] == "") macList[i][2] = "0";
      if(!(macList[i][2] == "OFFLINE")){
        int timehere = (macList[i][2].toInt());
        timehere ++;
        macList[i][2] = String(timehere);
    }
      newTime --;
      if(newTime <= 0){
        macList[i][1] = String(newTime);
      }else{
        macList[i][1] = String(newTime);
      }
    }
  }
}

void showMyMACs(){ // show the MACs that are on both macList and macList2.
  String res = "";
  int counter=0;
  for(int i=0;i<maxMacs;i++){
    //Serial.println(macList[i][0]);
    String tmp1 = macList[i][0];
    if(!(tmp1 == "")){
      for(int j=0;j<maxMacs;j++){
        if(macList[i][0] == macList2[j][1]){
          counter += 1;
          res += (String(counter) +  ". MAC=" + macList[i][0] + "  ALIAS=" + macList2[j][0] + "  Channel=" + macList[i][2] + "  Timer=" + macList[i][1]);
          //Serial.println("\r\n"+(String(counter) +  ". MAC=" + macList[i][0] + "  ALIAS=" + macList2[j][0] + "  Channel=" + macList[i][2] + "  Timer=" + macList[i][1] + "\r\n"));
          Serial.print(macList2[j][0]); Serial.print("  is online   = "); Serial.println(macList2[j][2]);
          // pixel = (macList2[j][2]).toInt(); 

          // assign a color to each user.
          // if ((macList2[j][2]) == "0") NeoPixel.setPixelColor(pixel, dred);
          // if ((macList2[j][2]) == "1") NeoPixel.setPixelColor(pixel, blue);
          // if ((macList2[j][2]) == "2") NeoPixel.setPixelColor(pixel, green);
          // if ((macList2[j][2]) == "3") NeoPixel.setPixelColor(pixel, orange);
          // if ((macList2[j][2]) == "4") NeoPixel.setPixelColor(pixel, violet);
          // if ((macList2[j][2]) == "5") NeoPixel.setPixelColor(pixel, lblue);
          // if ((macList2[j][2]) == "6") NeoPixel.setPixelColor(pixel, grey);
          // if ((macList2[j][2]) == "8") NeoPixel.setPixelColor(pixel, brown);
          // NeoPixel.show();
        }
      }
    }
  }
}

void setup() {
  // NeoPixel.begin();
  // NeoPixel.clear();
  // runlight();
  // turnoff(); delay(1000);

  
  Serial.begin(115200);
  wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
  esp_wifi_init(&cfg);
  esp_wifi_set_storage(WIFI_STORAGE_RAM);
  esp_wifi_set_mode(WIFI_MODE_NULL);
  esp_wifi_start();
  esp_wifi_set_promiscuous(true);
  esp_wifi_set_promiscuous_filter(&filt);
  esp_wifi_set_promiscuous_rx_cb(&sniffer);
  esp_wifi_set_channel(channel, WIFI_SECOND_CHAN_NONE);

}


void loop() {
    if(channel > 14) channel = 1;
    esp_wifi_set_channel(channel, WIFI_SECOND_CHAN_NONE);
    delay(3000);
    // turnoff();
    if (timer>0) updateTimer();
    if (debugMode == false) showMyMACs();
    channel++;
}


// void runlight () {   //start indicator
//     for (int pixel = 0; pixel < MAX_PIXELS; pixel++) { 
//     NeoPixel.setPixelColor(pixel, NeoPixel.Color(0, 0, 155));
//     NeoPixel.setPixelColor(pixel-1, NeoPixel.Color(0, 0, 0));
//     NeoPixel.show();
//     delay(100); // pause between each pixel
//   }
// }


// void turnoff() {
//   NeoPixel.clear();
//   NeoPixel.show();
// }
