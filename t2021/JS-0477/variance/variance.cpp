#include<bits/stdc++.h>
#define ll long long
#define md 1000000007
using namespace std;
int n,ans=2e9,a[100003];
map<int,bool>mp;
int geth(){
	int num=1;
	for(int i=1;i<=n;++i)
		num=(53ll*num+a[i])%md;
	return num;
}
int getn(){
	int num=0,d=0;
	for(int i=1;i<=n;++i)d+=a[i],num+=a[i]*a[i];
	return (ll)n*num-(ll)d*d;
}
void dfs(){ 
	int hs=geth();
	if(mp.find(hs)!=mp.end())return;
	else mp[hs]=1;
	ans=min(ans,getn());
	for(int i=2,d;i<n;++i){
		d=a[i];
		a[i]=a[i-1]+a[i+1]-a[i];
		dfs();
		a[i]=d;
	}
}
signed main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	dfs();
	printf("%d",ans);
	return 0;
}
