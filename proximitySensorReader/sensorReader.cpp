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

void Reader::getCapValues(int* cap_values) {
	for (int i = 0; i < 3; ++i)
	{
		cap_values[i] = _capValues[i];
	}
}

//Capacitive sensor reader
void Reader::readCapSensors() {
	
	for (int i = 0; i < 3; i++) {
		_prevCapValues[i] = _capValues[i];
		//_capValues[i] = digitalRead(_cap[i]);
		_capValues[i] = _cap[i].capacitiveSensor(30);
     if (_capValues[i] < 500){
        _capValues[i] = _CAPINACTIVE;
     }else{
        _capValues[i] = _CAPACTIVE;
     }
	}

	_allCapInactive();

	for (int i = 0; i < 3; ++i) {
		_activatedCapacitiveSensorsSequence(i + 1);
	}
 
	_capacitiveSetPath();
  _setCapInteractionTime();
	
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
int Reader::getCapPath(){

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
	_setCapacitivePins(cap1, cap2, cap3);
}

//Saves the sequence of three capacitive sensors as, preprevious sensor detected, previous sensor detected and current sensor detected
void Reader::_activatedCapacitiveSensorsSequence(int capSensor){
	if(capSensor != _previousCapActivated){

		_prePreviousCapActivated = _previousCapActivated;
		_previousCapActivated = capSensor;

		for (int i = 0; i < 3; i++) {
			if (capSensor == _CAP[i]) {
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
 
  if (pathNumber == 123 || pathNumber == 132 || pathNumber == 213 || pathNumber == 231){
    _capacitivePath = 1;
  } else if (pathNumber == 211 || pathNumber == 113 || pathNumber == 131 || pathNumber == 311) {
    _capacitivePath = 2;
  } else if (pathNumber == 221 || pathNumber == 121 || pathNumber == 122 || pathNumber == 223) {
    _capacitivePath = 3;
  } else if (pathNumber == 231 || pathNumber == 322 || pathNumber == 323 || pathNumber == 331) {
    _capacitivePath = 4;
  } else if (pathNumber == 133 || pathNumber == 111 || pathNumber == 222 || pathNumber == 333) {
    _capacitivePath = 5;
  } else {
    _capacitivePath = 6; 
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
  /*pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);*/
 
	_cap[0] = CapacitiveSensor(2,pin1);
	_cap[1] = CapacitiveSensor(2,pin2);
	_cap[2] = CapacitiveSensor(2,pin3);
}
