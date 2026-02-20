<p align="center">
  <img src="https://img.shields.io/badge/Platform-ESP32-blue?style=for-the-badge&logo=espressif&logoColor=white" />
  <img src="https://img.shields.io/badge/Protocol-MQTT-purple?style=for-the-badge&logo=mqtt&logoColor=white" />
  <img src="https://img.shields.io/badge/Dashboard-Node--RED-red?style=for-the-badge&logo=nodered&logoColor=white" />
  <img src="https://img.shields.io/badge/License-MIT-green?style=for-the-badge" />
</p>

# 🌐 SLIoT School Category Workshop

> **IoT workshop materials for the SLIoT School Category** — Learn to build real IoT projects using **ESP32**, **MQTT**, and **Node-RED**!

---

## 📖 Overview

This repository contains hands-on Arduino sketches designed for the **SLIoT (Sri Lanka IoT) School Category Workshop**. The workshop walks you through building IoT systems step-by-step — from reading sensors to controlling devices remotely — all connected through **MQTT** and visualized with **Node-RED** dashboards.

---

## 📂 Project Structure

```
📦 SLIoT-School-category-workshop
├── 📁 code01/          → Temperature monitoring via MQTT
├── 📁 code02/          → Temperature & humidity (JSON payload) via MQTT
├── 📁 code03/          → Remote LED control via MQTT + Node-RED
├── 📄 LICENSE           → MIT License
└── 📄 README.md         → You are here!
```

---

## 🚀 Workshop Exercises

| #   | Folder              | Description                            | Sensor / Actuator       | MQTT Topic             |
| --- | ------------------- | -------------------------------------- | ----------------------- | ---------------------- |
| 1   | [`code01`](code01/) | Publish temperature readings           | DHT11 (Temperature)     | `home/temperature`     |
| 2   | [`code02`](code02/) | Publish temperature & humidity as JSON | DHT11 (Temp + Humidity) | `tharusha/dht11`       |
| 3   | [`code03`](code03/) | Control an LED remotely via Node-RED   | LED (GPIO 23)           | `tharusha/led/control` |

---

## 🛠️ Prerequisites

### Hardware

- **ESP32** development board
- **DHT11** temperature & humidity sensor
- **LED** + 220Ω resistor (for code03)
- Breadboard & jumper wires
- USB cable for programming

### Software

- [Arduino IDE](https://www.arduino.cc/en/software) (v2.x recommended)
- [Node-RED](https://nodered.org/) installed on your PC or Raspberry Pi
- ESP32 Board Package for Arduino IDE

### Arduino Libraries

Install these libraries via **Arduino IDE → Library Manager**:

| Library              | Purpose                             |
| -------------------- | ----------------------------------- |
| `WiFi.h`             | ESP32 Wi-Fi connectivity (built-in) |
| `PubSubClient`       | MQTT client for Arduino             |
| `DHT sensor library` | Read DHT11/DHT22 sensors            |

---

## ⚡ Quick Start

### 1. Clone the Repository

```bash
git clone https://github.com/TharushaDinujaya/SLIoT-School-category-workshop.git
```

### 2. Configure Wi-Fi & MQTT

In each `.ino` file, update these lines with your credentials:

```cpp
const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";
const char* mqtt_server = "test.mosquitto.org";  // or your broker IP
```

### 3. Upload to ESP32

1. Open the `.ino` file in Arduino IDE
2. Select **Board** → `ESP32 Dev Module`
3. Select the correct **Port**
4. Click **Upload** ⬆️

### 4. Launch Node-RED

```bash
node-red
```

Open your browser and navigate to `http://localhost:1880` to build your dashboard flows.

---

## 🔌 Circuit Diagrams

### DHT11 Wiring (code01 & code02)

```
ESP32          DHT11
──────         ─────
3.3V  ───────  VCC
GND   ───────  GND
GPIO4 ───────  DATA
```

### LED Wiring (code03)

```
ESP32           LED
──────          ───
GPIO23 ──[220Ω]──  Anode (+)
GND   ────────────  Cathode (-)
```

---

## 🌐 MQTT Broker

The examples use the **public Mosquitto test broker**:

| Setting | Value                |
| ------- | -------------------- |
| Broker  | `test.mosquitto.org` |
| Port    | `1883`               |
| Auth    | None required        |

> 💡 **Tip:** For production use, set up your own MQTT broker (e.g., local Mosquitto instance) for reliability and security.

---

## 📚 Learning Path

```
code01 (Basics)          code02 (Intermediate)        code03 (Advanced)
┌─────────────────┐     ┌──────────────────────┐     ┌──────────────────────┐
│ • WiFi Setup     │     │ • JSON Payloads       │     │ • MQTT Subscribe     │
│ • MQTT Publish   │ ──▶ │ • Multi-sensor Data   │ ──▶ │ • Callback Handling  │
│ • Single Value   │     │ • Structured Messages  │     │ • Bi-directional     │
│ • Serial Monitor │     │ • Node-RED Parsing     │     │ • LED Actuation      │
└─────────────────┘     └──────────────────────┘     └──────────────────────┘
```

---

## 🤝 Contributing

Contributions are welcome! Feel free to:

- 🐛 Report bugs via [Issues](https://github.com/TharushaDinujaya/SLIoT-School-category-workshop/issues)
- 💡 Suggest new workshop exercises
- 🔀 Submit pull requests

---

## 📄 License

This project is licensed under the **MIT License** — see the [LICENSE](LICENSE) file for details.

---

<p align="center">
  Made with ❤️ for the <strong>SLIoT School Category Workshop</strong>
</p>
