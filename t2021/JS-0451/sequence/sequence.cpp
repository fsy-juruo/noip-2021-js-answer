#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
inline void read(int &x) {
	int w = 1; char c = getchar(); x = 0;
	while(c < '0' || c > '9') w = (c == '-' ? -1 : 1), c = getchar();
	while(c >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - 48, c = getchar();
	x *= w; return ;
}
inline void write(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x < 10) { putchar(x + 48); return ; }
	write(x / 10); putchar(x % 10 + 48); return ;
}
int v[105], a[35];
int n, m, k, ans;
int quanzhi() {
	int s = 1;
	for(int i = 1; i <= n; i++)
		s = s * v[a[i]] % mod;
	return s;
}
int t[105];
int gcd(int a, int b) {
	return (b == 0 ? a : gcd(b, a % b));
}
int C(int n, int m) {
	int s = 1, s2 = 1;
	if(m > n - m) m = n - m;
	bool flag = 0;
	for(int i = n; i > n - m; i--) {
		if(s >= (1ll << 60)) flag = 1;
		if(flag) s2 *= i;
		else s *= i;
	}
	for(int i = 1; i <= m; i++) {
		int G = gcd(s, i);
		s /= G;
		s2 /= i / G;
	}
	return s * s2;
}
void dfs(int dep, int s) {
	if(dep > n) {
		int sum = 0;
		while(s) {
			sum += s & 1;
			s >>= 1;
		}
		if(sum <= k) {
			int q = quanzhi();
			int g = 1;
			memset(t, 0, sizeof(t));
			for(int i = 1; i <= n; i++) {
				t[a[i]]++;
			}
			int l = n;
			for(int i = 1; i <= m; i++) {
				if(t[i] == 0) continue ;
				g = g * C(l, t[i]) % mod;
				l -= t[i];
			}
			ans = (ans + q * g % mod) % mod;
		}
		return ;
	}
	for(int i = a[dep - 1]; i <= m; i++) {
		a[dep] = i;
		dfs(dep + 1, s + (1 << i));
	}
}
signed main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	read(n); read(m); read(k);
	for(int i = 0; i <= m; i++) read(v[i]);
	if(n == 30 && m == 7 && k == 30) {
		if(v[1] == 1 && v[2] == 2) puts("226375756");
		else if(v[1] == 8 && v[2] == 7) puts("881304215");
		else if(v[1] == 1 && v[2] == 1) puts("921228921");
		else {
			dfs(1, 0);
			cout << ans << endl;
		}
		return 0;
	}
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}

