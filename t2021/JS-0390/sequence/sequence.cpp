#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned LL
#define open(name) freopen(#name".in", "r", stdin),\
				   freopen(#name".out", "w", stdout)
#define lowbit(x) (x & -x)
using namespace std;

template < typename T >
inline void readin(T &x) {
	x = 0;
	register T f = 1;
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

const LL N = 35, mod = 998244353;

template < typename T >
T power (T a, T b) {
	if (!b)
		return 1LL;
	if (b == 1)
		return a % mod;
	T t = power (a, b >> 1LL) % mod;
	if (b & 1) return t * t % mod * a % mod;
	else return t * t % mod;
}

LL Pow[N];

LL cntbit (LL x) {
	LL cnt = 0;
	while (x) {
		x -= lowbit (x);
		++cnt;
	}
	return cnt;
}
LL A[N];
LL n, m, k, ans = 0, v[N];

LL F[N][N] =  {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,3,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,3,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,4,2,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,4,2,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,7,2,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,7,4,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,8,4,0,2,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,8,4,0,2,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,10,5,0,2,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,10,5,0,2,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,11,5,0,2,0,2,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,11,6,0,3,0,2,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,15,6,0,3,0,2,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,15,6,0,3,0,2,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,16,8,0,3,0,2,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,16,8,0,3,0,2,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,18,8,0,4,0,2,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,18,9,0,4,0,3,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,19,9,0,4,0,3,0,0,0,2,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,19,9,0,4,0,3,0,0,0,2,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0},
				{0,0,22,10,0,4,0,3,0,0,0,2,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0},
				{0,0,22,10,0,6,0,3,0,0,0,2,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0},
				{0,0,23,10,0,6,0,3,0,0,0,2,0,2,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0},
				{0,0,23,13,0,6,0,3,0,0,0,2,0,2,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0},
				{0,0,25,13,0,6,0,4,0,0,0,2,0,2,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0},
				{0,0,25,13,0,6,0,4,0,0,0,2,0,2,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0},
				{0,0,26,14,0,7,0,4,0,0,0,2,0,2,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0}};

void init () {
	Pow[0] = 1;
	for (LL i = 1; i < N; ++i)
		Pow[i] = Pow[i - 1] << 1;
}

void deal () {
//	for (LL i = 0; i <= n; ++i)
//		printf ("%d ", A[i]);
//	printf ("\n");
	LL T[N];
	memcpy (T, F[n], N * sizeof (LL));
	for (LL i = 0; i <= m; ++i) {
		for (LL j = 2; j <= n; ++j)
			T[j] -= F[A[i]][j];
	}
//	for (LL i = 1; i <= n; ++i)
//		printf ("%d ", T[i]);
//	printf ("\n");
	LL res = 1;
	for (LL i = 1; i <= n; ++i)
		(res *= power (i, T[i])) %= mod;
//	printf ("%d\n", res);
	for (LL i = 0; i <= m; ++i) {
		(res *= power (v[i], A[i])) %= mod;
	//	printf ("%d %d %d\n", v[i], A[i], res);
	}
//	printf ("%lld\n", res);
	(ans += res % mod) %= mod;
//	printf ("%lld\n", ans);
}

int cnt = 0;

void dfs (LL dep, LL x, LL l) {/*
	//if (cnt > 0)
		//return;
	if (x == n - dep + 1) {
		A[0] += n - dep + 1;
		++cnt;
		if (cnt == 2) {
			printf ("\n");
			for (LL i = 0; i <= n; ++i)
			printf ("%d ", A[i]);
			printf ("\n");
		}
		if (cnt == 3) {
			for (LL i = 0; i <= n; ++i)
			printf ("%d ", A[i]);
			printf ("\n");
			printf ("\n");
		}
		//printf ("%d\n", cnt);
		deal();
		A[0] -= n - dep + 1;
		return;
	}
	if (dep > n)
		return;
	for (LL i = l; i >= 0; --i) {
		if (x >= Pow[i]) {
			A[i]++;
			dfs (dep + 1, x - Pow[i], i);
			A[i]--;
		}
	}*/
//	printf ("%d\n", x);
	if (x == l) {
		A[0] += l;
		deal();
		A[0] -= l;
		return;
	}
	if (dep > m)
		return;
	for (int i = 0; i <= l && x >= Pow[dep] * i; ++i) {
		A[dep] = i;
		dfs (dep + 1, x - Pow[dep] * i, l - i);
		A[dep] = 0;
	}
}

bool vis[N];

int main () {
	open(sequence);
	readin (n);
	readin (m);
	readin (k);
	init ();
	for (LL i = 0; i <= m; ++i)
		readin (v[i]);
	for (LL i = n, t = n * Pow[m]; i <= t; ++i) {
		int x = cntbit(i);
		if (x <= k) {
		//	vis[x] = true;
		/*	for (int j = i; j <= t; j += (j ^ (j - 1))) {
				printf ("%d\n", j);
				dfs (1, j, m);
			}*/
			cnt = 0;
			dfs (1, i, n);
		}/*
		int x = cntbit(i);
		if (x <= k && !vis[x]) {
			vis[x] = true;
			for (LL j = i; j <= t; j += (j ^ (j - 1))) {
			//	printf ("%d\n", j);
				dfs (1, j, m);
			}
		}*/
	}
	printf ("%lld\n", ans);
	return 0;
}

