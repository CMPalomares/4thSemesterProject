#include "sensorReader.h"

int prox_sensors[5] = {A0, A1, A2, A3, A4};
Reader proxSensorReader;

int k = 0;

void setup(){
  Serial.begin(9600);
  proxSensorReader.setProximitySensors(prox_sensors[0],
                     prox_sensors[1],
                     prox_sensors[2],
                     prox_sensors[3],
                     prox_sensors[4]);

}

void loop(){
  int resultProxReading = proxSensorReader.readProxSensors();
  Serial.println(resultProxReading);

}
