#include "Fenwick2D.h"

class Fenwick2DRange
{
   Fenwick2D m_sum;
   Fenwick2D m_mul;

   void internalUpdate(int atx, int aty, int sum, int mul)
   {
      m_sum.update(atx, aty, sum);
      m_mul.update(atx, aty, mul);
   }

public:
   Fenwick2DRange(int r, int c) : m_sum(r,c), m_mul(r,c)
   {

   }

   int getSum(int atx, int aty)
   {
      int sum = m_sum.getSum(atx, aty);
      int mul = m_mul.getSum(atx, aty);
      return sum + mul * atx * aty;
   }

   void update(int atx1, int aty1, int atx2, int aty2, int by)
   {
      assert(atx1 <= atx2);
      assert(aty1 <= aty2);
      internalUpdate(atx1, aty1, , by);
   }


};
