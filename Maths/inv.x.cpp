#include "Common.h"

int main()
{
   srand(time(NULL));
   for (LL i = 0; i < 100000; ++i)
   {
      LL x, y;
      LL a = rand() % 100000;
      LL n = 1 + rand() % 100000;
      a = a % n;
      LL inverse = inv(a, n);
      if (a == 0)
      {

      } else if (gcd(a, n) != 1)
      {
         // Not relatively prime, no inverse
         if (inverse != -1)
         {
            cout << "Test fail case 1" << endl;
            exit(0);
         }
      } else if ((inverse * a) % n != 1)
      {
         cout << "Test fail case 2 " << inverse << " " << a << " " << n << endl;
         exit(0);
      }
   }
   cout << "All inv Tests passed!" << endl;

   for (LL i = 0; i < 100000; ++i)
   {
      LL a = rand() % 100000;
      LL n = 1 + rand() % 100000;
      a = a % n;
      LL inverse = invExp(a, n);
      if (a == 0)
      {

      }
      // not relatively prime, no inverse
      else if (gcd(a, n) != 1)
      {
      } else if ((inverse * a) % n != 1)
      {
         cout << "Test fail case 3 " << inverse << " " << a << " " << n << endl;
         exit(0);
      }
   }
   cout << "All invExp Tests passed!" << endl;

   for (LL i = 0; i < 100; ++i)
   {
      LL n = 1 + rand() % 10000;
      if (!isPrime(n))
         continue;

      LL R[n];
      invAll(R, n);

      for(LL x=0;x<n;x++)
      {
         if (x == 0)
         {

         }
         // not relatively prime, no inverse
         else if (gcd(x, n) != 1)
         {
            if (R[x] != 0)
            {
               cout << "Test fail 4" << R[x] << " " << x << " " << n << endl;
            }
         }
         else if ((R[x] * x) % n != 1)
         {
            cout << "Test fail case 5 " << R[x] << " " << x << " " << n << endl;
            exit(0);
         }
      }
   }
   cout << "All invAll Tests passed!" << endl;

   return 0;
}
