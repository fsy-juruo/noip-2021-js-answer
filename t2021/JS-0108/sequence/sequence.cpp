#include <bits/stdc++.h>
#define Mod 998244353
#define LL long long
using namespace std;

int f[130005][25], n, m, k, er[130005], v[305], d;

LL C[2005][2005];

LL ans = 0;

LL calc(int now)
{
	LL Sum = 1, tot = 0;
	for (int i = 0; i <= d; i++)
		tot += f[now][i];
	for (int i = 0; i <= m; i++)
	{
		if (f[now][i])
		{
			Sum = Sum * C[tot][f[now][i]] % Mod;
			tot -= f[now][i];
		}
	}
	if (tot != 0) return 0;
	return Sum;
}

LL ksm(LL x, LL y)
{
	LL res = 1;
	while (y)
	{
		if (y & 1) res = res * x % Mod;
		x = x * x % Mod;
		y >>= 1;
	}
	return res;
}

LL ca(int now)
{
	LL Sum = 1;
	for (int i = 0; i <= m; i++)
		Sum = Sum * ksm(v[i], f[now][i]) % Mod;
	return Sum;
}

void dfs(int now, int x, int lasti)
{ 
	if (x == n) 
	{
		(ans += calc(now) * ca(now)) %= Mod;
		return ;
	}	
	for (int i = lasti; i >= 1; i--)
		if (f[now][i])
		{
			f[now][i]--;
			f[now][i - 1] += 2;	
			dfs(now, x + 1, i);
			f[now][i]++;
			f[now][i - 1] -= 2;
		}
}

int check(int x)
{
	int now = x, Sum = 0, t = 0;
	while (x)
	{
		f[now][t++] = x % 2;
		Sum += (x % 2);
		x /= 2;
	}
	return Sum;
}

int main()
{
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	d = log2(n * (1 << m));
	for (int i = 0; i <= m; i++)
		scanf("%d", &v[i]);
	for (int i = n; i <= n * (1 << m); i++)	
		er[i] = check(i);
	for (int i = 1; i <= n; i++)	
		C[i][0] = 1;
	C[1][1] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= n; j++)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % Mod;
	for (int i = n; i <= n * (1 << m); i++)
		if (er[i] <= k)
			dfs(i, er[i], d);
	printf("%lld\n", ans);
	return 0;
}

