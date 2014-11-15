#include "DSU.h"

int main()
{
   int n = 100;
   DSU dsu(n);
   dsu.join(1,2);
   if (dsu.connected(1,2) == true)
      cout << "Test 1 OK" << endl;
   if (dsu.connected(1,3) == false)
         cout << "Test 2 OK" << endl;
   return 0;
}
