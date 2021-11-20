#include<bits/stdc++.h>
using namespace std;
const long long N=1005,p=998244353;
long long n,a[N],ans=LONG_LONG_MAX;
bool vis[N];
long long read()
{
	long long f=1,x=0;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
long long qp(long long a,long long b)
{
	long long s=1;
	while(b)
	{
		if(b&1) s=(s*a)%p;
		a=(a*a)%p;
		b>>=1;
	}
	return s;
}
long long ny(long long a,long long b)
{
	return a*qp(b,p-2)%p;
}
void dfs(long long k)
{
	long long av=0,sum=0;
	for(int i=1;i<=n;i++)
	{
		av=(av+a[i])%p;
	}
	av=ny(av,n);
	for(int i=1;i<=n;i++)
	{
		sum=(sum+(a[i]-av)*(a[i]-av)%p)%p;
	}
	sum=(sum*n)%p;
	ans=min(ans,sum);
//	printf("%lld %lld\n",av,sum);
	for(int i=2;i<n;i++)
	{
		if(a[i]-a[i-1]==a[i+1]-a[i]||vis[i]) continue;
		a[i]=a[i+1]+a[i-1]-a[i];
		vis[i]=true;
		dfs(k+1);
		vis[i]=false;
		a[i]=a[i+1]+a[i-1]-a[i];
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}

