#include "Common.h"

int main()
{
   if (isPrime(19) == true)
   {
      cout << "Test 1 OK" << endl;
   }

   if (isPrime(9) == false)
   {
      cout << "Test 2 OK" << endl;
   }

   if (isPrime(101) == true)
   {
      cout << "Test 3 OK" << endl;
   }

   if (isPrime(13*101) == false)
   {
      cout << "Test 4 OK" << endl;
   }

   constexpr int n = 10000;
   std::array<int, n> A;
   buildPrimes<int, n>(A);
   bool fail = false;
   for(int i=2;i<n;i++)
   {
      if ((A[i]==1) ^ isPrime(i)) { cout << i << " " << A[i] << " " << isPrime(i) << endl; fail = true; }
   }

   if (!fail)
   {
      cout << "Test Seive OK " << endl;
   }
   else
   {
      cout << "Test Seive Fail" << endl;
   }

   return 0;
}
