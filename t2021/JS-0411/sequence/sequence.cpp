#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=35,maxm=105,mod=998244353;

int read(){
	int s=0,w=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-')  w=-w;ch=getchar();}
	while (ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+(ch^'0');ch=getchar();}
	return s*w;
}
int n,m,k;
int a[maxn],jc[maxn],inv[maxn],tmp[maxm][maxn];
int f[maxm][maxn][maxn][maxn],bc[maxn];

int quick_power(int x,int y){
	int res=1;
	for (;y;y=y>>1,x=(x*x)%mod){
		if (y&1)  res=(res*x)%mod;
	}
	return res;
}
int ny(int tmpx){return quick_power(tmpx,mod-2);}
void chksum(int x,int &y){y=(x+y)%mod;}

namespace ducati{
	void get_all_in(){
		n=read(),m=read()+1,k=read();
		for (int i=1;i<=m;i++)  a[i]=read();
	}
	void init(){
		jc[0]=1;
		for (int i=1;i<=n;i++)  jc[i]=(jc[i-1]*i)%mod;
		
		inv[n]=ny(jc[n]);
		for (int i=n-1;i>=0;i--)  inv[i]=(inv[i+1]*(i+1))%mod;
		for (int i=1;i<=m;i++){
			tmp[i][0]=1;
			for (int j=1;j<=n;j++)  tmp[i][j]=(tmp[i][j-1]*a[i])%mod;
		}
		for (int i=0;i<=n;i++)  bc[i]=bc[i>>1]+(i&1);
	}
	void DP(){
		f[0][0][0][0]=1;
		for (int i=0;i<m;i++){
			for (int j=0;j<=n;j++){
				for (int k=0;k<=n;k++){
					for (int w=0;w<=n;w++){
						if (!f[i][j][k][w])  continue;
						for (int p=0;p<=n-w;p++){
							int kk=(tmp[i+1][p]*inv[p])%mod,jj=(j/2)+p;
							chksum((f[i][j][k][w]*kk)%mod,f[i+1][jj][k+(jj&1)][w+p]);
						}
					}
				}
			}
		}
	}
	void calc_ans(){
		int ans=0;
		for (int j=0;j<=n;j++){
			for (int t=0;t<=k;t++){
				if (!f[m][j][t][n])  continue;
				if (bc[j/2]+t<=k)  chksum(f[m][j][t][n],ans);
			}
		}
		ans=(ans*jc[n])%mod;
		cout<<(ans%mod+mod)%mod<<endl;
	}
	void solve(){get_all_in(),init(),DP(),calc_ans();}
}

signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	
	ducati::solve();
	return 0;
} 
