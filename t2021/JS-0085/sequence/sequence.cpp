#include <bits/stdc++.h>
using namespace std;
int n,m,k,v[60],dg[20];
long long ans;
bool ck(int x){
	int cnt=0;
	while(x>0){
		cnt+=x%2;
		x/=2;
	}
	return (cnt<=k);
}
int d[60];
long long mt(int x){
	long long ret=1;
	while(x>1){
		ret=ret*x%998244353;
		x--;
	}
	return ret;
}
long long cob(){
	long long s=mt(n);
	for(int i=0;i<=m;i++)if(d[i]>1)s/=mt(d[i]);
	return s;
}
void dfs(int pos,int last){
	if(pos==n+1){
		int s=0;
		for(int i=1;i<=n;i++)s+=pow(2,dg[i]);
		if(ck(s)){
			memset(d,0,sizeof(d));
			long long mult=1;
			for(int i=1;i<=n;i++){
				d[dg[i]]++;
				mult=(mult*v[dg[i]])%998244353;
			}
			ans=(ans+mult*(cob()))%998244353; 
		}
		return;
	}
	for(int i=last;i<=m;i++){
		dg[pos]=i;
		dfs(pos+1,i);
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++)scanf("%d",v+i);
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
