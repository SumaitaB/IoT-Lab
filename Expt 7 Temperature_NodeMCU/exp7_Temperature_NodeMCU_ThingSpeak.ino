#include <ESP826Wifi.h>
#include <WifiClient.h>
#include <ThingSpeak.h>

const char* ssid = ""; //Wifi name
const char* password = ""; //Wifi password
int val;
int pin = A0;

WifiClient client;
unsigned long myChannelNumber = ; //Channel ID
const char * myWriteAPIKey = ""; //write API

void setup()
{
    Serial.begin(9600);
    delay(10);
    Wifi.begin(ssid, password);
    ThingsSpeak.begin(client);
}

void loop()
{
    val = analogRead(pin)*0.322265;
    Serial.print("Temperature: ");
    Serial.print(val);
    Serial.println("*C");
    delay(1000);
    ThingsSpeak.writeField(myChannelNumber, 1, val, myWriteAPIKey);
    delay(100);
}
