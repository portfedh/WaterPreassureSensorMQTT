//--------------Water Preassure Sensor--------------------------------
/* Sketch reads values from a preassure sensor connected to the main waterline.
*  It then sends the values through MQTT to a broker 
*  Read the Readme file first */

//-----------Configuration--------------------------------------------

#include "config.h"  // Changes in congiguration should be done here.

//-----------Libraries------------------------------------------------

#include "EspMQTTClient.h" // Enables connecting to MQTT 

//-----------Variable Declarations-------------------------------------

//Possible Analog to Digital Converter values:
const float min_analog_real = 10.0;           // Calibration Value
const float min_analog_theoretical = 102.4;
const float min_analog = min_analog_real; 
const float max_analog = 921.6; 

//Output voltage range produced by the Sensor:
const float min_volts = 0.5; 
const float max_volts = 4.5; 

//Bar preassure range supported by the sensor:
const float min_bars = 0.0; 
const float max_bars = 12.0; 

//PSI preassure range supported by the sensor:
const float min_psi = 0.0; 
const float max_psi = 174.04; 

// Analog to voltage, bars and PSI functions can be substituted by mapped funcion:
// int mappedValue = map(raw_value, 10.0 , 921.6, 0, 1023)

// Function to connect to MQTT 
EspMQTTClient client(
                  SECRET_SSID,
                  SECRET_PASS,
                  BROKER_IP,        // MQTT Broker server IP
                  BROKER_USERNAME,  // Can be omitted if not needed
                  BROKER_PASSWORD,  // Can be omitted if not needed
                  CLIENT_NAME,      // Client name that uniquely identify your device
                  BROKER_PORT       // The MQTT port, default to 1883. this line can be omitted
);

//-----------Setup--------------------------------------------
void setup() 
{    
    // Sets resolution to 10 bits (values 0-1023). 
    //analogReadResolution(10);    // Blocked in Wemos D1 R1 version. Use with Esp8266 or ESP32

    // Defines pin 35 as an Input // // Blocked in Wemos D1 R1 version. Use with Esp8266 or ESP32
    //pinMode(35, INPUT); // Esp32 version

    // Sets the Baud Rate
    Serial.begin(serial_baud_rate);

    // MQTT Initial Connection
    client.enableDebuggingMessages(); // Enable debugging messages sent to serial output
    client.enableHTTPWebUpdater();    // Enable the web updater. 
    
    // MQTT Last Will & Testament
    client.enableLastWillMessage( lastwill_topic , lastwill_text);  // You can activate the retain flag by setting the third parameter to true
}

//MQTT Innitial Connection
void onConnectionEstablished()
{
  client.publish(startup_topic, String(client_name + " is now online."));
  }

//-----------Loop--------------------------------------------
void loop(){

// MQTT Loop: Must be called once per loop.
client.loop(); 

// Getts current Time
unsigned long current_time = millis();

// Millis If Statment
if(current_time - previous_time >= event_interval) {

    // Gets the analog sensor value 0-1023
    int sensor_value = analogRead(A0);  // Wemos version
    //int sensor_value = analogRead(35);  // Esp32 version

    // Print Sensor value
    Serial.print("Sensor Value: ");
    Serial.print(sensor_value);
    Serial.print('\n');

    // Converts Analog value to Voltage //
    float voltage = (((sensor_value-min_analog)*(max_volts-min_volts))/(max_analog-min_analog))+min_volts;
        Serial.print("Volts: ");
        Serial.print(voltage);
        Serial.print('\n');

    // Converts Analog value to Bars //
    float preassure_bar = (((sensor_value-min_analog)*(max_bars-min_bars))/(max_analog-min_analog))+min_bars;
        Serial.print("Bars: ");
        Serial.print(preassure_bar);
        Serial.print('\n');

    // Converts Analog value to PSI //
    float preassure_psi = (((sensor_value-min_analog)*(max_psi-min_psi))/(max_analog-min_analog))+min_psi;
        Serial.print("PSI: ");
        Serial.print(preassure_psi);
        Serial.print('\n');
        Serial.print('\n');

    // MQTT Client Publisher
    client.publish(water_pressure_psi_topic, String(preassure_psi));
    client.publish(water_pressure_bar_topic, String(preassure_bar));
    Serial.print('\n');
        
    // Update timing for next Mills Loop
    previous_time = current_time;
}
}
