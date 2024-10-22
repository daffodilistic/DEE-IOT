/*
  Lab1 modified for ESP8266-based "Smart Weather Clock"
*/

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define WIFI_SSID "ssid"
#define WIFI_PASSWORD "password"
#define MQTT_SERVER_HOST "test.mosquitto.org"
#define MQTT_SERVER_PORT 1883
#define MQTT_CLIENT_NAME "esp32Client_SohThiamHing"
#define MQTT_TOPIC "sph2/room/LED"
#define GLED BUILTIN_LED

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("Given IP by the router to ESP32 is ");
  Serial.println(WiFi.localIP());
}

void connect_mqtt() {
  while (!client.connected()) {
    Serial.println("Connecting to MQTT ...");
    if (client.connect(MQTT_CLIENT_NAME))  //, mqttUser, mqttPassword) )
    {
      Serial.println("Connected");
      MQTTSubscribe();
    } else {
      Serial.print("Failed with state ");
      Serial.print(client.state());
      delay(2000);
    }
  }
}

void callback(String topic, byte* payload, unsigned int length) {
  String messageTemp;
  Serial.print("Message received in topic: ");
  Serial.print(topic);
  Serial.print(" length is: ");
  Serial.println(length);

  Serial.print("Data received from broker: ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
    messageTemp += (char)payload[i];
  }

  if (topic == MQTT_TOPIC) {
    char message[128] = "Changing room LED to ";
    if (messageTemp == "Off") {
      digitalWrite(GLED, HIGH);
      strcat(message, "Off");
    } else if (messageTemp == "On") {
      digitalWrite(GLED, LOW);
      strcat(message, "On");
    }
    Serial.println(message);
  }
}

void MQTTSubscribe() {
  client.subscribe(MQTT_TOPIC);
}

void setup_mqtt() {
  client.setServer(MQTT_SERVER_HOST, MQTT_SERVER_PORT);
  client.setCallback(callback);
}

void setup() {
  Serial.begin(9600);
  delay(5000);

  pinMode(GLED, OUTPUT);
  digitalWrite(GLED, LOW);

  setup_wifi();
  setup_mqtt();
}

void loop() {
  if (!client.connected()) {
    connect_mqtt();
  }
  client.loop();
}
