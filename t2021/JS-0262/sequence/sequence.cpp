#include <bits/stdc++.h>
#define M 998244353
using namespace std;

int n,m,k,i,a[32];
long long v[110],ans=0;

int count(int a[]){
	int cnt=0;
	int x=0;
	for(int i=1;i<=n;i++)
	  x+=(1<<a[i]);
	while(x>0){
		cnt+=x%2;
		x=(x>>1);
	}
	return cnt;
}

void dfs(int pos){
	if(pos>n){
		if(count(a)<=k){
			long long qz=1;
    		for(int i=1;i<=n;i++)
    		  qz=(qz*v[a[i]])%M;
    		ans=(ans+qz)%M;
		}
		return;
	}
	for(int i=0;i<=m;i++){
		a[pos]=i;
		dfs(pos+1);
	}
}

int main(){
	freopen("sequence.in","r",stdin);freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(i=0;i<=m;i++){
		scanf("%lld",&v[i]);
	}
	dfs(1);
	cout<<ans<<endl;
	
	return 0;
}
