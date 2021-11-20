#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int dp[113][64][33][33],fac[33],inv[33],cnt[64];
int v[103],n,m,K,pw;
int mypow(int x,int times){
	int ret=1;
	while(times){
		if(times&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;
		times/=2; 
	}return ret;
}
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&K);
	for(int i=0;i<=m;i++)
		scanf("%d",v+i);
	fac[0]=1;for(int i=1;i<33;i++)fac[i]=1ll*fac[i-1]*i%mod;
	for(int i=0;i<33;i++)inv[i]=mypow(fac[i],mod-2);
	dp[0][0][0][0]=fac[n];
	for(int i=1;i<=m+1;i++)
		for(int j=0;j<64;j++)
			for(int o=0;o<=30;o++)
				for(int k=0;k<=n;k++){
					pw=1;
					for(int l=0;l<=n-k;l++){
						add(dp[i][j+l>>1][k+l][o+(j+l&1)],1ll*dp[i-1][j][k][o]*inv[l]%mod*pw%mod);
						pw=1ll*pw*v[i-1]%mod;
					}
				}
	int ans=0;
	for(int i=0;i<64;i++){
		cnt[i]=cnt[i>>1]+(i&1);
		for(int j=0;j<=K;j++)
			if(j+cnt[i]<=K)
				add(ans,dp[m+1][i][n][j]);
	}
	printf("%d",ans);
	return 0;
}//tourist bless me!
