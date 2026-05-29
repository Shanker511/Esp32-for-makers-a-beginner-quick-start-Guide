# ESP32 for Makers

Project files, Arduino sketches, printable parts, diagrams, corrections, and support material for the book:

**ESP32 for Makers: A Beginner Quick-Start Guide to Wi-Fi, Bluetooth, Sensors, Displays, and Small Electronics Projects**  
Published by **Absolute Nerd Books**  
Author: **Gareth W. Erwin**

This repo is the living toolbox behind the printed book.

The book gives the map. This repo holds the files.

## What is included

- ESP32 Arduino example sketches
- Spicy Blink sketch
- Button input sketch
- Button-controlled LED sketch
- DHT11 temperature and humidity sketch
- Local ESP32 web dashboard sketch
- Breadboard holder STL
- Wiring notes
- Parts list
- Known gremlins / errata
- Changelog

## Download the book files

The main support page can point here:

```text
https://github.com/YOUR-GITHUB-USERNAME/esp32-for-makers
```

Replace `YOUR-GITHUB-USERNAME` with your actual GitHub username after creating the repo.

## Amazon author page

More Absolute Nerd Books:

```text
https://www.amazon.com/stores/Gareth-w-Erwin/author/B0965F3HBV
```

## Arduino libraries used

Some examples may require:

- ESP32 board package by Espressif Systems
- DHT sensor library
- Adafruit Unified Sensor library
- WiFi library
- WebServer library

## Hardware warning

Most ESP32 GPIO pins use **3.3V logic**.

Do not feed 5V directly into GPIO pins unless your module is designed for ESP32-safe logic or you are using a level shifter / voltage divider.

GPIO pins are signal pins. They are not power supplies for motors, pumps, relays, LED strips, or other hungry little power goblins.

## Suggested repo layout

```text
esp32-for-makers/
├─ code/
│  ├─ 01-spicy-blink/
│  ├─ 02-button-test/
│  ├─ 03-button-toggle-led/
│  ├─ 04-dht11-sensor/
│  └─ 05-web-dashboard/
├─ stl/
├─ diagrams/
├─ book/
├─ docs/
└─ .github/
```

## License summary

- Code examples: MIT License
- Documentation text in this repo: Copyright Gareth W. Erwin / Absolute Nerd Books
- STL files: See `stl/LICENSE-STL.md`
- Book interior text and book design: not open source unless explicitly stated

Build it. Break it. Fix it. Document the crime scene.
