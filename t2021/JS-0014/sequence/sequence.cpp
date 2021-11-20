#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mem(x, v, s) memset(x, v, sizeof(x[0]) * (s))
#define cpy(x, y, s) memcpy(x, y, sizeof(x[0]) * (s))
#define pii pair <int, int>
#define gc getchar()
#define pc(x) putchar(x)
bool Mbe;

inline int read() {
	int x = 0, sgn = 0; char s = gc;
	while(!isdigit(s)) sgn |= s == '-', s = gc;
	while(isdigit(s)) x = x * 10 + s - '0', s = gc;
	return sgn ? -x : x;
}
void rprint(int x) {if(x >= 10) rprint(x / 10); pc(x % 10 + '0');}
void print(int x) {if(x < 0) pc('-'), x = -x; rprint(x);}

const int N = 30 + 5;
const int M = 100 + 5;
const int mod = 998244353;
int n, m, ans, K, v[M][N], C[N][N], f[2][N][N][N];
void add(int &x, int y) {x += y, x >= mod && (x -= mod);}

bool Med;
int main() {
	fprintf(stderr, "%.3lf\n", (&Mbe - &Med) / 1048576.0);
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	cin >> n >> m >> K;
	for(int i = 0; i <= m; i++) {
		cin >> v[i][1], v[i][0] = 1;
		for(int j = 2; j <= n; j++) v[i][j] = 1ll * v[i][j - 1] * v[i][1] % mod;
	}
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= i; j++)
			if(j == 0) C[i][j] = 1;
			else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
	f[0][0][0][0] = 1;
	for(int i = 0, p = 0, q = 1; i <= m; i++, swap(p, q)) {
		mem(f[q], 0, N);
		for(int j = 0; j <= n; j++)
			for(int k = 0; k <= n; k++)
				for(int l = 0; l <= K; l++)
					if(f[p][j][k][l])
						for(int c = 0; c + j <= n; c++) {
							int coef = 1ll * v[i][c] * C[c + j][c] % mod;
							int nk = k + c >> 1, nl = l + ((k + c) & 1);
							if(nl > K) continue;
							add(f[q][c + j][nk][nl], 1ll * coef * f[p][j][k][l] % mod);
						}
	}
	for(int p = (m + 1) & 1, i = 0; i <= n; i++)
		for(int j = 0; j <= K; j++)
			if(__builtin_popcount(i) + j <= K)
				add(ans, f[p][n][i][j]);
	cout << ans << endl;
	return cerr << "Time : " << clock() << endl, 0;
}
