#define GTEST_DECLARES_MAIN

#include "../src/main.cpp"
#include <gtest/gtest.h>
using namespace std;
using namespace testing;

TEST(highest_power_of_2, simple)
{
    ASSERT_EQ(8, highest_power_of_2(9));
    ASSERT_EQ(64, highest_power_of_2(64));
}

TEST(get_last_candle, examples)
{
    ASSERT_EQ(1, get_last_candle(2));
    ASSERT_EQ(5, get_last_candle(10));
    ASSERT_EQ(19, get_last_candle(25));
}

int main(int argc, char *argv[])
{
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}