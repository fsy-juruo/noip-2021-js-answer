//rp++
#include<bits/stdc++.h>
using namespace std;

void fre() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
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

const ll INF=1e18;
const int N=10100;

void chkmin(ll &x,ll y) {
	if(x>y) x=y;
}

int n;
ll a[N];
ll d[N];

ll b[N];
ll c[N];
ll calc() {
	ll ret=0,sum=0;
	b[1]=a[1];
	rep(i,2,n) b[i]=b[i-1]+c[i-1];
	rep(i,1,n) {
		sum+=b[i];
		ret+=b[i]*b[i];
	}
	ret*=n;
	ret-=sum*sum;
	return ret;
}

bool vis[N];
ll ans=INF;
void dfs(int dept) {
	if(dept==n) {
		chkmin(ans,calc());
		return;
	}
	rep(i,1,n-1) if(!vis[i]) {
		vis[i]=1;
		c[dept]=d[i];
		dfs(dept+1);
		vis[i]=0;
		c[dept]=0;
	}
}

int main() {
	fre();

	n=read();
	rep(i,1,n) a[i]=read();
	rep(i,1,n-1) d[i]=a[i+1]-a[i];
	sort(d+1,d+n-1+1);

	dfs(1);
	writeln(ans);

	return 0;
}
