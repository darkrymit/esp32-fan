#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <Arduino.h>
#include "Fan.h"

// --- fan specs ----------------------------------------------------------------------------------------------------------------------------
// fanPWM
#define PWMPIN               GPIO_NUM_17
#define PWMFREQ              25000
#define PWMCHANNEL           0
#define PWMRESOLUTION        8
#define FANMAXRPM            1500         // only used for showing at how many percent fan is running

// fanTacho
#define TACHOPIN                             GPIO_NUM_16
#define TACHOUPDATECYCLE                     1000 // how often tacho speed shall be determined, in milliseconds
#define NUMBEROFINTERRUPSINONESINGLEROTATION 2    // Number of interrupts ESP32 sees on tacho signal on a single fan rotation. All the fans I've seen trigger two interrups.

// initial pwm fan speed on startup (0 <= value <= 255)
#define INITIALPWMVALUE            120

TEST(FanTest, CanStoreTachoUpdateFreq)
{
    Fan fan(TACHOPIN, TACHOUPDATECYCLE, NUMBEROFINTERRUPSINONESINGLEROTATION, PWMPIN, PWMCHANNEL, PWMRESOLUTION, PWMFREQ, INITIALPWMVALUE);

    EXPECT_EQ(fan.getTachoUpdateFreq(), TACHOUPDATECYCLE);
}

TEST(FanTest, CanStoreTachoNumberOfPulsesPerRevolution)
{
    Fan fan(TACHOPIN, TACHOUPDATECYCLE, NUMBEROFINTERRUPSINONESINGLEROTATION, PWMPIN, PWMCHANNEL, PWMRESOLUTION, PWMFREQ, INITIALPWMVALUE);

    EXPECT_EQ(fan.getTachoNumberOfPulsesPerRevolution(), NUMBEROFINTERRUPSINONESINGLEROTATION);
}

TEST(FanTest, CanStorePWMCannel)
{
    Fan fan(TACHOPIN, TACHOUPDATECYCLE, NUMBEROFINTERRUPSINONESINGLEROTATION, PWMPIN, PWMCHANNEL, PWMRESOLUTION, PWMFREQ, INITIALPWMVALUE);

    EXPECT_EQ(fan.getPWMChannel(), PWMCHANNEL);
}

TEST(FanTest, CanStorePWMResolution)
{
    Fan fan(TACHOPIN, TACHOUPDATECYCLE, NUMBEROFINTERRUPSINONESINGLEROTATION, PWMPIN, PWMCHANNEL, PWMRESOLUTION, PWMFREQ, INITIALPWMVALUE);

    EXPECT_EQ(fan.getPWMResolution(), PWMRESOLUTION);
}

TEST(FanTest, CanStorePWMFreq)
{
    Fan fan(TACHOPIN, TACHOUPDATECYCLE, NUMBEROFINTERRUPSINONESINGLEROTATION, PWMPIN, PWMCHANNEL, PWMRESOLUTION, PWMFREQ, INITIALPWMVALUE);

    EXPECT_EQ(fan.getPWMFreq(), PWMFREQ);
}

TEST(FanTest, CanControlFanSpeed)
{
    const int slow_pwm_value = 170;
    const int medium_pwm_value = 200;
    const int fast_pwm_value = 250;

    Fan fan(TACHOPIN, TACHOUPDATECYCLE, NUMBEROFINTERRUPSINONESINGLEROTATION, PWMPIN, PWMCHANNEL, PWMRESOLUTION, PWMFREQ, INITIALPWMVALUE);
    
    EXPECT_EQ(fan.getPWMValue(), INITIALPWMVALUE);
    fan.setPWMValue(slow_pwm_value);
    EXPECT_EQ(fan.getPWMValue(), slow_pwm_value);
    fan.setPWMValue(medium_pwm_value);
    EXPECT_EQ(fan.getPWMValue(), medium_pwm_value);
    fan.setPWMValue(fast_pwm_value);
    EXPECT_EQ(fan.getPWMValue(), fast_pwm_value);
}

void setup()
{
    // should be the same value as for the `test_speed` option in "platformio.ini"
    // default value is test_speed=115200
    Serial.begin(115200);

    ::testing::InitGoogleTest();
    // if you plan to use GMock, replace the line above with
    // ::testing::InitGoogleMock();
}

void loop()
{
  // Run tests
  if (RUN_ALL_TESTS())
  ;

  // sleep for 1 sec
  delay(1000);
}
