#include<bits/stdc++.h>
#define LL long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define DF(i,a,b) for (int i=(a);i>=(b);i--)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
#define mp make_pair
using namespace std;
int read(){
	char ch=getchar();int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
	return w*c;
}
const int mod=998244353,N=105,M=33;
LL dp[2][M][M][M];//carrier , number used (0,n) , bit sz (0,k)
LL fac[M],inv[M];
LL fast(LL x,LL p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
}
int n,m,k,a[N],sz[1111];
LL pw[N][M];
void init(){
	fac[0]=1;
	F(i,1,n) fac[i]=fac[i-1]*i%mod;
	inv[n]=fast(fac[n],mod-2);
	DF(i,n,1) inv[i-1]=inv[i]*i%mod;
	F(i,0,m){
		pw[i][0]=1;
		F(j,1,n){
			pw[i][j]=pw[i][j-1]*a[i]%mod;
		}
	}
	F(i,0,1000){
		sz[i]=sz[i>>1]+(i&1);
	}
}
void red(LL &x){
	x=(x>=mod ? x-mod : x);
}
void solve(){
	int now=1,pre=0;
	dp[now][0][0][0]=1;
	F(i,0,m){
		swap(now,pre);
		ms(dp[now],0);
		F(car,0,n){
			F(num,0,n){
				F(bs,0,k){
					if (dp[pre][car][num][bs]){
						F(nw,0,n-num){	
//							cerr<<i<<" "<<car<<" "<<num<<" "<<bs<<" "<<now<<"\n";
							LL val=dp[pre][car][num][bs]*pw[i][nw]%mod*inv[nw]%mod;
							red(dp[now][(car+nw)>>1][num+nw][bs+((car+nw)&1)]+=val);
						}
					}
				}
			}
		}
	}
	LL ans=0;
	F(car,0,n)
	F(bs,0,k){
		if (bs+sz[car]<=k){
			LL tmp=dp[now][car][n][bs]*fac[n]%mod;
			ans=(ans+tmp)%mod;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(); m=read(); k=read();
	F(i,0,m) a[i]=read();
	init();
//	return 0;
	solve();
	return 0;
}
/*

*/

