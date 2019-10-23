/*
 * HCSR04Ultrasonic/examples/UltrasonicDemo/UltrasonicDemo.pde
 */

#include <Ultrasonic.h>
#define TRIGGER_PIN  4
#define ECHO_PIN     2

Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

void setup()
  {
  Serial.begin(9600);
  }

void loop()
  {
  int cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = (int) ultrasonic.convert(microsec, Ultrasonic::CM);
  Serial.println(cmMsec);
  delay(500);
  }
