#include <Arduino.h>
#include <esp32-hal.h>
#include <esp32-hal-ledc.h>
#include "log.h"
#include "Fan.h"
#include "FunctionalInterrupt.h"

Fan::Fan(uint8_t tachoPin, uint32_t tachoUpdateFreq, uint8_t tachoNumberOfPulsesPerRevolution, uint8_t pwmPin, uint8_t pwmChannel, uint8_t pwmResolution, uint32_t pwmFreq, int pwmInitialValue)
{
    this->tachoPin = tachoPin;
    this->tachoUpdateFreq = tachoUpdateFreq;
    this->tachoNumberOfPulsesPerRevolution = tachoNumberOfPulsesPerRevolution;
    this->tachoRPMCounter = 0;
    this->tachoLastRPMCounter = 0;
    this->tachoRPMInterruptFunctionRef = std::bind(&Fan::tachoRPMInterruptFunction, this);

    this->pwmPin = pwmPin;
    this->pwmChannel = pwmChannel;
    this->pwmResolution = pwmResolution;
    this->pwmFreq = pwmFreq;
    this->pwmInitialValue = pwmInitialValue;
    this->pwmValue = pwmInitialValue;
}

void Fan::init(void)
{
    // configure Tacho pin
    digitalWrite(tachoPin, HIGH);
    // interrupt on falling edge
    attachInterrupt(digitalPinToInterrupt(tachoPin), tachoRPMInterruptFunctionRef, FALLING);
    Log.printf("  Fan tacho detection sucessfully initialized.\r\n");

    // configure PWM pin
    ledcSetup(pwmChannel, pwmFreq, pwmResolution);
    // attach the channel to the GPIO to be controlled
    ledcAttachPin(pwmPin, pwmChannel);
    pwmValue = pwmInitialValue;
    Log.printf("  Fan PWM sucessfully initialized.\r\n");

    // configure timer
    timer.every(tachoUpdateFreq, std::bind(&Fan::tachoProcessRPM, this));
}
void Fan::update(void)
{
    timer.tick();
}

uint32_t Fan::getTachoUpdateFreq(void)
{
    return tachoUpdateFreq;
}

uint8_t Fan::getTachoNumberOfPulsesPerRevolution(void)
{
    return tachoNumberOfPulsesPerRevolution;
}

int Fan::getRPM(void)
{
    return tachoLastRPMCounter;
}

void Fan::tachoRPMInterruptFunction()
{
    tachoRPMCounter++;
}

bool Fan::tachoProcessRPM(void)
{

    // detach interrupt while calculating rpm
    detachInterrupt(digitalPinToInterrupt(tachoPin));

    // calculate rpm
    tachoLastRPMCounter = tachoRPMCounter * ((float)60 / (float)tachoNumberOfPulsesPerRevolution) * ((float)1000 / (float)tachoUpdateFreq);

    // reset counter
    tachoRPMCounter = 0;

    // attach interrupt again
    attachInterrupt(digitalPinToInterrupt(tachoPin), tachoRPMInterruptFunctionRef, FALLING);

    return true;
}

void Fan::setPWMValue(int pwmValue)
{
    this->pwmValue = min(max(pwmValue, 0), (int)pow(2, pwmResolution) - 1);
    ledcWrite(pwmChannel, this->pwmValue);
}

int Fan::getPWMValue(void)
{
    return pwmValue;
}

uint8_t Fan::getPWMChannel(void)
{
    return pwmChannel;
}

uint8_t Fan::getPWMResolution(void)
{
    return pwmResolution;
}

uint32_t Fan::getPWMFreq(void)
{
    return pwmFreq;
}