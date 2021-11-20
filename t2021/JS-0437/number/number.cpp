#include<bits/stdc++.h>
using namespace std;
struct P100
{
	bool f[10001005];
	int a[800005];
	int k=0,n=10001000;
	inline bool ok(int x)
	{
		int y=x;
		while(y)
		{
			if(y%10==7)
			{
				for(register int i=x;i<=n;i+=x)f[i]=1;
				return 0;
			}
			y/=10;
		}
		return 1;
	}
	void shai()
	{
		for(register int i=1;i<=n;i++)if(!f[i]&&ok(i))a[k++]=i;
	}
	void solve()
	{
		shai();
		int tt,n;
		scanf("%d",&tt);
		while(tt--)
		{
			scanf("%d",&n);
			int x=lower_bound(a,a+k,n)-a;
			if(a[x]!=n)printf("-1\n");
			else printf("%d\n",a[x+1]);
		}
	}
}p100;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	p100.solve();
	return 0;
}
