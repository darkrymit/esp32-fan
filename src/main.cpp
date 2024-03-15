#include <Arduino.h>

#include "config.h"
#include "log.h"
#include "Fan.h"
#include "arduino-timer.h"

Fan fan(TACHOPIN, TACHOUPDATECYCLE, NUMBEROFINTERRUPSINONESINGLEROTATION, PWMPIN, PWMCHANNEL, PWMRESOLUTION, PWMFREQ, INITIALPWMVALUE);

Timer<2> timer;

// Mode of fan speed enum (SLOW,MEDIUM,FAST)
enum fanSpeedMode {SLOW, MEDIUM, FAST};

// array of fan speed modes pwm values
int fanSpeeds[] = {SLOWPWMVALUE, MEDIUMPWMVALUE, FASTPWMVALUE};

fanSpeedMode mode = SLOW;


bool changeMode(){
  if (mode == SLOW) {
      mode = MEDIUM;
    } else if (mode == MEDIUM) {
      mode = FAST;
    } else if (mode == FAST) {
      mode = SLOW;
    }
    fan.setPWMValue(fanSpeeds[mode]);

    Log.printf("Mode changed to %d\r\n", mode);
  return true;
}

bool doLog(void){
  Log.printf("fan rpm = %d, fan pwm = %d\r\n", fan.getRPM(), fan.getPWMValue());
  return true;
}

void setup(){
  Serial.begin(115200);
  Serial.println("");
  Log.printf("Setting things up ...\r\n");
  fan.init();
  fan.setPWMValue(fanSpeeds[mode]);

  // set up timer
  timer.every(10000, std::bind(&changeMode));

  timer.every(1000, std::bind(&doLog));

  Log.printf("Settings done. Have fun.\r\n");
}

void loop(){
  // functions that shall be called as often as possible
  // these functions should take care on their own that they don't nee too much time
  fan.update();
  timer.tick(); 
}