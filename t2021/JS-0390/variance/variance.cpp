#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned LL
#define open(name) freopen(#name".in", "r", stdin),\
				   freopen(#name".out", "w", stdout)
using namespace std;

template < typename T >
inline void readin(T &x) {
	x = 0;
	register int f = 1;
	register char ch = getchar ();
	while (!isdigit (ch) && ch != '-')
		ch = getchar ();
	if (ch == '-')
		f = -1, ch = getchar();
	do {
		x = x * 10 + ch - '0';
		ch = getchar ();
	}
	while (isdigit (ch));
	x *= f;
}

const int N = 10005;

int A[N];

int main () {
	srand ((unsigned)time(NULL));
	open(variance);
	int n, S = 0;
	readin (n);
	for (int i = 1; i <= n; ++i)
		readin(A[i]), S += A[i];
	bool p = true;
	while (p) {
		p = false;
		for (int j = 2; j < n; ++j) {
			int i = rand () % (n - 3) + 2;
			int ap = A[i - 1] + A[i + 1] - A[i],
			Sp = S - A[i] + ap;
			if (abs(S * 1.0 / n - A[i]) > abs(Sp * 1.0 / n - ap)) {
				A[i] = ap, S = Sp;
				p = true;
			}
		}
	}
	int D = 0;
	for (int i = 1; i <= n; ++i)
		D += n * A[i] * A[i] - 2 * A[i] * S;
	D += S * S;
	printf ("%d\n", D);
	return 0;
}


