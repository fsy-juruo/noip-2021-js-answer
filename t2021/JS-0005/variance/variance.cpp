#include <bits/stdc++.h>
using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3f;

void chmin(long long &x, long long y) {
	x = min(x, y);
}

int n;
int a[10010];
long long f[500010];
long long tmp[500010];

long long VAL(int x) {
	return 1ll * x * (x + 1) * (2 * x + 1) / 6;
}

int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	n--;
	for (int i = 0; i < n; i++) {
		a[i] = a[i + 1] - a[i];
	}
	sort(a, a + n);
	int S = 0;
	for (int i = 0; i < n; i++) {
		S += a[i];
	}
	memset(f, 0x3f, sizeof(f));
	for (int T = 0; T <= n * S; T++) {
		int nT = T + S;
		long long A = (n + 2) * S - nT;
		f[T] = -A * A;
//		f[T] = 0;
	}
	for (int i = n - 1; i >= 0; i--) {
		int x = a[i];
		int sz = 1;
		while (i - sz >= 0 && a[i - sz] == x) sz++;
		int M = (i + 1) * S;
		S -= x * sz, i -= sz - 1;
		for (int T = 0; T <= i * S; T++) {
			long long res = INF; int nT = T; long long A = (i + 1) * S - T;
			tmp[0] = 0;
			for (int j = 1; j <= sz; j++) {
				tmp[j] = tmp[j - 1] + (S + j * x) * (S + j * x);
			}
			for (int j = 0; j <= sz; j++) {
				int nT = T + 1ll * (sz - j) * (i + 1 + i + sz - j) / 2 * x;
				int nS = S + 1ll * (sz - j) * x;
				int ni = i + sz - j;
				long long wei = tmp[sz - j];
				long long nA = (ni + 1) * nS - nT;
				int nnT = nT + 1ll * j * (j + 1) / 2 * x + nS * j;
				wei += 1ll * x * x * VAL(j);
				wei += 2ll * j * x * nA + 1ll * x * x * ni * j * j;
//				int nT = T + S * j;
//				long long wei = tmp[sz - j] + 2ll * j * x * A + 1ll * x * x * i * j * j;
				wei *= (n + 1);
				chmin(res, f[nnT] + wei);
			}
			f[T] = res;
		}
		for (int T = i * S + 1; T <= M; T++) {
			f[T] = INF;
		}
	}
	printf("%lld\n", f[0]);
	return 0;
}

