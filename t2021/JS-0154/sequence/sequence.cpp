#include<bits/stdc++.h>
using namespace std;
#define MAXn 33
#define MAXm 111
#define MOD 998244353
typedef long long ll;
#define SIZE(X) int((X).size())

int read()
{
	int ret = 0; char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
	return ret;
}
ll readll()
{
	ll ret = 0; char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
	return ret;
}
void write(ll x)
{
	if(x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
void writeln(ll x) {write(x); putchar('\n');}

int n, m, k;
ll v[MAXm], ans, f[MAXn][123456];
set<int> s;
set<int>::iterator it;
vector<int> ve;

int calc(int x)
{
	int ret = 0;
	while(x) ++ret, x -= x & -x;
	return ret;
}

void dp()
{
	for(int i = 0;i <= m;++i) f[1][1 << i] = v[i], s.insert(1 << i);
	for(int i = 2;i <= n;++i)
	{
		ve.clear();
		for(it = s.begin();it != s.end();++it)
			for(int j = 0;j <= m;++j)
			{
				f[i][(*it) + (1 << j)] = (f[i][(*it) + (1 << j)] + f[i - 1][*it] * v[j]) % MOD;
				ve.push_back((*it) + (1 << j));
			}
		for(int j = 0;j < SIZE(ve);++j) s.insert(ve[j]);
	}
	for(it = s.begin();it != s.end();++it)
		if(calc(*it) <= k)
			ans = (ans + f[n][*it]) % MOD;
}

int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n = read(); m = read(); k = read();
	for(int i = 0;i <= m;++i) v[i] = readll();
	dp();
	writeln(ans);
	return 0;
}
