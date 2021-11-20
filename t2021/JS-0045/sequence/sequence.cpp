//rp++
/*
dp
*/
#include<bits/stdc++.h>
using namespace std;

void fre() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
}

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef double db;

inline ll read() {
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void write(ll x) {
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
#define writesp(x) write(x),putchar(' ')
#define writeln(x) write(x),putchar('\n')

#define rep(x,l,r) for(int x=l;x<=r;x++)
#define per(x,r,l) for(int x=r;x>=l;x--)
#define rep0(x) while(x--)

#define psf push_front
#define psb push_back
#define ppf pop_front
#define ppb pop_back

#define fi first
#define se second

const ll MOD=998244353;
const int N=40,M=120;

void add(ll &x,ll y) {
	x+=y;
	if(x>=MOD) x-=MOD;
}

ll power(ll a,ll k,ll mod=MOD) {
	ll ret=1;
	while(k) {
		if(k&1) ret=ret*a%mod;
		a=a*a%mod;
		k>>=1;
	}
	return ret;
}
ll inverse(ll a,ll mod=MOD) {
	//mod must be a prime
	return power(a,mod-2,mod);
}

ll jc[1010],jcinv[1010];
void getjc() {
	jc[0]=jcinv[0]=1;
	rep(i,1,1000) {
		jc[i]=jc[i-1]*i%MOD;
		jcinv[i]=inverse(jc[i]);
	}
}
ll C(int n,int m) {
	if(m<0) return 0;
	if(m>n) return 0;
	return jc[n]*jcinv[m]%MOD*jcinv[n-m]%MOD;
}

int n,m,k;
ll v[M];
ll f[N][M][N][N];
//30*100*30*30==300w good
/*
f[i][j][p][q]:
get i numbers
filling 2^j
already have 1 ,count p
jinwei q
*/

int bitcnt(int x) {
	int ret=0;
	while(x) {
		ret++;
		x-=(x&-x);
	}
	return ret;
}

int main() {
	fre();
	
	getjc();
	
	n=read(),m=read(),k=read();
	rep(i,0,m) v[i]=read();
	
	rep(i,0,n) {
		f[i][0][i%2][i/2]=power(v[0],i)*C(n,i)%MOD;
	}
	
	rep(i,0,n) rep(j,1,m) rep(p,0,k) rep(q,0,n) {
		rep(r,0,n) if(i+r<=n) {
			int jw=q+r;
			add(f[i+r][j][p+jw%2][jw/2],f[i][j-1][p][q]*power(v[j],r)%MOD*C(n-i,r)%MOD);
			//cout<<i<<" "<<j<<" "<<p<<" "<<q<<" "<<r<<" "<<f[i][j-1][p][q]*power(v[j],r)%MOD*C(n-i,r)%MOD<<endl;
		}
	}
	/*
	rep(i,0,n) rep(j,0,m) rep(p,0,k) rep(q,0,n) cout<<i<<" "<<j<<" "<<p<<" "<<q<<" "
	<<f[i][j][p][q]<<endl;
	*/
	ll ans=0;
	rep(p,0,k) rep(q,0,n) {
		if(p+bitcnt(q)<=k) {
			add(ans,f[n][m][p][q]);
		}
	}
	writeln(ans);
	
	return 0;
}
