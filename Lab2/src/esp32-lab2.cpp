#include <Arduino.h>

#define PIN_LED_RED 23
#define PIN_LED_YELLOW 19
#define PIN_LED_GREEN 18
#define PIN_BUTTON_1 27
#define PIN_BUTTON_2 25
#define PIN_POTENTIOMETER A5

int64_t blinkCount = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  // Configure pins
  pinMode(PIN_LED_RED, OUTPUT);
  pinMode(PIN_LED_YELLOW, OUTPUT);
  pinMode(PIN_LED_GREEN, OUTPUT);
  // Set initial state
  digitalWrite(PIN_LED_RED, LOW);
  digitalWrite(PIN_LED_YELLOW, LOW);
  digitalWrite(PIN_LED_GREEN, LOW);
}

void loop() {
  // Blink all LEDs
  digitalWrite(PIN_LED_RED, HIGH);
  digitalWrite(PIN_LED_YELLOW, HIGH);
  digitalWrite(PIN_LED_GREEN, HIGH);
  delay(500);
  digitalWrite(PIN_LED_RED, LOW);
  digitalWrite(PIN_LED_YELLOW, LOW);
  digitalWrite(PIN_LED_GREEN, LOW);
  delay(1000);
  blinkCount++;
  Serial.println("Blink count: " + String(blinkCount));
}
