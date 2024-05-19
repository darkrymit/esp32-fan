#include <gtest/gtest.h>

TEST(SetupTest, ShouldPassIfArduinoIsIncluded)
{
    #ifndef ARDUINO
    FAIL();
    #else
    SUCCEED();
    #endif
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
