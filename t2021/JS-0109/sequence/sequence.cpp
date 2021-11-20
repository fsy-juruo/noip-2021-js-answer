#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

inline ll read()
{
	ll res=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') res=(res<<1)+(res<<3)+(c^48),c=getchar();
	return res*f;
}

const int N=105;
const int mod=998244353;
int n,m,k;
ll v[N];

struct normal{

int a[N];
int cnt[N];
ll A[N];
ll ans;

inline int count(ll x)
{
	int res=0;
	while(x)
	{
		res++;
		x-=x&-x;
	}
	return res;
}

void dfs(int x)
{
	if(x>n)
	{
		ll u=0;
		for(int i=1;i<=n;i++)
			u+=1<<a[i];
		if(count(u)>k)
			return;
		
		for(int i=1;i<=n;i++)
			cnt[a[i]]++;
		
		int ci=A[n];
		for(int i=1;i<=n;i++)
		{
			ci/=A[cnt[a[i]]];
			cnt[a[i]]=0;
		}
		
		ll res=ci;
		for(int i=1;i<=n;i++)
			res=res*v[a[i]]%mod;
		ans=(ans+res)%mod;
		
		return;
	}
	for(int i=a[x-1];i<=m;i++)
	{
		a[x]=i;
		dfs(x+1);
	}
}

void solve()
{
	A[0]=1;
	for(int i=1;i<=n;i++)
		A[i]=A[i-1]*i;
	
	a[0]=0;
	dfs(1);
	printf("%lld\n",ans);
}

}p1;

struct k_is_one{

void solve()
{
	
}

}p2;

struct k_is_n{

void solve()
{
	
}

}p3;

int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	
	n=read(),m=read();k=read();
	for(int i=0;i<=m;i++)
		v[i]=read();
	
	if(n<=8)
		p1.solve();
	else if(k==1)
		p2.solve();
	else
		p3.solve();
	
	return 0;
}
/*
5 1 1
2 1

*/
