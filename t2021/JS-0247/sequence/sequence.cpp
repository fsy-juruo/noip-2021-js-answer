#include<bits/stdc++.h>
using namespace std;
const int SYX=998244353;
int n,m,k;
int v[105],a[105];
int cho[105];
long long ans;
int count(int x){
	int tot=0;
	while(x){
		tot+=(x&1);
		x>>=1;
	}
	return tot;
}
void dfs(int cnt,long long s,long long p){
	if(cnt==n+1){
		if(count(s)>k)return ;
		ans+=p;
		ans%=SYX;
		return ;
	}
	for(int i=0;i<=m;++i){
		cho[cnt]=i;
		long long k=p*v[i];
		k%=SYX;
		dfs(cnt+1,s+(1<<i),k);
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;++i)scanf("%d",&v[i]);
	dfs(1,0,1);
	cout<<ans;
	return 0;
}
