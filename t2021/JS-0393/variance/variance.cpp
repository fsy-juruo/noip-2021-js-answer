#include<bits/stdc++.h>
using namespace std;

long long n;
long long a[400+10];
long long ans=0x7fffffffff;
bool vis[400+10];
bool f[600+10][600+10];
long long jsfc(){
	long long pj=0;
	long long fc=0;
	for(long long i=1;i<=n;i++){
		pj+=a[i];
	}
	for(long long i=1;i<=n;i++){
		fc+=(pj-a[i]*n)*(pj-a[i]*n);
	}
	return fc/n;
}
long long zs(){
	long long dddd=0;
	for(int i=1;i<=n;i++){
		dddd+=a[i];
	}
	return dddd;
}
void dfs(long long place){
	long long k=a[place];
	a[place]=a[place-1]+a[place+1]-a[place];
	if(a[place]==k){
		return ;
	}	
	long long sss=jsfc();
	if(f[sss][zs()]==true){
		return ;
	}
	f[sss][zs()]=true;
	ans=min(ans,sss);
	for(long long i=2;i<=n-1;i++){
		dfs(i);
	}
	a[place]=k;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long sss=jsfc();
	f[sss][zs()]=true;
	ans=min(ans,sss);
	for(long long i=2;i<=n-1;i++){
		dfs(i);
	}
	cout<<ans<<endl;
	return 0;
}

