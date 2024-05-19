#include <Arduino.h>

#include "log.h"
#include <DHT.h>
#include "TemperatureSensor.h"

TemperatureSensor::TemperatureSensor(uint8_t temp_pin, uint8_t temp_sensor_type, uint32_t temp_update_freq)
{
    this->temp_pin = temp_pin;
    this->temp_sensor_type = temp_sensor_type;
    this->temp_update_freq = temp_update_freq;
    this->last_temperature = 0.0;
    this->dht = new DHT(temp_pin, temp_sensor_type); // Fix: Create a dynamic instance of DHT
}

TemperatureSensor::~TemperatureSensor()
{
    delete dht;
}

void TemperatureSensor::init(void)
{
    dht->begin();
    delay(1000); // wait for sensor to initialize
    Log.printf("  Temperature sensor sucessfully initialized.\r\n");
    timer.every(temp_update_freq, std::bind(&TemperatureSensor::processTemperature, this));
}

void TemperatureSensor::update(void)
{
    timer.tick();
}

float TemperatureSensor::getTemperature(void)
{
    return last_temperature;
}

uint8_t TemperatureSensor::getTemperatureSensorType(void)
{
    return temp_sensor_type;
}

uint32_t TemperatureSensor::getTempUpdateFreq(void)
{
    return temp_update_freq;
}

bool TemperatureSensor::processTemperature(void)
{
    last_temperature = dht->readTemperature();
    return true;
}