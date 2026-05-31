# Smart IoT Environment Monitoring & Control System

A smart Internet of Things (IoT) system built using an ESP32, Arduino Mega 2560, Firebase Realtime Database, and a web dashboard for real-time monitoring and control of environmental conditions.

## Overview

This project enables users to monitor temperature and humidity remotely through a web dashboard while controlling connected devices such as lights. Sensor data is collected by an Arduino Mega connected to a DHT11 sensor and transmitted to an ESP32, which sends the data to Firebase. The web application retrieves the data from Firebase and allows users to send control commands back to the ESP32.

## Features

* Real-time temperature monitoring
* Real-time humidity monitoring
* Remote light control (ON/OFF)
* Firebase Realtime Database integration
* Responsive web dashboard
* Wireless communication through ESP32 Wi-Fi
* Serial communication between Arduino Mega and ESP32

## System Architecture

```text
DHT11 Sensor
      │
      ▼
Arduino Mega 2560
      │ UART (Serial1)
      ▼
ESP32 WROOM
      │ Wi-Fi
      ▼
Firebase Realtime Database
      ▲
      │
Web Dashboard
```

## Hardware Components

| Component         | Description                              |
| ----------------- | ---------------------------------------- |
| Arduino Mega 2560 | Reads sensor data                        |
| ESP32 WROOM       | Handles Wi-Fi and Firebase communication |
| DHT11 Sensor      | Measures temperature and humidity        |
| 10kΩ Resistor     | Voltage divider resistor                 |
| 20kΩ Resistor     | Voltage divider resistor                 |
| Jumper Wires      | Hardware connections                     |
| Breadboard        | Circuit prototyping                      |

## Wiring Connections

### DHT11 → Arduino Mega 2560

| DHT11 Pin | Arduino Mega Pin |
| --------- | ---------------- |
| VCC       | 5V               |
| GND       | GND              |
| DATA      | Digital Pin 2    |

### Arduino Mega 2560 → ESP32 WROOM

> **Important:** Arduino Mega TX outputs 5V logic while ESP32 RX pins are 3.3V tolerant only. Use the voltage divider shown below.

```text
Mega TX1 (Pin 18)
        |
      [10kΩ]
        |
        +---------- ESP32 GPIO16 (RX2)
        |
      [20kΩ]
        |
       GND
```

### Additional Connections

| Arduino Mega | ESP32                            |
| ------------ | -------------------------------- |
| TX1 (Pin 18) | GPIO16 (RX2) via voltage divider |
| RX1 (Pin 19) | GPIO17 (TX2)                     |
| GND          | GND                              |

## Required Libraries

Install the following libraries through the Arduino IDE Library Manager:

### Arduino Mega

* Adafruit Unified Sensor
* DHT Sensor Library by Adafruit

### ESP32

* WiFi
* Firebase ESP Client Library

## Configuration

### Arduino Mega

```cpp
#define DHTPIN 2
#define DHTTYPE DHT11
```

### Serial Communication

Both devices communicate at:

```cpp
9600 baud
```

### Data Format

The Arduino sends data to the ESP32 in the following format:

```text
T:25.30,H:60.10
```

Where:

* T = Temperature in °C
* H = Humidity in %

A newline character (`\n`) is appended to indicate the end of each message.

## How It Works

1. The DHT11 sensor measures temperature and humidity.
2. Arduino Mega reads the sensor values.
3. The Mega sends the data to the ESP32 using UART Serial1.
4. ESP32 receives the sensor data.
5. ESP32 uploads the data to Firebase Realtime Database.
6. The web dashboard reads the latest values from Firebase.
7. Users can control lights from the dashboard.
8. ESP32 receives commands from Firebase and switches the light accordingly.

## Example Serial Monitor Output

```text
Temperature: 25.30°C
Humidity: 60.10%
```

## Error Handling

If the DHT11 fails to return valid data:

```text
Error reading temperature!
Error reading humidity!
```

Invalid readings are not transmitted to the ESP32, preventing corrupted data from reaching Firebase.

## Technologies Used

* Arduino Mega 2560
* ESP32 WROOM
* Firebase Realtime Database
* DHT11 Sensor
* HTML
* CSS
* JavaScript
* Wi-Fi Networking
* UART Serial Communication

## Use Cases

* Smart Home Automation
* Environmental Monitoring
* Remote Device Control
* IoT Learning Projects
* Educational Demonstrations

## Future Improvements

* Multiple sensor support
* Mobile application integration
* Data logging and analytics
* Alert and notification system
* Energy monitoring features

## Author

Rapheal Chinyama

Developed as an educational IoT project to demonstrate sensor integration, cloud communication, and remote device control using Arduino, ESP32, Firebase, and Web Technologies.

## License

This project is open-source and intended for educational and research purposes.
