# 🌡️💧 Code 02 — Temperature & Humidity (JSON) via MQTT

> Publish **temperature and humidity** data as a **JSON payload** from a DHT11 sensor to an MQTT broker using ESP32.

---

## 📖 Description

Building on Code 01, this exercise introduces **structured data transmission** using JSON. Instead of sending a single value, the ESP32 packages both temperature and humidity into a JSON object before publishing. This is a more realistic approach used in real-world IoT applications.

---

## 🔧 What You'll Learn

- ✅ Reading multiple sensor values (temperature + humidity)
- ✅ Constructing JSON payloads on ESP32
- ✅ Publishing structured data via MQTT
- ✅ Parsing JSON in Node-RED

---

## 📡 MQTT Details

| Property             | Value                |
| -------------------- | -------------------- |
| **Broker**           | `test.mosquitto.org` |
| **Port**             | `1883`               |
| **Publish Topic**    | `tharusha/dht11`     |
| **Payload Format**   | JSON                 |
| **Publish Interval** | Every 5 seconds      |

### Example Payload

```json
{
  "temperature": 28.5,
  "humidity": 65.0
}
```

---

## 🔌 Circuit Diagram

<p align="center">
  <img src="../docs/circuit_image.png" alt="DHT11 Circuit Diagram" width="500" />
</p>

```
ESP32          DHT11
──────         ─────
3.3V  ───────  VCC
GND   ───────  GND
GPIO4 ───────  DATA
```

> Same wiring as Code 01 — no changes needed if you already have it set up!

---

## ⚙️ Configuration

Before uploading, update these values in `code02.ino`:

```cpp
const char* ssid = "YOUR_WIFI";          // Your Wi-Fi SSID
const char* password = "YOUR_PASSWORD";   // Your Wi-Fi password
const char* mqtt_server = "test.mosquitto.org";  // MQTT broker address
```

---

## 🚀 How to Use

1. Wire the DHT11 sensor to the ESP32 (same as Code 01)
2. Open `code02.ino` in Arduino IDE
3. Update Wi-Fi and MQTT credentials
4. Upload to ESP32
5. Open **Serial Monitor** (baud rate: `115200`) to see the JSON output
6. Subscribe to `tharusha/dht11` in Node-RED to receive structured data

---

## 🔗 Node-RED Integration

1. Add an **MQTT In** node:
   - **Server:** `test.mosquitto.org:1883`
   - **Topic:** `tharusha/dht11`

2. Add a **JSON** node to parse the payload

3. Use a **Function** or **Change** node to extract individual values:

   ```javascript
   msg.temperature = msg.payload.temperature;
   msg.humidity = msg.payload.humidity;
   ```

4. Connect to **Dashboard Gauge** / **Chart** nodes for visualization

### 📊 Serial Monitor Output

<p align="center">
  <img src="../docs/Monitor.png" alt="Serial Monitor Output" width="600" />
</p>

> The Serial Monitor shows the JSON payloads being published to the MQTT broker in real time.

---

## 🆚 Code 01 vs Code 02

| Feature        | Code 01            | Code 02                |
| -------------- | ------------------ | ---------------------- |
| Sensor Data    | Temperature only   | Temperature + Humidity |
| Payload Format | Plain text         | JSON                   |
| MQTT Topic     | `home/temperature` | `tharusha/dht11`       |
| Data Parsing   | Direct use         | JSON parsing required  |

---

## 📦 Required Libraries

| Library              | Install via             |
| -------------------- | ----------------------- |
| `PubSubClient`       | Arduino Library Manager |
| `DHT sensor library` | Arduino Library Manager |

---

[⬅️ Back to Main README](../README.md) · [Previous: Code 01](../code01/README.md) · [Next: Code 03 ➡️](../code03/README.md)
