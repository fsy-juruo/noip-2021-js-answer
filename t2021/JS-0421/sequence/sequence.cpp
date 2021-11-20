#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<n;i++)
#define forn(i,a,b) for(int i=a;i<=b;i++)
#define fore(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define m_p make_pair
using namespace std;
const int N=35,mod=998244353;
ll dp[2][4100*N];
ll v[N];
int n,m,k;
int cnt(int x){
	int res=0;
	rep(i,20){
		if((x>>i)&1)res++;
	}
	return res;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	rep(i,m+1)cin>>v[i];
	dp[0][0]=1;
	forn(i,1,n){
		int cur=i&1;
		int lst=cur^1;
		rep(j,4100*N)dp[cur][j]=0;
		forn(s,0,30*4096){
			if(dp[lst][s]==0)continue;
			rep(j,m+1){
				int x=1<<j;
				dp[cur][s+x]+=(dp[lst][s]*v[j])%mod;
				dp[cur][s+x]%=mod;
			}
		}
	}
	ll ans=0;
	forn(s,0,30*4096){
		if(cnt(s)<=k){
			ans+=(dp[n&1][s]);ans%=mod;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
