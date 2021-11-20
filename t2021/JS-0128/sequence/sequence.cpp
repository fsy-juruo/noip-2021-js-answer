#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rep2(i,j,k) for(int i=j;i>=k;i--)
#define mo 998244353
using namespace std;
template<typename T> void read(T &num){
	char c=getchar();T f=1;num=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	num*=f;
}
template<typename T> void qwq(T x){
	if(x>9)qwq(x/10);
	putchar(x%10+'0');
}
template<typename T> void write(T x){
	if(x<0){x=-x;putchar('-');}
	qwq(x);putchar('\n');
}
template<typename T> void chkinc(T &x,T y){x=(x+y>=mo)?(x+y-mo):(x+y);}
template<typename T> void chkdec(T &x,T y){x=(x-y<0)?(x-y+mo):(x-y);}
int v[110];int c[1010][1010];
int dp[102][31][61][31];
int cnt(int x){
	int ret=0;
	while(x){ret++;x-=x&(-x);}
	return ret;
}
void Pre(){
	rep(i,0,1000)c[i][0]=1;
	c[1][1]=1;
	rep(i,2,1000){
		rep(j,1,i){c[i][j]=c[i-1][j-1];chkinc(c[i][j],c[i-1][j]);}
	}
	return;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	Pre();
	int n,m,K;read(n);read(m);read(K);
	rep(i,0,m)read(v[i]);
	dp[0][0][0][0]=1;
	rep(i,1,m+1){
		rep(j,0,n){
			rep(k,0,2*n-1){
				rep(l,(k&1),K){
					int s=1;
					rep(p,max(0,(2*k-2*n+1)/2),min(j,k)){
						int nop=0;
						if((k-p)*2<=2*n-1)chkinc(nop,dp[i-1][j-p][(k-p)*2][l-(k&1)]);
						if((k-p)*2+1<=2*n-1)chkinc(nop,dp[i-1][j-p][(k-p)*2+1][l-(k&1)]);
						nop=(1ll*nop*c[n-j+p][p]%mo*s)%mo;
						s=(1ll*s*v[i-1])%mo;
						chkinc(dp[i][j][k][l],nop);
					}
					//if(dp[i][j][k][l]){
					//	cout<<i<<","<<j<<","<<k<<","<<l<<":"<<dp[i][j][k][l]<<endl;
					//}
				}
			}
		}
	}
	int ans=0;
	rep(i,0,2*n-1){
		int nop=cnt(i)-(i&1);
		rep(j,0,K-nop)chkinc(ans,dp[m+1][n][i][j]);
	}
	write(ans);
	return 0;
}
/*
430246987
8 9 4
934258593 150407625 187068439 162292791 219945760 512449588 803393963 983648121 484675481 412407699

642171527
*/
