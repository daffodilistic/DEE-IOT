#include <Arduino.h>

#define sensor_pin 2
#define PIN_LED_RED 23
#define PIN_LED_GREEN 18
#define PIN_LED_YELLOW 19
#define PIN_BUTTON_1 27
#define PIN_BUTTON_2 25
#define PIN_POTENTIOMETER A5

#define LED_RED_INTERVAL 1000
#define LED_GREEN_INTERVAL 500
#define LED_YELLOW_INTERVAL 2000

uint16_t ledBlinkInterval[3] = {
    LED_RED_INTERVAL,
    LED_GREEN_INTERVAL,
    LED_YELLOW_INTERVAL};
uint16_t ledPins[3] = {
    PIN_LED_RED,
    PIN_LED_GREEN,
    PIN_LED_YELLOW};
uint16_t ledCurrentTimeMs[3] = {0, 0, 0};
int8_t ledStates[3] = {LOW, LOW, LOW};

void setup()
{
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  // Configure pins
  pinMode(PIN_LED_RED, OUTPUT);
  pinMode(PIN_LED_GREEN, OUTPUT);
  pinMode(PIN_LED_YELLOW, OUTPUT);
  pinMode(sensor_pin, OUTPUT);
  // Set initial state
  digitalWrite(PIN_LED_RED, LOW);
  digitalWrite(PIN_LED_GREEN, LOW);
  digitalWrite(PIN_LED_YELLOW, LOW);
  digitalWrite(sensor_pin, LOW);
}

void loop()
{
  long currentMs = millis();
  for (uint8_t i = 0; i < 3; i++)
  {
    uint16_t timePassed = currentMs - ledCurrentTimeMs[i];
    if (timePassed >= ledBlinkInterval[i])
    {
      ledStates[i] = LOW;
      ledCurrentTimeMs[i] = currentMs;
      char buffer[32];
      sprintf(buffer, "[%d] [%d] [%d]",
              ledCurrentTimeMs[0],
              ledCurrentTimeMs[1],
              ledCurrentTimeMs[2]);
      Serial.print("Time: ");
      Serial.println(buffer);
    }
    else
    {
      ledStates[i] = HIGH;
    }
    digitalWrite(ledPins[i], ledStates[i]);
  }
  // To speed up emulator
  delay(1);
}