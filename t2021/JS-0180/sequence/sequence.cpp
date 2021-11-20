#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1e6+7;
const int M = 998244353;
int n, m, k, tot;
int a[107], lo[107];
int s[N];
long long ans = 0;
int main()
{
	freopen ("sequence.in", "r", stdin);
	freopen ("sequence.out", "w", stdout);
	scanf ("%d %d %d", &n, &m, &k);
	for (int i = 0; i <= m; ++i)
		scanf ("%d", &a[i]);
	for (int i = n; i <= (n<<m); ++i)
	{
		int er = i, t = 0;
		while (er)
		{
			if (er%2) ++t;
			er >>= 1;
		}
		if (t <= k) s[tot++] = i;
	}
//	for (int i = 0; i < tot; ++i)
//		printf ("%d ", s[i]);
	for (int r = 0; r < tot; ++r){
	int max = 1;
	for (int j = 0; j < n; ++j) max *= m+1;
	max -= 1;
	for (int i = 0; i <= max; ++i)
	{
		int kas = 0, cf = i;
		for (int j = 0; j < n; ++j) 
		{
			kas += 1<<(cf%(m+1));
			cf /= m+1;
		}
		if (kas == s[r]) 
		{
			cf = i;
			int pl = 1;
			for (int j = 0; j < n; ++j) 
			{
				pl *= a[cf%(m+1)];
	//			cout << cf%(m+1) <<' ';
				cf /= m+1;
			}
			ans += pl;
			ans = ans%M;
//			cout << endl;
		}
	}
	}
	cout << ans;
	return 0;
}
