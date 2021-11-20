#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

namespace IO
{
	const int BSIZ = 4096;
	char bufi[4105], bufo[4105];
	int posi = BSIZ, poso;
	void flI()
	{
		fread(bufi, 1, BSIZ, stdin); posi = 0;
	}
	void flO()
	{
		fwrite(bufo, 1, poso, stdout); poso = 0;
	}
	void getC(char& ch)
	{
		if(posi == BSIZ) flI();
		ch = bufi[posi ++];
	}
	void putC(char ch)
	{
		if(poso == BSIZ) flO();
		bufo[poso ++] = ch;
	}
	template<typename T>
	void getU(T& x)
	{
		char ch; x = 0;
		do getC(ch);
		while(ch < '0' || ch > '9');
		do {
			x = x * 10 + (ch - '0'); getC(ch);
		} while(ch >= '0' && ch <= '9');
	}
	char buf[25];
	template<typename T>
	void putU(T x)
	{
		int len = 0;
		do {
			buf[len ++] = x % 10 + '0'; x /= 10;
		} while(x > 0);
		for(int i = len - 1; i >= 0; i --) putC(buf[i]);
	}
}

int n, m, t, v[115]; 
int dp[35][35][35], ndp[35][35][35], tmp[35], fac[35], ifac[35];
int power(int x, int t)
{
	int ret = 1;
	while(t > 0) {
		if(t & 1) ret = 1ULL * ret * x % MOD;
		x = 1ULL * x * x % MOD;
		t >>= 1; 
	}
	return ret;
}
void trans(int coef)
{
	tmp[0] = 1;
	rep1(i, n) tmp[i] = 1ULL * tmp[i - 1] * coef % MOD;
	for(int i = 0; i <= n; i ++) tmp[i] = 1ULL * tmp[i] * ifac[i] % MOD;
	memset(ndp, 0, sizeof(ndp));
	for(int i = 0; i <= t; i ++) for(int j = 0; j <= n; j ++) for(int k = max(i, j); k <= n; k ++)
	ndp[i + (j & 1)][j >> 1][k] = (ndp[i + (j & 1)][j >> 1][k] + dp[i][j][k]) % MOD;
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i <= t; i ++) for(int j = 0; j <= n; j ++) for(int k = max(i, j); k <= n; k ++) for(int l = 0; l + k <= n; l ++)
	dp[i][j + l][k + l] = (dp[i][j + l][k + l] + 1ULL * ndp[i][j][k] * tmp[l]) % MOD;
}

int main()
{
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	
	IO::getU(n); IO::getU(m); IO::getU(t);
	m ++; rep(i, m) IO::getU(v[i]);
	fac[0] = 1;
	rep1(i, n) fac[i] = 1ULL * fac[i - 1] * i % MOD;
	ifac[n] = power(fac[n], MOD - 2);
	for(int i = n; i >= 1; i --) ifac[i - 1] = 1ULL * ifac[i] * i % MOD;
	
	dp[0][0][0] = 1;
	rep(i, m + 10) trans(v[i]);
	int ans = 0;
	for(int i = 0; i <= t; i ++) ans = (ans + dp[i][0][n]) % MOD;
	ans = 1ULL * ans * fac[n] % MOD;
	IO::putU(ans); IO::putC('\n');
	IO::flO();
	return 0;
}
