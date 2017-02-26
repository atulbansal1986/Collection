#include "SegmentTree.h"

constexpr LL SIZE = 10000;
constexpr LL MAXVAL = 100000;
constexpr LL ITER = 10000;

int main()
{
	ios_base::sync_with_stdio(false);
	LL N = rand() % SIZE;

	vector<LL> v (N, 0);
	for (LL i=0;i<N;++i) {
	   v[i] = rand() % (MAXVAL);
	}

	ST st(v);

	for (LL i = 0; i < ITER; i++) {
	   LL l = rand() % N;
	   LL r = rand() % N;
	   if (l > r) swap(l, r);

      LL p = rand() % N;
	   LL x = rand() % MAXVAL;

	   st.modify(p, x);
	   LL res1 = 0;
	   for (LL j=l;j<r;++j)
	      res1 += v[j];

	   LL res2 = st.query(l, r);

	   if (res1 != res2) {
	      cerr << "Test Failed" << i << endl;
	      exit(EXIT_FAILURE);
	   }
	}

	cerr << "Test Passed" << endl;


	return 0;
}
