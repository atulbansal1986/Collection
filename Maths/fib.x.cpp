#include "Common.h"

int main()
{
   srand (0);
   for(int i=0;i<10000;++i)
   {
      int n = rand() % 60;
      if (fib(n) != fibFast(n))
      {
         cout << "Test failed for " << n << endl;
         exit(0);
      }
   }
   cout << "All tests OK" << endl;

	return 0;
}
