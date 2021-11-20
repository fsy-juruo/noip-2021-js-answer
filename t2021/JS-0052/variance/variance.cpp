#include<bits/stdc++.h>
using namespace std;
#define xh(i,a,b) for(int i=(a);i<(b);++i)
#define ll long long
template <typename T>
inline T rd(T& a) {
	a = 0;
	bool f = 1;
	char c = getchar();
	while(c > '9' || c < '0') {
		f = c - '-';
		c = getchar();
	}
	while(c <= '9' && c >= '0') {
		a = a * 10 + c - '0';
		c = getchar();
	}
	a = f ? a : -a;
	return a;
}
int nn = 10010, n, a[20055], d[20055], ans[20055], l, r, nl, nr;
ll ta[4], mt;
bool fl;
inline ll fc(int s, int t) {
	ll m = 0, l = t - s;
	ll tans = 0;
	xh(i, s, t)m += ans[i];
	xh(i, s, t)tans += (l * ans[i] - m) * ((l * ans[i] - m));
	return tans / l;
}
inline bool jh(int s, int t) {
	ll a = fc(l, r + 1);
	int d = ans[s + 1] - ans[s] - (ans[t + 1] - ans[t]);
	xh(i, s + 1, t + 1)ans[i] -= d;
	if(a < fc(l, r + 1)) {
		xh(i, s + 1, t + 1)ans[i] += d;
		return 0;
	} else return 1;
}
int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	rd(n);
	xh(i, 1, n + 1)rd(a[i]);
	xh(i, 1, n)d[i] = a[i + 1] - a[i];
	sort(d + 1, d + n );
	a[nn] = 0;
	l = r = nn;
	for(int i = 1; i < n; ++i) {
		ans[l - 1] = ans[l] - d[i];
		ans[r + 1] = ans[r] + d[i];
		if(fc(l - 1, r + 1) < fc(l, r + 2)) --l;
		else ++r;
	}
	if(n <= 400) {
		fl = 1;
		while(fl) {
			fl = 0;
			xh(i, l, nn)
			xh(j, nn, r)
			fl = jh(i, j);
		}
	} else {
		nr = nn;
		for(int i = nn - 1; i >= l; --i) {
			for(; nr < r; ++nr)
				if(ans[i + 1] - ans[i] <= ans[nr + 1] - ans[nr] && ans[i + 1] - ans[i] >= ans[nr] - ans[nr - 1]) {
					jh(i, nr - 1);
					jh(i, nr);
					break;
				}

		}
	}
	//xh(i, l + 1, r + 1) {
	//	printf("%d ", ans[i] - ans[i - 1]);
	//}
	printf("%lld", fc(l, r + 1));
	return 0;
}

