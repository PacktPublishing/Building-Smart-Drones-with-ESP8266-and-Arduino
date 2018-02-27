#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "**********";
char ssid[] = "**********";
char pass[] = "**********";

void setup() {
  Blynk.begin(auth, ssid, pass);
  pinMode(4, OUTPUT); //for trigger
  pinMode(5, INPUT); //for echo
}

void loop() {
  long duration, distance;
  digitalWrite(4, LOW); //for trigger
  delayMicroseconds(2);
  digitalWrite(4, HIGH);
  delayMicroseconds(10);
  digitalWrite(4, LOW);
  duration = pulseIn(5, HIGH); //for echo
  distance = (duration / 2) / 29.1;
  Blynk.virtualWrite(V0, distance);
  delay(200);
  Blynk.run();
}
