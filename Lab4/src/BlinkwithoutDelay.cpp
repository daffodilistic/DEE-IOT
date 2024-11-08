#include <Arduino.h>

#define sensor_pin 2
#define PIN_LED_RED 23
#define PIN_LED_YELLOW 19
#define PIN_LED_GREEN 18
#define PIN_BUTTON_1 27
#define PIN_BUTTON_2 25
#define PIN_POTENTIOMETER A5

long previousMillis = 0;
uint16_t interval = 1000;
uint8_t ledState = LOW;
int8_t blinkCount = 0;

void setup()
{
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  // Configure pins
  pinMode(PIN_LED_RED, OUTPUT);
  pinMode(PIN_LED_YELLOW, OUTPUT);
  pinMode(PIN_LED_GREEN, OUTPUT);
  pinMode(sensor_pin, OUTPUT);
  // Set initial state
  digitalWrite(PIN_LED_RED, LOW);
  digitalWrite(PIN_LED_YELLOW, LOW);
  digitalWrite(PIN_LED_GREEN, LOW);
  digitalWrite(sensor_pin, LOW);
}

void loop()
{
  long currentMillis = millis();
  if ((currentMillis - previousMillis) >= interval)
  {
    previousMillis = currentMillis; // save the last time you blinked the LED
    if (ledState == LOW)
    {
      ledState = HIGH;
    }
    else
    {
      ledState = LOW;
    }
    blinkCount++;
    Serial.println("Blink count: " + String(blinkCount));
  }
  digitalWrite(PIN_LED_RED, ledState);
  digitalWrite(PIN_LED_YELLOW, ledState);
  digitalWrite(PIN_LED_GREEN, ledState);
}