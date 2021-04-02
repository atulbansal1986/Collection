#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

typedef tree<
int,
int,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_map;


int main()
{
   ios::sync_with_stdio(0);

   ordered_map os;

   os.insert(make_pair(1,11));
   os[2] = 22;
   os[5] = 55;
   os[9] = 99;

   map<int, int> mp;

   for(auto it: os)
      cout << it.first << " -> " << it.second << endl;

   cout << os.find_by_order(0)->first << endl;
   cout << os.find_by_order(1)->first << endl;
   cout << os.find_by_order(2)->first << endl;
   cout << os.find_by_order(3)->first << endl;
   cout << os.find_by_order(4)->first << endl;
   cout << os.find_by_order(5)->first << endl;

   if (os.find_by_order(4) == os.end())
      cout << "order 4 not present" << endl;

   cout << os.order_of_key(-5) << endl;  // 0
   cout << os.order_of_key(1) << endl;   // 0
   cout << os.order_of_key(3) << endl;   // 2
   cout << os.order_of_key(4) << endl;   // 2
   cout << os.order_of_key(400) << endl; // 4




   return 0;
}
