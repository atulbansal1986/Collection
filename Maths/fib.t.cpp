#include "Common.h"
#include <gtest/gtest.h>

TEST(MathTests, FibTest)
{
   srand (0);
   for(int i=0;i<10000;++i)
   {
      int n = rand() % 60;
      if (fib(n) != fibFast(n))
      {
         cout << "Test failed for " << n << endl;
         EXPECT_EQ(1, 0);
      }
   }
}
