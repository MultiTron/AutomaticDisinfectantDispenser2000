#include <Servo.h>

#define sensorPin 12
Servo servo;
int pirState = LOW;// we start, assuming no motion detected
int val = 0;       // variable for reading the pin status

void setup() {
  pinMode(sensorPin, INPUT); // declare sensor as input
  servo.attach(13);
}

void loop() {
   PIRSensor();
}

void PIRSensor() {
   val = digitalRead(sensorPin);// read input value
  if (val == HIGH) {          // check if the input is HIGH
    servo.write(0);// turn LED ON
    if (pirState == LOW) {
      pirState = HIGH;
    }
  } else {
    servo.write(90); // turn LED OFF
    if (pirState == HIGH){
      pirState = LOW;
    }
  }
}
