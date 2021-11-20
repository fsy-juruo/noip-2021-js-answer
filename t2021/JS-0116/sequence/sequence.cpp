#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,M=998244353,a[111],d[1010100];
ll P(ll w,ll h){
	ll r=1;
	for(int i=0;i<h;i++)r=r*w%M;
	return r;
}
ll C(ll w,ll h){
	ll r=1,R=1;
	for(int i=1;i<=h;i++){
		r*=(w-i+1);
		R*=i;
	}
	return r/R;
}
ll ans=0;
void dfs(int x,int s,int e,ll r){
	if(x>m){
		int g=0;
		for(int i=1;i<=(1<<20);i*=2)g+=(e&i);
		if(g<=k)ans+=r*(s==0);
		return;
	}
	for(int i=0;i<=x;i++){
		dfs(x+1,s-i,e+i*(1<<x),r*P(a[x],i)*C(s,i));
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++)cin>>a[i];
	dfs(0,n,0,1);
	cout<<ans<<endl;
	return 0;
}
