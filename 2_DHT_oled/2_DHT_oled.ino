/*
 * Adaptado de
 * Sergei Bellagamba January 2018
 * 
 */
 
#include <Arduino.h>
#include "U8glib.h"
#include "DHT.h"

DHT dht(2, DHT11);

U8GLIB_SSD1306_128X64 tela(U8G_I2C_OPT_NO_ACK); 

void draw(void) {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  tela.setFont(u8g_font_9x15);
  tela.setPrintPos(0, 11);
  tela.print("Umidade"); 
  tela.setPrintPos(20, 25);
  tela.print(h); tela.print(" %");
  tela.setPrintPos(0, 38);
  tela.print("Temperatura"); 
  tela.setPrintPos(20, 53);
  tela.print(t); tela.print(" C");
  
}

void setup(void) {
  
  dht.begin();

  tela.begin();  
}

void loop(void) {

    // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();
  
  tela.firstPage();
  do {
    draw();
  } while( tela.nextPage() );
  

}
