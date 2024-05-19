#include <gtest/gtest.h>

TEST(SetupTest, ShouldPassIfArduinoIsNotIncluded)
{
    #ifndef ARDUINO
    SUCCEED();
    #else
    FAIL();
    #endif
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
	if (RUN_ALL_TESTS())
	;
	// Always return zero-code and allow PlatformIO to parse results
	return 0;
}