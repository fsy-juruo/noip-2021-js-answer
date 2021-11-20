#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;
const LL INF = 0x3f3f3f3f3f3f3f3f;

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

int n, a[10005], m, d, l, t;
LL dp[1500005];

void trans(int dif)
{
	l -= dif; d -= dif;
	for(int i = l; i <= 2 * m; i ++)
	dp[i] = min(dp[i + dif] + (LL)(i - m) * (i - m), dp[i] + (LL)(i - d - m) * (i - d - m));
}

int main()
{
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	
	IO::getU(n);
	rep(i, n) IO::getU(a[i]);
	d = a[n - 1] - a[0];
	rep(i, n - 1) a[i] = a[i + 1] - a[i];
	sort(a, a + n - 1);
	reverse(a, a + n - 1);
	l = m = d = n * d;
	memset(dp, 0x3f, sizeof(dp));
	for(int i = 0; i <= m; i ++) dp[i + m] = (LL)(i) * i + (LL)(i - m) * (i - m);
	rep(i, n - 1) if(a[i]) trans(n * a[i]);
	else t ++;
	LL ans = INF;
	for(int i = 0; i <= 2 * m; i ++) ans = min(ans, dp[i] + (LL)(t - 1) * (i - m) * (i - m));
	IO::putU(ans / n); IO::putC('\n');
	IO::flO();
	return 0;
}
