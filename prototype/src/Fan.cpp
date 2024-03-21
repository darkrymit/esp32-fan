#include <Arduino.h>
#include <esp32-hal.h>
#include <esp32-hal-ledc.h>
#include "log.h"
#include "Fan.h"
#include "FunctionalInterrupt.h"

Fan::Fan(uint8_t tacho_pin, uint32_t tacho_update_freq, uint8_t tacho_number_of_pulses_per_revolution, uint8_t pwm_pin, uint8_t pwm_channel, uint8_t pwm_resolution, uint32_t pwm_freq, int pwm_initial_value)
{
    this->tacho_pin = tacho_pin;
    this->tacho_update_freq = tacho_update_freq;
    this->tacho_number_of_pulses_per_revolution = tacho_number_of_pulses_per_revolution;
    this->tacho_rpm_counter = 0;
    this->tacho_last_rpm_counter = 0;
    this->tacho_rpm_interrupt_function_ref = std::bind(&Fan::tachoRPMInterruptFunction, this);

    this->pwm_pin = pwm_pin;
    this->pwm_channel = pwm_channel;
    this->pwm_resolution = pwm_resolution;
    this->pwm_freq = pwm_freq;
    this->pwm_initial_value = pwm_initial_value;
    this->pwm_value = pwm_initial_value;
}

void Fan::init(void)
{
    // configure Tacho pin
    digitalWrite(tacho_pin, HIGH);
    // interrupt on falling edge
    attachInterrupt(digitalPinToInterrupt(tacho_pin), tacho_rpm_interrupt_function_ref, FALLING);
    Log.printf("  Fan tacho detection sucessfully initialized.\r\n");

    // configure PWM pin
    ledcSetup(pwm_channel, pwm_freq, pwm_resolution);
    // attach the channel to the GPIO to be controlled
    ledcAttachPin(pwm_pin, pwm_channel);
    pwm_value = pwm_initial_value;
    Log.printf("  Fan PWM sucessfully initialized.\r\n");

    // configure timer
    timer.every(tacho_update_freq, std::bind(&Fan::tachoProcessRPM, this));
}

void Fan::update(void)
{
    timer.tick();
}

uint32_t Fan::getTachoUpdateFreq(void)
{
    return tacho_update_freq;
}

uint8_t Fan::getTachoNumberOfPulsesPerRevolution(void)
{
    return tacho_number_of_pulses_per_revolution;
}

int Fan::getRPM(void)
{
    return tacho_last_rpm_counter;
}

void Fan::tachoRPMInterruptFunction()
{
    tacho_rpm_counter++;
}

bool Fan::tachoProcessRPM(void)
{
    // detach interrupt while calculating rpm
    detachInterrupt(digitalPinToInterrupt(tacho_pin));

    // calculate rpm
    tacho_last_rpm_counter = tacho_rpm_counter * ((float)60 / (float)tacho_number_of_pulses_per_revolution) * ((float)1000 / (float)tacho_update_freq);

    // reset counter
    tacho_rpm_counter = 0;

    // attach interrupt again
    attachInterrupt(digitalPinToInterrupt(tacho_pin), tacho_rpm_interrupt_function_ref, FALLING);

    return true;
}

void Fan::setPWMValue(int pwm_value)
{
    this->pwm_value = min(max(pwm_value, 0), (int)pow(2, pwm_resolution) - 1);
    ledcWrite(pwm_channel, this->pwm_value);
}

int Fan::getPWMValue(void)
{
    return pwm_value;
}

uint8_t Fan::getPWMChannel(void)
{
    return pwm_channel;
}

uint8_t Fan::getPWMResolution(void)
{
    return pwm_resolution;
}

uint32_t Fan::getPWMFreq(void)
{
    return pwm_freq;
}