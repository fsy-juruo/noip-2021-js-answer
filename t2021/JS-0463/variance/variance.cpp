#include<bits/stdc++.h>
using namespace std;
long long mmin = 10000000000000;
int main ()
{
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	int n, a[100001], now = 1;
	cin >> n;
	for ( int i = 1; i <= n; i++ )
		cin >> a[i];
	for ( int i = 1; i <= (n - 1) * (n - 2); i++ )
	{
		now++;
		if ( now == n )
			now = n - 1;
		a[now] = a[now - 1] + a[now + 1] - a[now];
		int s = 0, sum = 0;
		for ( int i = 1; i <= n; i++ )
			s += a[i] * a[i], sum += a[i];
		long long k = s * n - sum * sum;
		mmin = min(mmin, k);
	}
	cout << mmin << endl;
	return 0;
}
