💧 Ultrasonic Water Level Indicator  
**Short Description:** Real-time water level monitor using ultrasonic sensor and LCD display.

### Description:
An Arduino-based water tank level monitoring system using an HC-SR04 ultrasonic sensor. It displays the water level percentage and height in cm on an LCD and gives buzzer alerts for low or full levels.

### Components:
- Arduino UNO
- HC-SR04 Ultrasonic Sensor
- Buzzer
- I2C 16x2 LCD
- Jumper Wires

### Pin Configuration:
| Component | Arduino Pin |
|----------|-------------|
| Ultrasonic Trigger | D9 |
| Ultrasonic Echo | D10 |
| Buzzer | D7 |
| LCD SDA | A4 |
| LCD SCL | A5 |

### Features:
- Displays tank level in cm and percentage
- Sensor error handling
- Buzzer alarm when tank is full or empty
- Out-of-range detection

---
