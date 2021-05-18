#include <WiFi.h>
#include "time.h"

const char* ssid     = "JANDERSON";
const char* password = "13051986";

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = -10800;
const int   daylightOffset_sec = 0;

const int led = 23;
const int pinoSensor = 4;

void setup(){
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  pinMode(pinoSensor, INPUT); //DEFINE O PINO COMO ENTRADA
  digitalWrite(led, LOW); //LED INICIA DESLIGADO

  // Connect to Wi-Fi
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  
  // Init and get the time
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  printLocalTime();

  //disconnect WiFi as it's no longer needed
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
}

void loop(){
  delay(1000);
  printLocalTime();
}

void printLocalTime(){
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
   if(&timeinfo, "%H == 19" && "%M == 41" && "%S == 00"){
    digitalWrite(led, HIGH);
    //delay(2000);
    //digitalWrite(led, LOW);

   if(digitalRead(pinoSensor) == LOW){ //SE A LEITURA DO PINO FOR IGUAL A LOW, FAZ
      digitalWrite(led, LOW); //ACENDE O LED
    
    
  }
  
}

}
 
  
