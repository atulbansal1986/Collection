/*
 * SegmentTree.h
 *
 *  Created on: 04-Jun-2016
 *      Author: atulb
 */

#pragma once
#include "Maths/Common.h"

class ST {
   vector<LL> t;
   LL N;
public:
   ST(LL n) {
      assert(n > 0);
      N = n;
      t.resize(2*N, 0);
   }

   ST(const vector<LL>& in) {
      N = in.size();
      t.resize(2*N, 0);
      for (LL i = 0; i < N; i++) {
         t[i + N] = in[i];
      }
      build();
   }

   void build() {
      for (LL i = N-1; i >= 0; --i) {
         t[i] = t[i << 1] + t[(i << 1) + 1];
      }
   }

   void modify(LL i, LL val) {
      assert(0 <= i && i < N);
      for (LL p = i + N; p > 1; p >>= 1) {
         t[p >> 1] = t[p] + t[p^1ll];
      }
   }

   LL query(LL l, LL r) {
      LL res = 0;
      for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
         if (l & 1) res += t[l++];
         if (r & 1) res += t[--r];
      }
      return res;
   }

};
