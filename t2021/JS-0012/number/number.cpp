//O(n log log n) seems slower than brute force
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

const int MAXN = 10005000;
bool ok[10005005];
int nxt[10005005];

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	ok[0] = true;
	rep1(i, MAXN) ok[i] = ok[i / 10] & (i % 10 != 7);
	for(int i = MAXN; i >= 1; i --) if(!ok[i]) for(int j = i * 2; j <= MAXN; j += i) ok[j] = false;
	for(int i = MAXN; i >= 1; i --) nxt[i] = ok[i] ? i : nxt[i + 1];
	
	int q, x;
	IO::getU(q);
	rep(i, q) {
		IO::getU(x);
		if(ok[x]) IO::putU(nxt[x + 1]);
		else {
			IO::putC('-'); IO::putC('1');
		}
		IO::putC('\n');
	}
	IO::flO();
	return 0;
}
