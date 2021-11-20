#include<bits/stdc++.h>
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
using namespace std; 
inline int read(){
	int v=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}
const int Maxn=35;
const int Maxm=105;
const int mod=998244353;
void Add(int &x,int y){
	x+=y;
	if (x>=mod) x-=mod;
}
int qp(int x,int p){
	int ret=1;
	while (p){
		if (p&1) ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;
		p>>=1;
	}
	return ret;
}
int inv(int x){
	return qp(x,mod-2);
}
int fact[Maxn],ivf[Maxn];
int dp[Maxm][Maxn][Maxn][Maxn];
int n,m,K,v[Maxm];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	fact[0]=1;
	for (int i=1;i<Maxn;i++){
		fact[i]=1ll*fact[i-1]*i%mod;
	}
	for (int i=0;i<Maxn;i++) ivf[i]=inv(fact[i]);
	
	n=read();m=read();K=read();
	for (int i=0;i<=m;i++) v[i]=read();
	dp[0][0][0][0]=1;
	
	for (int i=0;i<=m;i++){
		for (int j=0;j<=n;j++){
			for (int k=0;k<=K;k++){
				for (int l=j;l<=n;l++){
					
					if (dp[i][j][k][l]){
						int pp=1;
						for (int c=0;l+c<=n;c++){
							
							Add(dp[i+1][j/2+c][k+((j/2+c)&1)][l+c],1ll*dp[i][j][k][l]*ivf[c]%mod*pp%mod);
							pp=1ll*pp*v[i]%mod;
						}
					}
				}
			}
		}
	}
	int res=0;
	for (int j=0;j<=n;j++){
		for (int k=0;k<=K;k++){
			int ans=dp[m+1][j][k][n];
			
			int R=__builtin_popcount(j>>1);
			if (R+k<=K){
				Add(res,ans);
			}
		}
	}
	res=1ll*res*fact[n]%mod;
	printf("%d\n",res);
	return 0;
}
