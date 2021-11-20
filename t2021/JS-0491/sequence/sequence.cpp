#include <bits/stdc++.h>
using namespace std;

int minv(int a, int m) {
	assert(a != 0);
	if (a == 1) return 1;
	else return int64_t(m-m/a) * minv(m%a, m) % m;
}
template <int MOD>
struct modnum {
	int v;
	modnum(int64_t v_ = 0) : v((v_%MOD+MOD)%MOD) { }
	
	modnum& operator+=(const modnum& o) {
		v += o.v;
		if (v >= MOD) v -= MOD;
		return *this;
	}
	modnum& operator-=(const modnum& o) {
		v -= o.v;
		if (v < 0) v += MOD;
		return *this;
	}
	modnum& operator*=(const modnum& o) {
		v = int64_t(v)*o.v%MOD;
		return *this;
	}
	modnum inv() const { return modnum(minv(v, MOD)); }
	modnum& operator/=(const modnum& o) {
		return *this *= o.inv();
	}
	
	friend modnum pow(modnum a, int64_t n) { modnum res = 1; for (; n; n>>=1, a*=a) if (n&1) res *= a; return res; } 
	friend modnum operator+(const modnum& a, const modnum& b) { return modnum(a) += b; }
	friend modnum operator-(const modnum& a, const modnum& b) { return modnum(a) -= b; }
	friend modnum operator*(const modnum& a, const modnum& b) { return modnum(a) *= b; }
	friend modnum operator/(const modnum& a, const modnum& b) { return modnum(a) /= b; }
	
	friend istream& operator>>(istream& i, modnum& a) {
		int64_t v; i >> v;
		a = modnum(v);
		return i;
	}
	friend ostream& operator<<(ostream& o, const modnum& a) { return o << a.v; }
	
	friend bool operator==(const modnum& a, const modnum& b) { return a.v == b.v; }
	friend bool operator!=(const modnum& a, const modnum& b) { return a.v != b.v; }
};
using num = modnum<998244353>;

const int MAXN = 35, MAXM = 110, MASK = (1<<5)-1;
int N, M, K;
num V[233], dp[2][33][MAXN][MAXN][MAXN], pw[233][233], fact[233], ifact[233];
int pcnt[233];

int main() {
//	freopen("data.in", "r", stdin);
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout); 
	ios::sync_with_stdio(false), cin.tie(nullptr);
	fact[0] = 1;
	for (int i = 1; i < 233; i++) fact[i] = fact[i-1]*i;
	for (int i = 0; i < 233; i++) ifact[i] = fact[i].inv();
	for (int i = 1; i < 233; i++) {
		int x = i;
		while (x) pcnt[i] += x%2==1, x /= 2;
	}
	cin >> N >> M >> K;
	for (int i = 0; i <= M; i++) {
		cin >> V[i];
		pw[i][0] = 1;
		for (int j = 1; j <= N; j++) pw[i][j] = pw[i][j-1]*V[i];
//		cerr << pw[i][N] << '\n';
	}
	int cur = 0;
	memset(dp[0], 0, sizeof dp[0]);
	dp[0][0][0][0][0] = 1;
	for (int i = M; i >= 0; i--) {
		cur ^= 1;
		// f->g
		#define f dp[cur^1]
		#define g dp[cur]
		memset(g, 0, sizeof g);
		for (int S = 0; S < (1<<5); S++) {
			for (int c = 0; c <= N; c++) {
				for (int t = 0; t <= N; t++) {
					for (int u = 0; u <= N; u++) if (f[S][c][t][u] != 0) {
						num ft = f[S][c][t][u];
//						cerr << bitset<5>(S) << ',' << c << ',' << t << ',' << u << ": " << ft << '\n';
						int nS = (S<<1)&MASK;
						int nc = 0;
						if (S>>4&1) nc = c+1;
						else nc = 0;
						int nt = t, nu = u;
						g[nS][nc][nt][nu] += ft;
//						cerr << bitset<5>(S) << ',' << c << ',' << t << ',' << u << " -> " <<
//								bitset<5>(nS) << ',' << nc << ',' << nt << ',' << nu << '\n';
						// 2^i*T
						for (int T = 1; T+u <= N; T++) {
							if (nS == MASK) {
								if (nc > 0) {
									nt = nt - 5 - nc + 1;
									nc = 0, nS = 0, nu++;
								} else {
									nt = nt - 5 + 1;
									nc = c+1, nS = 0, nu++;
								}
							} else {
								nt = nt-pcnt[nS]+pcnt[nS+1], ++nS;
								nu++;
							}
//							cerr << "!" << pw[i][T] << '\n';
							g[nS][nc][nt][nu] += ft*pw[i][T]*ifact[T];
//							cerr << "G " << g[nS][nc][nt][nu] << '\n';
//							cerr << bitset<5>(S) << ',' << c << ',' << t << ',' << u << " -> " <<
//									bitset<5>(nS) << ',' << nc << ',' << nt << ',' << nu << '\n';
						}
					}
				}
			}
		}
	}
	num ans = 0;
	for (int S = 0; S < (1<<5); S++) {
		for (int c = 0; c <= N; c++) {
			for (int t = 0; t <= K; t++) {
				ans += dp[cur][S][c][t][N];
			}
		}
	}
	cout << fact[N]*ans << '\n';
	return 0;
}













