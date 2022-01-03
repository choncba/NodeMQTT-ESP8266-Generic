///////////////////////////////////////////////////////////////////////////
//   PINS
///////////////////////////////////////////////////////////////////////////
#include "secrets.h"
#ifdef ARDUINO_ESP8266_ESP01
#define INPUT   0 // D3  // GPIO0   
#define OUTPUT  2 // D4  // GPIO1 
#else
#define INPUT   D3  // GPIO0
#define OUTPUT  D10  // LED en el ESP12, lógica invertida
#endif

///////////////////////////////////////////////////////////////////////////
//   WiFi
///////////////////////////////////////////////////////////////////////////
#define WIFI_SSID       WIFI_SECRET_SSID
#define WIFI_PASSWORD   WIFI_SECRET_PASSWORD
#define DHCP            // uncomment for use DHCP
#ifndef DHCP
IPAddress NODE_IP(192,168,0,55);
IPAddress NODE_GW(192,168,0,1);
IPAddress NODE_MASK(255,255,255,0);
#endif
///////////////////////////////////////////////////////////////////////////
//   MQTT
///////////////////////////////////////////////////////////////////////////
#define MQTT_CLIENT_ID    "TestNode"
#define MQTT_USERNAME     MQTT_SECRET_USERNAME
#define MQTT_PASSWORD     MQTT_SECRET_PASSWORD
// #define MQTT_SERVER       "iotdevar.duckdns.org"
#define MQTT_SERVER       "192.168.0.3"
#define MQTT_SERVER_PORT  1883

#define BASE_TOPIC "/" MQTT_CLIENT_ID
#define SET_TOPIC BASE_TOPIC "/set"
#define STATUS_OUTPUT_TOPIC BASE_TOPIC "/status_output"
#define STATUS_INPUT_TOPIC BASE_TOPIC "/status_input"
#define LWT_TOPIC BASE_TOPIC "/LWT"
#define MQTT_CONNECTED_STATUS "online"
#define MQTT_DISCONNECTED_STATUS "offline"

#ifdef ARDUINO_ESP8266_ESP01
#define ON   "1"
#define OFF  "0"
#else
#define ON   "0"    // EL Led del ESP12 tiene lógica invertida
#define OFF  "1"
#endif

#define TIMEOUT 5000

#define RETAIN true
#define QoS     0

///////////////////////////////////////////////////////////////////////////
//   DEBUG
///////////////////////////////////////////////////////////////////////////
#define DEBUG_TELNET
//#define DEBUG_SERIAL
