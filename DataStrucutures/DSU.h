#include <bits/stdc++.h>

using namespace std;

class DSU
{
      vector<int> parent{};
      vector<int> size{};

   public:
      DSU(int n)
      {
         for (int i = 0; i < n; i++)
         {
            parent.push_back(i);
            size.push_back(i);
         }
      }

      bool connected(int u, int v)
      {
         return root(u) == root(v);
      }

      void join(int u, int v)
      {
         int ru = root(u);
         int rv = root(v);
         if (size[ru] > size[rv])
         {
            parent[rv] = parent[ru];
         }
         else
         {
            parent[ru] = parent[rv];
         }
      }

      int root(int x)
      {
         while (parent[x] != x)
         {
            parent[x] = parent[parent[x]];
            x = parent[x];
         }
         return x;
      }

};
