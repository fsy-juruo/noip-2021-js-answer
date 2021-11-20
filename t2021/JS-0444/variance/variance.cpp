#include<bits/stdc++.h>
using namespace std;
int n;
int a[10005];
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	int num=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		num+=a[i];
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=a[i]*a[i];
	}
	ans*=n;
	ans-=(num*num);
	printf("%lld",ans);
	return 0;
}
