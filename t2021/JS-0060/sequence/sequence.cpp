#include<bits/stdc++.h>

#define ll long long

using namespace std;
int n,m,l;
ll const mod=998244353;

ll v[115];
ll inv[115];
ll f[115][35][35][35];

ll s[115][35];
ll p[35];

ll qpow(ll x,ll y)
{
	ll ret=1;
	while(y)
	{
		if(y&1) ret=ret*x%mod;
		y>>=1;
		x=x*x%mod;
	}
	return ret;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout); 
	scanf("%d%d%d",&n,&m,&l);
	for(int i=0;i<=m;++i)
	{
		scanf("%lld",&v[i]);
		s[i][0]=1;
		for(int j=1;j<=n;++j)
		{
			s[i][j]=s[i][j-1]*v[i]%mod;
		}
	}
	p[0]=1;
	for(int i=1;i<=n;++i)
	{
		p[i]=p[i-1]*qpow(1ll*i,mod-2)%mod;
	}
	
	int mx=0;
	for(int i=0;i<=n;++i)
	{
		f[0][i][i%2][i/2]=s[0][i]*p[i]%mod;
	}
	
	for(int i=1;i<=m||((1<<(i-m))<=n);++i)
	{
		mx=i;
		s[i][0]=1;
		for(int j=0;j<=n;++j)
		{
			for(int k=0;k<=j;++k)
			{
				for(int t=0;2*t<=j-k;++t)
				{
					if(f[i-1][j][k][t]==0) continue;
					for(int w=0;j+w<=n;++w)
					{
						if((w+t)&1) (f[i][j+w][k+1][(w+t)/2]+=f[i-1][j][k][t]*s[i][w]%mod*p[w]%mod)%=mod;
						else (f[i][j+w][k][(w+t)/2]+=f[i-1][j][k][t]*s[i][w]%mod*p[w]%mod)%=mod;
					}
				}
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=l;++i)
	{
		ans=(ans+f[mx][n][i][0])%mod;
	}
	for(int i=1;i<=n;++i)
	{
		ans=ans*i%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
/*
5 1 1
2 1

*/
