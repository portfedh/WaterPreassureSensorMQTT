# MQTT Water Pressure Sensor

With increasing water scarcity, it is often useful to know when tap/municipal water is unavailable.

With this sensor, if pressure is decreasing or non-existent, you may immediately cut down on water consumption and make your water tank last longer.

The sensor may also be used to monitor the pressure of other non-corrosive gases or liquids, such as a propane tank, an oil tank, or anything which falls within the sensor's working pressure range.

## What it does

The Arduino code uses a simple Steel Pressure Sensor (SKU237545), connected to the main waterline and a Wemos D1 to read and send the data.

The microcontroller will take measurements every 5 minutes and transform the Voltage values into its corresponding pressure measurement (Bars and PSI).

Measurements will be sent through WIFI to an MQTT broker. Although the code for the MQTT in not provided, here is a brief description of what can be achieved:

With an MQTT broker, Node-Red and Grafana, you can receive the values, store them in a database and then retrieve and display them in a graphical manner. Both Grafana and Node-Red can be integrated with Telegram. This allows message alarms to be sent in case water pressure falls below a threshold value. Alarms can also be sent once the water pressure is restored.

## How to Install

To use this script, you must have the following:

**Hardware:**

- Wemos D1
- Steel Pressure Sensor (SKU237545)
- An Electrical connection to power microcontroller
- A water line
- Some adapters (depending on how you want to set it up):

The adapters I used were:

- 1/4 female to 1/4 female
- 1/4 male to 1/4 male
- 1/4 female to 1/2 male

This way I could screw the fitting into a 1/2 inch copper male threaded copper tube (see picture below).

**Software:**

- ESP8266 Boards installed from the Boards Manager
- Arduino Library: [EspMQTTClient.h](https://www.arduino.cc/reference/en/libraries/espmqttclient/)

The sensor requires 5V input to work.  
The Wemos D1 Board was chosen because it can output 5V to power the sensor.  
The ESP8266 can also be used, but the sensor will have to be powered independently from the microcontroller.

**Connection Diagram:**

![Connection Diagram](https://bite-size.mx/WaterPressureDiagram.png)

**Wemos D1 (Wemos D1 Mini will work as well):**
![Wemos D1](https://bite-size.mx/WemosD1.jpg)

**How to Connect the sensor:**
![Connected Sensor](https://bite-size.mx/WaterPressureSensor.jpg)

## How to Use

1. Edit the config_blanc.h file

    - Add your Wi-Fi username & password
    - Define your MQTT port (1883 is conventionally used)
    - Add your MQTT broker Username & Password
    - Define a name to identify your sensor
    - Define the MQTT topic the sensor will publish the data into
        - At startup
        - When reporting PSI / BAR values
        - When it goes offline unexpectedly

2. Rename the file to config.h

3. Verify and upload your code

4. Check with the serial monitor that the values are being reported

5. Check with your MQTT broker that values are being reported correctly through WI-FI.

**Output should be something similar to the following:**

---(Serial Monitor GIF here)---

----(MQTT Broker GIF here)--

## Use cases

I designed this to monitor the water pressure in the municipal water line. The idea is to know if there is a water shortage immediately.

Other uses could be:  

- Monitor the air pressure of a compressed air tank (for a workshop or car mechanic)
- Monitor the level of a propane tank
- Monitor the oil level of a central heater
- Monitor the pressure in a vapor line

There are many home and industrial applications.  
The sensor is very cheap and very easy to set up.

## Contributing

The explanation of how to use this sensor could be broadened by:  

- Explaining how to configure the MQTT Broker
- Explaining how to configure Node-Red
- Explaining how to configure a database (I use Influx DB)
- Explaining how to set up Grafana to visualize the information
- Explaining how to set up alarms with Telegram

It could go even further by:

- Explaining how to set up the database and Grafana on AWS/Azure or a server you can access from anywhere.
- How to create an API so anyone can download the information.
