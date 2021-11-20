#include<bits/stdc++.h>
using namespace std;
namespace FIFO{
//char buf[1<<23],*p1=buf,*p2=buf;
//#define gc() (p1==p2&&(p2=buf+fread(p1=buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#define gc() getchar()
void read(int&x){
	x=0;
	char c=gc();
	while(c>'9'||c<'0')c=gc();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=gc();
}
void print(int x){if(x<=9)putchar('0'+x);else print(x/10),putchar('0'+x%10);}
}using namespace FIFO;
const int mod=998244353;
int n,m,K,f[110][40][40][40],C[40][40],a[110],g[40],res;
void ADD(int&x,int y){if((x+=y)>=mod)x-=mod;}
int cnt[40];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&K);
	for(int i=0;i<=m;i++)read(a[i]);
	for(int i=0;i<=n;i++)C[i][0]=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	f[0][0][0][0]=1;
	for(int i=0;i<=m;i++)for(int j=0;j<=K;j++){
		g[0]=1;for(int k=1;k<=n;k++)g[k]=1ll*g[k-1]*a[i]%mod;
		for(int k=0;k<=n;k++)for(int l=0;l<=k;l++)if(f[i][j][k][l])for(int p=0;p+k<=n;p++)
			ADD(f[i+1][j+((l+p)&1)][p+k][(l+p)>>1],1ll*f[i][j][k][l]*g[p]%mod*C[p+k][p]%mod);
	}
	cnt[0]=0;for(int i=1;i<=n;i++)cnt[i]=cnt[i>>1]+(i&1);
	for(int j=0;j<=K;j++)for(int l=0;l<=n;l++)if(j+cnt[l]<=K)ADD(res,f[m+1][j][n][l]);
	printf("%d\n",res);
	return 0;
}
