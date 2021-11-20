#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<cstdio>
using namespace std;
//priority_queue
queue<int>q;
const int maxn=1<<14;
const long long mod=998244353;
long long dp[maxn][33],ans;	
int n,m,k,val[100000];
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int i,j;
	cin>>n>>m>>k;
	for(i=0;i<=m;i++)
		cin>>val[i];
	for(i=0;i<=m;i++)
	{
		dp[1<<i][1]=val[i];
		//cout<<dp[1<<i][1];
	}
	for(i=1;i<n;i++)
	{
		for(j=0;j<=n*(1<<m);j++)
		{
			for(int l=0;l<=m;l++)
			{
				int t=j+(1<<l);
				dp[t][i+1]+=dp[j][i]*val[l];
				dp[t][i+1]%=mod; 
				//cout<<dp[t][n+1]<<endl;
			}
		}
	}
	for(i=n;i<=n*(1<<m);i++)
	{
		int ii=i,cnt=0;
		while(ii>0)
		{
			cnt+=ii%2;
			ii/=2;
		}
		if(cnt<=k)
			ans+=dp[i][n],ans%=mod;
	}
	cout<<ans<<endl;
}
