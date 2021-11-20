#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=10005;
ll n,a[N],sum,res,ans;
bool vis[N];
void dfs(ll x,ll pre){
	if(x>10)return;
	ans=min(ans,n*res-sum*sum);
	for(ll i=2;i<=n-1;i++){
		//if(vis[i])continue;
		//vis[i]=true;
		if(i==pre)continue;
		ll t=a[i];a[i]=a[i+1]-a[i]+a[i-1];
		sum+=a[i]-t;res+=a[i]*a[i]-t*t;
		dfs(x+1,i);
		//vis[i]=false;
		sum-=a[i]-t;
		res-=a[i]*a[i]-t*t;a[i]=t;
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum+=a[i];res+=a[i]*a[i];
	}
	ans=n*res-sum*sum;
	dfs(0,-1);
	printf("%lld\n",ans);
	return 0;
} //
