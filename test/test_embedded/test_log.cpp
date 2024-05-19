#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <Arduino.h>
#include "log.h"

TEST(LogTest, CanLog)
{
  size_t len = 0;
  
  len = Log.printf("Hello, world!\r\n");
  
  // check if the number of characters written is greater than 0 (i.e. something was written)
  // actual value is unimportant
  EXPECT_GT(len, 0);
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
