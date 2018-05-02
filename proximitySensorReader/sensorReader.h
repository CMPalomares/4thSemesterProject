 #ifndef sensorReader_h
 #define sensorReader_h

 #include "Arduino.h"

 class Reader{
	 public:
	 	Reader();
	 	int readProxSensors();
	 	void readCapSensors ();
	 	char getCapPath();
	 	void setProximitySensors(int zone1, int zone2, int zone3, int zone4, int zone5);
	 	void setCapacitiveSensors(int cap1, int cap2, int cap3);
	 	void getTimeProxSensors(int* time_prox);
	 	void getProxValues(int* prox_values);
	 	void getTimeCapSensors(int* time_cap);


	 private:

	 	const int _CAP [3] = {1, 2, 3};
	 	const int _PROXACTIVE = 0;
	 	const int _PROXINACTIVE = 1;
	 	const int _CAPACTIVE = 0;
	 	const int _CAPINACTIVE = 1;
	 	int _zones [5];
	 	int _prox [5];
	 	int _prevProx[5];
   		int _proxTime[5];
   		int _currentProxTime[5];
   		int _cap[3];
   		int _capValues[3];
   		int _prevCapValues[3];
   		int _currentCapTime[3];
   		int _capTime[3];
	 	int _previousCapActivated;
	 	int _prePreviousCapActivated;
	 	int _currentCapActivated;
	 	char _capacitivePath;
	 	void _activatedCapacitiveSensorsSequence(int capSensor);
	 	int _capacitiveSquencePathCases();
	 	void _capacitiveSetPath();
	 	void _setProximityPins(int pin1, int pin2, int pin3, int pin4, int pin5);
	 	void _setCapacitivePins(int pin1, int pin2, int pin3);

 };
 #endif
