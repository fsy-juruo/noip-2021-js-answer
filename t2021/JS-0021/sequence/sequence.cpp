#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define X first
#define Y second
bool Mbe;
//func_func_func_func_func_func_func_func_func_func_func_func_func_func_func_func_func_func_func
const int mod=998244353;
int qpow(int x,int y){
	int res=1;
	while(y){
		if(y&1)res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		y>>=1; 
	}
	return res;
}
int inv(int x){return qpow(x,mod-2);}
const int N=40,S=40,M=110;
int n,m,s;//N! M! S! 
int v[M];
int fact[N],factinv[N];
int dp[M][S][32][N];
//main_main_main_main_main_main_main_main_main_main_main_main_main_main_main_main_main_main_main
bool Med;
signed main(){
	fprintf(stderr,"size: %.3lfMB\n",1.*(&Mbe-&Med)/(1<<20));
	freopen("sequence.in","r",stdin);freopen("sequence.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<=m;i++)cin>>v[i];
	fact[0]=factinv[0]=1;for(int i=1;i<=n;i++)fact[i]=1ll*fact[i-1]*i%mod,factinv[i]=inv(fact[i]);
	for(int i=0;i<=n;i++)dp[0][0][i][i]=1ll*qpow(v[0],i)*factinv[i]%mod;
	for(int i=0;i<m;i++)for(int j=0;j<=s;j++)for(int k=0;k<32;k++)for(int o=0;o<=n;o++)if(dp[i][j][k][o]){
		const int dpval=dp[i][j][k][o];
		int vc=1;
		for(int p=0;p+o<=n;p++){
			(dp[i+1][j+(k&1)][(k>>1)+p][p+o]+=1ll*vc*factinv[p]%mod*dpval%mod)%=mod;
			vc=1ll*vc*v[i+1]%mod;
		}
	}
	int ans=0;
	for(int j=0;j<=s;j++)for(int k=0;k<32;k++){
		int kk=k,bitc=0;
		while(kk)bitc++,kk^=kk&-kk;
		if(j+bitc<=s)(ans+=dp[m][j][k][n])%=mod; 
	}
	ans=1ll*ans*fact[n]%mod;
	cout<<ans<<"\n";
	return 0;
}
