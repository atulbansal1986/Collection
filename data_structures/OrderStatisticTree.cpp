#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;


int main()
{
   ios::sync_with_stdio(0);

   ordered_set os;

   os.insert(1);
   os.insert(2);
   os.insert(5);
   os.insert(10);

   for(auto it: os)
      cout << it << endl;

   cout << *os.find_by_order(0) << endl;
   cout << *os.find_by_order(1) << endl;
   cout << *os.find_by_order(2) << endl;
   cout << *os.find_by_order(3) << endl;
   cout << *os.find_by_order(4) << endl;
   cout << *os.find_by_order(5) << endl;

   if (os.find_by_order(4) == os.end())
      cout << "order 4 not present" << endl;

   cout << os.order_of_key(-5) << endl;  // 0
   cout << os.order_of_key(1) << endl;   // 0
   cout << os.order_of_key(3) << endl;   // 2
   cout << os.order_of_key(4) << endl;   // 2
   cout << os.order_of_key(400) << endl; // 4




   return 0;
}
