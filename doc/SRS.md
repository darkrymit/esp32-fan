---
title: Software Requirements Specification for Cooling Fan Controller on ARDUINO/ESP32
author: [Maksym Prokopenko]
version: 1.0
---

# Introduction

## Purpose
The purpose of this Software Requirements Specification (SRS) document is to provide a detailed description of the Cooling Fan Controller project, which is built on the ARDUINO/ESP32 platform. This document outlines the system architecture, structure of project components, and specific product requirements to ensure the project meets its intended functionality.

## References {#ref}
- ARDUINO official documentation: [https://www.arduino.cc/en/Guide/HomePage](https://www.arduino.cc/en/Guide/HomePage)
- ESP32 official documentation: [https://docs.espressif.com/projects/esp-idf/en/latest/](https://docs.espressif.com/projects/esp-idf/en/latest/)
- PlatformIO documentation: [https://docs.platformio.org/en/latest/](https://docs.platformio.org/en/latest/)
- Wokwi simulator documentation: [https://docs.wokwi.com/](https://docs.wokwi.com/)

# Terminology {#term}

## Definitions

| Term                    | Definition                                        |
|-------------------------|--------------------------------------------------|
| PWM                     | Pulse Width Modulation                           |
| ESP32                   | A powerful Wi-Fi and Bluetooth-enabled microcontroller |
| Arduino Framework       | An open-source electronics platform based on easy-to-use hardware and software |
| Wokwi Simulator         | A web-based simulator for electronics projects   |
| PlatformIO              | An open-source ecosystem for embedded development |

## Abbreviations

| Abbreviation | Description |
|--------------|-------------|
| SRS          | Software Requirements Specification |
| PWM          | Pulse Width Modulation              |
| ESP32        | A Wi-Fi and Bluetooth-enabled microcontroller |
| IDE          | Integrated Development Environment  |

# System Overall Description {#overall}

## Product Overview
The Cooling Fan Controller project aims to regulate the speed of a cooling fan based on temperature readings from a sensor. The system is built using the Arduino framework on the ESP32 microcontroller, utilizing PWM signals for fan control. The primary goal is to maintain a desired temperature range dynamically.

## Product Functions
- Use PWM signals to adjust the cooling fan speed.
- Read temperature data from a connected sensor.
- Dynamically control fan speed to maintain the desired temperature range.
- Provide logging and debugging information via a serial monitor.

## Constraints

**Implementation restrictions**
- Must be developed using the Arduino framework and deployed on the ESP32 microcontroller.
- The system should use a 5V/12V PWM fan and DHT11/DHT22 temperature sensor.
- Use PlatformIO as the development environment.

**Resource limits**
- Limited processing power and memory of the ESP32 microcontroller.
- Dependence on external power supply for the cooling fan.

**Data limits**
- Temperature data limited by the accuracy and range of the DHT11/DHT22 sensor.

## Assumption and Dependencies
- The project assumes availability of a stable 5V/12V power supply for the cooling fan.
- The system is dependent on the Arduino framework, ESP32 microcontroller, and PlatformIO extension for development and deployment.
- Wokwi simulator is optional but recommended for simulation and testing purposes.

# Specific Requirements

## Interfaces

### Hardware Interfaces
- **Microcontroller**: ESP32
  - PWM pin connected to the fan control wire.
  - Analog input pin connected to the temperature sensor.
- **Cooling Fan**: 5V/12V PWM Fan
  - Requires a 10 kΩ pull-up resistor for the tachometer signal.
  - External power supply.

### Software Interfaces
- **PlatformIO Extension**: For building and uploading the project to the ESP32.
- **Serial Monitor**: For viewing logs and debug messages.

## Functional Requirements

- **Fan Speed Control**
  - The system must generate PWM signals to control the fan speed.
  - The fan speed should adjust dynamically based on temperature readings.

- **Temperature Monitoring**
  - The system must read temperature data from the DHT11/DHT22 sensor.
  - The temperature readings should be processed to determine the appropriate fan speed.

- **Simulation and Testing**
  - The system should support simulation using the Wokwi simulator.

# Data Requirements
- The system must log temperature readings and fan speed adjustments.
- Data should be accessible via the serial monitor for debugging purposes.
