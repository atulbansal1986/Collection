#include "Fenwick.h"

using namespace std;

class FenwickRange
{
   Fenwick m_sum;
   Fenwick m_mul;
   int sz;

   void internalUpdate(int at, int mul, int sum)
   {
      m_sum.update(at, sum);
      m_mul.update(at, mul);
   }

public:
   FenwickRange(int n) : m_sum(n), m_mul(n)
   {
      sz = n;
   }

   int getSum(int at)
   {
      int sum = m_sum.getSum(at);
      int mul = m_mul.getSum(at);
      return sum + mul * at;
   }

   void update(int left, int right, int by)
   {
      internalUpdate(left, by, -by * (left - 1));
      internalUpdate(right, -by, by * right);
   }
};
