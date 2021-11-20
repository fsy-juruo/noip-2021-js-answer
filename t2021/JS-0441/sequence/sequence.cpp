#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0;char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
inline void write(int x){
	if(x>9)write(x/10);
	putchar(x%10|48);
}
inline void writeln(int x){
	write(x),putchar('\n');
}
#define mod 998244353
int ksm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=ans*1ll*a%mod;
		a=a*1ll*a%mod;
		b>>=1;
	}
	return ans;
}
int f[33][105][33][33],g[103][33],inv[33],v[33];
int ck(int i,int j){
	while(j){
		i+=(j&1);
		j>>=1;
	}
	return i;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	inv[0]=1;
	for(int i=1;i<=30;++i)inv[i]=inv[i-1]*1ll*ksm(i,mod-2)%mod;
	int n=read(),m=read(),k=read(),ans=0;
	for(int i=0;i<=m;++i)v[i]=read();
	for(int i=0;i<=m;++i)for(int j=0;j<=n;++j)g[i][j]=ksm(v[i],j);
	f[0][0][0][0]=1;
	for(int i=0;i<=n;++i){
		for(int j=0;j<=m+1;++j){
			for(int p=0;p<=k;++p){
				for(int q=0;q<=n;++q){
					for(int r=0;r<=n-i;++r){
						f[i+r][j+1][p+((q+r)&1)][(q+r)>>1]=(f[i+r][j+1][p+((q+r)&1)][(q+r)>>1]+f[i][j][p][q]*1ll*inv[r]%mod*g[j][r])%mod;
					}
				}
			}
		}
	}
	for(int i=0;i<=k;++i){
		for(int j=0;j<=n;++j){
			if(ck(i,j)<=k)ans=(ans+f[n][m+1][i][j])%mod;
		}
	}
	writeln(ans*1ll*ksm(inv[n],mod-2)%mod);
	return 0;
}
