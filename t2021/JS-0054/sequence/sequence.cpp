//pts: 90 ~ 100
#include <cstdio>

#define _P 998244353
#define _M 105
#define _N 35

struct Mod {
	long long val;
	Mod() {
		val = 0;
	}
	Mod(long long x) {
		val = (x % _P + _P) % _P;
	}
};

Mod operator +(const Mod& left, const Mod& right) {
	return left.val + right.val;
}
Mod operator -(const Mod& left, const Mod& right) {
	return left.val - right.val;
}
Mod operator *(const Mod& left, const Mod& right) {
	return left.val * right.val;
}

Mod fstpw(Mod x, long long y) {
	Mod res = 1;
	while (y) {
		if (y & 1) {
			res = res * x;
		}
		x = x * x;
		y >>= 1;
	}
	return res;
}

Mod operator /(const Mod& left, const Mod& right) {
	return left.val * fstpw(right, _P - 2).val;
}

int n, m, K;
Mod v[_M];

Mod inv[_N];
Mod fac[_N];
Mod ifac[_N];

Mod f[_M][_N][_N][_N];

int popcnt(int x) {
	int res = 0;
	while (x) {
		if (x & 1) {
			res++;
		}
		x >>= 1;
	}
	return res;
}

int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	fac[0] = ifac[0] = 1;
	inv[1] = 1;
	for (int i = 2; i < _N; i++) {
		inv[i] = Mod(_P - _P / i) * inv[_P % i];
	}
	for (int i = 1; i < _N; i++) {
		fac[i] = fac[i - 1] * Mod(i);
		ifac[i] = ifac[i - 1] * inv[i];
	}
	scanf("%d%d%d", &n, &m, &K);
	for (int i = 0; i <= m; i++) {
		scanf("%lld", &v[i].val);
	}
	Mod tpw = 1;
	for (int q = 0; q <= n; q++, tpw = tpw * v[0]) {
		f[0][q & 1][q >> 1][q] = fac[n] * ifac[q] * tpw;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j <= n; j++) {
			for (int p = 0; p <= n; p++) {
				for (int q = 0; q <= n; q++) {
					Mod pw = 1;
					for (int k = 0; k <= n - q; k++, pw = pw * v[i + 1]) {
//						printf("i: %d j: %d p: %d q: %d --k: %d-> i: %d j: %d p: %d q: %d\n", i, j, p, q, k, i + 1, j + ((p + k) & 1), (p + k) >> 1, k + q);
						f[i + 1][j + ((p + k) & 1)][(p + k) >> 1][k + q] = 
							f[i + 1][j + ((p + k) & 1)][(p + k) >> 1][k + q] 
							+ f[i][j][p][q] * pw * ifac[k];
					}
				}
			}
		}
	}
	Mod ans = 0;
	for (int j = 0; j <= K; j++) {
		for (int p = 0; p <= n; p++) {
			if (j + popcnt(p) <= K) {
				ans = ans + f[m][j][p][n];
			}
		}
	}
	printf("%lld\n", ans.val);
	return 0;
}
