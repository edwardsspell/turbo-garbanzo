#include <ESP8266WiFi.h>
//#define BLYNK_PRINT Serial    
#include <BlynkSimpleEsp8266.h>
char auth[] = "3ur8yLkOzDlsO_CmwYqFzk2x8gqwobss";
  
char ssid[] = "bjp";
char pass[] = "12344321";

//infrard pin
 
#define parkpin1 13
#define parkpin2 12
#define parkpin3 14


int parkslot1;
int parkslot2;
int parkslot3; 

//blynk pin
WidgetLED parkled1(V3);
WidgetLED parkled2(V4);
WidgetLED parkled3(V5);  
BlynkTimer timer;

void Bconnect(){
  if(!Blynk.connected()){
    Serial.println("Blynk disconnected");
    if (Blynk.connect()){
      Serial.println("Reconnected");
    }
    else{
      Serial.println("Not reconected");
    }
  }
}
void setup()
{
  Serial.begin(115200);
  delay(10);
  Blynk.begin(auth, ssid, pass);
  while(Blynk.connect() == false){}
  timer.setInterval(60*1000,Bconnect);
  pinMode(parkpin1, INPUT);
}
 
void loop()
{
  timer.run();
  if(Blynk.connected()){
    getParkValue();
    Blynk.run();
  }
}
void getParkValue(void)
{
  parkslot1 = digitalRead(parkpin1);
  parkslot2 = digitalRead(parkpin2);
  parkslot3= digitalRead(parkpin3);
  if (!parkslot1) 
  { 
    parkled1.on(); 
  }
  else{
    parkled1.off();
  }
  
  if (!parkslot2) 
  { 
    parkled2.on(); 
  }
  else{
    parkled2.off();
  }
  
  if (!parkslot3) 
  { 
    parkled3.on(); 
  }
  else{
    parkled3.off();
  }
}
