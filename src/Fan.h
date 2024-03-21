
#ifndef FAN_H
#define FAN_H

#include "Arduino.h"
#include <arduino-timer.h>

class Fan
{
public:
    Fan(uint8_t tacho_pin, uint32_t tacho_update_freq, uint8_t tacho_number_of_pulses_per_revolution, uint8_t pwm_pin, uint8_t pwm_channel, uint8_t pwm_resolution, uint32_t pwm_freq, int pwm_initial_value);
    void init(void);
    void update(void);

    uint32_t getTachoUpdateFreq(void);
    uint8_t getTachoNumberOfPulsesPerRevolution(void);
    int getRPM(void);

    void setPWMValue(int pwm_value);
    int getPWMValue(void);
    uint8_t getPWMChannel(void);
    uint8_t getPWMResolution(void);
    uint32_t getPWMFreq(void);

private:
    Timer<2> timer;

    uint8_t tacho_pin;
    uint32_t tacho_update_freq;
    uint8_t tacho_number_of_pulses_per_revolution;
    volatile int tacho_rpm_counter;
    int tacho_last_rpm_counter;
    std::function<void(void)> tacho_rpm_interrupt_function_ref;
    void IRAM_ATTR tachoRPMInterruptFunction();
    bool tachoProcessRPM(void);

    uint8_t pwm_pin;
    uint8_t pwm_channel;
    uint8_t pwm_resolution;
    uint32_t pwm_freq;
    int pwm_initial_value;
    int pwm_value;
};

#endif
