#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define vi vector<int>
#define pb push_back
#define endl "\n"

template<typename T>
T power(T a, LL b)
{
   if (b==0) return 1;

   T rem = 1;

   while (b > 1)
   {
      if (b%2 == 1) rem = rem * a;

      b = b / 2;
      a = a * a;
   }

   return a*rem;
}

LL power(LL a, LL b, LL mod)
{
   assert(b>=0);
   if (b==0) return 1;

   LL rem = 1;

   while (b > 1)
   {
      if (b%2 == 1) rem = (rem * a) % mod;

      b = b / 2;
      a = (a * a) % mod;
   }

   return (a*rem) % mod;
}

LL gcd(LL a, LL b)
{
   if (a < b) swap(a,b);
   while (b > 0)
   {
      LL temp = a % b;
      a = b;
      b = temp;
   }
   return a;
}

LL gcdExt(LL a, LL b, LL& x, LL& y)
{
   if (a < b) return gcdExt(b,a,y,x);
   if (b == 0)
   {
      x = 1;
      y = 0;
      return a;
   }
   else
   {
      LL x1,y1;
      LL g = gcdExt(b, a%b, x1, y1);
      x = y1;
      y = x1 - (a/b)*y1;
      return g;
   }
}

LL lcm(LL a, LL b)
{
   return a * b / gcd(a,b);
}

LL fact(LL n, LL mod)
{
   if (n==0) return 0;
   LL ret = 1;
   while (n > 0) { ret  = (ret * n) % mod; --n; }
   return ret;
}

LL fibFast(LL n)
{

}

LL isPrime(LL a)
{
   if (a < 2) return false;
   LL m = sqrt(a);
   for(int i=2;i<=m;++i)
   {
      if (a % i == 0)
         return false;
   }
   return true;
}

void buildPrimes(int* A, int n)
{
   assert(n>0);
   for(int i=0;i<n;++i)
   {
      A[i] = 1;
   }
   A[0] = 0;
   A[1] = 0;
   for(int i=2;i<n;++i)
   {
      if (0 == A[i]) continue;
      else
      {
         int j = 2;
         while (j*i < n)
         {
            A[i*j] = 0;
            ++j;
         }
      }
   }
}

LL phi(LL n)
{
   vector<LL> pfacts;
   LL m = sqrt(n);
   for (LL i = 1; i <= m; i++)
   {
      if (n % i == 0)
      {
         if (isPrime(i))
            pfacts.pb(i);

         int d = n / i;
         if (isPrime(d) && i < d)
            pfacts.pb(d);
      }
   }

   for(auto it : pfacts)
   {
      n = n / it;
      n = n * (it - 1);
   }

   return n;
}

LL inv(LL a, LL n)
{
   LL x,y;
   LL g = gcdExt(a,n,x,y);
   if (g != 1)
      return -1;
   else
      return (x%n+n)%n;
}

LL invExp(LL a, LL n)
{
   LL p = phi(n) - 1;
   return power(a, p, n);
}

LL invAll(LL* R, LL m)
{
   assert(isPrime(m));
   R[0] = 0;
   R[1] = 1;
   for(LL i=2;i<m;++i)
   {
      R[i] = (m - ((m/i)*R[m%i]) % m) % m;
   }
}
