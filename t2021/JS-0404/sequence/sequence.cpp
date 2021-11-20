#include<bits/stdc++.h>
#define RE return
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define P pair
#define F first
#define S second
#define ALL(a) a.begin(),a.end()
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
void read(int &x){
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	x=0;
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+c-'0',c=getchar();
}
void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int dp[105][35][35][35],mod=998244353;
int C[35][35],p[105][35];
//前多少位，确定了多少个，进位多少，有多少1
int v[105];
int n,m,tk; 
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
int cnt(int x){
	int re=0;
	while(x){
		re+=(x&1);
		x/=2;
	}
	RE re;
}
signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);read(m);read(tk);
	m++;
	FOR(i,1,m){
		read(v[i]);
		p[i][0]=1;
		FOR(j,1,n){
			p[i][j]=1ll*p[i][j-1]*v[i]%mod;
		}
	}
	FOR(i,0,30){
		C[i][0]=1;
		FOR(j,1,i){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
	}
	dp[0][0][0][0]=1;
	FOR(i,1,m)FOR(j,0,n)FOR(k,0,n)FOR(c,0,tk)if(dp[i-1][j][k][c]){
//		cout<<i-1<<' '<<j<<' '<<k<<' '<<c<<' '<<dp[i-1][j][k][c]<<'\n';
		FOR(to,0,n-j){
			int toc=k+to;
			add(dp[i][j+to][toc/2][c+(toc&1)],1ll*p[i][to]*dp[i-1][j][k][c]%mod*C[j+to][to]%mod);
		}
	}
	int ans=0;
	FOR(k,0,n){
		FOR(c,0,tk){
			int now=c+cnt(k);
			if(now<=tk){
				add(ans,dp[m][n][k][c]);
			}
		}
	}
	write(ans);
	RE 0;
}

