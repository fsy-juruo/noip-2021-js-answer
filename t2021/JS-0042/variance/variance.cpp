// 2021.11.20, NOIP2021
// Code by LTb
// 地球最后的告白。

// 你妈，打这个题的时候通报有人作弊了
// 别又省队名额--啊、、、、

// rp++（各种意义上
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define int long long
#define fi first
#define se second
#define debug printf("Passing Line %d in function [%s].\n", __LINE__, __FUNCTION__)
inline void chmax(int &x, int y) {x = max(x, y);}
inline void chmin(int &x, int y) {x = min(x, y);}

const int MOD = 998244353;
inline int add(int x, int y){return (x+y>=MOD)?(x+y-MOD):((x+y<0)?(x+y+MOD):(x+y));}

inline int read() {
	int x=0,f=1;
	char c='.';
	while (c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while (c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return f*x;
}

const int MAXN = 100005;
int n, m;
int a[MAXN], b[MAXN], c[MAXN];

inline ll calc() {
	for (int i = 2; i <= n; i++)
		a[i] = a[i - 1] + c[i - 1];
	
	int s = 0;
	for (int i = 1; i <= n; i++)
		s += a[i];

	ll res = 0;
	for (int i = 1; i <= n; i++)
		res += 1ll * (n * a[i] - s) * (n * a[i] - s);
	
	return res / n;
}

ll ans = 0;

inline void opt() {
	int x = rand() % m + 1, y = rand() % (m - 1) + 1;
	if (y >= x) y++;
	swap(c[x], c[y]);
	ll res = calc();
	if (res < ans) ans = res;
	else swap(c[x], c[y]);
}

signed main()

{
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	srand(time(NULL));
	n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		b[i - 1] = a[i] - a[i - 1];
	}

	sort(b + 1, b + n);
	m = n - 1;
	if (m % 2 == 1) {
		c[m / 2 + 1] = b[1];
		int s1 = 0, s2 = 0;
		for (int i = 1; i <= m / 2; i++) {
			int l = m / 2 + 1 - i, r = m / 2 + 1 + i;
			int x1 = b[i * 2], x2 = b[i * 2 + 1];
			c[l] = x1, c[r] = x2;
			if (s1 < s2) swap(c[l], c[r]);
			s1 += c[l], s2 += c[r];
		}
	} else {
		int s1 = a[1], s2 = a[2];
		for (int i = 1; i <= m / 2 - 1; i++) {
			int l = m / 2 - i, r = m / 2 + 1 + i;
			int x1 = b[i * 2 + 1], x2 = b[i * 2 + 2];
			c[l] = x1, c[r] = x2;
			if (s1 < s2) swap(c[l], c[r]);
			s1 += c[l], s2 += c[r];
		}
	}

	ans = calc();
	int r;
	if (n > 400) r = 2.5e8 / n;
	else if (n >= 80) r = 2e8 / n;
	else r = 1e8 / n;

	while (r--) opt();
	
	cout << ans << '\n';
	return 0;
}