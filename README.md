# Arduino Air Quality Monitoring System

An Arduino-based system that monitors air quality, temperature, and humidity
in real time using environmental sensors. The system displays live readings
on an I2C LCD and outputs data to the Serial Monitor.

---

## Features
- Real-time air quality monitoring
- Temperature and humidity measurement using DHT11
- Live data display on 16×2 I2C LCD
- Serial monitor logging
- Low-cost and beginner-friendly project

---

## Components Used
- Arduino Uno / Mega
- DHT11 Temperature & Humidity Sensor
- Air Quality Sensors (connected to A0, A1, A2)
- 16×2 I2C LCD Display (I2C)
- Jumper wires

---

## Wiring Diagram / Connections

| Component | Pin | Arduino Pin | Notes |
|---------|-----|------------|------|
| DHT11 | VCC | 5V | Power supply |
|  | GND | GND | Ground |
|  | Data | Pin 2 | Signal output |
| Air Quality Sensor 1 | Signal | A0 | Analog input |
| Air Quality Sensor 2 | Signal | A1 | Analog input |
| Air Quality Sensor 3 | Signal | A2 | Analog input |
| LCD (I2C) | SDA | A4 | I2C Data |
|  | SCL | A5 | I2C Clock |
|  | VCC | 5V | Power supply |
|  | GND | GND | Ground |

---

## How It Works
The Arduino reads temperature and humidity values from the DHT11 sensor and
air quality values from analog sensors. The processed data is displayed on
the I2C LCD and printed to the Serial Monitor at regular intervals.

---

## How to Run
1. Connect all components as per the wiring diagram.
2. Upload the Arduino code to the board.
3. Open the Serial Monitor at 9600 baud rate.
4. Observe live air quality, temperature, and humidity readings.

---

## Future Improvements
- Use DHT22 for better accuracy
- Add WiFi module (ESP8266 / ESP32) for IoT support
- Add alert system (LED/Buzzer)
- Cloud data logging and visualization

---

## Author
Ajith M
