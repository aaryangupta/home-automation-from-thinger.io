#include <ThingerESP8266.h>

// Username, Device ID and Device credential all things are compulsory to the connect device to thinger io

#define USERNAME "Aaryangupta"

#define DEVICE_ID "homeautomation"

#define DEVICE_CREDENTIAL "123456789"

// Here replace your ssid and password to provide network for NodeMCU

#define SSID "Corona Virus"

#define SSID_PASSWORD "Welcometoiot"

ThingerESP8266 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

void setup() {

//Define Pin for Output

pinMode(D0, OUTPUT);

pinMode(D1, OUTPUT);

// Start Serial monitor

Serial.begin(9600);

thing.add_wifi(SSID, SSID_PASSWORD);

thing["led1"] << digitalPin(D0);

thing["led2"] << digitalPin(D1);

}

void loop() {

thing.handle();

}
