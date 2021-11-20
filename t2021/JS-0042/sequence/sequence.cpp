// 2021.11.20, NOIP2021
// Code by LTb
// 地球最后的告白。
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define fi first
#define se second
#define debug printf("Passing Line %d in function [%s].\n", __LINE__, __FUNCTION__)
inline void chmax(int &x, int y) {x = max(x, y);}
inline void chmin(int &x, int y) {x = min(x, y);}

const int MOD = 998244353;
inline int add(int x, int y){return (x+y>=MOD)?(x+y-MOD):((x+y<0)?(x+y+MOD):(x+y));}
inline void upd(int &x, int y) {x = x * y % MOD;}
inline void Add(int &x, int y) {x=add(x,y);}

inline int read() {
	int x=0,f=1;
	char c='.';
	while (c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while (c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return f*x;
}

const int MAXN = 40, MAXM = 120;
int n, m, lim;
int val[MAXM];
int f[MAXM][MAXN][MAXN][MAXN];
int C[MAXM][MAXM];

inline int ksm(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = ans * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return ans;
}

int mul[MAXM][MAXN];

signed main()

{
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	for (int i = 0; i <= 110; i++) {
		C[i][0] = 1;
		for (int j = 1; j <= i; j++)
			C[i][j] = add(C[i - 1][j], C[i - 1][j - 1]);
	}

	n = read(), m = read(), lim = read();
	for (int i = 1; i <= m + 1; i++)
		val[i] = read();

	// mul[0][0] = 1;
	for (int i = 0; i <= m + 7; i++) {
		mul[i][0] = 1;
		for (int j = 1; j <= n + 1; j++)
			mul[i][j] = mul[i][j - 1] * val[i] % MOD;
	}
	
	f[0][0][0][0] = 1;
	int ans = 0;
	for (int i = 1; i <= m + 7; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k <= j; k++) {
				for (int l = 0; l <= j / 2; l++) {
					for (int u = 0; u <= j; u++) {
						int qwq = l * 2 - u;
						if (qwq > j) break;
						int cost = mul[i][u] * C[j][u] % MOD;
						// chmax(cost, 1ll);
						if (qwq >= 0) Add(f[i][j][k][l], f[i - 1][j - u][k][qwq] * cost % MOD);
						if (qwq + 1 >= 0 && k > 0) Add(f[i][j][k][l], f[i - 1][j - u][k - 1][qwq + 1] * cost % MOD);
					}

					// printf("f[%lld][%lld][%lld][%lld] = %lld\n", i, j, k, l, f[i][j][k][l]);
					// if (l == 0 && j == n && k <= lim) {
					// 	Add(ans, f[i][j][k][l]);
					// 	debug;
					// }
				}
			}
		}
	}

	for (int i = 0; i <= lim; i++)
		Add(ans, f[m + 7][n][i][0]);

	cout << ans << endl;
	return 0;
}
