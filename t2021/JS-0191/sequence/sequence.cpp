#include <bits/stdc++.h>
#define ll long long
#define MOD 998244353
using namespace std;
int scan()
{
	int x=0,f=1;
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
int n,m,k;
ll ans;
int a[105];
int v[105];
int bit(int x)
{
	int ans=0;
	while(x)
	{
		if(x&1)ans++;
		x>>=1;
	}
	return ans;
}
void dfs(int x,ll kx)
{
	if(x==n+1)
	{
		if(bit(kx)<=k)
		{
			for(int i=1;i<=x-1;i++)cout<<a[i]<<" ";cout<<endl;
			ll sum=1;
			for(int i=1;i<=x-1;i++)
				sum=(sum%MOD)*(v[a[i]]%MOD)%MOD;
			ans+=sum;
		}
		return;
	}
	for(int i=0;i<=m;i++)
	{
		a[x]=i;
		dfs(x+1,kx+(1<<i));	
	}	
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=scan,m=scan,k=scan;
	for(int i=0;i<=m;i++)
		v[i]=scan;
	dfs(1,0);
	printf("%lld\n",ans%MOD);
	return 0;
}
