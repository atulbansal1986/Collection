#include "FenwickRange_v2.h"

int main()
{
   srand (0);
   int n = 20;
   int num_tests = 100000;
   FenwickRange f(n);

   vector<int> A(n + 1, 0);
   vector<int> Cum(n + 1, 0);
   for (int i = 1; i <= n; i++)
   {
      A[i] = rand() % 100;
      f.update(i, i, A[i]);
   }

   for(int i=1;i<num_tests;i++)
   {
      int left = 1 + rand() % n;
      int right = 1 + rand() % n;
      if (left > right) swap(left, right);
      int by = (rand() % 100) - 50;
      f.update(left, right, by);
      for (int x=left;x<=right;x++)
      {
         A[x] += by;
      }
   }

   for(int i=1;i<n;i++)
   {
      Cum[i] = Cum[i-1] + A[i];
   }

   for (int i = 1; i <= n; i++)
   {
      cout << A[i] << " ";
   }
   cout << endl;

   bool pass = true;
   for (int i = 1; i <= n; i++)
   {
      int curr = f.getSum(i) - f.getSum(i - 1);
      cout << f.getSum(i) - f.getSum(i-1) << " ";
      if (curr != A[i])
         pass = false;
   }
   cout << endl;
   if (pass)
      cout << "Test OK" << endl;
   cout << endl;

   return 0;
}
