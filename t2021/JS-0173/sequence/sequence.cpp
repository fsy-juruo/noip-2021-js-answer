#include<bits/stdc++.h>
using namespace std;
const int N=105,p=998244353;
typedef long long ll;
int v[N],n,m,k,a[N];ll ans;
void dfs(int x){
	if(x>n){
		ll s=0,res=1;
		for(int i=1;i<=n;i++) s+=(1ll<<a[i]),(res*=v[a[i]])%=p;
		if(__builtin_popcountll(s)<=k) (ans+=res)%=p;return;
	}
	for(int i=0;i<=m;i++) a[x]=i,dfs(x+1);
}
int main( ){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++) cin>>v[i];
	dfs(1);cout<<ans<<endl;return 0;
}
