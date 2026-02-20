#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";
const char* mqtt_server = "test.mosquitto.org";

WiFiClient espClient;
PubSubClient client(espClient);

#define LED_PIN 23  // Built-in LED for most ESP32 boards

int currentLEDState = LOW;  // Tracks the last LED state

void callback(char* topic, byte* payload, unsigned int length) {
  String message;

  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  Serial.print("Message received: ");
  Serial.println(message);

  int newState = currentLEDState;

  if (message == "ON") {
    newState = HIGH;
  } else if (message == "OFF") {
    newState = LOW;
  }

  // Only update LED and publish state if it has changed
  if (newState != currentLEDState) {
    digitalWrite(LED_PIN, newState);
    currentLEDState = newState;

    // Publish updated state to Node-RED
    String stateMessage = (currentLEDState == HIGH) ? "ON" : "OFF";
    client.publish("tharusha/led/state", stateMessage.c_str());
    Serial.print("Published LED state: ");
    Serial.println(stateMessage);
  }
}

void reconnect() {
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
    if (client.connect("ESP32_LED_Client")) {
      client.subscribe("tharusha/led/control");
      Serial.println("Connected & Subscribed");
    } else {
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("WiFi Connected");

  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}