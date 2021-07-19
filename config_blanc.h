// Rename this file config.h for the code to run

// Add the required information

/* ---------- Wifi Configuration-------------------------------------- */
#define SECRET_SSID  "<wifi_name>"
#define SECRET_PASS  "<wifi_password>"

/* ---------- MQTT Information---------------------------------------- */
#define BROKER_IP        "<internal_IP_address_of_MQTT_Broker>"
#define BROKER_PORT      <mqttt_port_here>
#define BROKER_USERNAME  "<broker_username>"
#define BROKER_PASSWORD  "<broker_password>"
#define CLIENT_NAME      "<mqtt_client_name_to_identify_your_device>"

String  client_name                = CLIENT_NAME;                   // MQTT Topic to report initial value
String  startup_topic              = "<mqtt_startup_topic>";        // MQTT Topic to report startup
String  water_pressure_psi_topic   = "<mqtt_pressure_psi_topic>";	// MQTT topic to report psi values
String  water_pressure_bar_topic   = "<mqtt_pressure_bar_topic>";   // MQTT topic to report bar values


#define lastwill_topic  "<mqtt_lastwill_topic>"                   // MQTT topic to report lastwill and testament.
#define lastwill_text   "Sensor has gone offline unexpextedly."   // MQTT message to report lastwill and testament.

/* ---------- Serial Information--------------------------------------- */
#define serial_baud_rate  115200             // Speed for USB Serial Console

/* ---------- Mills Function definitions------------------------------- */
const unsigned long event_interval = 300000; // 5 minutes,  300 second delay
unsigned long previous_time = 0; 
