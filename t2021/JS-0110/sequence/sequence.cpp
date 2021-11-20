#include <bits/stdc++.h>
#define FILE
using namespace std;
typedef long long ll;
const string FILENAME = "sequence";
const ll MOD = 998244353;
ll add(const ll &x, const ll &y)
{
	return (x + y) % MOD;
}
inline ll mult(const ll &x, const ll &y)
{
	return x * y % MOD;
}
ll C[35][35];
template <typename T>
void read(T &x)
{
	char c;bool f = 0;
	while (!isdigit(c = getchar())) f ^= (c == '-');
	x = (c ^ 48);
	while (isdigit(c = getchar())) x = (x << 3) + (x << 1) + (c ^ 48);
	if (f) x = -x;
}
template <typename T>
T read()
{
	T x;
	read(x);
	return x;
}
int n, m, k;
ll v[105], ans;
int x[105];
bool judge()
{
	ll s = 0;
	for (int i = 0;i <= m;++i) s += x[i] * (1ll << i);
	return __builtin_popcountll(s) <= k;
}
ll value()
{
	int tmp = n;ll res = 1;
	for (int i = 0;i < m;++i)
		res = mult(res, C[tmp][x[i]]), tmp -= x[i];
	for (int i = 0;i <= m;++i)
		for (int j = 0;j < x[i];++j)
			res = mult(res, v[i]);
	return res;
}
void dfs(int dep = 0, int sum = 0)
{
	if (dep == m)
	{
		x[m] = n - sum;
		if (judge())
		{
			ans = add(ans, value());
		}
		return ;
	}
	for (x[dep] = 0;x[dep] <= n - sum;++x[dep])
		dfs(dep+1, sum+x[dep]);
}
int main()
{
#ifdef FILE
	freopen((FILENAME+".in").c_str(), "r", stdin);
	freopen((FILENAME+".out").c_str(), "w", stdout);
#endif
    for (int i = 0;i <= 30;++i)
    	C[i][0] = C[i][i] = 1;
    for (int i = 1;i <= 30;++i)
    	for (int j = 1;j < i;++j)
    		C[i][j] = C[i-1][j] + C[i-1][j-1];
    read(n);read(m);read(k);
    for (int i = 0;i <= m;++i) read(v[i]);
    dfs();
    printf("%lld\n", ans);
	return 0;
}

