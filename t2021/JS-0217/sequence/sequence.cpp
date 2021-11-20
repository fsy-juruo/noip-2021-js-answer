#include <bits/stdc++.h>
using namespace std;
const int P=998244353;
int n,m,k;
int v[110];
int f[110];
int fas(int x,int c){
	int sum=1;
	while(c){
		if(c%2)sum*=x;
		x*=x;
		c/=2;
	}
	return sum;
}
long long ans;
void dfs(int dep,int s,long long tem){
	if(dep>n){
		int cnt=0;
		while(s){
			if(s%2)cnt++;
			s/=2;
		}
		if(cnt<=k)
			ans=(ans+tem)%P;
		return ;
	}
	for(int i=0;i<=m;++i)
		dfs(dep+1,s+f[i],(tem*v[i])%P);
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;++i)scanf("%d",&v[i]);
	for(int i=0;i<=m;++i)f[i]=fas(2,i);
	dfs(1,0,1);
	printf("%lld",ans);
	return 0;
}

