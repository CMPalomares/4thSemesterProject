	#include "Arduino.h"
	#include "sensorReader.h"
	
	Reader::Reader(){
		this->_zone1 = 0;
		this->_zone2 = 0;
		this->_zone3 = 0;
		this->_cap1 = 0;
		this->_cap2 = 0;
		this->_cap3 = 0;
		this->_currentProxActivated = 0;
		this->_currentCapActivated = 0;
		this->_previousProxActivated = 0;
		this->_previousCapActivated = 0;
		this->_prePreviousProxActivated = 0;
		this->_prePreviousCapActivated = 0;
		this->_previousProxSensor = 0;
		this->_previousCapSensor = 0;
		this->_proximityPath = "noinfo";
		this->_capacitivePath = "noinfo";
		this->_currentTime = 0;
		this->_previousTime = 0;
	}

//Proximity sensor reader 
bool Reader::readProxSensor (int proxSensor){
	int val = 0;
	for (int i= 0; i < 2; i++){
		val += analogRead (proxSensor);
	}
	
	Serial.print (val);
	Serial.print (" , ");

	bool stateBool = false;
	this->_proximityPath = "noinfo";
	if (val > 30){//random value that the proximity sensor would detect, we need to change this
		this-> _activatedProximitySensorsSequence(proxSensor);
		this-> _proximitySetPath();
		stateBool = true;
	}
	return stateBool;
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

//Saves the proximity path detected
String Reader::getProxPath(){
	return this->_proximityPath;
}

//Saves the capacitive path detected
String Reader::getCapPath(){

	return this->_capacitivePath;
}

//Sets the proximity sensors
void Reader::setProximitySensors(int zone1, int zone2, int zone3){
	this->_zone1 = zone1;
	this->_zone2 = zone2;
	this->_zone3 = zone3;
	this->_setProximityPins(zone1, zone2, zone3);
}

//Sets the capacitive sensors
void Reader::setCapacitiveSensors(int cap1, int cap2, int cap3){
	this->_cap1 = cap1;
	this->_cap2 = cap2;
	this->_cap3 = cap3;
	this->_setCapacitivePins(cap1, cap2, cap3);
}

//Saves the sequence of three proximity sensors as, preprevious sensor detected, previous sensor detected and current sensor detected
void Reader::_activatedProximitySensorsSequence(int proxSensor){
	if(proxSensor != this->_previousProxSensor){
		this->_previousProxSensor = proxSensor;
		this->_prePreviousProxActivated = this->_previousProxActivated;
		this->_previousProxActivated = this->_currentProxActivated;
		if (proxSensor == this->_zone1){
			this->_currentProxActivated = _ZONE1;
		}else if (proxSensor == this->_zone2){
			this->_currentProxActivated = _ZONE2;
		}else if (proxSensor == this->_zone3){
			this->_currentProxActivated =_ZONE3;
		}	
	}
}

//Saves the sequence of three capacitive sensors as, preprevious sensor detected, previous sensor detected and current sensor detected
void Reader::_activatedCapacitiveSensorsSequence(int capSensor){
	if(capSensor != this->_previousCapSensor){
		this->_previousCapSensor = capSensor;
		this->_prePreviousCapActivated = this->_previousCapActivated;
		this->_previousCapActivated = this->_currentCapActivated;
		if (capSensor == this->_zone1){
			this->_currentCapActivated = _ZONE1;
		}else if (capSensor == this->_zone2){
			this->_currentCapActivated = _ZONE2;
		}else if (capSensor == this->_zone3){
			this->_currentCapActivated =_ZONE3;
		}	
	}
}

//Generates the proximity sequence properly for its later use so we have the confguration 
int Reader::_proximitySequencePathCases(){
	return(this->_currentProxActivated*100 + this->_previousProxActivated*10 + this->_prePreviousProxActivated);
}

//Generates the capacitive sequence properly for its later use so we can have the configuration
int Reader::_capacitiveSquencePathCases(){
	return(this->_currentCapActivated*100 + this->_previousCapActivated*10 + this->_prePreviousCapActivated);
}

//Depending on the proximity path generated it gives a precise output
void Reader::_proximitySetPath(){
	int pathNumber = this->_proximitySequencePathCases();
	if(pathNumber == 123){
		this->_proximityPath = "a";
	}else if (pathNumber == 213){
		this->_proximityPath = "b";
	}else if (pathNumber == 231){
		this->_proximityPath = "c";
	}else if (pathNumber == 321){
		this->_proximityPath = "d";
	}else if (pathNumber == 312){
		this->_proximityPath = "e";
	}else if (pathNumber == 132){
		this->_proximityPath = "f";
	}else{
		this->_proximityPath = "noinfo";
	}
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

//Sets the proximity pins enabling the pullups
void Reader::_setProximityPins(int pin1, int pin2, int pin3){
	pinMode(pin1, INPUT_PULLUP);
	pinMode(pin2, INPUT_PULLUP);
	pinMode(pin3, INPUT_PULLUP);
}

//Sets the proximity pins enabling the pullups
void Reader::_setCapacitivePins(int pin1, int pin2, int pin3){
	pinMode(pin1, INPUT_PULLUP);
	pinMode(pin2, INPUT_PULLUP);
	pinMode(pin3, INPUT_PULLUP);
}