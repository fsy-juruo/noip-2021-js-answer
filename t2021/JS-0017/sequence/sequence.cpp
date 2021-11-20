#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
template<typename T> inline void read(T &F) {
	F = 0; int R = 1; char CH = getchar();
	for(; !isdigit(CH); CH = getchar()) if(CH == '-') R = -1;
	for(; isdigit(CH); CH = getchar()) F = F * 10 + CH - 48;
	F = F * R;
}
inline void file(string str) {
	freopen((str + ".in").c_str(), "r", stdin);
	freopen((str + ".out").c_str(), "w", stdout);
}
const int N = 32, M = 105;
const LL mod = 998244353;
LL f[M][N][N][N], n, m, k, ai[M]; LL pre[M], inv[M]; //vector<vector<int> > fa[M][N][N][N];
LL Qpow(LL x, LL k) {
	if(k <= 1) return k ? x : 1;
	LL h = Qpow(x, k / 2); h = h * h % mod;
	return k & 1 ? h * x % mod : h;
}
int main() {
	file("sequence");
	read(n), read(m), read(k); m++;
	for(int i = 1; i <= m; i++) read(ai[i]);
	pre[0] = 1;
	for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] * i % mod;
	inv[n] = Qpow(pre[n], mod - 2);
	for(int i = n - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
	f[0][0][0][0] = 1;
	for(int i = 0; i < m; i++) {
		//f[i][0][0][0] = 1;
		for(int j = 0; j <= n; j++)
			for(int c = 0; c <= k; c++)
				for(int g = 0; g <= 31; g++)
					if(f[i][j][c][g]) {
						LL ri = 1;
						for(int p = 0; p + j <= n; p++) {
							if(c + ((g + p) & 1) <= k) {
								//vector<vector<int> > l =  fa[i][j][c][g];
								//for(auto q : l) q.push_back(p), fa[i + 1][p + j][c + ((g + p) & 1)][(g + p) >> 1].push_back(q);
								(f[i + 1][p + j][c + ((g + p) & 1)][(g + p) >> 1] += f[i][j][c][g] * ri % mod * inv[p] % mod) %= mod;	
							}
							ri = ri * ai[i + 1] % mod;
						}
					}
	}
	//cout << f[1][2][0][1] << endl;
	LL ans = 0;
	for(int c = 0; c <= k; c++)
		for(int g = 0; g <= 31; g++)
			if(c + __builtin_popcount(g) <= k)
				(ans += f[m][n][c][g]) %= mod;
	cout << ans * pre[n] % mod << endl;
	return 0;
}

