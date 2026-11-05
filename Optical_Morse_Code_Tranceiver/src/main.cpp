#include <Arduino.h>

const int LASER_PIN = 8;
char mode = '1'; // '1' = 1 kHz pulse train, '2' = 2 Hz visual blink

void setup() {
  pinMode(LASER_PIN, OUTPUT);
  Serial.begin(9600);

  // Start hardware-timed 1000 Hz square wave (50% duty cycle) on Pin 8
  tone(LASER_PIN, 1000);

  Serial.println("Optical Transmitter Active: 1 kHz Pulse Train Running.");
  Serial.println("Type '1' for 1 kHz Pulse Train, or '2' for 2 Hz Visual Blink.");
}

void loop() {
  if (Serial.available() > 0) {
    char input = Serial.read();
    if (input == '1') {
      mode = '1';
      tone(LASER_PIN, 1000);
      Serial.println("Switched to: 1 kHz Pulse Train");
    } else if (input == '2') {
      mode = '2';
      noTone(LASER_PIN);
      Serial.println("Switched to: 2 Hz Visual Blink");
    }
  }

  if (mode == '2') {
    digitalWrite(LASER_PIN, HIGH);
    delay(250);
    digitalWrite(LASER_PIN, LOW);
    delay(250);
  }
}