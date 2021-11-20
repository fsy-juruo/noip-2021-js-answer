#include<bits/stdc++.h>
#define fz1(i,n) for((i)=1;(i)<=(n);(i)++)
#define fz0g(i,n) for((i)=0;(i)<=(n);(i)++)
#define fz0k(i,n) for((i)=0;(i)<(n);(i)++)
#define fd1(i,n) for((i)=(n);(i)>=1;(i)--)
#define fz(i,a,b) for((i)=(a);(i)<=(b);(i)++)
using namespace std;
void read(int &x)
{
	int s=0,f=1;char c;
	while((c=getchar())>'9'||c<'0') if(c=='-') f=-1;
	s=(c&15);
	while((c=getchar())>='0'&&c<='9') s=s*10+(c&15);
	x=s*f;
}
const int mod=998244353;
int n,m,lim,i,j,k,l,p,v[105],pw[105],ans;
int f[2][65][65][35]; // bit curval curpopcount curcnt
int fac[105],inv[105],fi[105];
int main()
{
	fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;
	fz(i,2,103){
		fac[i]=1ll*fac[i-1]*i%mod;
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
		fi[i]=1ll*fi[i-1]*inv[i]%mod;
	}
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);read(m);read(lim);fz0g(i,m) read(v[i]);
	f[1][0][0][0]=1;
	fz0g(i,m){
		memset(f[i&1],0,sizeof(f[i&1]));
		pw[0]=1;fz1(p,n) pw[p]=1ll*pw[p-1]*v[i]%mod;
		fz0g(j,n*2)fz0g(k,lim)fz0g(l,n)if(f[(i-1)&1][j][k][l]){
			for(p=0;l+p<=n;p++){
				if(k+((j+p)&1)>lim) continue;
				f[i&1][(j+p)/2][k+((j+p)&1)][l+p]=(f[i&1][(j+p)/2][k+((j+p)&1)][l+p]+1ll*f[(i-1)&1][j][k][l]*pw[p]%mod*fi[p])%mod;
			}
		}
	}
	fz0g(j,n*2)fz0g(k,lim){
		int nk=k;
		fz0k(i,30) if((j>>i)&1) nk++;
		if(nk<=lim) ans=(ans+f[m&1][j][k][n])%mod;
	}
	cout<<1ll*ans*fac[n]%mod<<endl;
	return 0;
}
