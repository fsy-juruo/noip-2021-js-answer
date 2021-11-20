/*
dog pear fruit fake win like ant
seven eagle fire bat pen take juice
*/
#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
using namespace std;
const ll md=998244353;
inline ll qp(ll x,ll y){
	ll rt=1;
	for(;y;y>>=1,(x*=x)%=md)if(y&1)(rt*=x)%=md;
	return rt;
}
const int mxn=111;
inline ll inv(ll x){return qp(x,md-2);}
ll Fra[mxn],Inv[mxn];
ll n,m,K,v[mxn];
ll dp[111][33][33][33];//令dp[i][j][k][f]表示考虑到第i个数 前面已经有了j个1 这一位在转成2进制前为k 已经选了f个数时的权值和
inline void add(ll&x,ll y){
	x+=y;
	if(x>=md)x-=md;
}
inline ll C(ll x,ll y){return Fra[x]*Inv[y]%md*Inv[x-y]%md;}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	Fra[0]=1;
	for(ll i=1;i<mxn;++i)Fra[i]=Fra[i-1]*i%md;
	for(ll i=0;i<mxn;++i)Inv[i]=inv(Fra[i])%md;
	cin>>n>>m>>K;
	for(int i=0;i<=m;++i)cin>>v[i];
	dp[0][0][0][0]=1;
	for(int i=0;i<=m;++i){
		for(int j=0;j<=K;++j){
			for(int k=0;k<=n;++k){//大K为输入 小k为dp 
				for(int f=0;f<=n;++f){
					ll t=dp[i][j][k][f];
					if(t==0)continue;
					for(int nxt=0;nxt<=n-f;++nxt)add(dp[i+1][j+(k+nxt)%2][(k+nxt)/2][f+nxt],t*qp(v[i],nxt)%md*C(f+nxt,nxt)%md);
				}
			}
		}
	}
	ll ans=0;
	for(int j=0;j<=K;++j){
		for(int k=0;k<=n;++k){
			int t=j,tk=k;
			for(;tk;){
				t+=tk%2;
				tk/=2;
			}
			if(t<=K)add(ans,dp[m+1][j][k][n]);
		}
	}
	cout<<ans<<'\n';
	return 0;
}
