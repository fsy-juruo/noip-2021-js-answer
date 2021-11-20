#include<bits/stdc++.h>
using namespace std;
int n,a[10001],b[10001];
long long ans;
string h;
long long did()
{
	long long tot=0,siz=0;
	for(int i=1;i<=n;i++)
	{
		tot=tot+b[i];
	}
	for(int i=1;i<=n;i++)
	{
		siz=siz+(b[i]*n-tot)*(b[i]*n-tot);
	}
	return siz/n;
}
void dfs(int x)
{
	if(x>=n)
	{
		ans=min(ans,did());
	}
	else
	{
		dfs(x+1);
		int y=b[x];
		b[x]=b[x+1]+b[x-1]-b[x];
		dfs(x+1);
		b[x]=y;
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
 		b[i]=a[i];
	}
	ans=did();
	if(n<=2)
	{
		cout<<ans<<endl;
		return 0;
	}
	if(n==3)
	{
		a[2]=a[1]+a[3]-a[2];
		ans=min(ans,did());
		cout<<ans<<endl;
		return 0;
	}
	if(n==4)
	{
		b[2]=b[1]+b[3]-a[2];
		if(ans>did())
		ans=did();
		b[2]=a[2];
		b[3]=b[4]+b[2]-a[3];
		if(ans>did())
		ans=did();
		b[2]=a[1]+a[4]-a[3];
		ans=min(ans,did());
		b[2]=a[1]+a[3]-a[2];
		b[3]=a[1]+a[4]-a[2];
		ans=min(ans,did());
		b[2]=a[1]+a[4]-a[3];
		b[3]=a[1]+a[4]-a[2];
		ans=min(ans,did());
		cout<<ans<<endl;
		return 0;
	}
	dfs(2);
	cout<<ans<<endl;
  return 0;
}