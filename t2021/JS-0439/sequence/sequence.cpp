#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,m,k,v[105],dp[3][32][32][32][32],ans,pre1[105][105],pre2[105][105],lastk,lastl,k2;
long long dp2[32][32][32][32];
bool vis[103];
long long pw(int x,int y){return pre1[x][y];}
long long mul(int x,int y){return pre2[x][y];}
long long cnt(int x)
{
	int temp=0;
	while(x)
	{
		temp+=(x%2);
		x/=2; 
	}
	return temp;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k2;
	for(int i=0;i<=m;i++)
	cin>>v[i];
	for(int j=0;j<=n;j++)
	{
		for(int k=0;k<=n;k++)
		{
			memset(vis,0,sizeof(vis));
			pre1[j][k]=1;
			for(int l=j;l>j-k;l--)
			{
				pre1[j][k]*=l;
				for(int i=1;i<=k;i++)
				{
					if(vis[i]==0&&pre1[j][k]%i==0)
					pre1[j][k]/=i,vis[i]=1;
				}
			}
			pre1[j][k]%=mod;
		}
	}
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			pre2[i][j]=1;
			for(int k=1;k<=j;k++)
			pre2[i][j]=(pre2[i][j]*v[i])%mod;
		}
	}
	for(int j=0;j<=n;j++)
	{
		int k=j%2; 
		int l=n-j;
		dp[0][j][k][l][j/2]=((pw(n,j)%mod)*mul(0,j))%mod;
	}
	for(int j=0;j<=n;j++)
	{
		for(int k=0;k<=k2;k++)
		{
			for(int l=0;l<=n;l++)
			{
				for(int lj=0;lj<=n;lj++)
				{
					dp2[j][k][l][lj]=dp[0][j][k][l][lj];
					if(j>0)
					dp2[j][k][l][lj]=(dp2[j][k][l][lj]+dp2[j-1][k][l][lj])%mod;
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			for(int k=0;k<=k2;k++)
			{
				for(int l=0;l<=n-j;l++)
				{
					lastl=l+j;
					for(int lj2=0;lj2<=n;lj2++)
					{
						if(k-((j+lj2)%2)<0)
						continue;
						dp[1][j][k][l][(lj2+j)/2]=(dp[1][j][k][l][(lj2+j)/2]+((dp2[n-lastl][k-((j+lj2)%2)][lastl][lj2]*pw(lastl,j))%mod)*mul(i,j))%mod;
					}
				}
			}
		}
		for(int j=0;j<=n;j++)
		{
			for(int k=0;k<=k2;k++)
			{
				for(int l=0;l<=n;l++)
				{
					for(int lj=0;lj<=n;lj++)
					{
						dp[0][j][k][l][lj]=dp[1][j][k][l][lj],dp[1][j][k][l][lj]=0;
						dp2[j][k][l][lj]=dp[0][j][k][l][lj];
						if(j>0)
						dp2[j][k][l][lj]=(dp2[j][k][l][lj]+dp2[j-1][k][l][lj])%mod;
					}
				}
			}
		}
	}
	for(int j=0;j<=n;j++)
	{
		for(int k=0;k<=k2;k++)
		{
			for(int j2=0;j2<=n;j2++)
			{
				if(k+cnt(j2)<=k2)
				ans=(ans+dp[0][j][k][0][j2])%mod;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
