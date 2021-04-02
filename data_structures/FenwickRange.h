#include <bits/stdc++.h>

using namespace std;

class FenwickRange
{
   vector<int> dataSum;
   vector<int> dataMul;
   int sz;

   void internalUpdate(int at, int mul, int sum)
   {
      for (int i = at; i <= sz; i += (i & -i))
      {
         dataSum[i] += sum;
         dataMul[i] += mul;
      }
   }

public:
   FenwickRange(int n)
   {
      dataSum.resize(n + 1, 0);
      dataMul.resize(n + 1, 0);
      sz = n;
   }

   int getSum(int at)
   {
      int start = at;
      int sum = 0;
      int mul = 0;
      for (int i = at; i > 0; i -= (i & -i))
      {
         sum += dataSum[i];
         mul += dataMul[i];
      }
      return sum + mul * start;
   }

   void update(int left, int right, int by)
   {
      internalUpdate(left, by, -by * (left - 1));
      internalUpdate(right, -by, by * right);
   }
};
