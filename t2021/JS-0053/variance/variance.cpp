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

const int N=1e4+5;
int n,a[N],b[N],c[N],l,r,tot,d[N];
bool vst[N];
ll ans=1e18,sum;
struct node{int l,v;}p[N];

inline ll calc(){
	ll res=0;
	for(re i=1;i<n;++i) res+=1ll*i*(n-i)*d[i]*d[i];
	for(re i=1;i<n;++i)
		for(re j=i+1;j<n;++j) res+=2ll*i*(n-j)*d[i]*d[j];
	return res;
}

inline void search(int nw){
	if(nw==n){ans=min(ans,calc());return ;}
	for(re i=1;i<n;++i)
		if(!vst[i]) d[nw]=b[i],vst[i]=1,search(nw+1),vst[i]=0;
}

/*inline void dfs(int nw){
	if(nw>tot) return ;
	if(nw==tot){
		ll res=0;
		for(re i=1;i<n;++i) res+=1ll*i*(n-i)*c[i]*c[i];
		for(re i=1;i<n;++i)
			for(re j=i+1;j<n;++j) res+=2ll*i*(n-j)*c[i]*c[j];
		ans=min(ans,res);
		return ;
	}
	dfs(nw+1);swap(c[p[nw].l],c[n-p[nw].l]);dfs(nw+1);
}*/

// ----------  ---------- //

int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	rd(n);
	for(re i=1;i<=n;++i) rd(a[i]);
	for(re i=1;i<n;++i) d[i]=b[i]=a[i+1]-a[i];
	sort(b+1,b+n);sort(d+1,d+n);
	if(n>20){
	if(n&1){
		for(re i=(n-1)/2;i>0;--i){
			c[i]=b[((n-1)/2-i)*2+1],c[n-i]=b[((n-1)/2-i)*2+2];
			if(c[i]^c[n-i]) p[++tot]=(node){i,c[n-i]-c[i]};
		}
	}
	else{
		c[n/2]=b[1];
		for(re i=n/2-1;i>0;--i){
			c[i]=b[(n/2-i)*2],c[n-i]=b[(n/2-i)*2+1];
			if(c[i]^c[n-i]) p[++tot]=(node){i,c[n-i]-c[i]};
		}
	}
	for(re i=1;i<n;++i) ans+=1ll*i*(n-i)*c[i]*c[i];
	for(re i=1;i<n;++i)
		for(re j=i+1;j<n;++j) ans+=2ll*i*(n-j)*c[i]*c[j];
	wr(ans);puts("");return 0;
}
	search(1);
	wr(ans);puts("");
	return 0;
}

// ---------- Main ---------- //

