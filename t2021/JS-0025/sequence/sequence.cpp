#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int power(int a,int b){
	int res=1;
	while(b){
		if(b&1) res=1ll*res*a%mod;
		a=1ll*a*a%mod,b>>=1;
	}
	return res;
}
int n,m,K,v[125][35],fac[35],invf[35];
int f[125][35][35][35],ans;
int tot=0;
inline void add(int &x,int y){
	x+=y; if(x>=mod) x-=mod;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&K);
	for(int i=0;i<=m;++i) scanf("%d",&v[i][1]);
	for(int i=0;i<=m+8;++i){
		v[i][0]=1;
		for(int j=2;j<=n;++j) v[i][j]=1ll*v[i][j-1]*v[i][1]%mod;
	}
	fac[0]=1;
	for(int i=1;i<=n;++i) fac[i]=1ll*fac[i-1]*i%mod;
	invf[n]=power(fac[n],mod-2);
	for(int i=n;i>=1;--i) invf[i-1]=1ll*invf[i]*i%mod;
	m+=8;
	f[m+1][0][0][0]=1;
	for(int i=m;i>=0;--i)
		for(int j=0;j<=1;++j)
			for(int q=0;q<=n;++q)
				for(int l=0;l<=n&&l<=q*2+j;++l){
					int us=q*2+j-l;
					if(i>m-8&&us!=0) continue;
					for(int k=j;k<=K;++k)
						for(int p=us;p<=n;++p)
							{
								//++tot;
								//if(us>p) continue;
								add(f[i][k][l][p],1ll*f[i+1][k-j][q][p-us]*v[i][us]%mod*invf[us]%mod); 
	//							cerr<<i<<" "<<k<<" "<<l<<" "<<p<<endl;
	//							cerr<<i+1<<" "<<k-j<<" "<<q<<" "<<p-us<<endl;
//								if(f[i][k][l][p]!=0){
//	//								cerr<<i<<" "<<k<<" "<<l<<" "<<p<<endl;
//	//								cerr<<f[i][k][l][p]<<endl;
//								}
							}
				}
	//cerr<<tot<<endl;
	for(int i=1;i<=K;++i)
		add(ans,f[0][i][0][n]);
	ans=1ll*ans*fac[n]%mod;
	printf("%d\n",ans);
	return 0;
}
/*
5 1 1
2 1
*/ 

