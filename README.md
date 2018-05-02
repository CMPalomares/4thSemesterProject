# 4thSemesterProject
The code reads from three proximity sensors and from three capacitive sensors, detects the patter of how have they been activated and generates an output that sends data to max msp

## The message sent
This application sends a message through the serial port, which has four different parts:
  - **Zone 1** -> The values for five proximity sensors.
  - **Zone 2** -> The time that each of the proximity sensors has been active.
    - If the sensor is inactive but it was inactive in the previous read it sends a 0.
    - If the sensor is active it sends a -1.
    - If the sensor is inactive but it was active in the previous read it sends the time the interaction took in milliseconds. 
  - **Zone 3** -> The pattern that is detected when reading the three capacitive sensors
  - **Zone 4** -> The time that the active zone, the capacitive sensors, has been active.
    - If there was no interaction and there is still no interaction it sends a 0.
    - If there is interaction it sends a -1.
    - If there is no interaction but in the previous there was, it sends the time the interaction took in milliseconds. 

`1 1 1 0 1 36 36 36 -1 36 f 0 0 0`
