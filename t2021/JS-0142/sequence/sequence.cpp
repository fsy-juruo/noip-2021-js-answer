#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const int N = 105, M = 998244353;
ull n, m, k, v[N], box[N], res = 0;

ull qsm(ull x, ull y)
{
	if(!y) return 1;
	int tmp = qsm(x, y >> 1);
	if(y & 1) return tmp * tmp % M * x % M;
	return tmp * tmp % M;
}

bool check(int x)
{
	int cnt = 0;
	while(x)
	{
		if(x & 1) cnt++;
		x >>= 1;
	}
	if(cnt <= k) return true;
	return false;
}

void dfs(int x, int y)
{
	if(y > n) return;
	if(y == n && x == 0)
	{
		int ans = 1;
		for(int i = 0; i <= m; i++)
			ans = qsm(v[i], box[i]) * ans % M;
		res += ans;
		res %= M;
		return;
	}
	for(int i = 0; i <= m; i++)
		if(x >= (1 << i))
		{
			box[i]++;
			dfs(x - (1 << i), y + 1);
			box[i]--;
		}
		else break;
}

int main()
{
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i <= m; i++)
		scanf("%d", v + i);
	for(int i = n; i <= n * (1 << m); i++)
		if(check(i))
			dfs(i, 0);
	printf("%d\n", res);
	return 0;
}

