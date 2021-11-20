#include<iostream>
#include<cstdio>
#define ll long long
const ll mod=998244353;
int n,m,mk;
ll v[155]={0};
ll p[155][105]={0};
ll f[110][35][35][65]={0};
ll ans=0,cnt=0;
ll lf[105]={0};
ll inv[105]={0},fac[105]={0},invf[105]={0};
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&mk);
	for(int i=1;i<=m+1;++i){
		scanf("%lld",&v[i]);
		p[i][0]=1;
		for(int j=1;j<=n;++j){
			p[i][j]=p[i][j-1]*v[i]%mod;
		}
	}
	inv[1]=1;
	invf[0]=1;
	invf[1]=1;
	fac[0]=1;
	fac[1]=1;
	for(int i=2;i<=n;++i){
		fac[i]=fac[i-1]*i%mod;
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
		invf[i]=invf[i-1]*inv[i]%mod;
	}
	for(int i=0,ti;i<=n;++i){
		ti=i;
		cnt=0;
		while(ti){
			if(ti&1) ++cnt;
			ti>>=1;
		}
		lf[i]=cnt;
	}
	f[0][0][0][0]=1;
	for(int i=1;i<=m+1;++i){
		for(int j=0;j<=n;++j){
			for(int k=0;k<=mk;++k){
				for(int l=0;l<=n;++l){
					for(int num=0;num<=j;++num){
						if(l*2-num>=0) f[i][j][k][l]=(f[i][j][k][l]+(f[i-1][j-num][k][l*2-num]*p[i][num]%mod)*invf[num])%mod;
						if(k&&l*2-num+1>=0) f[i][j][k][l]=(f[i][j][k][l]+(f[i-1][j-num][k-1][l*2-num+1]*p[i][num]%mod)*invf[num])%mod;
					}
//					std::cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<f[i][j][k][l]<<"\n";
				}
			}
		}
	}
	for(int i=0;i<=mk;++i){
		for(int j=0;j<=n;++j){
			if(i+lf[j]<=mk) ans=(ans+f[m+1][n][i][j])%mod;
		}
	}
	printf("%lld",ans*fac[n]%mod);
}
