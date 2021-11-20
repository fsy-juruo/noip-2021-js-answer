#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD=998244353;
const int N=1e2+1;

int n,m,k,v[N],g[N];
ll ans=0,times[N];

inline bool check() {
//	for(int i=0;i<=m;i++) printf("%d ",g[i]); puts("");
	int p[N]={0},gs=0;
	for(register int i=0;i<=m;i++) p[i]+=g[i];
	for(register int i=0;i<=m+4;i++)
		p[i+1]+=p[i]/2 , p[i]&=1;
//	for(int i=0;i<=m+3;i++) printf("%d ",p[i]);	puts("");
	for(register int i=0;i<=m+4;i++) gs+=(p[i]==1);
	return gs <= k;	
}

inline void dfs(register int x,register int he) {
	if(x==m) {
		g[m]=he;
		if(!check()) return;
		ll lhm = 1;
		for(register int i=0;i<=m;i=-~i)
		for(register int j=1;j<=g[i];j=-~j) lhm = lhm * v[i] % MOD;
		ll t = times[n];
		for(register int i=0;i<=m;i++) t /= times[g[i]];
//		printf("%lld %lld\n",lhm,t);
		ans = (ans + lhm * t % MOD) % MOD;
		return;
	}
	for(g[x]=0;g[x]<=he;g[x]=-~g[x]) dfs(x+1,he-g[x]);
}

int main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(register int i=0;i<=m;i=-~i) scanf("%d",v+i);
	times[0]=1;
	for(register int i=1;i<=n;i=-~i) times[i]=times[i-1] * i % MOD;
//	int s=1;
	dfs(0,n);
	printf("%lld\n",ans);
	return 0;
}

