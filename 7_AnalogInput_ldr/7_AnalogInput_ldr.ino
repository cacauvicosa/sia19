

int sensorPin0 = A0;  
int sensorPin1 = A1;  
int sensorValue = 1000;  // variable to store the value coming from the sensor

void setup() {
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin0);
  Serial.println(sensorValue);
  sensorValue = analogRead(sensorPin1);
   Serial.println(sensorValue);
  delay(1000);
}
