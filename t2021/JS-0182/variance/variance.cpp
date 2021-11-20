#include <bits/stdc++.h>
#define LL long long
#define N 10005
using namespace std;

int n, ans, a[N], cnt[N];
int S, SS;

inline void dfs(int lst, int SS, int S)
{
	if (cnt[lst] > n) return;
	ans = min(ans, n * SS - S * S);
	//printf("%d %d %d\n", lst, n * SS - S * S, cnt[lst]);
	int newSS = SS, newS = S;
	if (lst == -1)
	{
		for (int i = 2; i < n; ++i)
			if (cnt[i] < n && a[i] * 2 != a[i - 1] + a[i + 1])
			{
				++cnt[i];
				newSS = SS - a[i] * a[i], newS = S - a[i];
				a[i] = a[i - 1] + a[i + 1] - a[i];
				newSS += a[i] * a[i], newS += a[i];
				dfs(i, newSS, newS);
				a[i] = a[i - 1] + a[i + 1] - a[i];
				--cnt[i];
			}
	}
	else
	{
		if (lst >= 2 && cnt[lst - 1] < n)
		{
			if (a[lst - 1] * 2 != a[lst - 2] + a[lst])
			{
				++cnt[lst - 1];
				newSS = SS - a[lst - 1] * a[lst - 1], newS = S - a[lst - 1];
				a[lst - 1] = a[lst - 2] + a[lst] - a[lst - 1];
				newSS += a[lst - 1] * a[lst - 1], newS += a[lst - 1];
				dfs(lst - 1, newSS, newS);
				a[lst - 1] = a[lst - 2] + a[lst] - a[lst - 1];
				--cnt[lst - 1];
			}
		}
		if (lst <= n - 2 && cnt[lst + 1] < n)
		{
			if (a[lst + 1] * 2 != a[lst + 2] + a[lst])
			{
				++cnt[lst + 1];
				newSS = SS - a[lst + 1] * a[lst + 1], newS = S - a[lst + 1];
				a[lst + 1] = a[lst + 2] + a[lst] - a[lst + 1];
				newSS += a[lst + 1] * a[lst + 1], newS += a[lst + 1];
				dfs(lst + 1, newSS, newS);
				a[lst + 1] = a[lst + 2] + a[lst] - a[lst + 1];
				--cnt[lst + 1];
			}
		}
	}
}

int main()
{
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", a + i);
		S += a[i], SS += a[i] * a[i];
	}
	ans = n * SS - S * S;
	dfs(-1, SS, S);
	printf("%d\n", ans);
	return 0;
}

