#include "Common.h"

struct BigInteger {
   BigInteger();
   BigInteger(string s);

   string getString() const;

   BigInteger& operator=(const BigInteger& rhs);

   BigInteger& operator+=(const BigInteger& rhs);
   BigInteger& operator-=(const BigInteger& rhs);
   BigInteger& operator*=(const BigInteger& rhs);
   BigInteger& operator/=(const BigInteger& rhs);

   typedef vector<int> lnum_t;
   static const int base = 1e9;
   lnum_t num;
};

string BigInteger::getString() const
{
   char buf[10240];
   snprintf (buf, sizeof(buf), "%d", num.empty() ? 0 : num.back());
   for (int i=(int)num.size()-2; i>=0; --i)
      snprintf (buf, sizeof(buf), "%09d", num[i]);
   return buf;
}

BigInteger::BigInteger()
{
   BigInteger("0");
}

BigInteger::BigInteger(string s)
{
   for (int i = (int) s.length(); i > 0; i -= 9)
      if (i < 9)
         num.push_back(atoi(s.substr(0, i).c_str()));
      else
         num.push_back(atoi(s.substr(i - 9, 9).c_str()));

   while (num.size() > 1 && num.back() == 0)
      num.pop_back();
}

BigInteger& BigInteger::operator=(const BigInteger& rhs)
{
   num.clear();
   for(auto it : rhs.num)
   {
      num.pb(it);
   }
}

BigInteger& BigInteger::operator+=(const BigInteger& rhs)
{
   int carry = 0;
   for (size_t i=0; i<max(num.size(), rhs.num.size()) || carry; ++i) {
      if (i == num.size())
         num.push_back (0);
      num[i] += carry + (i < rhs.num.size() ? rhs.num[i] : 0);
      carry = num[i] >= base;
      if (carry) num[i] -= base;
   }
   return *this;
}

BigInteger& BigInteger::operator-=(const BigInteger& rhs)
{
   int carry = 0;
   for (size_t i=0; i<rhs.num.size() || carry; ++i) {
      num[i] -= carry + (i < rhs.num.size() ? rhs.num[i] : 0);
      carry = num[i] < 0;
      if (carry)  num[i] += base;
   }
   while (num.size() > 1 && num.back() == 0)
      num.pop_back();

   return *this;
}

BigInteger& BigInteger::operator*=(const BigInteger& rhs)
{
   size_t sz = num.size() + rhs.num.size();
   lnum_t c(sz, 0);
   for (size_t i=0; i<num.size(); ++i)
      for (int j=0, carry=0; j<(int)num.size() || carry; ++j) {
         LL cur = c[i+j] + num[i] * 1ll * (j < (int)rhs.num.size() ? rhs.num[j] : 0) + carry;
         c[i+j] = int (cur % base);
         carry = int (cur / base);
      }
   while (c.size() > 1 && c.back() == 0)
      c.pop_back();
   num.clear();
   for(auto it: c)
      num.pb(it);

   return *this;
}

BigInteger& BigInteger::operator/=(const BigInteger& rhs)
{

}

BigInteger operator+(const BigInteger& lhs, const BigInteger& rhs)
{
   BigInteger b = lhs;
   b += rhs;
   return b;
}
BigInteger operator-(const BigInteger& lhs, const BigInteger& rhs)
{
   BigInteger b = lhs;
   b -= rhs;
   return b;
}
BigInteger operator*(const BigInteger& lhs, const BigInteger& rhs)
{
   BigInteger b = lhs;
   b *= rhs;
   return b;
}
BigInteger operator/(const BigInteger& lhs, const BigInteger& rhs)
{
   BigInteger b = lhs;
   b /= rhs;
   return b;
}
