#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long dp[1<<18][31],v[101];
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n,m,k;scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++)
		scanf("%lld",&v[i]);
	if(m<30)
	{
		dp[0][0]=1;
		for(int i=1;i<1<<(m+6);i++)
			for(int j=0;j<=m;j++)
				if(i>=(1<<j))
					for(int l=1;l<=n;l++)
						dp[i][l]=(dp[i][l]+dp[i-(1<<j)][l-1]*v[j]%mod)%mod;
		long long ans=0;
		for(int i=1;i<1<<(m+6);i++)
		{
			int t=0;
			for(int j=0;j<m+6;j++)
				if(i&(1<<j))t++;
			if(t<=k)ans=(ans+dp[i][n])%mod;
		}
		printf("%lld",ans);
	}
	return 0;
}
