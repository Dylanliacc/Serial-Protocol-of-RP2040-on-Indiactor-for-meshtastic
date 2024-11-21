#include <SoftwareSerial.h>

SoftwareSerial softSerial1(27, 26); // RX, TX
SoftwareSerial softSerial2(17, 16); // RX, TX

void setup() {
  Serial.begin(9600); 
  softSerial1.begin(9600); 
  softSerial2.begin(9600); 
}

void loop() {

  if (softSerial1.available()) {
    int data = softSerial1.read();
     Serial.print("recv from gps:");
     Serial.println(data);
    softSerial2.write(data);
  }

  if (softSerial2.available()) {
    int data = softSerial2.read();
    Serial.print("recv from esp32:");
    Serial.println(data);
    softSerial1.write(data);
  }
}