#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define INF 0x3f3f3f3f
#define N 103
#define MOD 998244353
int n,m,k,m2[N];
LL v[N],ans;
bool f[150003];
void dfs(int t,int s,LL val){
	if(t>n){
		if(f[s]) ans=(ans+val)%MOD;
		return;
	}
	for(int i=0;i<=m;++i)
		dfs(t+1,s+m2[i],val*v[i]%MOD);
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	m2[0]=1;
	for(int i=1;i<=12;++i)
		m2[i]=m2[i-1]*2;
	for(int i=1;i<=150000;++i){
		int b=i,cnt=0;
		while(b) cnt+=b%2,b/=2;
		if(cnt<=k) f[i]=true;
	}
	for(int i=0;i<=m;++i)
		scanf("%lld",&v[i]);
	dfs(1,0,1);
	printf("%lld\n",ans);
	return 0;
}
//然而没分 
