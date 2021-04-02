#include "Common.h"
#include <gtest/gtest.h>

TEST(MathTests, InvTest)
{
   srand(0);
   for (int64_t i = 0; i < 100000; ++i)
   {
      int64_t a = rand() % 100000;
      int64_t n = 1 + rand() % 100000;
      a = a % n;
      int64_t inverse = inv(a, n);
      if (a == 0)
      {

      } 
      else if (gcd(a, n) != 1)
      {
         // Not relatively prime, no inverse
         EXPECT_EQ(inverse, -1);
      } 
      else
      {
         EXPECT_EQ((inverse * a) % n, 1);
      }
   }
}


TEST(MathTests, InvExpTest)
{
   for (int64_t i = 0; i < 100000; ++i)
   {
      int64_t a = rand() % 100000;
      int64_t n = 1 + rand() % 100000;
      a = a % n;
      int64_t inverse = invExp(a, n);
      if (a == 0)
      {

      }
      // not relatively prime, no inverse
      else if (gcd(a, n) != 1)
      {
      } 
      else
      {
         EXPECT_EQ((inverse * a) % n, 1);
      }
   }
}


TEST(MathTests, InvALLTest)
{
   for (int64_t i = 0; i < 100; ++i)
   {
      int64_t n = 1 + rand() % 10000;
      if (!isPrime(n))
         continue;

      vector<int64_t> R(n, 0);
      invALL(R);

      for(int64_t x = 0; x < n; ++x)
      {
         if (x == 0)
         {

         }
         // not relatively prime, no inverse
         else if (gcd(x, n) != 1)
         {
            EXPECT_EQ(R[x], 0);
         }
         else
         {
            EXPECT_EQ((R[x] * x) % n, 1);
         }
      }
   }
}
