#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
using namespace std;
int n,m,k;
int v[105];
int dp[105][35][35][35];
int c[105][105]; 
const int mod=998244353;
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<=m;i++)
		scanf("%d",&v[i]);
	for(int i=0;i<=n;i++) c[i][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	ll pre=1;
	for(int j=0;j<=n;j++){
		dp[0][j][0][j]=pre*c[n][j]%mod;
		pre=pre*v[0]%mod;
	}
	for(int i=0;i<m;i++)
		for(int j=0;j<=n;j++)
			for(int l=0;l<=k;l++)
				for(int r=0;r<=n;r++){
					if(!dp[i][j][l][r]) continue;
					pre=1;
					for(int o=0;o+j<=n;o++){
						(dp[i+1][j+o][l+(r&1)][(r>>1)+o]+=(ll)dp[i][j][l][r]*(ll)pre%mod*(ll)c[n-j][o]%mod)%=mod;
						pre=pre*v[i+1]%mod;
					}
				}
	ll ans=0;
	for(int l=0;l<=k;l++)
		for(int r=0;r<=n;r++)
			if(l+__builtin_popcount(r)<=k)
				ans=(ans+dp[m][n][l][r])%mod;
	printf("%lld\n",ans);
	return 0;
}
//int overflow
//memset
//out of bound
//corner cases
//big testcase
/*
5 1 1
2 1
*/
