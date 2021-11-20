#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline int read() {
	int val = 0, neg = 1;
	char ch = getchar();
	while (ch > '9' || ch < '0') {
		if (ch == '-') neg = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		val = val * 10 + ch - 48;
		ch = getchar();
	}
	return val * neg;
}

const int N = 1e4 + 10;
int a[N], tmp[N], cnt, st, n = 0, p = 0;
double ans = 0x7f7f7f7f;

void dfs(int now) {
	if (p > 10) return;
	cout << n << endl;
	int oa = a[now], ni = (a[now + 1] + a[now - 1] - a[now]);
	if (oa != ni) {
		a[now] = ni;
		p++, dfs(now + 1);
	}
}

int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	int n = read(); cnt = 1;
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += a[i];
	}
	double ave = (double)(sum) / (double)(n);
	double fc = 0;
	for (int i = 1; i <= n; i++) {
		fc += (ave - a[i]) * (ave - a[i]);
	}
	printf("%lld\n", (ll)(fc * n));
	return 0;
}

