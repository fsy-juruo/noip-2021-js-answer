#include<bits/stdc++.h>
using namespace std;
const long long md=998244353;
long long n,m,kk,dp[111][33][33][35],v[111],c[111][111],pw[111][111];
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	c[0][0]=1;
	for(int i=1;i<=105;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)
		{
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%md;
		}
	}
	cin>>n>>m>>kk;
	m++;
	for(int i=0;i<m;i++)
	{
		cin>>v[i];
		pw[i][0]=1;
		for(int j=1;j<105;j++)
		{
			pw[i][j]=(pw[i][j-1]*v[i])%md;
		}
	}
	dp[0][0][0][0]=1;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			for(int k=0;k<32;k++)
			{
				for(int l=0;l<34;l++)
				{
					if(dp[i][j][k][l]==0)
					{
						continue;
					}
					for(int ll=0;ll<=n-j;ll++)
					{
//						cout<<n-j<<' '<<ll<<endl;
//						cout<<dp[i][j][k][l]<<' '<<pw[i][ll]<<' '<<c[n-j][ll]<<endl;
						dp[i+1][j+ll][k+((l+ll)&1)][(l+ll)>>1]+=dp[i][j][k][l]*pw[i][ll]%md*c[n-j][ll]%md;
						dp[i+1][j+ll][k+((l+ll)&1)][(l+ll)>>1]%=md;
//						cout<<dp[i+1][j+ll][k+((l+ll)&1)][(l+ll)>>1]<<endl;
					}
				}
			}
		}
	}
	long long ans=0;
	for(int k=0;k<32;k++)
	{
		for(int l=0;l<34;l++)
		{
			if(k+__builtin_popcount(l)<=kk)
			{
				ans+=dp[m][n][k][l];
				ans%=md;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
