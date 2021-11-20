#include<bits/stdc++.h>
using namespace std;
#define LL long long
const LL MOD=998244353;
LL read(){
	LL x=0,sign=1;
	char ch=getchar();
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-'){
		sign=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*sign;
}
LL f[35][123000];
LL v[15];
//LL f[6][11];
//LL v[6];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	LL n=read(),m=read(),k=read(),x=1;
	for(LL i=0;i<=m;i++){
		v[i]=read();
		f[1][x]+=v[i];
		x*=2;
	}
	LL maxs=pow((LL)2,m)*(n-1);
	for(LL i=1;i<n;i++){
//		printf("\n");
		for(LL j=1;j<=maxs;j++){
			x=1;
			for(LL k=0;k<=m;k++){
				f[i+1][j+x]=(f[i+1][j+x]+v[k]*f[i][j])%MOD;
				x*=2;
			}
//			printf("%lld ",f[i][j]);
		}
	}
	maxs=pow(2,m)*n;
	LL ans=0;
//	printf("\n");
	for(int i=1;i<=maxs;i++){
//		printf("%lld ",f[n][i]);
		LL itp=i,cnt=0;
		while(itp>0){
			cnt+=itp&1;
			itp>>=1;
		}
		if(cnt<=k) ans=(ans+f[n][i])%MOD;
	}
	printf("%lld",ans);
	
	return 0;
}
