#include <bits/stdc++.h>

using namespace std;

class Fenwick2D
{
   vector<vector<int> > bit;
   int rows;
   int cols;

public:
   Fenwick2D(int r, int c)
   {
      rows = r;
      cols = c;
      bit.resize(r+1);
      for (int i = 0; i <= rows; i++)
      {
         bit[i].resize(c + 1, 0);
      }
   }

   int getSum(int atx, int aty)
   {
      int res = 0;
      for (int x = atx; x > 0; x -= (x & -x))
         for (int y = aty; y > 0; y -= (y & -y))
         {
            res += bit[x][y];
         }
      return res;
   }

   void update(int atx, int aty, int by)
   {
      for (int x = atx; x <= rows; x += (x & -x))
         for (int y = aty; y <= cols; y += (y & -y))
         {
            bit[x][y] += by;
         }
   }
};
