#include "Common.h"
#include <gtest/gtest.h>

TEST(MathTests, FactorialTest)
{
	EXPECT_EQ(fact(5, 1000), 120);
}

TEST(MathTests, LCMTest)
{
	EXPECT_EQ(lcm(15, 6), 30);
}
