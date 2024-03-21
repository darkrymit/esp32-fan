
#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

#include "Arduino.h"
#include <DHT.h>
#include <arduino-timer.h>

class TemperatureSensor
{
public:
    TemperatureSensor(uint8_t temp_pin, uint8_t temp_sensor_type, uint32_t temp_update_freq);

    ~TemperatureSensor();


    void init(void);
    void update(void);

    float getTemperature(void);
    
    uint8_t getTemperatureSensorType(void);
    
    uint32_t getTempUpdateFreq(void);

private:
    Timer<1> timer;
    DHT* dht;

    uint8_t temp_pin;
    uint8_t temp_sensor_type;
    uint32_t temp_update_freq;
    float last_temperature;
    bool processTemperature(void);
};

#endif
