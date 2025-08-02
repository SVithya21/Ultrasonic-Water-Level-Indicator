# Ultrasonic-Water-Level-Indicator
Uses an HC-SR04 ultrasonic sensor to measure water level in a 20cm tank. Displays water distance and fill percentage on an LCD and gives buzzer alerts at low or full levels. Ideal for home tanks and irrigation.

## 📁 Project : Ultrasonic Water Level Indicator

### 🔧 Platform
- **Microcontroller:** Arduino Uno

### 📂 File
- Uploaded

### 📝 Description
Monitors water level in a 20 cm tank using an HC-SR04 ultrasonic sensor. Displays distance and water percentage on an I2C LCD and alerts using a buzzer at empty/full levels.

### 🔌 Pin Configuration
| Component         | Pin (Arduino Uno) | Description           |
|-------------------|-------------------|-----------------------|
| HC-SR04 Trig      | D9                | Trigger pin           |
| HC-SR04 Echo      | D8                | Echo pin              |
| I2C LCD SDA       | A4                | I2C Data              |
| I2C LCD SCL       | A5                | I2C Clock             |
| Buzzer            | D7                | Alert for low/full    |

### 💡 Logic
- Ultrasonic sensor sends pulse and receives echo.
- Time of flight → Distance.
- Level = Tank height - distance.
- Show fill % and trigger buzzer at thresholds.

### 🛠️ Components
- Arduino Uno
- HC-SR04 Sensor
- I2C 16x2 LCD
- Buzzer
- Jumper wires, Tank mock-up

---
