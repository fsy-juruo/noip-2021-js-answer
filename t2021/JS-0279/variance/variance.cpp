#include<bits/stdc++.h>
#define ll long long
#define i2 (a[i - 1] + a[i + 1] - a[i])
#define arg2 (argd - 2 * a[i] + a[i + 1] + a[i - 1])
using namespace std;

ll n, a[701];
bool sur;

ll argd, ans, argds;

int main()
{
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	
	scanf("%lld", &n);
	for(int i = 1; i <= n; i ++)
	{
		scanf("%lld", &a[i]);
		argd += a[i];
		argds += n * a[i] * a[i];
	}
	
	int i = 2;
	int w = 14;
	while(w --)
	{
		if(i == n)
			i = 2;
		
//		if(n * (a[i] * a[i] - i2 * i2) > 2 * (a[i] * argd - i2 * arg2))

//		ll x = argds - n * a[i] * a[i] + n * (a[i + 1] + a[i - 1] - a[i]) * (a[i + 1] + a[i - 1] - a[i]) - arg2 * arg2;
//		cout << x << endl;

		if(argds - argd * argd > argds - n * a[i] * a[i] + n * (a[i + 1] + a[i - 1] - a[i]) * (a[i + 1] + a[i - 1] - a[i]) - arg2 * arg2)
		{
			argd = arg2;
			argds = argds - n * a[i] * a[i] + n * (a[i + 1] + a[i - 1] - a[i]) * (a[i + 1] + a[i - 1] - a[i]);
			a[i] = i2;
		}
		
		i ++;
	}

	ans = argds - pow(argd, 2);
	
	printf("%lld", ans);
	
	return 0;
}
