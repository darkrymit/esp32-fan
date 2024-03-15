
#ifndef FAN_H
#define FAN_H

#include "Arduino.h"
#include <arduino-timer.h>

class Fan
{
public:
    Fan(uint8_t tachoPin,uint32_t tachoUpdateFreq, uint8_t tachoNumberOfPulsesPerRevolution, uint8_t pwmPin, uint8_t pwmChannel,uint8_t pwmResolution, uint32_t pwmFreq, int pwmInitialValue);
    void init(void);
    void update(void);

    uint32_t getTachoUpdateFreq(void);
    uint8_t getTachoNumberOfPulsesPerRevolution(void);
    int getRPM(void);
    
    void setPWMValue(int pwmValue);
    int getPWMValue(void);
    uint8_t getPWMChannel(void);
    uint8_t getPWMResolution(void);
    uint32_t getPWMFreq(void);
    
private:
    Timer<2> timer;

    uint8_t tachoPin;
    uint32_t tachoUpdateFreq;
    uint8_t tachoNumberOfPulsesPerRevolution;
    volatile int tachoRPMCounter;
    int tachoLastRPMCounter;
    std::function<void(void)> tachoRPMInterruptFunctionRef;
    void IRAM_ATTR tachoRPMInterruptFunction();
    bool tachoProcessRPM(void);

    uint8_t pwmPin;
    uint8_t pwmChannel;
    uint8_t pwmResolution;
    uint32_t pwmFreq;
    int pwmInitialValue;
    int pwmValue;
};

#endif
