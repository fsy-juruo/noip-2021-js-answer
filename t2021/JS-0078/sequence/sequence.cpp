#include <bits/stdc++.h>

const int mod=998244353;

inline int bitcnt(int x)
{
	int res=0;
	while(x)
	{
		res++;
		x &= x-1;
	}
	return res;
}

int dp[130050][35];

int main()
{	
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n,m,k,a[505];
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i <= m;i++)
	{
		scanf("%d",a+i);
		dp[1 << i][1]=a[i];
	}
	for(int s=1;s<n*(1 << m);s++)
	{
		for(int i=1;i<n;i++)
			for(int j=0;j <= m;j++)
			{
				int ss=s+(1 << j);
				if(ss>n*(1 << m))
					continue;
				dp[ss][i+1]=(1ll*dp[s][i]*a[j]+dp[ss][i+1])%mod;
			}
	}
	int ans=0;
	for(int s=n;s <= n*(1 << m);s++)
		if(bitcnt(s) <= k)
			ans=(1ll*dp[s][n]+ans)%mod;
	printf("%d\n",ans);
	return 0;
}
