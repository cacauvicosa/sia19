#include <OneWire.h>

OneWire  ds(D2);  // on pin 10 (a 4.7K resistor is necessary)


#include "UbidotsMicroESP8266.h"

#define TOKEN  "A1E-JNeU4UUGSsaFyzGd3JwyevtQdDyNKQDbKHISd8lUqYZGQq5no8H63tdp"  // Put here your Ubidots TOKEN
#define WIFISSID "3gCacau" // Put here your Wi-Fi SSID
#define PASSWORD "arduino351" // Put here your Wi-Fi password

Ubidots client(TOKEN);



int sensor;
void setup(void) {
  Serial.begin(9600);
  sensor = 0;
  client.wifiConnection(WIFISSID, PASSWORD);
}

float readTemp()
{
  byte i;
  byte present = 0;
  byte type_s;
  byte data[12];
  byte addr[8];
  float celsius;
  
  if ( !ds.search(addr)) {
    ds.reset_search();
    delay(250);
    sensor = 0;
    return -1;
  }
  ds.reset();
  ds.select(addr);
  ds.write(0x44, 1);        // start conversion, with parasite power on at the end
  
  delay(1000);     // maybe 750ms is enough, maybe not
  // we might do a ds.depower() here, but the reset will take care of it.
  
  present = ds.reset();
  ds.select(addr);    
  ds.write(0xBE);         // Read Scratchpad
  for ( i = 0; i < 9; i++) {           // we need 9 bytes
    data[i] = ds.read();
  }

  // Convert the data to actual temperature
  int16_t raw = (data[1] << 8) | data[0];
  if (type_s) {
    raw = raw << 3; // 9 bit resolution default
    if (data[7] == 0x10) {
      // "count remain" gives full 12 bit resolution
      raw = (raw & 0xFFF0) + 12 - data[6];
    }
  } else {
    byte cfg = (data[4] & 0x60);
    // at lower res, the low bits are undefined, so let's zero them
    if (cfg == 0x00) raw = raw & ~7;  // 9 bit resolution, 93.75 ms
    else if (cfg == 0x20) raw = raw & ~3; // 10 bit res, 187.5 ms
    else if (cfg == 0x40) raw = raw & ~1; // 11 bit res, 375 ms
    //// default is 12 bit resolution, 750 ms conversion time
  }
  celsius = (float)raw / 16.0;
  sensor++;
  return celsius;
}


void loop(void) {
  
  float t;

  t = readTemp();
  if ( t > 0 ) {
    Serial.print(sensor);
    Serial.print("  Temperature = ");
    Serial.println(t);
    if ( sensor == 1) 
      client.add("temp1",t);
    else 
      client.add("temp2",t);
    client.sendAll(true);
    delay(3000);
  }
 
  
}
