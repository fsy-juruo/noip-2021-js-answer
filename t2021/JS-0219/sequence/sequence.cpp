#include<bits/stdc++.h>
#define ll long long 
using namespace std;

const int MAXN=50;
const int P=998244353;
int n,m,k;

ll v[MAXN];
int dp[32][31*(1<<14)];

int cnt1[1<<20];



int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;++i)
	{
		cin>>v[i];
	}
	
	if(m<=12)
	{
		for(int i=1;i<n*(1<<(m+1));++i)
		{
			cnt1[i]=cnt1[i>>1]+(i&1);
		//	cout<<i<<' '<<cnt1[i]<<endl;
		}
		
		dp[0][0]=1;
		for(int i=1;i<=n;++i)
		{
			for(int j=0;j<n*(1<<(m+1));++j)
			{
				for(int a=0;a<=m;++a)
				{
					if(j-(1<<a)>=0) dp[i][j]=(dp[i][j]+dp[i-1][j-(1<<a)]*v[a]%P)%P;
				}
			}
		}
		
		ll ans=0;
/*		
		for(int i=1;i<=n;++i)
		{
			for(int j=0;j<n*(1<<(m+1));++j)
			{
				cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
			}
		}
*/		
		for(int i=0;i<n*(1<<(m+1));++i)
		{
			if(cnt1[i]<=k)
			{
				ans=(ans+dp[n][i])%P;
				//cout<<i<<' '<<dp[n][i]<<endl;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	
	if(k==1)
	{
		
	}
	
	return 0;
}
/*
30 10 12 
1 1 1 1 1 1 1 1 1 1 1
*/

