#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
#define debug printf
#else
#define debug(...)
#endif
int read()
{
	int s = 0,f = 1;
	char c = getchar();
	while(!isdigit(c))
	{
		if(c == '-')
		{
			f = 0;
		}
		c = getchar();	
	} 
	while(isdigit(c))
	{
		s = s * 10 + c - '0';
		c = getchar();
	}
	return f ? s : -s;
}
ll readll()
{
	ll s = 0,f = 1;
	char c = getchar();
	while(!isdigit(c))
	{
		if(c == '-')
		{
			f = 0;
		}
		c = getchar();	
	} 
	while(isdigit(c))
	{
		s = s * 10 + c - '0';
		c = getchar();
	}
	return f ? s : -s;
}
int a[10005];
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
//auto beg = clock();
	srand(19260817);
	int n;
	scanf("%d",&n);
	int T = 60000000 / n;
	ll presum = 0,presqr = 0;
	ll ans = 0;
	for(int i = 1;i <= n; ++i)
	{
		a[i] = read();
		presum += a[i];
		presqr += a[i] * a[i];
	}
	ans = n * presqr - presum * presum;
	while(T--)
	{
		int fg = 0;
		for(int i = 2;i < n; ++i)
		{
			ll pre = n * presqr - presum * presum;
			ll now = a[i - 1] + a[i + 1] - a[i];
			ll nowans = n * (presqr - a[i] * a[i] + now * now) + presum * presum 
						- (presum - a[i] + now) * (presum - a[i] + now);
//			printf("i = %d,nowans = %lld\n",i,nowans);
			if(nowans < pre)
			{
				fg = 1;
				presum = presum - a[i] + now;
				presqr = presqr - a[i] * a[i] + now * now;
				a[i] = now;
			}
		}
		if(fg == 0)
		{
			int t = rand() % (n - 2) + 2;
			ll now = a[t - 1] + a[t + 1] - a[t];
			presum = presum - a[t] + now;
			presqr = presqr - a[t] * a[t] + now * now;
			a[t] = now;
		}
		ans = min(ans,n * presqr - presum * presum);
	}
//	auto e = clock();
//	printf("%.2f\n",((double)e - beg) / 1000.0);
	printf("%lld\n",ans);
	return 0;
}
