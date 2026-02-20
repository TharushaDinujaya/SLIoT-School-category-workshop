# 💡 Code 03 — Remote LED Control via MQTT + Node-RED

> Control an **LED** connected to ESP32 remotely through **Node-RED** using **MQTT** — with bi-directional state feedback!

---

## 📖 Description

This is the **final exercise** in the workshop and introduces **bi-directional MQTT communication**. The ESP32 subscribes to a control topic to receive commands ("ON" / "OFF") and publishes the current LED state back to Node-RED. This creates a complete **feedback loop** — a fundamental pattern in IoT systems.

---

## 🔧 What You'll Learn

- ✅ Subscribing to MQTT topics on ESP32
- ✅ Handling incoming messages with a callback function
- ✅ Controlling hardware (LED) based on MQTT messages
- ✅ Publishing state feedback for bi-directional communication
- ✅ Building interactive dashboards in Node-RED

---

## 📡 MQTT Details

| Property            | Value                  |
| ------------------- | ---------------------- |
| **Broker**          | `test.mosquitto.org`   |
| **Port**            | `1883`                 |
| **Subscribe Topic** | `tharusha/led/control` |
| **Publish Topic**   | `tharusha/led/state`   |
| **Command Format**  | `ON` or `OFF`          |
| **State Format**    | `ON` or `OFF`          |

### Communication Flow

```
┌──────────────┐         MQTT          ┌──────────────┐
│   Node-RED   │ ── "ON" / "OFF" ───▶  │    ESP32     │
│  Dashboard   │   tharusha/led/control │   + LED      │
│              │ ◀── "ON" / "OFF" ───  │              │
│              │   tharusha/led/state   │              │
└──────────────┘                        └──────────────┘
```

---

## 🔌 Circuit Diagram

```
ESP32             LED
──────            ───
GPIO23 ──[220Ω]──  Anode (+)
GND   ────────────  Cathode (-)
```

> 💡 **GPIO 23** is used in this example. You can change it by modifying `#define LED_PIN 23` in the code.

---

## ⚙️ Configuration

Before uploading, update these values in `code03.ino`:

```cpp
const char* ssid = "YOUR_WIFI";          // Your Wi-Fi SSID
const char* password = "YOUR_PASSWORD";   // Your Wi-Fi password
const char* mqtt_server = "test.mosquitto.org";  // MQTT broker address
```

---

## 🚀 How to Use

1. Wire the LED to GPIO 23 with a 220Ω resistor
2. Open `code03.ino` in Arduino IDE
3. Update Wi-Fi and MQTT credentials
4. Upload to ESP32
5. Open **Serial Monitor** (baud rate: `115200`) to see connection & message logs
6. Use Node-RED to send `ON` / `OFF` commands

---

## 🔗 Node-RED Integration

### Suggested Flow

1. **Dashboard Switch** node → Outputs `ON` / `OFF`
2. **MQTT Out** node:
   - **Server:** `test.mosquitto.org:1883`
   - **Topic:** `tharusha/led/control`
3. **MQTT In** node:
   - **Topic:** `tharusha/led/state`
4. **Dashboard Text / LED indicator** → Shows current state

### Flow Diagram

```
[Switch] ──▶ [MQTT Out: tharusha/led/control]

[MQTT In: tharusha/led/state] ──▶ [Dashboard LED Indicator]
```

### 🎛️ Node-RED User Inputs

<p align="center">
  <img src="../docs/user%20inputs.png" alt="Node-RED User Inputs" width="600" />
</p>

> The Node-RED dashboard provides interactive controls (switches/buttons) to send `ON` / `OFF` commands to the ESP32.

---

## 🧠 Key Concepts

### Callback Function

The `callback()` function is triggered whenever a message arrives on the subscribed topic. It parses the payload and controls the LED accordingly.

### State Management

The code tracks the current LED state and **only updates when the state changes**, preventing unnecessary writes and redundant MQTT publishes — an important optimization in IoT systems.

---

## 📦 Required Libraries

| Library        | Install via             |
| -------------- | ----------------------- |
| `PubSubClient` | Arduino Library Manager |

> ℹ️ No DHT library needed for this exercise — only Wi-Fi and MQTT!

---

[⬅️ Back to Main README](../README.md) · [Previous: Code 02](../code02/README.md)
