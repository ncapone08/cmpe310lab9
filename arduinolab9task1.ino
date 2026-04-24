#include <Wire.h>

const int probePin = 4;   // Input from probes
const int signalPin = 7; // Output to LED and Buzzer

void setup() {
  // Use internal pull-up resistor to keep pin HIGH until grounded
  pinMode(probePin, INPUT_PULLUP); 
  pinMode(signalPin, OUTPUT);
}

void loop() {
  // Read the probe state
  int isConnected = digitalRead(probePin);

  // If probes touch, pin goes LOW
  if (isConnected == LOW) {
    digitalWrite(signalPin, HIGH); // Turn on LED/Buzzer
  } else {
    digitalWrite(signalPin, LOW);  // Turn off LED/Buzzer
  }
}