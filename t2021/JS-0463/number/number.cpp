#include<bits/stdc++.h>
using namespace std;
bool b[10000001];
int t, x, a[10000001], n;
void init()
{
	for ( int i = 1; i <= 10000000; i++ )
	{
		if ( b[i] )
			continue;
		bool bb = 0;
		int k = i;
		while ( k )
		{
			if ( k % 10 == 7 )
			{
				bb = 1;
				break;
			}
			k /= 10;
		}
		if ( bb )
			for ( int j = 1; j * i <= 10000000; j++ )
				b[j * i] = 1;
	}
	for ( int i = 1; i <= 10000000; i++ )
		if ( !b[i] )
			a[++n] = i;
}
int mid_search(int l, int r, int f)
{
	if ( l > r )
		return -1;
	int mid = (l + r) / 2;
	if ( a[mid] == f )
		return mid;
	if ( a[mid] > f )
		mid_search(l, mid - 1, f);
	else
		mid_search(mid + 1, r, f);
}
int main ()
{
    freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> t;
	init();
	while ( t-- )
	{
		cin >> x;
		if ( b[x] )
			cout << -1 << endl;
		else
		{
			int wh = mid_search(1, n, x);
			cout << a[wh + 1] << endl;
		}
	}
	return 0;
}
