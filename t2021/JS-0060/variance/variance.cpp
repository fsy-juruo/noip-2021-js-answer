#include<bits/stdc++.h>

using namespace std;

int n;

int a[5];

int cal()
{
	int ret=0;
	int s=0;
	for(int i=1;i<=n;++i)
	{
		ret+=n*a[i]*a[i];
		s+=a[i];
	}
	ret-=s*s;
	return ret;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	if(n<=2)
	{
		printf("%d\n",cal());
		return 0;
	}
	else if(n==3)
	{
		int ans=cal();
		a[2]=a[1]+a[3]-a[2];
		ans=min(ans,cal());
		printf("%d\n",ans);
		return 0;
	}
	else if(n==4)
	{
		int ans=cal();
		for(int i=1;i<=3;++i)
		{
			a[2]=a[1]+a[3]-a[2];
			ans=min(ans,cal());
			a[3]=a[2]+a[4]-a[3];
			ans=min(ans,cal());
		}
		for(int i=1;i<=3;++i)
		{
			a[3]=a[2]+a[4]-a[3];
			ans=min(ans,cal());
			a[2]=a[1]+a[3]-a[2];
			ans=min(ans,cal());	
		}
		printf("%d\n",ans);
	}
	return 0;
}
