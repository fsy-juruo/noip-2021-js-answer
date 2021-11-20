#include <bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
using namespace std;
typedef long long ll;
const int Inf = 0x3f3f3f3f;

const int jt = 998244353;
void inline add(int &a, int b) { a += b - jt; a += (a >> 31) & jt; }
void inline sub(int &a, int b) { a -= b; a += (a >> 31) & jt; }
void inline mul(int &a, int b) { a = 1ll * a * b % jt; }
int inline Add(int a, int b) { return a + b >= jt ? a + b - jt : a + b; }
int inline Sub(int a, int b) { return a - b < 0 ? a - b + jt : a - b; }
int inline Mul(int a, int b) { return 1ll * a * b % jt; }

int N, M, K;
int a[106], am[106][106];
int C[33][33];
int dp[33][106][33][33];

int main() {
	freopen("sequence.in", "r", stdin);
	#ifndef Acetyl
	freopen("sequence.out", "w", stdout);
	#endif
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i <= M; ++i) {
		scanf("%d", a + i);
		am[i][0] = 1;
		for (int j = 1; j <= N; ++j) am[i][j] = Mul(am[i][j - 1], a[i]);
	}
	for (int i = M + 1; i <= M + 5; ++i) am[i][0] = 1;
	for (int i = 0; i <= N; ++i) C[i][0] = 1;
	for (int i = 1; i <= N; ++i) for (int j = 1; j <= i; ++j) C[i][j] = Add(C[i - 1][j], C[i - 1][j - 1]);
	dp[0][0][0][0] = 1;
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j <= M + 4; ++j) {
			for (int k = 0; k <= N; ++k) {
				for (int l = 0; l <= K; ++l) {
					for (int ni = i; ni <= N; ++ni) {
						int nk = k + ni - i;
						add(dp[ni][j + 1][nk >> 1][l + (nk & 1)], Mul(dp[i][j][k][l], Mul(C[ni][i], am[j][ni - i])));
					}
				}
			}
		}
	}
	int ans = 0;
	for (int l = 0; l <= K; ++l) add(ans, dp[N][M + 5][0][l]);
	printf("%d\n", ans);
	return 0;
}
