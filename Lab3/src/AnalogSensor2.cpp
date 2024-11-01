#include <Arduino.h>

#define PIN_LED_RED 23
#define PIN_LED_YELLOW 19
#define PIN_LED_GREEN 18
#define ADC_IN A5
#define ADC_REF 3.3

void setup() {
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  // Configure pins
  pinMode(PIN_LED_RED, OUTPUT);
  pinMode(PIN_LED_YELLOW, OUTPUT);
  pinMode(PIN_LED_GREEN, OUTPUT);
  // Set initial state
  digitalWrite(PIN_LED_RED, HIGH);
  digitalWrite(PIN_LED_YELLOW, HIGH);
  digitalWrite(PIN_LED_GREEN, HIGH);
}

void loop() {
  uint16_t adcRes = analogRead( ADC_IN );
  if (adcRes <= 1000) {
    // Turn on green LED
    digitalWrite(PIN_LED_GREEN, LOW);
    // Turn off other LEDs
    digitalWrite(PIN_LED_RED, HIGH);
  } else if (adcRes > 1000 && adcRes < 3500) {
    // Turn on red LED
    digitalWrite(PIN_LED_RED, LOW);
    // Turn off other LEDs
    digitalWrite(PIN_LED_GREEN, HIGH);
  } else if (adcRes >= 3500) {
    // Turn on green & red LEDs
    digitalWrite(PIN_LED_RED, LOW);
    digitalWrite(PIN_LED_GREEN, LOW);
  }
  delay(100);
}
