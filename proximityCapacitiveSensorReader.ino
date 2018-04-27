#include "sensorReader.h"

int prox_sensors[3] = {A0, A1, A2};
int cap_sensors[3] = {A3, A4, A5};
Reader proxSensorReader;
Reader capSensorReader;
int k = 0;

void setup(){
  Serial.begin(9600);
  proxSensorReader.setProximitySensors(prox_sensors[0], prox_sensors[1], prox_sensors[2]);
  capSensorReader.setCapacitiveSensors(cap_sensors[0], cap_sensors[1], cap_sensors[2]);
}

void loop(){
  bool resultProxReading = proxSensorReader.readProxSensor(prox_sensors[k]);
  bool resultCapReading = capSensorReader.readCapSensor(cap_sensors[k]);
  Serial.print("\n");
  k += 1;
  if (k > 2){
    k = 0;
  }
  String proxPath = proxSensorReader.getProxPath();
  String capPath = capSensorReader.getCapPath();
  if ((proxPath == "a") && (capPath == "a")){
    Serial.print("aa");//this is the general output configuration of speakers on and off
    Serial.print(" ");
    Serial.print(proxSensorReader.readProxSensor(prox_sensors[k]));//this is the value used to alter the volume
  }else if ((proxPath == "a") && (capPath == "b")){
    Serial.print("ab");
    Serial.print(" ");
    Serial.print(proxSensorReader.readProxSensor(prox_sensors[k]));
  }else if ((proxPath == "a") && (capPath == "c")){
    Serial.print("ac");
    Serial.print(" ");
    Serial.print(proxSensorReader.readProxSensor(prox_sensors[k]));
  }else if ((proxPath == "a") && (capPath == "d")){
    Serial.print("ad");
    Serial.print(" ");
    Serial.print(proxSensorReader.readProxSensor(prox_sensors[k]));
  }else if ((proxPath == "a") && (capPath == "e")){
    Serial.print("ae");
    Serial.print(" ");
    Serial.print(proxSensorReader.readProxSensor(prox_sensors[k]));
  }else if ((proxPath == "a") && (capPath == "f")){
    Serial.print("af");
    Serial.print(" ");
    Serial.print(proxSensorReader.readProxSensor(prox_sensors[k]));
  }else if((proxPath =="b") && (capPath == "a")){
    Serial.print("ba");
    Serial.print(" ");
    Serial.print(proxSensorReader.readProxSensor(prox_sensors[k]));
  }else if ((proxPath == "b") && (capPath == "b")){
    Serial.print("bb");
    Serial.print(" ");
    Serial.print(proxSensorReader.readProxSensor(prox_sensors[k]));
  }else if ((proxPath == "b") && (capPath == "c")){
    Serial.print("bc");
    Serial.print(" ");
    Serial.print(proxSensorReader.readProxSensor(prox_sensors[k]));
  }else if ((proxPath == "b") && (capPath == "d")){
    Serial.print("bd");
    Serial.print(" ");
    Serial.print(proxSensorReader.readProxSensor(prox_sensors[k]));
  }else if ((proxPath == "b") && (capPath == "e")){
    Serial.print ("be");
    Serial.print(" ");
    Serial.print(proxSensorReader.readProxSensor(prox_sensors[k]));
  }else if ((proxPath == "b") && (capPath == "f")){
    Serial.print("bf");
    Serial.print(" ");
    Serial.print(proxSensorReader.readProxSensor(prox_sensors[k]));
  }else if ((proxPath == "c") && (capPath == "a")){
    Serial.print ("ca");
    Serial.print(" ");
    Serial.print(proxSensorReader.readProxSensor(prox_sensors[k]));
  }else if ((proxPath == "c") && (capPath == "b")){
    Serial.print("cb");
    Serial.print(" ");
    Serial.print(proxSensorReader.readProxSensor(prox_sensors[k]));
  }else if ((proxPath == "c") && (capPath == "c")){
    Serial.print("cc");
    Serial.print(" ");
    Serial.print(proxSensorReader.readProxSensor(prox_sensors[k]));
  }else if ((proxPath == "c") && (capPath == "d")){
    Serial.print("cd");
    Serial.print(" ");
    Serial.print(proxSensorReader.readProxSensor(prox_sensors[k]));
  }else if ((proxPath == "c") && (capPath == "e")){
    Serial.print ("ce");
    Serial.print(" ");
    Serial.print(proxSensorReader.readProxSensor(prox_sensors[k]));
  }else if ((proxPath == "c") && (capPath == "f")){
    Serial.print ("cf");
    Serial.print(" ");
    Serial.print(proxSensorReader.readProxSensor(prox_sensors[k]));
  }else if ((proxPath == "d") && (capPath == "a")){
    Serial.print ("da");
    Serial.print(" ");
    Serial.print(proxSensorReader.readProxSensor(prox_sensors[k]));
  }else if ((proxPath == "d") && (capPath == "b")){
    Serial.print ("db");
    Serial.print(" ");
    Serial.print(proxSensorReader.readProxSensor(prox_sensors[k]));
  }else if ((proxPath == "d") && (capPath == "c")){
    Serial.print ("dc");
    Serial.print(" ");
    Serial.print(proxSensorReader.readProxSensor(prox_sensors[k]));
  }else if ((proxPath == "d") && (capPath == "d")){
    Serial.print ("dd");
    Serial.print(" ");
    Serial.print(proxSensorReader.readProxSensor(prox_sensors[k]));
  }else if ((proxPath == "d") && (capPath == "e")){
    Serial.print ("de");
    Serial.print(" ");
    Serial.print(proxSensorReader.readProxSensor(prox_sensors[k]));
  }else if ((proxPath == "d") && (capPath == "f")){
    Serial.print ("df");
    Serial.print(" ");
    Serial.print(proxSensorReader.readProxSensor(prox_sensors[k]));
  }else if ((proxPath == "e") && (capPath == "a")){
    Serial.print ("ea");
    Serial.print(" ");
    Serial.print(proxSensorReader.readProxSensor(prox_sensors[k]));
  }else if ((proxPath == "e") && (capPath == "b")){
    Serial.print ("eb");
    Serial.print(" ");
    Serial.print(proxSensorReader.readProxSensor(prox_sensors[k]));
  }else if ((proxPath == "e") && (capPath == "c")){
    Serial.print ("ec");
    Serial.print(" ");
    Serial.print(proxSensorReader.readProxSensor(prox_sensors[k]));
  }else if ((proxPath == "e") && (capPath == "d")){
    Serial.print ("ed");
    Serial.print(" ");
    Serial.print(proxSensorReader.readProxSensor(prox_sensors[k]));
  }else if ((proxPath == "e") && (capPath == "e")){
    Serial.print ("ee");
    Serial.print(" ");
    Serial.print(proxSensorReader.readProxSensor(prox_sensors[k]));
  }else if ((proxPath == "e") && (capPath == "f")){
    Serial.print ("ef");
    Serial.print(" ");
    Serial.print(proxSensorReader.readProxSensor(prox_sensors[k]));
  }else if ((proxPath == "f") && (capPath == "a")){
    Serial.print("fa");
    Serial.print(" ");
    Serial.print(proxSensorReader.readProxSensor(prox_sensors[k]));
  }else if ((proxPath == "f") && (capPath == "b")){
    Serial.print("fb");
    Serial.print(" ");
    Serial.print(proxSensorReader.readProxSensor(prox_sensors[k]));
  }else if ((proxPath == "f") && (capPath == "c")){
    Serial.print ("fc");
    Serial.print(" ");
    Serial.print(proxSensorReader.readProxSensor(prox_sensors[k]));
  }else if ((proxPath == "f") && (capPath == "d")){
    Serial.print ("fd");
    Serial.print(" ");
    Serial.print(proxSensorReader.readProxSensor(prox_sensors[k]));
  }else if ((proxPath == "f") && (capPath == "e")){
    Serial.print ("fe");
    Serial.print(" ");
    Serial.print(proxSensorReader.readProxSensor(prox_sensors[k]));
  }else if ((proxPath == "f") && (capPath == "f")){
    Serial.print ("ff");
    Serial.print(" ");
    Serial.print(proxSensorReader.readProxSensor(prox_sensors[k]));
  }else{
    Serial.print("noinfo");
    Serial.print(" ");
    Serial.print(proxSensorReader.readProxSensor(prox_sensors[k]));
  }
}
