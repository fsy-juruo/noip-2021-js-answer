#include <cstdio>
const int N = 1e4+3;
int n;
int a[N];
long long pj, ans;
int main()
{
	freopen ("variance.in", "r", stdin);
	freopen ("variance.out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf ("%d", &a[i]), pj+=a[i];
	ans += pj*pj;
	for (int i = 0; i < n; ++i)
	{
		ans += n*a[i]*a[i];
		ans -= 2*a[i]*pj;
	}
	printf ("%lld", ans);
	return 0;
}
