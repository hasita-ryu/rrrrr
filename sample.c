#include <SchooMyUtilities.h>
SchooMyUtilities scmUtils = SchooMyUtilities();

#include <OneWire.h>
#include <DallasTemperature.h>
#define SENSOR_BIT 9

OneWire _tempWire_18(18);
DallasTemperature _tempSensors_18(&_tempWire_18);

float _sbeGetTemperature(DallasTemperature& sensors) {
  sensors.requestTemperatures();
  float temp = sensors.getTempCByIndex(0);
  if (temp == DEVICE_DISCONNECTED_C) return 0;
  return temp;
}

void setup() {
  Serial.begin(9600);
  _tempSensors_18.begin();
  _tempSensors_18.setResolution(SENSOR_BIT);
}

void loop() {
  Serial.println(_sbeGetTemperature(_tempSensors_18));
  delay(1000);
}
