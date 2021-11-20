#include<bits/stdc++.h>
using namespace std;
int n;
double a[10010],mid,tot,ans;
void dfs(int x,double ax,double by)
{
	for(int i=2;i<n;i++)
	{
		if(i==x||a[i]>by&&a[i-1]+a[i+1]>=2*a[i]||a[i]<by&&a[i-1]+a[i+1]<=a[i]*2)continue;
		if(a[i]>by&&a[i-1]+a[i+1]<2*a[i]||a[i]<by&&a[i-1]+a[i+1]>2*a[i])
		{
			double Q=a[i];
			a[i]=a[i-1]+a[i+1]-a[i];
			double WWW=ax-Q+a[i];
			double QQQ=WWW/n;
			double answ=0;
			for(int i=1;i<=n;i++)
			    answ+=(QQQ-a[i])*(QQQ-a[i]);
			answ*=n;
			ans=min(ans,answ);
			dfs(i,WWW,QQQ);
			a[i]=Q;
		}
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		tot+=a[i];
	}
	mid=tot/n;
	for(int i=1;i<=n;i++)
	    ans+=(mid-a[i])*(mid-a[i]);
	ans*=n;
	dfs(0,tot,mid);
	cout<<ans;
	return 0;
}
