#include "sensorReader.h"

int prox_sensors[5] = {4, 5, 6, 7, 8};
int cap_sensors[3] = {1, 2, 3};
Reader proxSensorReader;
Reader capSensorReader;


void setup(){
  Serial.begin(9600);
  proxSensorReader.setProximitySensors(prox_sensors[0],
                     prox_sensors[1],
                     prox_sensors[2],
                     prox_sensors[3],
                     prox_sensors[4]);
  capSensorReader.setCapacitiveSensors(cap_sensors[0], 
  					 cap_sensors[1], 
  					 cap_sensors[2]);
}

void loop(){
  int resultProxReading = proxSensorReader.readProxSensors();
  int resultCapReading = capSensorReader.readCapSensors();
  Serial.println(resultProxReading);
  Serial.println(resultCapReading);

}
