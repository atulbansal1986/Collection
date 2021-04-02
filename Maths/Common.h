#include <bits/stdc++.h>

using namespace std;


template<typename T>
T power(T a, int64_t b)
{
   assert(b >= 0);

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
T power(T a, int64_t b, T id)
{
   assert(b >= 0);

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

int64_t power_mod(int64_t a, int64_t b, int64_t mod)
{
   assert(b >= 0);
   if (b == 0)
      return 1;

   int64_t rem = 1;

   while (b > 1)
   {
      if (b % 2 == 1)
         rem = (rem * a) % mod;

      b = b / 2;
      a = (a * a) % mod;
   }

   return (a * rem) % mod;
}

int64_t gcd(int64_t a, int64_t b)
{
   if (a < b)
   {
      swap(a, b);
   }

   while (b > 0)
   {
      int64_t temp = a % b;
      a = b;
      b = temp;
   }

   return a;
}

int64_t gcdExt(int64_t a, int64_t b, int64_t& x, int64_t& y)
{
   if (a < b)
   {
      return gcdExt(b, a, y, x);
   }

   if (b == 0)
   {
      x = 1;
      y = 0;
      return a;
   }
   else
   {
      int64_t x1{0}, y1{0};
      int64_t g = gcdExt(b, a % b, x1, y1);
      x = y1;
      y = x1 - (a / b) * y1;
      return g;
   }
}

int64_t lcm(int64_t a, int64_t b)
{
   return a * b / gcd(a, b);
}

int64_t fact(int64_t n, int64_t mod)
{
   if (n == 0)
      return 0;
   int64_t ret = 1;
   while (n > 0)
   {
      ret = (ret * n) % mod;
      --n;
   }
   return ret;
}

int64_t isPrime(int64_t a)
{
   if (a < 2)
      return false;
   // make sure to use int64_t here for i
   // o/w i*i can overflow!
   for (int64_t i = 2; i * i <= a; ++i)
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

int64_t phi(int64_t n)
{
   vector<int64_t> pfacts;
   int64_t m = (int64_t)sqrt(n);
   for (int64_t i = 1; i <= m; i++)
   {
      if (n % i == 0)
      {
         if (isPrime(i))
            pfacts.push_back(i);

         int64_t d = n / i;
         if (isPrime(d) && i < d)
            pfacts.push_back(d);
      }
   }

   for (auto it : pfacts)
   {
      n = n / it;
      n = n * (it - 1);
   }

   return n;
}

int64_t inv(int64_t a, int64_t n)
{
   int64_t x, y;
   int64_t g = gcdExt(a, n, x, y);
   if (g != 1)
      return -1;
   else
      return (x % n + n) % n;
}

int64_t invExp(int64_t a, int64_t n)
{
   int64_t p = phi(n) - 1;
   return power_mod(a, p, n);
}

void invALL(vector<int64_t>& R)
{
   int64_t m = (int64_t)R.size();
   assert(isPrime(m));
   R[0] = 0;
   R[1] = 1;
   for (int64_t i = 2; i < m; ++i)
   {
      R[i] = (m - ((m / i) * R[m % i]) % m) % m;
   }
}

struct Matrix
{
   Matrix(int64_t r, int64_t c)
   {
      reset(r, c);
   }

   Matrix(int64_t r)
   {
      reset(r, r);
      for (int64_t i = 0; i < r; ++i)
         A[i][i] = 1;
   }

   int64_t& operator()(int64_t i, int64_t j)
   {
      return A[i][j];
   }

   Matrix& operator=(const Matrix& rhs);

   vector<vector<int64_t> > A;
private:
   void reset(int64_t r, int64_t c)
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
   int64_t r = rhs.A.size();
   int64_t c = rhs.A[0].size();
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
   int64_t r = (int64_t)lhs.A.size();
   int64_t mm = (int64_t)lhs.A[0].size();
   int64_t c = (int64_t)rhs.A[0].size();
   assert(mm == (int64_t)rhs.A.size());
   Matrix ret(r, c);
   for (int64_t i = 0; i < r; ++i)
      for (int64_t j = 0; j < c; ++j)
         for (int64_t k = 0; k < mm; ++k)
            ret.A[i][j] += lhs.A[i][k] * rhs.A[k][j];

   return ret;
}

int64_t fib(int n)
{
   if (n == 0)
      return 0;
   else if (n == 1)
      return 1;
   else
   {
      int64_t curr = 1;
      int64_t prev = 0;
      for (int i = 2; i <= n; i++)
      {
         int64_t temp = curr + prev;
         prev = curr;
         curr = temp;
      }
      return curr;
   }
}

int64_t fibFast(int n)
{
   Matrix m(2, 2);
   m(0, 0) = 0;
   m(0, 1) = 1;
   m(1, 0) = 1;
   m(1, 1) = 1;
   Matrix id(2);
   return power(m, n, id)(1, 0);
}
