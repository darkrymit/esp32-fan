/*
  Before changing anything in this file, consider to copy file "config_local.h.example" to file "config_local.h" and to do your changes there.
  Doing so, you will
  - keep your credentials secret
  - most likely never have conflicts with new versions of this file
  Any define in CAPITALS can be moved to "config_local.h".
  All defines having BOTH lowercase and uppercase MUST stay in "config.h".
*/

#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <driver/gpio.h>
#include <esp32-hal-gpio.h>


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

// --- Serial Debug output ----------------------------------------------------------------------------------------------------------------------------
#define useSerial

// --- main settings ----------------------------------------------------------------------------------------------------------------------------
#define SLOWPWMVALUE 170
#define MEDIUMPWMVALUE 200
#define FASTPWMVALUE 250

// --- Temp sensor ----------------------------------------------------------------------------------------------------------------------------

#define TEMPPIN GPIO_NUM_4
#define TEMPSENSOR DHT11
#define TEMPUPDATEFREQ 1000

// --- include override settings from seperate file ---------------------------------------------------------------------------------------------------------------
#if __has_include("config_local.h")
  #include "config_local.h"
#endif

#endif /*__CONFIG_H__*/
