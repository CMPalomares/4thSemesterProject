#include "sensorReader.h"

int prox_sensors[5] = {4, 5, 6, 7, 8};
int cap_sensors[3] = {1, 2, 4};
int time_prox [5];
int time_cap [3];
int prox_values[5];

Reader sensorReader;


void setup() {
  Serial.begin(9600);
  sensorReader.setProximitySensors(prox_sensors[0],
                     prox_sensors[1],
                     prox_sensors[2],
                     prox_sensors[3],
                     prox_sensors[4]);
  sensorReader.setCapacitiveSensors(cap_sensors[0], 
  					 cap_sensors[1], 
  					 cap_sensors[2]);
}

void loop() {
	
	sensorReader.readProxSensors();
	sensorReader.readCapSensors();
	
	sensorReader.getProxValues(prox_values);
	sensorReader.getTimeProxSensors(time_prox);
	sensorReader.getTimeCapSensors(time_cap);
	char cap_path = sensorReader.getCapPath();

	sendMessage(prox_values[0], prox_values[1], prox_values[2], prox_values[3], prox_values[4],
							 time_prox[0], time_prox[1], time_prox[2], time_prox[3], time_prox[4], cap_path, 
							 time_cap[0], time_cap[1], time_cap[2]);
}

void sendMessage(int p1, int p2, int p3, int p4, int p5, 
				 int tp1, int tp2, int tp3, int tp4, int tp5,
				 char pattern, int tc1, int tc2, int tc3) {

	Serial.print(p1);
	Serial.print(" ");
	Serial.print(p2);
	Serial.print(" ");
	Serial.print(p3);
	Serial.print(" ");
	Serial.print(p4);
	Serial.print(" ");
	Serial.print(p5);
	Serial.print(" ");
	Serial.print(tp1);
	Serial.print(" ");
	Serial.print(tp2);
	Serial.print(" ");
	Serial.print(tp3);
	Serial.print(" ");
	Serial.print(tp4);
	Serial.print(" ");
	Serial.print(tp5);
	Serial.print(" ");
	Serial.print(pattern);
	Serial.print(" ");
	Serial.print(tc1);
	Serial.print(" ");
	Serial.print(tc2);
	Serial.print(" ");
	Serial.print(tc3);
	Serial.println();
}
