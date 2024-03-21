![Build](https://github.com/darkrymit/esp32-fan/actions/workflows/build-platformio.yml/badge.svg)

# Cooling Fan Controller on ARDUINO/ESP32

## Table of Contents

- [Description](#description)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Images](#images)

## Description

This project is a cooling fan controller built on the ARDUINO/ESP32 platform. 

It allows you to control the speed of a cooling fan based on temperature readings from a sensor. The fan speed is adjusted dynamically to maintain a desired temperature range. Fan speed is controlled using PWM (Pulse Width Modulation) signals, and the temperature sensor is connected to an analog input pin. 

The project is built using the Arduino framework but uses the ESP32 microcontroller for its advanced features and capabilities. The project can be simulated and tested using the Wokwi simulator.


## Features

- Use PWM signals to adjust the fan speed
- Read temperature from a sensor connected to microcontroller
- Dynamically adjust fan speed to maintain a desired temperature range
- Built using the Arduino framework and the ESP32 microcontroller
- Simulate project using the Wokwi simulator

## Requirements

### Software
Required software for the project:

| Name      | Link      | Mandatory |
|-----------|-----------|-----------|
| Visual Studio Code | [Download](https://code.visualstudio.com/) | Yes |
| PlatformIO Extension | [Download](https://platformio.org/install/ide?install=vscode) | Yes |
| Wokwi Simulator Extension | [Download](https://docs.wokwi.com/vscode/getting-started) | No |

### Hardware
Required hardware for the project:


| Group      | Parts | Notes |
|-----------|-----------|-----------|
| Microcontroller | ESP32 | Any ESP32 microcontroller will work |
| Cooling Fan | - 5v/12v PWM Fan (e.g. 4pin PC or Laptop fan) <br> - 5v/12v Power Supply <br> - 10 kΩ Resistor | You need 10 kΩ pull-up resistor for Tachometer signal. You need external power supply for the fan.|
| Temperature Sensor | DH11 | Can be replaced with any other temperature sensor but you need to modify the code if not using DH11/DHT22 |
| Prototyping Accessories (Optional) | Breadboard, Jumper Wires, etc. |  |

## Installation

1. Clone the repository to your local machine (SSH or HTTPS depending on your preference)
2. Open the project in Visual Studio Code
3. Install the PlatformIO extension if you haven't already
4. Install the Wokwi simulator extension if you want to simulate the project
5. Connect the ESP32 microcontroller to your computer
6. Build and upload the project to the microcontroller using the PlatformIO extension
7. Open the serial monitor to view the logs and debug messages


## Images

Todo: Add images of the project, such as a schematic, breadboard layout, or screenshots of the code running in the simulator.

