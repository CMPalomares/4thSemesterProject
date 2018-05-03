#include "Arduino.h"
#include "sensorReader.h"

	
	Reader::Reader(){
		_currentCapActivated = 0;
		_previousCapActivated = 0;
		_prePreviousCapActivated = 0;
	   _capTime = 0;
	}

//Proximity sensor reader 
int Reader::readProxSensors() {

	for (int i = 0; i < 5; i++) {
		_prevProx[i] = _prox[i];
		_prox[i] = digitalRead(_zones[i]);

		if (_prox[i] == _PROXACTIVE && _prevProx[i] == _PROXINACTIVE) {
			_currentProxTime[i] = millis();	
			_proxTime[i] = 1;
		} else if (_prox[i] == _PROXINACTIVE && _prevProx[i] == _PROXACTIVE) {
			_proxTime[i] = millis() - _currentProxTime[i];
		} else if (_prox[i] == _PROXACTIVE && _prevProx[i] == _PROXACTIVE) {
			_proxTime[i] = 1;
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
	}

	_allCapInactive();
	_setCapInteractionTime();
	
	for (int i = 0; i < 3; ++i) {
		_activatedCapacitiveSensorsSequence(_cap[i]);
	}

	_capacitiveSetPath();
	
}

void Reader::_setCapInteractionTime() {
	if (_allCapsValuesInactive == true){
		_capTime = 0;
		if (_allPrevCapsValuesInactive == true){
			if (millis() - _startTimeInteracion > _NEWINTERACTIONTIME){
				_firstInteraction = true;
				if (_firstTime == true){
					_firstTime = false;
					_capTime = millis() - _startTimeInteracion;
				}
			}else{
				_capTime = 1;
			}
		}
	}else{
		_capTime = 1;
		if(_allPrevCapsValuesInactive == true){
			if (_firstInteraction == true){
				_startTimeInteracion = millis();
				_firstTime = true;
				_firstInteraction = false;
			}
		}
	}
}

void Reader::_allCapInactive() {
	_allPrevCapsValuesInactive = _allCapsValuesInactive;
	for (int i = 0; i < 3; ++i){		
		if (_capValues[i] == _CAPACTIVE){
			_allCapsValuesInactive = false;
			break;
		}else{
			_allCapsValuesInactive = true;
		}
	}	
}

//Saves the capacitive path detected
char Reader::getCapPath(){

	return _capacitivePath;
}

unsigned long Reader::getTimeCapSensors() {
	
	return _capTime;
	
} 

// //Sets the proximity sensors
 void Reader::setProximitySensors(int zone1, int zone2, int zone3, int zone4, int zone5){

 	_zones[0] = zone1;
 	_zones[1] = zone2;
 	_zones[2] = zone3;
  	_zones[3] = zone4;
 	_zones[4] = zone5;

 	_setProximityPins(zone1, zone2, zone3, zone4, zone5);
 }

//Sets the capacitive sensors
void Reader::setCapacitiveSensors(int cap1, int cap2, int cap3){
	_cap[0] = cap1;
	_cap[1] = cap2;
	_cap[2] = cap3;
	_setCapacitivePins(cap1, cap2, cap3);
}

//Saves the sequence of three capacitive sensors as, preprevious sensor detected, previous sensor detected and current sensor detected
void Reader::_activatedCapacitiveSensorsSequence(int capSensor){
	if(capSensor != _previousCapActivated){

		_prePreviousCapActivated = _previousCapActivated;
		_previousCapActivated = capSensor;

		for (int i = 0; i < 3; i++) {
			if (capSensor == _cap[i]) {
				_currentCapActivated = _CAP[i];
			}
		}	
	}
}

//Generates the capacitive sequence properly for its later use so we can have the configuration
int Reader::_capacitiveSquencePathCases(){
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

}

//Sets the proximity pins enabling the pullups
void Reader::_setCapacitivePins(int pin1, int pin2, int pin3){
	pinMode(pin1, INPUT);
	pinMode(pin2, INPUT);
	pinMode(pin3, INPUT);
}
