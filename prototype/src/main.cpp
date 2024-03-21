#include <Arduino.h>

#include "config.h"
#include "log.h"
#include "Fan.h"
#include "TemperatureSensor.h"
#include "arduino-timer.h"

Fan fan(TACHOPIN, TACHOUPDATECYCLE, NUMBEROFINTERRUPSINONESINGLEROTATION, PWMPIN, PWMCHANNEL, PWMRESOLUTION, PWMFREQ, INITIALPWMVALUE);
TemperatureSensor temp_sensor(TEMPPIN, TEMPSENSOR, TEMPUPDATEFREQ);

Timer<2> timer;

// Mode of fan speed enum (slow, medium, fast)
enum FanSpeedMode
{
  slow,
  medium,
  fast
};

// array of fan speed modes pwm values
int fan_speeds[] = {SLOWPWMVALUE, MEDIUMPWMVALUE, FASTPWMVALUE};

FanSpeedMode mode = slow;

bool changeMode()
{
  float temperature = temp_sensor.getTemperature();

  FanSpeedMode previousMode = mode;

  if (temperature > 40)
  {
    mode = fast;
  }
  else if (temperature > 30)
  {
    mode = medium;
  }
  else
  {
    mode = slow;
  }

  if (mode == previousMode)
  {
    Log.printf("Mode not changed. Still %d\r\n", mode);
  }
  else
  {
    fan.setPWMValue(fan_speeds[mode]);
    Log.printf("Mode changed to %d\r\n", mode);
  }
  return true;
}

bool doLog(void)
{
  Log.printf("fan rpm = %d, fan pwm = %d, temp = %f, mode = %d\r\n", fan.getRPM(), fan.getPWMValue(), temp_sensor.getTemperature(), mode);
  return true;
}

void setup()
{
  Serial.begin(115200);
  Serial.println("");
  Log.printf("Setting things up ...\r\n");
  fan.init();
  fan.setPWMValue(fan_speeds[mode]);
  temp_sensor.init();

  // set up timer
  timer.every(10000, std::bind(&changeMode));

  timer.every(1000, std::bind(&doLog));

  Log.printf("Settings done. Have fun.\r\n");
}

void loop()
{
  // functions that shall be called as often as possible
  // these functions should take care on their own that they don't nee too much time
  fan.update();
  temp_sensor.update();
  timer.tick();
}