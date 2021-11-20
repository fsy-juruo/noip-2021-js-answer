#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll scan()
{
	ll x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0')
	{
		x=(x<<3)+(x<<1)+(ch^'0');
		ch=getchar();
	}
	return x*f;
}
#define scan scan()
ll n;
ll a[10005];
ll find(ll x)
{
	ll l=1,r=n,ans=-1;
	while(l<=r)
	{
		ll mid=l+r>>1;
		if(a[mid]>x)r=mid-1;
		if(a[mid]<=x)ans=mid,l=mid+1;
	}
	return ans;
}
ll var(ll a,ll b,ll c,ll d)
{
	ll sum=a+b+c+d;
	ll res=(sum-a*4)*(sum-a*4);
	res+=(sum-b*4)*(sum-b*4);
	res+=(sum-c*4)*(sum-c*4);
	res+=(sum-d*4)*(sum-d*4);
	return res/4;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=scan;
	for(int i=1;i<=n;i++)
		a[i]=scan;
	if(n==1)puts("0");
	else if(n==2)
	{
		ll sum=0;
		for(int i=1;i<=n;i++)
			sum+=a[i];
		ll ans=0;
		for(int i=1;i<=n;i++)
			ans+=(sum-n*a[i])*(sum-n*a[i]);
		printf("%lld\n",ans/n);
	}
	else if(n==3)
	{
		ll sum=0,ans=0x3f3f3f3f;
		for(int i=1;i<=n;i++)
			sum+=a[i];
		ll res=0;
		for(int i=1;i<=n;i++)
			res+=(sum-n*a[i])*(sum-n*a[i]);
		ans=min(ans,res);
		sum=0;
		a[2]=a[1]+a[3]-a[2];
		for(int i=1;i<=n;i++)
			sum+=a[i];
		res=0;
		for(int i=1;i<=n;i++)
			res+=(sum-n*a[i])*(sum-n*a[i]);
		ans=min(ans,res);
		printf("%lld\n",ans/n);
	}
	else if(n==4)
	{
		ll ans=0x3f3f3f3f;
		ans=min(ans,min(var(a[1],a[2],a[3],a[4]),var(a[1],a[1]+a[3]-a[2],a[3],a[4])));
		ans=min(ans,min(var(a[1],a[2],a[2]+a[4]-a[3],a[4]),var(a[1],a[1]+a[4]-a[3],a[2]+a[4]-a[3],a[4])));
		ans=min(ans,min(var(a[1],a[1]+a[3]-a[2],a[1]+a[4]-a[2],a[4]),var(a[1],a[1]+a[4]-a[3],a[1]+a[4]-a[2],a[4])));
		ans=min(ans,var(a[1],a[1]+a[4]-a[3],a[1]+a[4]-a[2],a[4]));
		printf("%lld\n",ans);
	}
	else
	{
		while(true)
		{
			ll t=0;
			ll sum=0;
			for(int i=1;i<=n;i++)
				sum+=a[i];
			ll arv=sum/n;
			int mid=find(arv);
			for(int i=2;i<=mid;i++)
				if(a[i+1]+a[i-1]-a[i]>a[i]&&abs(a[i+1]+a[i-1]-a[i]-arv)<=abs(a[i]-arv))a[i]=a[i+1]+a[i-1]-a[i],t++;
			for(int i=n-1;i>=mid+1;i--)
				if(a[i+1]+a[i-1]-a[i]<a[i]&&abs(a[i+1]+a[i-1]-a[i]-arv)<=abs(a[i]-arv))a[i]=a[i+1]+a[i-1]-a[i],t++;
			if(!t)break;
		}	
		ll sum=0;
		for(int i=1;i<=n;i++)
			sum+=a[i];
		ll ans=0;
		for(int i=1;i<=n;i++)
			ans+=(sum-n*a[i])*(sum-n*a[i]);
		printf("%lld\n",ans/n);
	}
	return 0;
}
