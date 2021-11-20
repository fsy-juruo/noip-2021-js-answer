#include<bits/stdc++.h>
#define mp make_pair
#define lb lower_bound
#define up upper_bound
#define re register int
using namespace std;
typedef long long ll;
typedef long double ld;

template<typename T> inline void rd(T &x){
	x=0;bool fl=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl^=1;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c-'0');
	if(fl) x=-x;
}

template<typename T> inline void wr(T x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	else wr(x/10),putchar(x%10+'0');
}

// ---------- IO ---------- //

const int N=32,M=105,T=35,mod=998244353;
int n,m,k,v[M],fac[M]={1},inv[M]={1},f[N][M][N][T],cnt[T<<3],Log[T<<3],ans,P[M][N];

inline int pw(int x,int y){
	int sum=1;
	while(y){
		if(y&1) sum=1ll*sum*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return sum;
}

inline int C(int x,int y){
	if(x<y) return 0;
	return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}

// ----------  ---------- //

int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	rd(n);rd(m);rd(k);++m;
	for(re i=1;i<M;++i) fac[i]=1ll*fac[i-1]*i%mod;
	inv[M-1]=pw(fac[M-1],mod-2);
	for(re i=M-2;i>0;--i) inv[i]=1ll*inv[i+1]*(i+1)%mod;
	cnt[0]=0;Log[0]=-1;
	for(re i=1;i<(T<<3);++i) cnt[i]=cnt[i>>1]+(i&1),Log[i]=Log[i>>1]+1;
	for(re i=1;i<=m;++i){
		rd(v[i]),P[i][1]=v[i],P[i][0]=1;
		for(re j=2;j<=n;++j) P[i][j]=1ll*P[i][j-1]*v[i]%mod;
	}
	f[0][0][0][0]=1;
	for(re i=0;i<=n;++i)
		for(re j=0;j<=m;++j)
			for(re a=0;a<=k;++a)
				for(re b=0;b<T;++b)
					if(f[i][j][a][b]){
						for(re d=j+1;d<=m;++d) // maxn
							for(re c=1;c+i<=n;++c){ // cnt
							//	cout<<i<<' '<<j<<' '<<a<<' '<<b<<' '<<f[i][j][a][b]<<endl;
								int nxta=a,nxtb;
								if(d-j>Log[b]+1) nxta+=cnt[b],nxtb=c;
								else nxta+=cnt[b]-cnt[b>>(d-j)],nxtb=c+(b>>(d-j));
							//	cout<<i+c<<' '<<d<<' '<<nxta<<' '<<nxtb<<' '<<1ll*pw(v[d],c)*C(n-i,c)%mod*f[i][j][a][b]%mod<<' '<<(f[i+c][d][nxta][nxtb]+1ll*pw(v[d],c)*C(n-i,c)%mod*f[i][j][a][b]%mod)%mod<<endl;
							//	puts("-----");
								if(nxta<=k) f[i+c][d][nxta][nxtb]=(f[i+c][d][nxta][nxtb]+1ll*P[d][c]*C(n-i,c)%mod*f[i][j][a][b]%mod)%mod;
							}
					}
	ans=0;
	for(re j=1;j<=m;++j)
		for(re a=0;a<=k;++a)
			for(re b=0;b<T;++b)
				if(a+cnt[b]<=k) ans=(ans+f[n][j][a][b])%mod;//,cout<<"qaq "<<n<<' '<<j<<' '<<a<<' '<<b<<' '<<f[n][j][a][b]<<endl;
	wr(ans);puts("");
	return 0;
}

// ---------- Main ---------- //

