#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
ll n,m,k,v[110],a[35],sum[110],cnt[110],ans,c[110][110];
void dfs(int x,int pre){
	if(x==n+1){
		for(int i=0;i<=m+5;i++)cnt[i]=sum[i];
		ll ret=0;
		for(int i=0;i<=m+5;i++){
			int t=cnt[i]/2;
			cnt[i]%=2;
			if(cnt[i]==1)ret++;
			cnt[i+1]+=t;
		}
		if(ret>k)return;
		ret=1;
		for(int i=1;i<=n;i++){
			ret=ret*v[a[i]]%MOD;
		}
		ll tmp=n;
		for(int i=0;i<=m;i++){
			ret=ret*c[tmp][sum[i]];
			ret%=MOD;
			tmp-=sum[i];
			if(tmp==0)break;
		}
		ans+=ret;
		ans%=MOD;
		return;
	}
	for(int i=pre;i<=m;i++){
		a[x]=i;sum[i]++;
		dfs(x+1,i);
		sum[i]--;
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=0;i<=m;i++)scanf("%lld",&v[i]);
	for(int i=0;i<=105;i++)c[i][0]=1;
	for(int i=1;i<=105;i++){
		for(int j=1;j<=i;j++)c[i][j]=c[i-1][j]+c[i-1][j-1];
	}
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
} 
