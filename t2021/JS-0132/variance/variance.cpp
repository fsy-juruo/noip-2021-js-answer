#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 405;
int n, a[N], b[N], d[N], l[N], r[N];
ll ans = -1;
ll get () {
	ll sum = 0, ret = 0;
	for (int i = 1; i <= n; i ++)
		sum += b[i];
	for (int i = 1; i <= n; i ++)
		ret += 1LL * ((1LL * b[i] * n) - sum) * ((1LL * b[i] * n) - sum);
	return ret;
}
int main () {
	freopen ("variance.in", "r", stdin);
	freopen ("variance.out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf ("%d", &a[i]);
		if (i > 1)
			d[i - 1] = a[i] - a[i - 1];
	}
	sort (d + 1, d + n);
	for (int i = 1; i < (1 << (n - 1)); i ++) {
		int L = 0, R = 0;
		for (int j = 0; j < n - 1; j ++)
			if (i & (1 << j))
				l[++ L] = d[j + 1];
			else
				r[++ R] = d[j + 1];
		b[1] = a[1];
		int now = 2;
		for (int i = L; i >= 1; i --) {
			b[now] = b[now - 1] + l[i];
			now ++;
		}
		for (int i = 1; i <= R; i ++) {
			b[now] = b[now - 1] + r[i];
			now ++;
		}
		ll ls = get ();
		if (ans == -1)
			ans = ls;
		else
			ans = min (ans, ls);
	}
	printf ("%lld\n", 1LL * ans / n);
	return 0;
}

