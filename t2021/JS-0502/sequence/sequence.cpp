#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL v[110];
LL f[35][35][35];
LL g[35][35][35];
LL inv[35];
LL c[35];
LL sqr(LL x){
	return x*x%998244353;
}
LL qpow(LL x,LL y){
	if(y==0)return 1;
	if(y==1)return x;
	if(y%2==1)return x*qpow(x,y-1)%998244353;
	return sqr(qpow(x,y/2));
}
LL n,m,K;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>K;
	c[0]=1;inv[0]=1;
	for(LL i=1;i<=n;i++){
		c[i]=c[i-1]*i;
		inv[i]=qpow(c[i],998244351);
	}
	for(LL i=0;i<=m;i++)cin>>v[i];
	f[0][0][0]=1;
	for(LL i=0;i<=m+5;i++){
		for(LL j=0;j<=n;j++){
			for(LL k=0;k<=K;k++){
				for(LL l=0;l<=32;l++){
//					if(l<=3)cout<<i<<":"<<j<<" "<<k<<" "<<l<<":"<<f[j][k][l]<<endl;
					for(LL p=0;p+j<=n;p++){
						if(i>m&&p)break;
						if((l+p)%2==1){
							g[j+p][k+1][(l+p)/2]+=inv[p]*f[j][k][l]%998244353*qpow(v[i],p)%998244353;
							g[j+p][k+1][(l+p)/2]%=998244353;
						}else{
							g[j+p][k][(l+p)/2]+=inv[p]*f[j][k][l]%998244353*qpow(v[i],p)%998244353;
							g[j+p][k][(l+p)/2]%=998244353;
						}
					}
				}
			}
		}
		for(LL j=0;j<=n;j++){
			for(LL k=0;k<=K;k++){
				for(LL l=0;l<=32;l++){
					f[j][k][l]=g[j][k][l];
					g[j][k][l]=0;
				}
			}
		}
	}
	LL ans=0;
	for(LL i=1;i<=K;i++){
		ans+=f[n][i][0];
		ans%=998244353;
	}
	cout<<ans*c[n]%998244353<<endl;
	return 0;
}

