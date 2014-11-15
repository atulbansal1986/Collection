#include "Fenwick.h"

class Fenwick2D
{
   vector<Fenwick> bit;
   int rows;
   int cols;

public:
   Fenwick2D(int r, int c)
   {
      rows = r;
      cols = c;
      bit.resize(r+1, Fenwick(cols));
   }

   int getSum(int atx, int aty)
   {
      int res = 0;
      for (int x = atx; x > 0; x -= (x & -x))
         res += bit[x].getSum(aty);
      return res;
   }

   void update(int atx, int aty, int by)
   {
      for (int x = atx; x <= rows; x += (x & -x))
         bit[x].update(aty, by);
   }
};
