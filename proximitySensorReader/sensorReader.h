 #ifndef sensorReader_h
 #define sensorReader_h

 #include "Arduino.h"

 class Reader{
	 public:
	 	Reader();
	 	int readProxSensors();
<<<<<<< HEAD
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
=======
	 	int readCapSensors ();
	 	String getCapPath();
	 	void setProximitySensors(int zone1, int zone2, int zone3, int zone4, int zone5);
	 	void setCapacitiveSensors(int cap1, int cap2, int cap3);


	 private:
	 	const int _ZONE1 = 1;
	 	const int _ZONE2 = 2;
	 	const int _ZONE3 = 3;
	 	const int _ZONE4 = 4;
	 	const int _ZONE5 = 5;
	 	const int _CAP1 = 1;
	 	const int _CAP2 = 2;
	 	const int _CAP3 = 3;
	 	int _zones [5];
	 	int _prox [5];
   		int _currTime[5];
   		int _cap[3];
   		int _capPath[3];
	 	int _cap1;
	 	int _cap2;
	 	int _cap3;
	 	int _previousCapActivated;
	 	int _currentCapActivated;
	 	int _prePreviousCapActivated;
	 	int _previousCapSensor;
	 	int _currentTime;
	 	int _previousTime;
	 	String _capacitivePath;
	 	void _activatedCapacitiveSensorsSequence(int capSensor);
	 	int _capacitiveSquencePathCases();
	 	void _capacitiveSetPath();
	 	int _proximityBinarySequence();
	 	int _proximityBinaryToDecimal();
>>>>>>> d584ee16bc9e2fb939d96c3fc5fcfcbce74f5214
	 	void _setProximityPins(int pin1, int pin2, int pin3, int pin4, int pin5);
	 	void _setCapacitivePins(int pin1, int pin2, int pin3);

 };
<<<<<<< HEAD
 #endif
=======
 #endif
>>>>>>> d584ee16bc9e2fb939d96c3fc5fcfcbce74f5214
