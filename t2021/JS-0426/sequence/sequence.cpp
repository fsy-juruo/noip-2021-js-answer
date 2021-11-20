#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define REP(x,y) for(int x=0;x<y;++x)
#define REPA(x,y) for(int x=1;x<=y;++x)
#define vi vector<int>
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define mp make_pair
using namespace std;
//const ll MOD=1e9+7;
const ll MOD=998244353;
const int INF=0x3f3f3f3f;
//const ll INF=0x3f3f3f3f3f3f3f3f;
inline ll quick_power(ll A,ll B){
	A%=MOD;ll ret=1;
	while(B){
		if(B&1)ret=ret*A%MOD;
		B>>=1;
		A=A*A%MOD;
	}
	return ret;
}
inline int lowbit(int x){return x&-x;}
const int MAXA=125000;
ll dp[33][MAXA];
int N,M,K;
ll v[33];
inline int ppc(int x){
	int ret=0;
	while(x)x-=lowbit(x),++ret;
	return ret;
}
int main(){
	//this method: O(N^2*2^M*M) about 4.5e7
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&N,&M,&K);++M;
	REP(i,M)scanf("%lld",v+i);
	int A=0;
	dp[0][0]=1;
	REPA(i,N){
		int tmp=A;
		REP(j,M){
			int nmsk=(1<<j);
			REP(msk,A+1){
				dp[i][msk+nmsk]=(dp[i][msk+nmsk]+dp[i-1][msk]*v[j]%MOD)%MOD;
				tmp=max(tmp,msk+nmsk);
			}
		}
		A=tmp;
	}
	ll ans=0;
	REP(msk,A+1){
		if(ppc(msk)<=K)ans=(ans+dp[N][msk])%MOD;
	}
	printf("%lld",ans);
	return 0;
}
/*
think twice, code once;
think once, debug forever.
*/
/*
sto QL orz
sto HJ orz
sto H2 orz
sto ET orz
sto I9 orz
sto FG orz
haoba, yyds!
*/

