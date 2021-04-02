#include "DSU.h"
#include <gtest/gtest.h>

TEST(MathTests, FactorialTest)
{
	int n = 100;
	DSU dsu(n);
	dsu.join(1,2);
	EXPECT_TRUE(dsu.connected(1,2));
	EXPECT_FALSE(dsu.connected(1,3));
}