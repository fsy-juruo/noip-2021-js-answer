#include<bits/stdc++.h>
#define int long long
using namespace std;

const long long mod = 998244353;
int n, m, k, S, ans;
int jc[105], v[105], cnt[105];

int ksm(int a, int b) {
	int ans = 1;
	while(b) {
		if(b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1; 
	}
	return ans;
}

bool check(int x) {
	int tot = 0;
	while(x) {
		x -= (x & (-x)); ++tot;
	}
	return tot <= k;
}

int C(int n, int m) {
	int fz = jc[n];
	int fm = jc[m] * jc[n - m] % mod;
	return fz * ksm(fm, mod - 2) % mod;
}

int calc() {
	int ans = 1, sum = n;
	for(int i = 0; i <= m; ++i) {
		ans = ans * C(sum, cnt[i]) % mod;
		sum -= cnt[i];
	}
	for(int i = 0; i <= m; ++i) {
		ans = ans * ksm(v[i], cnt[i]) % mod;
	}
	return ans;
}

void dfs(int tot, int qz, int lef, int s) {
	if(qz >= 0) {
		if(tot + lef * ksm(2, qz) < S) return;
		if(tot > S) return;
	}
	if(qz < 0) {
		if(tot == S && !lef) {
			ans =(ans + calc()) % mod; return;
		}
		 return;
	}
	
	for(int i = 0; i <=lef; ++i) {
		cnt[qz] = i;
		dfs(tot + i * ksm(2, qz), qz - 1, lef - i, s);
	}
	cnt[qz] = 0;
}

signed main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	jc[0] = 1;
	for(int i = 1; i <= 100; ++i) {
		jc[i] = jc[i - 1] * i % mod;
	} 
	scanf("%lld%lld%lld", &n, &m, &k);
	for(int j = 0; j <= m; ++j) scanf("%lld", &v[j]);
	for(S = n; S <= n * ksm(2, m); ++S) {
		if(check(S)) {
			dfs(0, m, n, S);
		}
	}
	cout << ans;
	return 0;
}


