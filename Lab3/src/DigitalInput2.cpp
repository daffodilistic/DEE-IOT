#include <Arduino.h>

#define PIN_LED_RED 23
#define PIN_LED_YELLOW 19
#define PIN_LED_GREEN 18
#define PIN_BUTTON_1 27
#define PIN_BUTTON_2 25
#define PIN_POTENTIOMETER A5

void setup() {
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  // Configure pins
  pinMode(PIN_LED_RED, OUTPUT);
  pinMode(PIN_LED_YELLOW, OUTPUT);
  pinMode(PIN_LED_GREEN, OUTPUT);
  pinMode(PIN_BUTTON_1, INPUT);
  pinMode(PIN_BUTTON_2, INPUT);
  // Set initial state
  digitalWrite(PIN_LED_RED, HIGH);
  digitalWrite(PIN_LED_YELLOW, HIGH);
  digitalWrite(PIN_LED_GREEN, HIGH);
}

void loop() {
  bool button1on = digitalRead(PIN_BUTTON_1);
  bool button2on = digitalRead(PIN_BUTTON_2);
  Serial.println("Button 1: " + String(button1on) + " Button 2: " + String(button2on));
  if (button1on && button2on) {
    Serial.println("Both buttons are pressed");
      digitalWrite(PIN_LED_RED, LOW);
      // digitalWrite(PIN_LED_YELLOW, LOW);
      digitalWrite(PIN_LED_GREEN, LOW);
  } else if (button1on == true && button2on == false) {
    Serial.println("Button 1 is pressed");
    digitalWrite(PIN_LED_RED, LOW);
    // digitalWrite(PIN_LED_YELLOW, HIGH);
    digitalWrite(PIN_LED_GREEN, HIGH);
  } else if (button1on == false && button2on == true) {
    Serial.println("Button 2 is pressed");
    digitalWrite(PIN_LED_RED, HIGH);
    // digitalWrite(PIN_LED_YELLOW, HIGH);
    digitalWrite(PIN_LED_GREEN, LOW);
  } else {
    Serial.println("No buttons are pressed");
      digitalWrite(PIN_LED_RED, HIGH);
      // digitalWrite(PIN_LED_YELLOW, HIGH);
      digitalWrite(PIN_LED_GREEN, HIGH);
  }
  delay(100);
}
