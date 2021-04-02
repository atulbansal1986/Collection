#include "Common.h"
#include <gtest/gtest.h>

TEST(MathTests, GCDTest1)
{
   EXPECT_EQ(gcd(9,6), 3);
}

TEST(MathTests, GCDTest2)
{
   EXPECT_EQ(gcd(19,6), 1);
}

TEST(MathTests, GCDTest3)
{
   EXPECT_EQ(gcd(60,72), 12);
}

TEST(MathTests, GCDTest4)
{
   EXPECT_EQ(gcd(60,60), 60);
}

TEST(MathTests, GCDTest5)
{
   srand (0);
   for(int i=0;i<100000;++i)
   {
      int64_t x,y;
      int64_t a = rand() % 100000;
      int64_t b = rand() % 100000;
      int64_t g = gcdExt(a,b,x,y);
      EXPECT_EQ(g, x*a + y*b);
   }
}
   