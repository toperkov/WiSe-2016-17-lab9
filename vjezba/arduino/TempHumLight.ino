#include <avr/pgmspace.h>
#include <LowPower.h>
#include "Sensors.h"

typedef enum {
  READ_SERIAL,
  GOTO_SLEEP,
  READ_SENSORS,
  NUM_STATES
} StateType;

SENSORS sensor;

void setup() {
  Serial.begin(115200);
  sensor.DHT_init();
  sensor.BH1750_init();
  delay(100); // give some time to send data over Serial before going to sleep
}

void loop() {
  StateType state = READ_SERIAL;
  for(;;) {
    switch(state) {
      case READ_SERIAL:
        state = GOTO_SLEEP;
        break;
      case GOTO_SLEEP:
        LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
        delay(100); // give him some time to wake up from sleep :D
        state = READ_SENSORS;
        break;
      case READ_SENSORS:
        sensor.readTempHum();
        sensor.readLight();
        delay(100); // give some time to send data over Serial
        state = READ_SERIAL;
        break;
    }
  }
}
