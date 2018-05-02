#include "Arduino.h"
<<<<<<< HEAD
#include "sensorReader.h"

	
	Reader::Reader(){
		_currentCapActivated = 0;
		_previousCapActivated = 0;
		_prePreviousCapActivated = 0;
	}

//Proximity sensor reader 
int Reader::readProxSensors() {

	for (int i = 0; i < 5; i++) {
		_prevProx[i] = _prox[i];
		_prox[i] = digitalRead(_zones[i]);

		if (_prox[i] == _PROXACTIVE && _prevProx[i] == _PROXINACTIVE) {
			_currentProxTime[i] = millis();	
			_proxTime[i] = -1;
		} else if (_prox[i] == _PROXINACTIVE && _prevProx[i] == _PROXACTIVE) {
			_proxTime[i] = millis() - _currentProxTime[i];
		} else if (_prox[i] == _PROXACTIVE && _prevProx[i] == _PROXACTIVE) {
			_proxTime[i] = -1;
		} else {
			_proxTime[i] = 0;
		}
	}
}

void Reader::getTimeProxSensors(int* time_prox) {
	
	for (int i = 0; i < 5; i++) {
		time_prox[i] = _proxTime[i];
	}
}

void Reader::getProxValues(int* prox_values) {
	
	for (int i = 0; i < 5; i++) {
		prox_values[i] = _prox[i];
	}
}

//Capacitive sensor reader
void Reader::readCapSensors() {
	
	for (int i = 0; i < 3; i++) {
		_prevCapValues[i] = _capValues[i];
		_capValues[i] += digitalRead(_cap[i]);

		if (_capValues[i] == _CAPACTIVE && _prevCapValues[i] == _CAPINACTIVE) {
			_currentCapTime[i] = millis();
			_capTime[i] = -1;
		} else if (_capValues[i] == _CAPINACTIVE && _prevCapValues[i] == _CAPACTIVE) {
			_capTime[i] = millis() - _currentCapTime[i];
		} else if (_capValues[i] == _CAPACTIVE && _prevCapValues[i] == _CAPACTIVE) {
			_capTime[i] = -1;
		} else {
			_capTime[i] = 0;
		}

		_activatedCapacitiveSensorsSequence(_cap[i]);
		_capacitiveSetPath();
	}
}

//Saves the capacitive path detected
char Reader::getCapPath(){

	return _capacitivePath;
}

void Reader::getTimeCapSensors(int* time_cap) {
	
	for (int i = 0; i < 3; i++) {
		time_cap[i] = _capTime[i];
	}
} 

// //Sets the proximity sensors
 void Reader::setProximitySensors(int zone1, int zone2, int zone3, int zone4, int zone5){

 	_zones[0] = zone1;
 	_zones[1] = zone2;
 	_zones[2] = zone3;
  	_zones[3] = zone4;
 	_zones[4] = zone5;

 	_setProximityPins(zone1, zone2, zone3, zone4, zone5);
=======
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
  int prevTime[5];
	for (int i= 0; i < 4; i++){
		_prox[i] = digitalRead(_zones[i]);
		if (_prox[i] = 1){
		  prevTime[i] = millis();
			this->_currTime[i] = millis() - prevTime[i];
		}else{
			prevTime[i] = 0;
			this-> _currTime[i] = millis() - prevTime[i];
		}
    Serial.print (_prox[i]);
    Serial.print (" , ");
    Serial.print (_currTime[i]);
    Serial.print (" , ");
	}


	//this->_proximityBinarySequence();
	//return this->_proximityBinaryToDecimal();
}

//Capacitive sensor reader
int Reader::readCapSensors(){
	for (int i = 0; i < 2; i++){
		_cap[i] += digitalRead (_capPath[i]);

		Serial.print (_cap[i]);
		Serial.print (" , ");

		if (_cap[i] > 0){
			this->_currentTime = abs(millis() - this->_previousTime);
			this->_previousTime = this->_currentTime;
			Serial.print (this->_currentTime);
			this->_activatedCapacitiveSensorsSequence(_cap[i]);
			this->_capacitiveSetPath();
		}else{
			this->_currentTime = this->_previousTime ;
		}
	}

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
>>>>>>> d584ee16bc9e2fb939d96c3fc5fcfcbce74f5214
 }

//Sets the capacitive sensors
void Reader::setCapacitiveSensors(int cap1, int cap2, int cap3){
<<<<<<< HEAD
	_cap[0] = cap1;
	_cap[1] = cap2;
	_cap[2] = cap3;
	_setCapacitivePins(cap1, cap2, cap3);
=======
	this->_cap1 = cap1;
	this->_cap2 = cap2;
	this->_cap3 = cap3;
	this->_setCapacitivePins(cap1, cap2, cap3);
>>>>>>> d584ee16bc9e2fb939d96c3fc5fcfcbce74f5214
}

//Saves the sequence of three capacitive sensors as, preprevious sensor detected, previous sensor detected and current sensor detected
void Reader::_activatedCapacitiveSensorsSequence(int capSensor){
<<<<<<< HEAD
	if(capSensor != _previousCapActivated){

		_prePreviousCapActivated = _previousCapActivated;
		_previousCapActivated = capSensor;

		for (int i = 0; i < 3; i++) {
			if (capSensor == _cap[i]) {
				_currentCapActivated = _CAP[i];
			}
=======
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
>>>>>>> d584ee16bc9e2fb939d96c3fc5fcfcbce74f5214
		}	
	}
}

//Generates the capacitive sequence properly for its later use so we can have the configuration
int Reader::_capacitiveSquencePathCases(){
<<<<<<< HEAD
	return(_prePreviousCapActivated * 100 + _previousCapActivated * 10 + _currentCapActivated);
}

//Depending on the capacitive path generated it gives a precise output
void Reader::_capacitiveSetPath() {
	int pathNumber = _capacitiveSquencePathCases();

	switch (pathNumber) {
		case 123: 
			_capacitivePath = 'a';
		case 132:
			_capacitivePath = 'b';
		case 213:
			_capacitivePath = 'c';
		case 231:
			_capacitivePath = 'd';
		case 312:
			_capacitivePath = 'e';
		default:	
			_capacitivePath = 'f';
	}
}

//Sets the proximity pins enabling the pullups
void Reader::_setProximityPins(int pin1, int pin2, int pin3, int pin4, int pin5){
	pinMode(pin1, INPUT);
	pinMode(pin2, INPUT);
	pinMode(pin3, INPUT);
	pinMode(pin4, INPUT);
	pinMode(pin5, INPUT);
=======
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
>>>>>>> d584ee16bc9e2fb939d96c3fc5fcfcbce74f5214

}

//Sets the proximity pins enabling the pullups
void Reader::_setCapacitivePins(int pin1, int pin2, int pin3){
<<<<<<< HEAD
	pinMode(pin1, INPUT);
	pinMode(pin2, INPUT);
	pinMode(pin3, INPUT);
}
=======
	pinMode(pin1, INPUT_PULLUP);
	pinMode(pin2, INPUT_PULLUP);
	pinMode(pin3, INPUT_PULLUP);
}
>>>>>>> d584ee16bc9e2fb939d96c3fc5fcfcbce74f5214
