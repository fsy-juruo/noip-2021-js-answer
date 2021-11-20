#include<bits/stdc++.h>
using namespace std;
//#define int long long

const int N=10010;

//bool st;
int n;
int a[N];
int sum=0;
int res=1e9;
bool st[N];
int b[N];
//bool en;

signed main()
{
	//cout<<(&en-&st)/1024.0/1024.0<<endl;
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	if(n==4)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=a[i]*a[i]*n+sum*sum/n-2*a[i]*sum;
		}
		res=min(res,ans);
		a[2]=a[1]+a[3]-a[2];
		ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=a[i]*a[i]*n+sum*sum/n-2*a[i]*sum;
		}
		res=min(res,ans);
		a[2]=a[1]+a[3]-a[2];
		a[3]=a[2]+a[4]-a[3];
		ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=a[i]*a[i]*n+sum*sum/n-2*a[i]*sum;
		}
		res=min(res,ans);
		a[2]=a[1]+a[3]-a[2];
		ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=a[i]*a[i]*n+sum*sum/n-2*a[i]*sum;
		}
		res=min(res,ans);
		a[2]=a[1]+a[3]-a[2];
		a[3]=a[2]+a[4]-a[3];
		a[2]=a[1]+a[3]-a[2];
		a[3]=a[2]+a[4]-a[3];
		ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=a[i]*a[i]*n+sum*sum/n-2*a[i]*sum;
		}
		res=min(res,ans);
		cout<<res<<endl;
		return 0;
	}
	if(n==5)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=a[i]*a[i]*n+sum*sum/n-2*a[i]*sum;
		}
		res=min(res,ans);
		a[2]=a[1]+a[3]-a[2];
		ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=a[i]*a[i]*n+sum*sum/n-2*a[i]*sum;
		}
		res=min(res,ans);
		a[3]=a[2]+a[4]-a[3];
		ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=a[i]*a[i]*n+sum*sum/n-2*a[i]*sum;
		}
		res=min(res,ans);
		a[2]=a[1]+a[3]-a[2];
		ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=a[i]*a[i]*n+sum*sum/n-2*a[i]*sum;
		}
		res=min(res,ans);
		cout<<res<<endl;
		return 0;
	}
	while(!st[n])
	{
		memcpy(b,a,sizeof(a));
		int i=2;
		while(st[i])
			st[i++]=false;
		st[i]=true;
		for(int i=2;i<=n-1;i++)
		{
			if(st[i])
			{
				sum+=a[i+1]+a[i-1]-a[i]-a[i];
				a[i]=a[i+1]+a[i-1]-a[i];
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=a[i]*a[i]*n+sum*sum/n-2*a[i]*sum;
		}
		res=min(res,ans);
	}
	cout<<res<<endl;
	return 0;
}

