#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n,ans=1e9+7;
int aaa[105],h[105],a[105];
const ll MOD=1e9+7,qqd=601; 
map<ll,bool> vis;
ll hashx(int aa[]){
	for(int i=0;i<n;i++){
		a[i]=aa[i];
	}
	ll fff=0;
	for(int i=0;i<n;i++){
		fff+=a[i]*h[i];
		fff%=MOD;
	}
	return fff;
}
int count_var(int aa[]){
	for(int i=0;i<n;i++){
		a[i]=aa[i];
	}
	int sum=0;
	for(int i=0;i<n;i++){
		//cout<<a[i]<<" ";
		sum+=a[i];
		a[i]*=n;
	}
	//cout<<endl; 
	int res=0;
	for(int i=0;i<n;i++){
		res+=(a[i]-sum)*(a[i]-sum);
		a[i]/=n;
	}
	res/=n;
	return res;
}
void dfs(int aa[]){
	for(int i=0;i<n;i++){
		a[i]=aa[i];
	}
	ll t=hashx(a);
	if(vis[t]){
		return;
	}
	//cout<<ans<<" ";
	vis[t]=1;
	int res=count_var(a);
	ans=min(ans,res);
	for(int i=1;i<n-1;i++){
		int tmp=a[i];
		if(a[i]!=a[i-1]+a[i+1]-a[i]){
			a[i]=a[i-1]+a[i+1]-a[i];
			dfs(a);
		}
		a[i]=tmp;
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	ll now=qqd;
	for(int i=0;i<=100;i++){
		h[i]=now;
		now*=qqd;
		now%=MOD;
	}
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>aaa[i];
	}
	dfs(aaa);
	//cout<<"???";
	cout<<ans;
	return 0;
}
/*
10
1 6 10 17 19 24 27 36 38 39
*/
