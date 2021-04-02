#include "Common.h"
#include <gtest/gtest.h>

TEST(MathTests, PhiTest1)
{
   srand (0);
   for(int x = 0; x < 100000; ++x)
   {
      int64_t n = 1 + rand() % 1000000;
      int64_t a = rand() % n;
      int64_t g = gcd(n, a);
      n /= g;
      a /= g;
      EXPECT_TRUE(a==0 || power_mod(a, phi(n), n) == 1);
   }
}
