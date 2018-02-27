#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

static const int RX = 4, TX = 5;
static const uint32_t GPSBaud = 9600;     

TinyGPSPlus mygps;
WidgetMap myMap(V0); 

SoftwareSerial test_GPS(RX, TX);

BlynkTimer timer;

float noofsats;


char auth[] = "********";                                       
char ssid[] = "********";                                       
char pass[] = "********";                                      

void setup()
{
  Serial.begin(115200);
  Serial.println();
  test_GPS.begin(GPSBaud);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(5000L, checkGPS);         
}

void checkGPS() {
  if (mygps.charsProcessed() < 10)
  {
    Serial.println(F("No GPS detected: check wiring."));
    Blynk.virtualWrite(V4, "GPS ERROR");    
  }
}

void loop()
{

  while (test_GPS.available() > 0)
  {
    if (mygps.encode(ss.read()))
      displayInfo();
  }
  Blynk.run();
  timer.run();
}

void displayInfo()
{

  if (mygps.location.isValid() )
  {

    float latitude = (mygps.location.lat());
    float longitude = (mygps.location.lng());

    Serial.print("LAT:  ");
    Serial.println(latitude, 6);  
    Serial.print("LONG: ");
    Serial.println(longitude, 6);
    Blynk.virtualWrite(V1, String(latitude, 6));
    Blynk.virtualWrite(V2, String(longitude, 6));
    myMap.location(move_index, latitude, longitude, "GPS_Location");
    sats = gps.satellites.value();    
    Blynk.virtualWrite(V3, sats);
  }
}
