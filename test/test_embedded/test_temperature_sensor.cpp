#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <Arduino.h>
#include "TemperatureSensor.h"

// --- Temp sensor ----------------------------------------------------------------------------------------------------------------------------

#define TEMPPIN GPIO_NUM_4
#define TEMPSENSOR DHT11
#define TEMPUPDATEFREQ 1000


TEST(TemperatureSensorTest, CanStoreTemperatureSensorType)
{
  TemperatureSensor sensor(TEMPPIN, TEMPSENSOR, TEMPUPDATEFREQ);

  EXPECT_EQ(sensor.getTemperatureSensorType(), TEMPSENSOR);
}

TEST(TemperatureSensorTest, CanStoreTempUpdateFreq)
{
  TemperatureSensor sensor(TEMPPIN, TEMPSENSOR, TEMPUPDATEFREQ);

  EXPECT_EQ(sensor.getTempUpdateFreq(), TEMPUPDATEFREQ);
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
