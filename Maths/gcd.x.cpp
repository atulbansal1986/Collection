#include "Common.h"

int main()
{
   if (gcd(9,6) == 3)
   {
      cout << "Test 1 OK" << endl;
   }

   if (gcd(19,6) == 1)
   {
      cout << "Test 2 OK" << endl;
   }

   if (gcd(60,72) == 12)
   {
      cout << "Test 3 OK" << endl;
   }

   if (gcd(60,60) == 60)
   {
      cout << "Test 4 OK" << endl;
   }

   srand (0);
   for(int i=0;i<100000;++i)
   {
      LL x,y;
      LL a = rand() % 100000;
      LL b = rand() % 100000;
      LL g = gcdExt(a,b,x,y);
      if (g != x*a + y*b)
      {
         cout << "Test fail" << endl;
      }
   }
   cout << "All gcdExt Tests passed!" << endl;

   return 0;
}
