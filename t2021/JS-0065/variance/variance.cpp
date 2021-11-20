#include<bits/stdc++.h>
#define ll long long
using namespace std;
double ans=INT_MAX,s,c;
int a[10005],n;
void dfs(int dep)
{
	if (dep>n)
	{
		c=s=0;
		for (int i=1;i<=n;i++)c+=a[i];
		c=c/n;
	//	cout<<c<<endl;
		for (int i=1;i<=n;i++)
		{
			s=s+(a[i]*1.0-c)*(a[i]*1.0-c);
		}
	//	cout<<s<<endl;
		s=s*n;
		ans=min(ans,s);
		return ;
	}
	dfs(dep+1);
	if (dep>1&&dep<n)
	{
		if (a[dep-1]+a[dep+1]-a[dep]!=a[dep])
		{
			int y=a[dep];
			a[dep]=a[dep-1]+a[dep+1]-a[dep];
			dfs(dep+1);
			a[dep]=y;
		}
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	
	for (int i=1;i<=n;i++)cin>>a[i];
	
	if(n>30)
	{
		c=s=0;
		for (int i=1;i<=n;i++)c+=a[i];
		c=c/n;
		for (int i=1;i<=n;i++)
		{
			s=s+(a[i]*1.0-c)*(a[i]*1.0-c);
		}
		s=s*n;
		cout<<s<<endl;
		return 0;
	}
	
	dfs(1);
	cout<<ans<<endl;
	return 0;
}

