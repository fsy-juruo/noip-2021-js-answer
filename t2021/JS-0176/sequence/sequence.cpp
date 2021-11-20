#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll n,m,k,ans,a[105],c[105][105],dp[15][31][1<<12];
ll power(ll x,ll y){
	ll res=1;
	for(int i=0;i<y;i++)
		res=res*x%mod;
	return res;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=0;i<=m;i++)
		cin >> a[i];
	for(int i=0;i<101;i++)
		c[i][0]=1;
	c[0][0]=1;
	for(int i=1;i<101;i++)
		for(int j=1;j<101;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	ll ab=1;
	for(int i=0;i<=n;i++){
		dp[0][i][i]=ab*c[n][i]%mod;
		ab=ab*a[0]%mod;
	}
	ab=2;
	for(int i=0;i<m;i++){
		for(int j=0;j<=n;j++)
			for(int p=0;p<n*(1<<m);p++){
				if(dp[i][j][p]==0)continue;
				for(int q=0;q+j<=n;q++){
					(dp[i+1][j+q][p+ab*q]+=dp[i][j][p]*power(a[i+1],q)%mod*c[n-j][q]%mod)%=mod;
				}
			}
		ab=ab*2;
	}
	for(int i=0;i<n*(1<<m);i++)
		if(__builtin_popcount(i)<=k)
			ans=(ans+dp[m][n][i])%mod;
	cout << ans;
	return 0;
}
