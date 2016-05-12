#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define vi vector<int>
#define pb push_back
#define endl "\n"

template<typename T>
T power(T a, LL b)
{
   if (b == 0)
      return 1;

   T rem = 1;

   while (b > 1)
   {
      if (b % 2 == 1)
         rem = rem * a;

      b = b / 2;
      a = a * a;
   }

   return a * rem;
}

template<typename T>
T power(T a, LL b, T id)
{
   if (b == 0)
      return id;

   T rem = id;

   while (b > 1)
   {
      if (b % 2 == 1)
         rem = rem * a;

      b = b / 2;
      a = a * a;
   }

   return a * rem;
}

LL power(LL a, LL b, LL mod)
{
   assert(b >= 0);
   if (b == 0)
      return 1;

   LL rem = 1;

   while (b > 1)
   {
      if (b % 2 == 1)
         rem = (rem * a) % mod;

      b = b / 2;
      a = (a * a) % mod;
   }

   return (a * rem) % mod;
}

LL gcd(LL a, LL b)
{
   if (a < b)
      swap(a, b);
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
   if (a < b)
      return gcdExt(b, a, y, x);
   if (b == 0)
   {
      x = 1;
      y = 0;
      return a;
   } else
   {
      LL x1, y1;
      LL g = gcdExt(b, a % b, x1, y1);
      x = y1;
      y = x1 - (a / b) * y1;
      return g;
   }
}

LL lcm(LL a, LL b)
{
   return a * b / gcd(a, b);
}

LL fact(LL n, LL mod)
{
   if (n == 0)
      return 0;
   LL ret = 1;
   while (n > 0)
   {
      ret = (ret * n) % mod;
      --n;
   }
   return ret;
}

LL isPrime(LL a)
{
   if (a < 2)
      return false;
   // make sure to use LL here for i
   // o/w i*i can overflow!
   for (LL i = 2; i * i <= a; ++i)
   {
      if (a % i == 0)
         return false;
   }
   return true;
}

template<typename T, int N>
void buildPrimes(array<T, N>& A)
{
   assert(N > 0);
   for (int i = 0; i < N; ++i)
   {
      A[i] = 1;
   }
   A[0] = 0;
   A[1] = 0;
   for (int i = 2; i < N; ++i)
   {
      if (0 == A[i])
         continue;
      else
      {
         int j = 2;
         while (j * i < N)
         {
            A[i * j] = 0;
            ++j;
         }
      }
   }
}

LL phi(LL n)
{
   vector<LL> pfacts;
   LL m = (LL)sqrt(n);
   for (LL i = 1; i <= m; i++)
   {
      if (n % i == 0)
      {
         if (isPrime(i))
            pfacts.pb(i);

         LL d = n / i;
         if (isPrime(d) && i < d)
            pfacts.pb(d);
      }
   }

   for (auto it : pfacts)
   {
      n = n / it;
      n = n * (it - 1);
   }

   return n;
}

LL inv(LL a, LL n)
{
   LL x, y;
   LL g = gcdExt(a, n, x, y);
   if (g != 1)
      return -1;
   else
      return (x % n + n) % n;
}

LL invExp(LL a, LL n)
{
   LL p = phi(n) - 1;
   return power(a, p, n);
}

void invAll(vector<LL>& R)
{
   LL m = (LL)R.size();
   assert(isPrime(m));
   R[0] = 0;
   R[1] = 1;
   for (LL i = 2; i < m; ++i)
   {
      R[i] = (m - ((m / i) * R[m % i]) % m) % m;
   }
}

struct Matrix
{
   Matrix(LL r, LL c)
   {
      reset(r, c);
   }

   Matrix(LL r)
   {
      reset(r, r);
      for (LL i = 0; i < r; ++i)
         A[i][i] = 1;
   }

   LL& operator()(LL i, LL j)
   {
      return A[i][j];
   }

   Matrix& operator=(const Matrix& rhs);

   vector<vector<LL> > A;
private:
   void reset(LL r, LL c)
   {
      assert(r > 0 && c > 0);
      A.resize(r);
      for (int i = 0; i < r; ++i)
      {
         A[i].resize(c, 0);
      }
   }
};

Matrix& Matrix::operator=(const Matrix& rhs)
{
   A.clear();
   LL r = rhs.A.size();
   LL c = rhs.A[0].size();
   A.resize(r);
   for (int i = 0; i < r; ++i)
   {
      A[i].resize(c);
   }
   for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j)
         A[i][j] = rhs.A[i][j];

   return *this;
}

Matrix operator*(const Matrix& lhs, const Matrix& rhs)
{
   LL r = (LL)lhs.A.size();
   LL mm = (LL)lhs.A[0].size();
   LL c = (LL)rhs.A[0].size();
   assert(mm == (LL)rhs.A.size());
   Matrix ret(r, c);
   for (LL i = 0; i < r; ++i)
      for (LL j = 0; j < c; ++j)
         for (LL k = 0; k < mm; ++k)
            ret.A[i][j] += lhs.A[i][k] * rhs.A[k][j];

   return ret;
}

LL fib(int n)
{
   if (n == 0)
      return 0;
   else if (n == 1)
      return 1;
   else
   {
      LL curr = 1;
      LL prev = 0;
      for (int i = 2; i <= n; i++)
      {
         LL temp = curr + prev;
         prev = curr;
         curr = temp;
      }
      return curr;
   }
}

LL fibFast(int n)
{
   Matrix m(2, 2);
   m(0, 0) = 0;
   m(0, 1) = 1;
   m(1, 0) = 1;
   m(1, 1) = 1;
   Matrix id(2);
   return power(m, n, id)(1, 0);
}
