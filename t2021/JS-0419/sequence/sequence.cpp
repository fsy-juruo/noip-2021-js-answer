#include<bits/stdc++.h>
#define next Cry_For_theMoon
#define lc(x) (x<<1)
#define rc(x) ((x<<1)|1)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define pi pair<int,int>
#define pii pair<int,pair<int,int> >
#define fr firsto
#define se second
#define pb push_back()
#define is insert()
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int mod=998244353,MAXN=35,MAXM=110;
ll power(ll a,ll n){
	if(!n)return 1;
	ll tmp=power(a,n/2);tmp=tmp*tmp%mod;
	if(n&1)tmp=tmp*a%mod;return tmp;
}
ll n,m,k,v[MAXM];
ll f[MAXM][MAXN][MAXN][MAXN],ans;
ll fact[MAXM],inv[MAXM],g[MAXM][MAXN];
void dp(){
	rep(cnt,0,n){
		//choose cnt v[0]
		f[0][cnt&1][cnt/2][cnt]=power(v[0],cnt)*inv[cnt]%mod;
	}
	rep(i,0,m){
		rep(j,0,n){
			g[i][j]=power(v[i],j);
		}
	}
	rep(i,0,m-1){
		rep(occ,0,k){
			rep(rest,0,n){
				rep(j,0,n){
					//first i 
					//occ 1 in S
					//rest k 1 in i+1
					//choose j index
					rep(cnt,0,n){
						if(cnt+j>n)break;
						int flag=(cnt+rest)&1;
						if(flag+occ>k)break;
						ll& ret=f[i+1][occ+flag][(cnt+rest)/2][cnt+j];
						ret=(ret+f[i][occ][rest][j]*g[i+1][cnt]%mod*inv[cnt]%mod)%mod;
					}
				}
			}
		}
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);	
	fact[0]=inv[0]=1;
	rep(i,1,100)fact[i]=fact[i-1]*i%mod;
	rep(i,1,100)inv[i]=power(fact[i],mod-2);
	cin>>n>>m>>k;
	rep(i,0,m)cin>>v[i];
	dp();
	rep(occ,0,k){
		rep(rest,0,n){
			ll ret=f[m][occ][rest][n];
			ll cnt=occ,val=rest;
			while(val){
				cnt+=val&1;
				val/=2;
			}
			if(cnt<=k){
				ans=(ans+ret*fact[n]%mod)%mod;
			}
		}
	}
	cout<<ans;

	return 0;
}
