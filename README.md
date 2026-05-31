# smart-IoT-Environment-Monitoring-Control-System
 Smart IoT system using ESP32, Firebase, and a web dashboard for real-time monitoring and control of lighting, temperature, and humidity.




# Smart IoT Environment Monitoring & Control System

This project is a simple Internet of Things (IoT) system built using an ESP32 microcontroller, Firebase Realtime Database, and a web-based dashboard. It enables real-time monitoring of environmental conditions and remote control of a lighting system.

##  Features

- Real-time temperature monitoring using DHT11/DHT22 sensor
- Real-time humidity monitoring
- Remote control of a light (ON/OFF) via web interface
- Live data synchronization using Firebase
- Simple and responsive web dashboard

##  System Architecture

Website ↔ Firebase Realtime Database ↔ ESP32 ↔ Sensors & Relay

## ⚙️ Technologies Used

- ESP32 Microcontroller
- DHT11 / DHT22 Sensor
- Relay Module (or LED for testing)
- Firebase Realtime Database
- HTML, CSS, JavaScript

## 🚀 How It Works

1. ESP32 connects to Wi-Fi
2. It reads temperature and humidity from the sensor
3. Data is sent to Firebase in real time
4. The web dashboard reads and displays the data
5. User sends ON/OFF commands from the website
6. ESP32 reads commands from Firebase and controls the light

## Use Cases

- Smart home systems
- Environmental monitoring
- Basic IoT learning project
- Remote device control systems

##  Author

Developed as a student IoT project for learning embedded systems and cloud integration.

## Note

This project is designed for educational purposes and demonstration of IoT concepts.
