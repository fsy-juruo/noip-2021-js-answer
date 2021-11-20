#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define INF 1000000000
#define LINF 1000000000000000000
#define mod 998244353
using namespace std;
ll dp[105][32][32][17],ccoef[35][35],bct[35];
ll n,m,k,v[105][32];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	ll i,j,l,p,x;
	cin>>n>>m>>k;
	bct[0]=0;
	for(i=1;i<35;++i)
	{
		bct[i]=bct[i/2]+(i&1);
	}
	for(i=0;i<=n;++i)
	{
		ccoef[i][0]=1;
	}
	ccoef[0][0]=1;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=i;++j)
		{
			ccoef[i][j]=(ccoef[i-1][j-1]+ccoef[i-1][j])%mod;
		}
	}
	for(i=0;i<=m;++i)
	{
		v[i][0]=1;
		cin>>v[i][1];
		for(j=2;j<=n;++j)
		{
			v[i][j]=(v[i][j-1]*v[i][1])%mod;
		}
	}
	for(i=0;i<=m;++i)
	{
		for(j=0;j<=n;++j)
		{
			for(l=0;l<=k;++l)
			{
				for(p=0;p*2<=n;++p)
				{
					dp[i][j][l][p]=0;
				}
			}
		}
	}
	dp[0][0][0][0]=1;
	for(i=0;i<=m;++i)
	{
		for(j=0;j<=n;++j)
		{
			for(l=0;l<=k;++l)
			{
				for(p=0;p*2<=n;++p)
				{
					if(dp[i][j][l][p]!=0)
					{
						for(x=0;x+j<=n;++x)
						{
							if(l+((x+p)&1)<=k)
							{
								dp[i+1][j+x][l+((x+p)&1)][(x+p)/2]=(dp[i+1][j+x][l+((x+p)&1)][(x+p)/2]+dp[i][j][l][p]*((v[i][x]*ccoef[j+x][x])%mod))%mod;
							}
						}
					}
				}
			}
		}
	}
	ll ans=0;
	for(i=0;i<=k;++i)
	{
		for(j=0;j*2<=n;j++)
		{
			if(i+bct[j]<=k)
			{
				ans=(ans+dp[m+1][n][i][j])%mod;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
