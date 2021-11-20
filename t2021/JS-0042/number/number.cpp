// 2021.11.20, NOIP2021
// Code by LTb
// 地球最后的告白。
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define int long long
#define fi first
#define se second
#define debug printf("Passing Line %d in function [%s].\n", __LINE__, __FUNCTION__)
inline void chmax(int &x, int y) {x = max(x, y);}
inline void chmin(int &x, int y) {x = min(x, y);}

const int MOD = 998244353;
inline int add(int x, int y){return (x+y>=MOD)?(x+y-MOD):((x+y<0)?(x+y+MOD):(x+y));}

inline int read() {
	int x=0,f=1;
	char c='.';
	while (c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while (c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return f*x;
}

const int MAXN = 10000050;
int q;

bool ok[MAXN];
int li[MAXN], tot = 0;
inline bool chk(int x) {
	if (x % 7 == 0) return false;
	while (x) {
		if (x % 10 == 7) return false;
		x /= 10;
	}
	return true;
}

void pre() {
	memset(ok, true, sizeof(ok));
	for (int i = 1; i <= MAXN - 49; i++) {
		if (!chk(i) && ok[i]) {
			ok[i] = false;
			for (int j = i * 2; j <= MAXN - 50; j += i)
				ok[j] = false;
		}

		if (ok[i]) {
			li[++tot] = i;
		}
	}
}

signed main()

{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	pre();
	// debug;
	q = read();
	while (q--) {
		int x = read();
		if (!ok[x]) {
			puts("-1");
			continue;
		}

		int pos = upper_bound(li + 1, li + 1 + tot, x) - li;
		printf("%d\n", li[pos]);
	}
	return 0;
}