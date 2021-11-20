#include<bits/stdc++.h>
using namespace std;
const int N=35,M=120,mod=998244353;
int n,m,k,a[M],p[M][N],dp[M][N][N][N],ans,c[N][N];
inline void add(int &a,int b){a+=b;if(a>=mod)a-=mod;}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++)
	{
		scanf("%d",&a[i]);
		p[i][0]=1;
		for(int j=1;j<=n;j++)
			p[i][j]=1ll*p[i][j-1]*a[i]%mod;
	}
	for(int i=m+1;i<=m+10;i++)
		p[i][0]=1;
	for(int i=0;i<=n;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	}
	dp[0][0][0][0]=1;
	for(int i=0;i<=m+10;i++)
	{
		for(int j=0;j<=n;j++)
		{
			for(int v=0;v<=n/2;v++)
			{
				for(int s=0;s<=k;s++)
				{
					int f=dp[i][j][v][s];
					if(!f)
						continue;
					for(int x=0;j+x<=n;x++)
					{
						int g=1ll*c[n-j][x]*f%mod*p[i][x]%mod;
						add(dp[i+1][j+x][(v+x)/2][s+(v+x)%2],g);
					}
				}
			}
		}
	}
	for(int i=0;i<=k;i++)
		add(ans,dp[m+10][n][0][i]);
	printf("%d\n",ans);
	return 0;
}

