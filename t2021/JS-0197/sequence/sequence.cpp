#include <bits/stdc++.h>
using namespace std;
template<typename TT>void read(TT &x){
	x=0;int f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+ch-'0';
	x*=f;
}
typedef long long LL;
const LL mod=998244353;
const int maxn=40,maxm=110;
LL f[maxm][maxn][maxn][maxn];
LL fp[maxm][maxm],jc[maxn],ny[maxn];

LL nyy(LL a){
	LL b=mod-2,ret=1;
	while(b){
		if(b&1)ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}

int cnt(int x){
	int ret=0;
	while(x)x-=(x&(-x)),ret++;
	return ret;
}

int n,m,maxk;
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);read(m);read(maxk);
	jc[0]=1;ny[0]=1;
	for(int i=1;i<=n;i++)jc[i]=jc[i-1]*i%mod,ny[i]=nyy(jc[i]);
	for(int i=0;i<=m;i++)read(fp[i][1]);
	for(int i=0;i<=m;i++)fp[i][0]=1;
	for(int i=0;i<=m;i++)
	for(int j=2;j<=n;j++)fp[i][j]=(fp[i][j-1]*fp[i][1])%mod;
	for(int j=0;j<=n;j++){
		if(j&1)f[0][j][1][j/2]=fp[0][j]*ny[j]%mod;
		else f[0][j][0][j/2]=fp[0][j]*ny[j]%mod;
	}
	for(int i=1;i<=m;i++)
	for(int j=0;j<=n;j++){
		//k==0
		for(int s=0;j-s>=0;s++)
		for(int l=0;2*l-s<=n;l++)if(2*l-s>=0)f[i][j][0][l]=(f[i][j][0][l]+f[i-1][j-s][0][2*l-s]*fp[i][s]%mod*ny[s]%mod)%mod;
		//k>0
		for(int k=1;k<=maxk;k++)
		for(int s=0;j-s>=0;s++){
			for(int l=0;2*l<=n;l++)if(2*l-s>=0)f[i][j][k][l]=(f[i][j][k][l]+f[i-1][j-s][k][2*l-s]*fp[i][s]%mod*ny[s]%mod)%mod;
			for(int l=0;2*l<=n;l++)if(2*l+1-s>=0)f[i][j][k][l]=(f[i][j][k][l]+f[i-1][j-s][k-1][2*l+1-s]*fp[i][s]%mod*ny[s]%mod)%mod;
		}
	}
//	for(int i=0;i<=m;i++)
//	for(int j=0;j<=n;j++)
//	for(int k=0;k<=maxk;k++)
//	for(int l=0;2*l<=n;l++)printf("f[%d][%d][%d][%d]=%lld\n",i,j,k,l,f[i][j][k][l]*jc[n]%mod);
	LL ans=0;
	for(int i=0;i<=maxk;i++)
	for(int l=0;l<=n;l++)if(cnt(l)+i<=maxk)ans=(ans+f[m][n][i][l]*jc[n]%mod)%mod;
	printf("%lld",ans);
	return 0;
}

