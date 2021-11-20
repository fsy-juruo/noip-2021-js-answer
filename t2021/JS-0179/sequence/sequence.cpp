#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,maxs,mod=998244353;
ll dp[31][122900],v[101],ans;
bool Count(int x)
{
	int sum=0;
	while(x)sum+=(x&1),x=x>>1;
	return sum<=k;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	maxs=n*(1<<m),dp[0][0]=1;
	for(int i=0;i<=m;i++)cin>>v[i];
	for(int i=1;i<=n;i++)
		for(int s=0;s<=maxs;s++)
			for(int j=0;j<=m;j++)
			{
				int x=(1<<j);if(s-x<0)continue;
				dp[i][s]=(dp[i][s]+dp[i-1][s-x]*v[j])%mod;
			}
	for(int s=0;s<=maxs;s++)
		if(Count(s))ans=(ans+dp[n][s])%mod;
	printf("%lld\n",ans);
	return 0;
}
