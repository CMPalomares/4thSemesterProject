# 4thSemesterProject
The code reads from three proximity sensors and from three capacitive sensors, detects the patter of how have they been activated and generates an output that sends data to max msp

## The message sent
This application sends a message through the serial port, which has four different parts:
  - **Zone 1** -> The values for five proximity sensors, therefore sends five values.
  - **Zone 2** -> The time that each of the proximity sensors has been active, therefore sends five values.
    - If the sensor is inactive but it was inactive in the previous read it sends a 0.
    - If the sensor is active it sends a 1.
    - If the sensor is inactive but it was active in the previous read it sends the time the interaction took in milliseconds. 
  - **Zone 3** -> The pattern that is detected when reading the three capacitive sensors, sends a number between 1 and 6.
  - **Zone 4** -> The time that the active zone, the three capacitive sensors, has been active, therefore sends 1 value.
    - If there was no interaction and there is still no interaction it sends a 0.
    - If there is interaction it sends a 1.
    - If there is no interaction but in the previous there was, it sends the time the interaction took in milliseconds. 

`0 0 0 0 0 1 1 1 1 1 f 1`
