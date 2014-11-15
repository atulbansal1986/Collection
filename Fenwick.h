#include <bits/stdc++.h>

using namespace std;

class Fenwick
{
      vector<int> bit;
      int sz;

   public:
      Fenwick(int n)
      {
         bit.resize(n+1, 0);
         sz = n;
      }

      int getSum(int at)
      {
         int res = 0;
         for (int i = at; i > 0; i -= (i & -i))
         {
            res += bit[i];
         }
         return res;
      }

      void update(int at, int by)
      {
         for(int i = at; i <= sz; i += (i & -i)) bit[i] += by;
      }

};
