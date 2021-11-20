#include<bits/stdc++.h>
using namespace std;

int n;
long long a[10010], ans = 1ll << 60;
map<long long, bool> mp;

template <typename Tp>
void read(Tp &x) {
	x = 0; int f = 1; char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = - 1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	x *= f;
}

void calc() {
	long long x = 0, sum1 = 0, sum2 = 0;
	for (int i = 1; i <= n; ++ i) {
		sum1 = sum1 + a[i];
		sum2 = sum2 + a[i] * a[i];
	}
	x = sum1 * sum1 + n * sum2;
	for (int i = 1; i <= n; ++ i) {
		x = x - 2 * sum1 * a[i]; 
	}
	ans = min(ans, x);
}

void dfs() {
	long long val = 0;
	for (int i = 1; i <= n; ++ i) val = val * 100 + a[i];
	if (mp[val]) return;
	else {
		calc();
		mp[val] = 1;
	}
	for (int i = 2; i < n; ++ i) {
		int tv = a[i];
		a[i] = a[i + 1] + a[i - 1] - a[i];
		dfs();
		a[i] = tv;
	}
}

int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	read(n);
	for (int i = 1; i <= n; ++ i) read(a[i]);
	if (n <= 4) {
		dfs();
		printf("%lld\n", ans);
	}
	else {
		if ((a[1] + a[n]) & 1) {
			int mid = (a[1] + a[n]) >> 1;
			for (int i = 2; i <= n / 2; ++ i) a[i] = mid;
			for (int i = n / 2 + 1; i < n; ++ i) a[i] = mid + 1;
		}
		else {
			for (int i = 2; i < n; ++ i) a[i] = (a[1] + a[n]) >> 1;
		}
		calc();
		printf("%lld\n", ans);
	}
	return 0;
}
