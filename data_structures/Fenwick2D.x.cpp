#include "Fenwick2D_v2.h"

int main()
{
   srand (0);
   int rows = 200;
   int cols = 20;
   Fenwick2D f(rows, cols);

   vector<vector<int> > A;
   vector<vector<int> > Cum;
   A.resize(rows+1);
   Cum.resize(rows+1);
   for(int i=0;i<=rows;i++)
   {
      A[i].resize(cols+1);
      Cum[i].resize(cols+1);
   }

   for (int i = 1; i <= rows; i++)
      for (int j = 1; j <= cols; j++)
      {
         A[i][j] = rand() % 100;
         f.update(i, j, A[i][j]);
      }

   for (int i = 1; i <= rows; i++)
      for (int j = 1; j <= cols; j++)
      {
         Cum[i][j] = Cum[i - 1][j] + Cum[i][j - 1] - Cum[i - 1][j - 1] + A[i][j];
      }

   cout << " Array A" << endl;
   for (int i = 1; i <= rows; i++)
   {
      for (int j = 1; j <= cols; j++)
      {
         cout << A[i][j] << " ";
      }
      cout << endl;
   }

   cout << "Cum array " << endl;
   for (int i = 1; i <= rows; i++)
   {
      for (int j = 1; j <= cols; j++)
      {
         cout << Cum[i][j] << " ";
      }
      cout << endl;
   }

   bool pass = true;
   for (int i = 1; i <= rows; i++)
   {
      for (int j = 1; j <= cols; j++)
      {
         int curr = f.getSum(i, j);
         if (curr != Cum[i][j])
            pass = false;
      }
   }
   if (pass)
      cout << "Test OK" << endl;
   else
      cout << "Test failed" << endl;
   cout << endl;

   return 0;
}
