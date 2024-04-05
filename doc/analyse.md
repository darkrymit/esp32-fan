# Analysis of analogues

### [ESP32 fan controller with MQTT support](https://github.com/KlausMu/esp32-fan-controller/tree/main)
**Pros:**

1. **Two Operating Modes:** The project offers two operating modes: fan mode and climate control mode. This allows users to choose the mode that best suits their needs and situation.

2. **PWM and Automatic Regulation Support:** The project allows users to set fan speed either manually through PWM signal or automatically based on temperature conditions.

3. **Parameter Measurements:** Built-in capabilities for measuring fan speed and ambient values such as temperature, humidity, and pressure ensure precise control and adjustment of room conditions.

4. **MQTT Support:** Integration with the MQTT protocol enables easy interaction with the fan controller from other devices and systems supporting this protocol.

5. **OTA Support:** Over-the-air firmware update functionality allows updating the fan controller directly from the network, making the update process convenient and user-friendly.

6. **TFT Display Support:** The presence of a TFT display for showing status information, ambient conditions, and the selected target temperature makes the fan controller more user-friendly and monitorable.

7. **Integration with Home Automation Systems:** The project supports integration with home automation systems such as Home Assistant or openHAB, making it part of a smart home.

**Cons:**

1. **Additional Components Required:** Some features of the project require additional hardware such as temperature sensors, TFT display, and others, which can increase overall costs and assembly complexity.

2. **Configuration Complexity:** Using certain features such as OTA setup or integration with applications may require additional knowledge and time for configuration.

3. **Software Dependency:** Updating or changing the software may affect the functionality of the controller, especially if users are not proficient in effectively managing these changes.

<hr/>

### [Fan Controller](https://github.com/ellull/fan-controller/tree/main)
**Pros:**

- **Home Assistant Integration:** The fan controller is integrable with Home Assistant, allowing for seamless incorporation into home automation setups.
- **Fan Speed Control:** Users can control the speed of the fan, providing flexibility in managing ventilation and noise levels.
- **RPM Sensor:** The controller features an RPM sensor, enabling monitoring and adjustment of fan performance.
- **Temperature Sensors:** Temperature sensors are included, allowing for monitoring of ambient temperature conditions.
- **Extensibility:** The controller supports connecting other I2C devices, such as screens or additional sensors, enhancing its functionality.
- **Physical Button:** A physical button is provided for toggling the fan, offering a convenient manual control option.
- **Future Expansion:** The controller exposes 8 additional GPIO pins for future extensibility, enabling further customization and enhancements.

**Cons:**

- **Limited Current Status:** The Gerber file for PCB production is awaiting arrival and testing, potentially delaying verification of hardware functionality.
- **Future Feature Completion:** Some planned features, such as physical buttons for adjusting fan speed and an alarm LED, are listed as future enhancements, suggesting that these capabilities are not yet implemented.
- **Hardware Assembly Required:** Building the fan controller requires ordering PCBs and components, as well as assembly, which may present a barrier to entry for some users.
- **Software Installation and Integration:** Users need to install the latest firmware and integrate the controller into Home Assistant, which may require technical knowledge and configuration effort.
- **ESPHome Compatibility Development:** The project required development work to add support for the Adafruit EMC2101 to ESPHome, which added complexity and potentially extended the development timeline.
- **Voltage-Level Shifter Requirement:** Due to differences in voltage levels between components, a bidirectional voltage-level shifter is needed, adding an additional component and potential complexity to the hardware setup.
- **Personal Project Limitation:** While the project meets the creator's personal needs for ventilation and temperature monitoring in a cabinet, its applicability to broader use cases may vary depending on individual requirements.

