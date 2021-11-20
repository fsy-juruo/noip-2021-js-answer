#include <bits/stdc++.h>
#define int long long
using namespace std;

template < typename T >
inline void read(T &x)
{
	bool flg = x = 0;
	char c;
	while ((c = getchar()) < 48 || c > 57)
		flg |= (c == '-');
	do
		x = (x << 1) + (x << 3) + (c ^ 48);
	while ((c = getchar()) > 47 && c < 58);
	if (flg) x = -x;
}

int OUTPUT[45];

template < typename T >
inline void write(T x)
{
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}
	int len = 0;
	do
	{
		OUTPUT[++len] = x % 10 | 48;
		x /= 10;
	}while (x);
	while (len)
		putchar(OUTPUT[len--]);
}

template < typename T >
inline void writesp(T x)
{
	write(x);
	putchar(32);
}

template < typename T >
inline void writeln(T x)
{
	write(x);
	putchar(10);
}

const int N = 1005, P = 998244353;
int n, m, k, ans/*, all*/, v[N], a[N], cnt[N], fac[N], inv[N];

inline int power(int x, int y)
{
	int ret = 1;
	while (y)
	{
		if (y & 1) ret = ret * x % P;
		x = x * x % P;
		y >>= 1;
	}
	return ret;
}

void dfs(int dep = 1, int sum = 1)
{
	if (dep > n)
	{
		int now = sum * fac[n] % P;
		for (register int i = 0; i <= m + 7; ++i)
			cnt[i] = 0;
		for (register int i = 1; i <= n; ++i)
			++cnt[a[i]];
		for (register int i = 0; i <= m; ++i)
			now = now * inv[cnt[i]] % P;
		for (register int i = 0; i <= m + 6; ++i)
			if (cnt[i])
			{
				int tmp = (cnt[i] >> 1);
				cnt[i + 1] += tmp;
				cnt[i] -= (tmp << 1);
			}
		int tot = 0;
		for (register int i = 0; i <= m + 7; ++i)
			if (cnt[i]) ++tot;
		if (tot > k) return;
//		int sum = 1;
//		for (register int i = 1; i <= n; ++i)
//			sum = sum * v[a[i]] % P;
		ans = (ans + now) % P;
//		++all;
//		for (register int i = 1; i < n; ++i)
//			writesp(a[i]);
//		writeln(a[n]);
		return;
	}
	for (register int i = a[dep - 1]; i <= m; ++i)
	{
		a[dep] = i;
		dfs(dep + 1, sum * v[i] % P);
	}
}

signed main()
{
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	read(n);
	read(m);
	read(k);
//	int num = ceil(log2(n));
	fac[0] = 1;
	for (register int i = 1; i <= n; ++i)
		fac[i] = fac[i - 1] * i % P;
	inv[n] = power(fac[n], P - 2);
	for (register int i = n - 1; ~i; --i)
		inv[i] = inv[i + 1] * (i + 1) % P/*power(fac[i], P - 2)*/;
	for (register int i = 0; i <= m; ++i)
		read(v[i]);
	dfs();
	writeln(ans);
//	writeln(all);
	return 0;
}
/*
5 1 1
2 1
*/
