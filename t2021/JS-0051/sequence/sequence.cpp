#include<bits/stdc++.h>
#define ll long long
#define N 40
#define M 115
using namespace std;
int n,m,k,wws[N];
ll mod=998244353,dp[M][N][N][N],v[M],jc[M],ny[M],ans,ks[M][N];

ll ksm(ll p,ll k){
	ll rt=1;
	while(k){
		if(k%2==1) rt*=p,rt%=mod;
		p*=p;
		p%=mod;
		k>>=1;
	}
	return rt;
}

int main(){
	
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m+1;i++){
		cin>>v[i];
		ks[i][0]=1;
		for(int j=1;j<=n;j++) ks[i][j]=ksm(v[i],j);
	}
	jc[0]=1;
	ny[0]=1;
	for(int i=1;i<=m+7;i++){
		jc[i]=jc[i-1]*i;
		jc[i]%=mod;
		ny[i]=ksm(jc[i],mod-2);
	}
	dp[0][0][0][0]=1;
	for(int i=1;i<=m+1;i++){
		for(int j=0;j<=k;j++){
			for(int l=0;l<=n;l++){
				for(int msk=0;msk<=l;msk++){
					for(int pt=0;pt<=l-msk;pt++){
						if((msk+pt)%2==0){
							dp[i][j][l][(msk+pt)/2]+=((((((dp[i-1][j][l-pt][msk]*jc[l])%mod)*ny[l-pt])%mod)*ny[pt])%mod*ks[i][pt]);
							dp[i][j][l][(msk+pt)/2]%=mod;
						}
						else{
							if(j>0){
								dp[i][j][l][(msk+pt)/2]+=(dp[i-1][j-1][l-pt][msk]*jc[l]%mod*ny[l-pt]%mod*ny[pt]%mod*ks[i][pt]);
								dp[i][j][l][(msk+pt)/2]%=mod;
							}
						}
					}
				}
			}
		}
	}
	for(int i=0;i<=32;i++){
		for(int j=0;j<7;j++){
			if((i>>j)&1) wws[i]++;
		}
	}
	for(int i=0;i<=k;i++){
			for(int msk=0;msk<=n;msk++){
				if(i+wws[msk]<=k) ans+=dp[m+1][i][n][msk];
				ans%=mod;
			}
	}
	cout<<ans;
	return 0;
}
