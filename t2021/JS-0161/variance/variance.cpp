#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T&x) {
	x = 0;
	char ch = getchar();
	T flg = 1;
	while ((!isdigit(ch)) && ch != '-') ch = getchar();
	if (ch == '-') ch = getchar(), flg = -1;
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	x *= flg;
}
const int MN = 10100;
int a[MN], n;
long long ans = INT_MAX;
set<unsigned long long> Hs;
inline void dfs(int dep, long long t, long long s, unsigned long long Hash) {
	if (Hs.find(Hash) != Hs.end()) return;
	Hs.insert(Hash);
	ans = min(ans, n * t - s * s);
	for (int i = 2; i < n; i++) {
		long long ti = t - a[i] * a[i];
		ti = ti + (a[i-1] + a[i+1] - a[i]) * (a[i-1] + a[i+1] - a[i]);
		long long si = s - a[i] + a[i-1] + a[i+1] - a[i];
		int tt = a[i];
		a[i] = a[i - 1] + a[i + 1] - a[i];
		unsigned long long Hasi = 0;
		for (int j = 1; j <= n; j++) Hasi = Hasi * 13331 + a[j];
		dfs(dep + 1, ti, si, Hasi);
		a[i] = tt;
	}
}
int main(){
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	long long t = 0, s = 0;
	unsigned long long Hash = 0;
	for (int i = 1; i <= n; i++) {
		t = t + a[i] * a[i];
		s = s + a[i];
		Hash = Hash * 13331 + a[i];
	}
	dfs(1, t, s, Hash);
	printf("%lld\n", ans);
	return 0;
}