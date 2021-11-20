#include <bits/stdc++.h>
#define LL long long
#define mod 998244353
using namespace std;

LL n, m, k, ans;
LL v[105], num[105];
LL jc[105], inv[105];

LL power(LL x, LL y)
{
	LL sum = 1ll;
	while (y)
	{
		if (y & 1) sum = sum * x % mod;
		y >>= 1ll, x = x * x % mod;
	}
	return sum;
}

void pre()
{
	jc[0] = 1ll;
	for (int i = 1; i <= 100; ++i)
	{
		jc[i] = jc[i - 1] * i % mod;
		inv[i] = power(jc[i], mod - 2);
	}
}

LL C(LL x, LL y)
{
	return jc[x] * inv[y] % mod * inv[x - y] % mod;
}

bool check(LL x)
{
	LL cnt = 0;
	while (x)
	{
		if (x % 2) ++cnt;
		x /= 2;
	}
	return cnt <= k;
}

void dfs(int x, int cnt, int lst)
{
	if (cnt > n)
	{
		if (!x)
		{
			LL mul = 1ll, CC = 1ll, lt = n;
			for (int i = 0; i <= m; ++i)
				if (num[i]) mul = mul * power(v[i], num[i]) % mod;
			for (int i = 0; i < m; ++i)
				if (num[i]) CC = CC * C(lt, num[i]), lt -= num[i];
			ans = (ans + CC * mul % mod) % mod;
			/*printf("%lld %lld\n", mul, CC);
			for (int i = 0; i <= m; ++i) printf("%lld ", num[i]);
			putchar('\n');*/
		}
		return;
	}
	for (int i = lst; (1 << i) <= x && i <= m; ++i)
	{
		++num[i];
		dfs(x - (1 << i), cnt + 1, i);
		--num[i];
	}
}

int main()
{
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	pre();
	scanf("%lld %lld %lld", &n, &m, &k);
	for (int i = 0; i <= m; ++i)
	{
		scanf("%lld", v + i);
	}
	for (LL i = n; i <= n * power(2, m); ++i)
	{
		if (check(i))
		{
			//printf("%lld\n", i);
			dfs(i, 1, 0);
		}
	}
	printf("%lld\n", ans);
	return 0;
}

