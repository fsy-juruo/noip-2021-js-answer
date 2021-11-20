#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 105
#define ll long long
using namespace std;

const ll mod=998244353;

int n,m,k;
ll ans,cnt,time,f;
ll v[N],g[N],y[N];

bool check(int d){
	ll p=0,y=0;
	for(int i=0;i<m;i++) p+=g[i]*(1<<i);
	p+=d*(1<<m);
	while(p){
		if(p&1) y++;
		p>>=1;
	}
	if(y<=k) return true;
	return false;
}

void dfs(int x){
	if(x==n+1) {
		time++;
		return;
	}
	for(int i=m;i>=f;i--){
		if(!g[i]) continue;
		g[i]--;
		dfs(x+1);
		g[i]++;
	}
}

void solve(int x,int d){
	if(x==m){
		cnt=1;time=0;f=0;
		if(!check(d)) return;
		for(int i=0;i<m;i++)
		  for(int j=1;j<=g[i];j++)
		   cnt=cnt*v[i]%mod;
		for(int i=1;i<=d;i++) cnt=cnt*v[m]%mod;
		g[m]=d;sort(g+0,g+0+m);
		for(int i=m;i>=0;i--) if(!g[i]) {f=i;break;}
		dfs(1);
		ans+=cnt*time%mod;
		return;
	}
	for(int i=0;i<=d;i++){
		g[x]=i;
		solve(x+1,d-i);
	}
}

int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++) scanf("%lld",&v[i]);
	solve(0,n);
	printf("%lld\n",ans);
	return 0;
}
