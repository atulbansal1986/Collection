#include "Common.h"
#include <gtest/gtest.h>

TEST(MathTests, PrimeTest1)
{
   EXPECT_TRUE(isPrime(19));
}

TEST(MathTests, PrimeTest2)
{
   EXPECT_FALSE(isPrime(9));
}

TEST(MathTests, PrimeTest3)
{
   EXPECT_TRUE(isPrime(101));
}

TEST(MathTests, PrimeTest4)
{
   EXPECT_FALSE(isPrime(13*101));
}

TEST(MathTests, PrimeSeive)
{
   constexpr int n = 10000;
   std::array<int, n> A;
   buildPrimes<int, n>(A);
   for(int i=2;i<n;i++)
   {
      EXPECT_EQ((A[i]==1), isPrime(i));
   }
}

   
