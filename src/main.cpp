#include <Arduino.h>
#include <SdsDustSensor.h>
#include <DHT.h>

/* SDS011 Dust Sensor */
const int SDS_RX_PIN = 5; // D2 -> SDS011 RX pin
const int SDS_TX_PIN = 4; // D1 -> SDS011 TX pin
SoftwareSerial softwareSerial(SDS_RX_PIN, SDS_TX_PIN);
SdsDustSensor sds(softwareSerial);

/* DHT22 Temperature and Humidity Sensor */
#define DHT_TYPE DHT22
const int DHT_PIN = 13; // D7
DHT dht(DHT_PIN, DHT_TYPE);


void setup() {
  Serial.begin(9600);
  sds.begin();
  dht.begin();
}

void loop() {
  delay(1000);

  /* SDS Reading */
  PmResult pm = sds.queryPm();
  Serial.println(sds.setQueryReportingMode().toString());
  Serial.print("PM2.5 = ");
  Serial.print(pm.pm25); // float, μg/m3
  Serial.print(", PM10 = ");
  Serial.println(pm.pm10);

  /* DHT Reading */
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print("Luftfeuchte: "); 
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperatur: "); 
  Serial.print(t);
  Serial.println(" C");
 
}
