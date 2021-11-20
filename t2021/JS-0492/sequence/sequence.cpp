#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353,maxn=2e5;
int n,m,k;
int pw[110],v[110];
long long dp[35][maxn];
void solve()
{
	int lmt=n*pw[m];
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			for(int l=pw[j];l<=lmt;l++)
			{
				if(dp[i-1][l-pw[j]])
				{
					dp[i][l]=(dp[i][l]+dp[i-1][l-pw[j]]*v[j]%Mod)%Mod;
				}
			}
		}
	}
	long long res=0;
	for(int i=n;i<=lmt;i++)
	{
		if(__builtin_popcount(i)<=k)
		{
			res=(res+dp[n][i])%Mod;
		}
	}
	printf("%lld\n",res);
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	pw[0]=1;
	for(int i=1;i<=m;i++)
	{
		pw[i]=pw[i-1]*2;
	}
	for(int i=0;i<=m;i++)
	{
		scanf("%d",v+i);
	}
	if(n<=30&&m<=12)
	{
		solve();
	}
	else
	{
		printf("0\n");
	}
	return 0;
}
/*
1. copy the names of the problems
2. freopen
3. int, long long overflow
4. memory overflow 
5. delete debug sentences
6. list the main ideas
7. special cases
*/
