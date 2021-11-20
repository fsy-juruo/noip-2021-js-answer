#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define rp(i,n) for(int i=1;i<=n;i++)
#define forn(i,a,n) for(int i=a;i<n;i++)
#define sz(s) (int)(s.size())
#define mod 998244353
using namespace std;
ll dp[5001][31];
int n,m,k;
ll v[201];
ll ans;
void solve(int x){
	int now=x,cnt=0;
	while(now){
		if(now%2)
		cnt++;
		now/=2;
	}
	if(cnt>k)
	return;
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	rep(i,n){
		forn(j,i,i*(1<<m)+1){
			if(j>x)
			break;
			rep(K,m+1){
				if(j+(1<<K)>x)
				break;
				dp[j+(1<<K)][i+1]+=dp[j][i]*v[K];
				dp[j+(1<<K)][i+1]%=mod;
			}
		}
	}
	ans+=dp[x][n];
	ans%=mod;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	rep(i,m+1)
	cin>>v[i];
	for(int s=n;s<=n*(1<<(m));s++){
		solve(s);
	}
	cout<<ans;
	return 0;
}


