// Created by: Pablo Cruz//
// Date: 12 March 2021 //

/* ----------Board Information-------------------------------
 Code desinged to run on Wemos in pin D0
     - 

 
 For runing in ESP8266 or ESP32 GPIO must be defined as input
    - pinMode(water_pressure_pin, INPUT);
    - 5V must be supplied to the sensor somehow
    - EspMQTTClient.h can be used (se terrarium project)
 */

/* ------------Sensor Specifications:-------------------------
Sensor Name: SKU237545 Pressure Sensor
Sensor Material: Carbon Steel Alloy
Min Working Preassure: 0 MPa
Max Working Preassure: 1.2 MPa (12 Bar) (174.04 PSI)
Min Working Temperature: 0 Deg Celsius
Max Working Temperature: 85 Deg Celsius
Meassuring Error: 1.5%
Working Voltage: 5V DC
Working Current: <= 10mA
Min Output Voltage: 0.5V  
Max Output Voltage: 4.5V */

/* -------------Possible Sensor Voltage Range:-----------------
Min Output Voltage: 0.5V  
Max Output Voltage: 4.5V */

/* -------------Possible Analog Sensor Output Range:-----------
Analog RangeAnalog Inputs can range from 0 - 1023
GPIO Input Voltage can range from 0 -5V
Translating Analog Reading to Voltage:
Minimun Analog Reading = 0.5 * (1024/5) = 102.4
Maximum Analog Reading = 4.5 * (1024/5) = 921.6 */


/* Inspired from:
George Kontaxis, April 14 2016
https://www.youtube.com/watch?v=AB7zgnfkEi4&list=PLwm6E6nKSCtWRQHRxp0DhX25KauXjOZ3B&index=44 

Ovens Garage, Apr 6, 2020
https://www.youtube.com/watch?v=UrqPxwsPWGk&t=660s

 Akram Lab, May 16, 2020
https://www.youtube.com/watch?v=CH-Q3IIWlm4

 Cambatronics Online, Apr 2, 2016
https://www.youtube.com/watch?v=WTa-A6_KFLw

Formula for converting ranges, March 25 2015
https://math.stackexchange.com/questions/1205733/how-to-convert-or-transform-from-one-range-to-another

*/
