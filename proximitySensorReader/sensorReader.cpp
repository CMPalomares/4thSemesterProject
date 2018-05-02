	#include "Arduino.h"
	#include "sensorReader.h"

	
	Reader::Reader(){
		this->_cap1 = 0;
		this->_cap2 = 0;
		this->_cap3 = 0;
		this->_currentCapActivated = 0;
		this->_previousCapActivated = 0;
		this->_prePreviousCapActivated = 0;
		this->_previousCapSensor = 0;
		this->_capacitivePath = "noinfo";
		this->_currentTime = 0;
		this->_previousTime = 0;
		
	}

//Proximity sensor reader 
int Reader::readProxSensors (){

	for (int i= 0; i < 4; i++){
		_prox[i] = analogRead(_zones[i]);
		Serial.print (_prox[i]);
		Serial.print (" , ");
		if (prox[i] = 1){
			int prevTime[i] = millis();
			this->_currTime[i] = millis() - prevTime[i];
		}else{
			int prevTime[i] = 0;
			int _currTime[i] = millis() - prevTime[i];
		}
	}
	Serial.print (_prox[i]);
	Serial.print (" , ");
	Serial.print (_curTime[i]);
	Serial.print (" , ");

	//this->_proximityBinarySequence();
	//return this->_proximityBinaryToDecimal();
}

//Capacitive sensor reader
bool Reader::readCapSensor(int capSensor){
	int val = 0;
	for (int i = 0; i < 2; i++){
		val += analogRead (capSensor);
	}

	Serial.print (val);
	Serial.print (" , ");

	bool stateBool = false;
	this->_capacitivePath = "noinfo";
	if (val > 0){
		this->_currentTime = abs(millis()) - this->_previousTime;
		this->_previousTime = this->_currentTime;
		Serial.print (this->_currentTime);
		this->_activatedCapacitiveSensorsSequence(capSensor);
		this->_capacitiveSetPath();
		stateBool = true;
	}else{
		this->_currentTime = this->_previousTime ;
	}
	return stateBool;

}

//Saves the capacitive path detected
String Reader::getCapPath(){

	return this->_capacitivePath;
}

// //Sets the proximity sensors
 void Reader::setProximitySensors(int zone1, int zone2, int zone3, int zone4, int zone5){

 	this->_zones[0] = zone1;
 	this->_zones[1] = zone2;
 	this->_zones[2] = zone3;
  	this->_zones[3] = zone4;
 	this->_zones[4] = zone5;

 	this->_setProximityPins(zone1, zone2, zone3, zone4, zone5);
 }

//Sets the capacitive sensors
void Reader::setCapacitiveSensors(int cap1, int cap2, int cap3){
	this->_cap1 = cap1;
	this->_cap2 = cap2;
	this->_cap3 = cap3;
	this->_setCapacitivePins(cap1, cap2, cap3);
}

//Saves the sequence of three capacitive sensors as, preprevious sensor detected, previous sensor detected and current sensor detected
void Reader::_activatedCapacitiveSensorsSequence(int capSensor){
	if(capSensor != this->_previousCapSensor){
		this->_previousCapSensor = capSensor;
		this->_prePreviousCapActivated = this->_previousCapActivated;
		this->_previousCapActivated = this->_currentCapActivated;
		if (capSensor == this->_cap1){
			this->_currentCapActivated = _CAP1;
		}else if (capSensor == this->_cap2){
			this->_currentCapActivated = _CAP2;
		}else if (capSensor == this->_cap3){
			this->_currentCapActivated =_CAP3;
		}	
	}
}

//Generates the capacitive sequence properly for its later use so we can have the configuration
int Reader::_capacitiveSquencePathCases(){
	return(this->_currentCapActivated*100 + this->_previousCapActivated*10 + this->_prePreviousCapActivated);
}

//Depending on the capacitive path generated it gives a precise output
void Reader::_capacitiveSetPath(){
	int pathNumber = this->_capacitiveSquencePathCases();
	if(pathNumber == 123){
		this->_capacitivePath = "a";
	}else if (pathNumber == 213){
		this->_capacitivePath = "b";
	}else if (pathNumber == 231){
		this->_capacitivePath = "c";
	}else if (pathNumber == 321){
		this->_capacitivePath = "d";
	}else if (pathNumber == 312){
		this->_capacitivePath = "e";
	}else if (pathNumber == 132){
		this->_capacitivePath = "f";
	}else{
		this->_capacitivePath = "noinfo";
	}
}
/*int Reader::_proximityBinarySequence(){
	int result;

	for (int i = 0; i < 5; ++i) {
		result += this->_prox[i] * 10^(4 - i);
	} 

	return result;
}*/

/*int Reader::_proximityBinaryToDecimal(){
	int result;
	int aux [5];

	for (int i = 0; i < 5; ++i) {
		aux[i] = _prox[i];
	}

	const int auxCount = sizeof aux / sizeof aux[0];

	for (int i=0; i < auxCount; i++) {
		int n = random(0, auxCount);  // Integer from 0 to questionCount-1
		int temp = aux[n];
		aux[n] =  aux[i];
		aux[i] = temp;
	}

	for (int i = 0; i < 4; i++) {
		result += aux[i] * 2^(4 - i);
	}

	return result;
}*/

//Sets the proximity pins enabling the pullups
void Reader::_setProximityPins(int pin1, int pin2, int pin3, int pin4, int pin5){
	pinMode(pin1, INPUT_PULLUP);
	pinMode(pin2, INPUT_PULLUP);
	pinMode(pin3, INPUT_PULLUP);
	pinMode(pin4, INPUT_PULLUP);
	pinMode(pin5, INPUT_PULLUP);

}

//Sets the proximity pins enabling the pullups
void Reader::_setCapacitivePins(int pin1, int pin2, int pin3){
	pinMode(pin1, INPUT_PULLUP);
	pinMode(pin2, INPUT_PULLUP);
	pinMode(pin3, INPUT_PULLUP);
}