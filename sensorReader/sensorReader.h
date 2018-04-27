 #ifndef sensorReader_h
 #define sensorReader_h

 #include "Arduino.h"

 class Reader{
	 public:
	 	Reader();
	 	bool readProxSensor(int proxSensor);
	 	bool readCapSensor (int capSensor);
	 	String getProxPath();
	 	String getCapPath();
	 	void setProximitySensors(int zone1, int zone2, int zone3);
	 	void setCapacitiveSensors(int cap1, int cap2, int cap3);

	 private:
	 	const int _ZONE1 = 1;
	 	const int _ZONE2 = 2;
	 	const int _ZONE3 = 3;
	 	const int _CAP1 = 1;
	 	const int _CAP2 = 2;
	 	const int _CAP3 = 3;
	 	int _zone1;
	 	int _zone2;
	 	int _zone3;
	 	int _previousProxActivated;
	 	int _prePreviousProxActivated;
	 	int _currentProxActivated;
	 	int _previousProxSensor;
	 	int _cap1;
	 	int _cap2;
	 	int _cap3;
	 	int _previousCapActivated;
	 	int _currentCapActivated;
	 	int _prePreviousCapActivated;
	 	int _previousCapSensor;
	 	int _currentTime;
	 	int _previousTime;
	 	String _proximityPath;
	 	String _capacitivePath;
	 	void  _activatedProximitySensorsSequence(int proxSensor);
	 	void _activatedCapacitiveSensorsSequence(int capSensor);
	 	int _proximitySequencePathCases();
	 	int _capacitiveSquencePathCases();
	 	void _proximitySetPath();
	 	void _capacitiveSetPath();
	 	void _setProximityPins(int pin1, int pin2, int pin3);
	 	void _setCapacitivePins(int pin1, int pin2, int pin3);

 };
 #endif