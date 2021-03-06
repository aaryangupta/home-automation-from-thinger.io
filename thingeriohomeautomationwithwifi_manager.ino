#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>         //https://github.com/tzapu/WiFiManager
#include <ThingerESP8266.h>

#define USERNAME "Aaryangupta"

#define DEVICE_ID "homeautomation"

#define DEVICE_CREDENTIAL "123456789"

#define SSID ""
#define SSID_PASSWORD ""

ThingerESP8266 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);
void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);

    //WiFiManager
    //Local intialization. Once its business is done, there is no need to keep it around
    WiFiManager wifiManager;
    //reset saved settings
    //wifiManager.resetSettings();
    
    //set custom ip for portal
    //wifiManager.setAPStaticIPConfig(IPAddress(10,0,1,1), IPAddress(10,0,1,1), IPAddress(255,255,255,0));

    //fetches ssid and pass from eeprom and tries to connect
    //if it does not connect it starts an access point with the specified name
    //here  "AutoConnectAP"
    //and goes into a blocking loop awaiting configuration
    wifiManager.autoConnect("AutoConnectAP","test");
    //or use this for auto generated name ESP + ChipID
    //wifiManager.autoConnect();

    
    //if you get here you have connected to the WiFi
    Serial.println("connected...yeey :)");
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  thing.add_wifi(SSID, SSID_PASSWORD);
  thing["led1"] << digitalPin(D0);
  thing["led2"] << digitalPin(D1);
}

void loop() {
    // put your main code here, to run repeatedly:
    thing.handle();
}
