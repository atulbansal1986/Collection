#include "Common.h"

int main()
{
   srand (0);
   for(int x = 0; x < 100000; ++x)
   {
      LL n = 1 + rand() % 1000000;
      LL a = rand() % n;
      LL g = gcd(n, a);
      n /= g;
      a /= g;
      if (a==0 || power(a, phi(n), n) == 1) { }
      else
      {
         cout << n << " " << a << " " << phi(n) << " " << isPrime(n) << endl;
         exit(0);
      }
   }

   cout << "All Tests OK" << endl;

   return 0;
}
