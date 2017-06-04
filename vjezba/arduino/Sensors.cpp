#include "Sensors.h"

DHT dht(DHTPIN, DHTTYPE);
BH1750 lightMeter(0x23);

SENSORS::SENSORS(){}
SENSORS::~SENSORS(){}

void SENSORS::DHT_init(){
  pinMode(DHTPIN_VCC,OUTPUT);
  digitalWrite(DHTPIN_VCC,LOW);
  Serial.println(F("DHTxx test!"));
  dht.begin();
}

void SENSORS::BH1750_init(){
  lightMeter.begin(BH1750_CONTINUOUS_HIGH_RES_MODE);
  Serial.println(F("BH1750 Test"));
}

void SENSORS::readTempHum() {
  digitalWrite(DHTPIN_VCC, HIGH);

  // Wait at least 2 seconds seconds between measurements.
  unsigned long previousMillis = millis();
  unsigned long currentMillis = millis();
  while (currentMillis - previousMillis <= 2300) {
    // save the last time you read the sensor
    currentMillis = millis();
  }

  Serial.print(F("Humidity: "));
  Serial.println(dht.readHumidity());
  //Serial.println(F(" %\t"));
  Serial.print(F("Temperature: "));
  Serial.println(dht.readTemperature());
  //Serial.println(F(" *C "));

  digitalWrite(DHTPIN_VCC,LOW);
}

void SENSORS::readLight() {
  Serial.print(F("Light: "));
  Serial.println(lightMeter.readLightLevel());
  //Serial.println(F(" lx"));
}
