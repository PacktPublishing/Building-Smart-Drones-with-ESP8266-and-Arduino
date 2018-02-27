
#define BLYNK_PRINT Serial
#include <SPI.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>
#include <ESP8266WiFi.h>

char auth[] = "**********";
char ssid[] = "**********";
char pass[] = "**********";

Servo s1;  
Servo s2;

void setup()  
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  s1.attach(0);
  s2.attach(2);
}
BLYNK_WRITE(V1)  
{
  s1.write(param.asInt());  
}
BLYNK_WRITE(V6)  
{ 
  s2.write(param.asInt());
}  
void loop()  
{ 
  Blynk.run();
}
