#include "Common.h"
#include <gtest/gtest.h>

int64_t powtest(int64_t a, int64_t b, int64_t mod)
{
   int64_t rem = 1;
   for(int64_t i = 0;i < b; ++i)
   {
      rem = (rem * a) % mod;
   }
   return rem;
}

TEST(MathTests, PowerTest1)
{
   EXPECT_EQ(power(1199, 2), int64_t(pow(1199, 2)));
}


TEST(MathTests, PowerTest2)
{
   EXPECT_EQ(power_mod(1199, 22, 10000007), powtest(1199, 22, 10000007));
}

TEST(MathTests, PowerTest3)
{
   EXPECT_EQ(power_mod(1199, 29, 10000007), powtest(1199, 29, 10000007));
}

TEST(MathTests, PowerTest4)
{
   EXPECT_EQ(power(21239, 2), int64_t (pow(21239, 2)));
}


/************* templated power **********************/
TEST(MathTests, PowerTest5)
{
   EXPECT_EQ(power<int64_t>(1199, 2), int64_t(pow(1199, 2)));
}

TEST(MathTests, PowerTest6)
{
   EXPECT_EQ(power<int64_t>(21239, 2), int64_t(pow(21239, 2)));
}
/************* end templated power **********************/
