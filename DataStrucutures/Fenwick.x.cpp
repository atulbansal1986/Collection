#include "Fenwick.h"

int main()
{
   int n = 1000;
   Fenwick f(n);

   vector<int> A(n+1,0);
   vector<int> Cum(n+1,0);
   for(int i=1;i<=n;i++)
   {
      A[i] = rand() % 100;
      f.update(i, A[i]);
      Cum[i] = Cum[i-1] + A[i];
   }

   for(int i=1;i<=n;i++)
   {
      cout << A[i] << " ";
   }
   cout << endl;
//   for(int i=1;i<=n;i++)
//   {
//      cout << Cum[i] << " ";
//   }
//   cout << endl;
   bool pass = true;
   for(int i=1;i<=n;i++)
   {
      int curr = f.getSum(i) - f.getSum(i-1);
      //cout << f.getSum(i) - f.getSum(i-1) << " ";
      if (curr != A[i]) pass = false;
   }
   if (pass)
      cout << "Test OK" << endl;
   else
      cout << "Test failed" << endl;
   cout << endl;

   return 0;
}
