#include "Common.h"

LL powtest(LL a, LL b, LL mod)
{
   LL rem = 1;
   for(int i=0;i<b;i++)
   {
      rem = (rem * a) % mod;
   }
   return rem;
}

int main()
{
   if (power(1199, 2) == LL (pow(1199, 2)))
   {
      cout << "Test 1 OK " << endl;
   }

   if (power(1199, 22, 10000007) == powtest(1199, 22, 10000007))
   {
      cout << "Test 2 OK " << endl;
   }

   if (power(1199, 29, 10000007) == powtest(1199, 29, 10000007))
   {
      cout << "Test 3 OK " << endl;
   }

   if (power(21239, 2) == LL (pow(21239, 2)))
   {
      cout << "Test 4 OK " << endl;
   }

   /************* templated power **********************/
   if (power<LL>(1199, 2) == LL (pow(1199, 2)))
   {
      cout << "Test 5 OK " << endl;
   }

   if (power<LL>(21239, 2) == LL (pow(21239, 2)))
   {
      cout << "Test 6 OK " << endl;
   }
   /************* end templated power **********************/


	return 0;
}
