ESP8266 4-Channel Home Automation System

A simple and practical IoT-based Home Automation System built using the ESP8266 NodeMCU. This project allows users to control four electrical output channels through a web-based dashboard hosted on the ESP8266.

The system uses a local Wi-Fi network and an HTTP web server, allowing users to turn connected devices ON or OFF directly from a smartphone, tablet, or computer browser.

Features

- 4 Independent Output Channels
- Local Web Server Control
- Wi-Fi Connectivity
- Mobile-Friendly Web Interface
- Real-Time Output State Display
- Individual ON/OFF Controls
- Simple and Lightweight Arduino Code
- No Cloud Platform Required

Hardware Requirements

- ESP8266 NodeMCU
- 4-Channel Relay Module (optional)
- Jumper Wires
- USB Cable
- Smartphone or Computer

Pin Configuration

Channel| ESP8266 Pin| GPIO
Channel 1| D2| GPIO 4
Channel 2| D5| GPIO 14
Channel 3| D6| GPIO 12
Channel 4| D1| GPIO 5

Wi-Fi Configuration

Update the following credentials in the source code:

const char* ssid = "SmartHome";
const char* password = "12345678";

How to Use

1. Connect the ESP8266 to your computer or smartphone.
2. Upload the Arduino code to the ESP8266.
3. Connect the ESP8266 to your Wi-Fi network.
4. Open the Serial Monitor at 115200 baud.
5. Find the IP address displayed in the Serial Monitor.
6. Open that IP address in a web browser.
7. Control the four output channels using the ON/OFF buttons.

Required Library

- ESP8266WiFi (included with the ESP8266 Arduino Core)

Applications

- Smart Home Automation
- Wireless Light Control
- Electrical Appliance Control
- DIY IoT Projects
- Educational Electronics Projects

Developer

Chandan Barman

YouTube channal: https://youtube.com/@technicalbdvrj?si=02xooP2TBYsjUe1B

Disclaimer

This project is intended for educational and experimental purposes. Always follow proper electrical safety precautions when working with AC mains voltage.

---

If you find this project useful, consider giving this repository a ⭐ Star!
