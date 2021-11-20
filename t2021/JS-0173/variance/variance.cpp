#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
const int N=10005,B=131;
typedef long long ll;
int n,a[N];ll ans=1e18;
gp_hash_table<ll,int> h;
void dfs(ll x,ll y){
	ll ha=0;
	for(int i=2;i<n;i++) ha=ha*B+a[i];
	if(h[ha]) return;h[ha]=1;
	ans=min(ans,n*y-x*x);
	for(int i=2;i<n;i++){
		int z=a[i-1]+a[i+1]-a[i],z1=a[i];
		if(z>=a[i-1] && z<=a[i+1] && z!=z1){
			a[i]=z;dfs(x-z1+z,y-z1*z1+z*z);a[i]=z1;
		}
	}
}
void dfs2(ll x,ll y,int z2){
	if(z2>=200) return;ll ha=0;
	for(int i=2;i<n;i++) ha=ha*B+a[i];
	if(h[ha]) return;h[ha]=1;
	ans=min(ans,1ll*n*y-x*x);
	for(int i=2;i<n;i++){
		int z=a[i-1]+a[i+1]-a[i],z1=a[i];
		if(z>=a[i-1] && z<=a[i+1] && z!=z1){
			a[i]=z;int xx=x-z1+z,yy=y-z1*z1+z*z;
			if(n*yy-xx*xx>ans) dfs2(xx,yy,z2+1);
			else dfs2(xx,yy,0);a[i]=z1;
		}
	}
}
int main( ){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;ll x=0,y=0,z=0;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),x+=a[i],y+=a[i]*a[i];
	if(n<=4) dfs(x,y);else dfs2(x,y,0);cout<<ans<<endl;return 0;
}
/*
10
1 4 6 8 13 15 35 56 71 75
*/

