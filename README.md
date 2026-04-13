# smart-energy-meter
# IoT Smart Energy Meter with Real-Time Theft Detection ⚡

![Platform](https://img.shields.io/badge/Platform-ESP32-blue)
![Framework](https://img.shields.io/badge/Framework-Arduino_IDE-orange)
![Cloud](https://img.shields.io/badge/Cloud-Blynk_IoT-green)
![Status](https://img.shields.io/badge/Status-Prototype_Complete-success)

An edge-computing, dual-node smart energy meter designed to proactively detect electricity theft, calculate real-time tiered billing, and mitigate grid fire hazards. 

Unlike traditional smart meters that only measure endpoint consumption, this system uses a **Differential Current Analysis** model (Kirchhoff’s Current Law) to compare the current at the utility pole with the current entering the house. If unauthorized line tapping is detected, the system physically isolates the load and pushes an MQTT alert to the cloud.

## 🌟 Key Features
* **Active Protection:** Instantly detects "Line Tapping" or "Bypass" theft and trips a 5V relay to cut power.
* **Triple-Check Debounce Logic:** Filters out inductive load spikes (like AC or fridge startups) to prevent false alarms.
* **Offline Resiliency:** Functions as a standalone protector even if the Wi-Fi router loses power.
* **Flash Memory Wear-Leveling:** Saves the customer's bill to the ESP32's Non-Volatile Storage (NVS) every 0.01 kWh, surviving power cuts while preserving the flash memory lifespan (10+ years).
* **Tiered "Slab" Billing:** Calculates live bills in Rupees (₹), dynamically switching from ₹7/unit to ₹12/unit after the first 100 units.
* **Cloud Telemetry:** Integrates with Blynk 2.0 for live mobile and web dashboards.

## 🛠️ Hardware Requirements
* **ESP32 Development Board** (Dual-Core, Wi-Fi enabled)
* 2x **ACS712 (30A)** Hall-Effect Current Sensors
* 1x **ZMPT101B** Active Voltage Transformer
* 1x **5V Relay Module** (Single Channel)
* 1x **16x2 I2C LCD Display**
* Piezo Buzzer & Indicator LED
* 230V AC Load (Bulb) for testing

## 🔌 Pin Mapping (ESP32)

| Component | ESP32 Pin | Function |
| :--- | :--- | :--- |
| **ZMPT101B (Voltage)** | GPIO 32 | Analog Input (ADC1_CH4) |
| **ACS712 (Pole Current)** | GPIO 34 | Analog Input (ADC1_CH6) |
| **ACS712 (House Current)**| GPIO 35 | Analog Input (ADC1_CH7) |
| **5V Relay** | GPIO 26 | Digital Output |
| **Piezo Buzzer** | GPIO 18 | Digital Output |
| **Alert LED** | GPIO 19 | Digital Output |
| **I2C LCD SDA** | GPIO 21 | I2C Data |
| **I2C LCD SCL** | GPIO 22 | I2C Clock |

## 🚀 Installation & Setup

1. **Clone the repository:**
   ```bash
   git clone https://github.com/YourUsername/Smart-Energy-Meter.git](https://github.com/Yashmk5523/smart-energy-meter.git
