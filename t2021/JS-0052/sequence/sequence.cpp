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
int n, m, k, ans;
ll v[1000], M = 998244353;
void dfs(int dep, ll st, ll val) {
	if(dep == n) {
		if(__builtin_popcountll(st) <= k)
			ans = (ans + val) % M;
			return;
	}
	xh(i, 0, m + 1)dfs(dep + 1, st + (1 << i), val * v[i]%M);
	return;
}
int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);

	rd(n);
	rd(m);
	rd(k);
	xh(i, 0, m + 1)rd(v[i]);
	dfs(0, 0, 1);
	cout << ans % M;
	return 0;
}

