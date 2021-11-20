#include <bits/stdc++.h>
#define ll long long
#define maxn 10010
#define dis(l) (abs(2 * l - E))
using namespace std;
inline ll read()
{
	ll X = 0; bool f = false; char ch = getchar();
	while (ch > '9' || ch < '0') {f |= ch == '-'; ch = getchar();}
	while (ch <= '9' && ch >= '0') {X = (X << 3) + (X << 1) + (ch ^ 48); ch = getchar();}
	return f ? -X : X;
}
inline void write(ll X)
{
	if (X == 0) {putchar('0'); return;}
	if (X < 0) {putchar('-'); X = -X;}
	short num[16], cnt = 0;
	while (X) {num[++cnt] = X % 10; X /= 10;}
	while (cnt) putchar(num[cnt--] ^ 48);
	return;
}
vector < ll > a;
ll n, x, loc, sum, ans;
double s, E, delta = 114514, ch = 0;
ll erfen(int fnd)
{
	ll l = 0, r = a.size() - 1, mid = (r + l + 1) >> 1;
	while (l < r)
	{
		if (a[mid] <= fnd) {l = mid; mid = (r + l + 1) >> 1;}
		else {r = mid - 1; mid = (r + l + 1) >> 1;}
	}
	return l;
}
int main()
{
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	n = read();
	x = read(); E += x; s += x; a.push_back(x);
	for (int i = 2; i <= n; ++i) {x = read(); a.push_back(x); s += x;}
	E += x;
	s /= n; E /= 2;
	while (delta > 0)
	{
		delta = 0;
		for (ll i = 1; i < n - 1; ++i)
		{
			if (abs(s - E) - abs((s * n - 2 * a[i] + a[i - 1] + a[i + 1]) / n - E) > delta
			|| (abs(s - E) - abs((s * n - 2 * a[i] + a[i - 1] + a[i + 1]) / n - E) == delta && dis(a[i]) - dis(a[i - 1] + a[i + 1] - a[i]) > ch))
			{
				loc = i; delta = abs(s - E) - abs((s * n - 2 * a[i] + a[i - 1] + a[i + 1]) / n - E); ch = dis(a[i]) - dis(a[i - 1] + a[i + 1] - a[i]);
			}
		}
		a.insert(a.begin() + erfen(a[loc - 1] + a[loc + 1] - a[loc]) + 1, a[loc - 1] + a[loc + 1] - a[loc]);
		a.erase(a.begin() + loc);
		s = 0; for (int i = 0; i < n; ++i) s += a[i]; s /= n;
	}
	for (int i = 0; i < n; ++i) {ans += n * a[i] * a[i]; sum += a[i];}
	ans -= sum * sum;
	write(ans);
	return 0;
}
