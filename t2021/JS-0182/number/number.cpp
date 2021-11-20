#include <bits/stdc++.h>
#define LL long long
#define N 200050
using namespace std;

LL n, m, lst, a[N];
LL tot, num[N];
set < LL > s;
set < LL > :: iterator it;
vector < LL > ans;

inline bool check(int x)
{
	while (x)
	{
		if (x % 10 == 7) return 1;
		x /= 10;
	}
	return 0;
}

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%lld", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%lld", a + i);
		m = max(m, a[i]);
	}
	for (int i = 7; i <= (m << 1); ++i)
	{
		if (check(i)) s.insert(i), num[++tot] = i;
	}
	for (int i = 1; i <= tot; ++i)
	{
		for (int j = 2; j * num[i] <= (m << 1); ++j)
			s.insert(j * num[i]);
	}
	for (it = s.begin(); it != s.end(); ++it)
	{
		if (it == s.begin())
		{
			lst = *it;
			continue;
		}
		if (lst + 1 != *it) ans.push_back(lst + 1);
		lst = *it;
	}
	for (int i = 1; i <= n; ++i)
	{
		it = lower_bound(s.begin(), s.end(), a[i]);
		if (*it == a[i]) puts("-1");
		else
		{
			if (*it != a[i] + 1) printf("%lld\n", a[i] + 1);
			else printf("%lld\n", *upper_bound(ans.begin(), ans.end(), a[i]));
		}
	}
	/*for (it = s.begin(); it != s.end(); ++it)
		printf("%d ", *it);
	putchar('\n');
	for (int i = 0; i < ans.size(); ++i)
		printf("%d ", ans[i]);*/
	return 0;
}

