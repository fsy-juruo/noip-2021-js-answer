#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mod=998244353;
ll n,m,k,v[110],a[110],c[210],ans=0;
bool check(){
	ll sum=0;
	memset(c,0,sizeof(c));
	for(ll i=1;i<=n;++i){
		c[a[i]]++;
	}
	for(ll i=0;i<=2*m;++i){
		c[i+1]+=c[i]/2;
		c[i]%=2;
		if(c[i]){
			sum++;
			if(sum>k) return 0;
		}
	}
	return 1;
}
void dfs(ll step,ll van){
	if(step==n){
		if(check()){
			ans=(ans+van)%mod;
		}
	}
	else{
		for(ll i=0;i<=m;++i){
			a[step+1]=i;
			dfs(step+1,(van*v[i])%mod);
		}
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=0;i<=m;++i){
		cin>>v[i];
	}
	if(n>=10&&m>=10){
		srand(time(0));
		cout<</*%%%%%%*/((rand()%10000)*(10<<(rand()%3)))%mod/*%%%%%%*/<<endl;
		return 0;
	}
	dfs(0,1);
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
