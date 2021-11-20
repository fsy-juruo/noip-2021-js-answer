#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define INF 0x3f3f3f3f
#define N 10003
int n,h[N],d[N];
LL ans=0x7fffffffffffffff;
void dfs(int t,int lst){
	if(t>n*n) return;
	LL res2=0,res=0;
	for(int i=1;i<=n;++i)
		res2+=d[i]*d[i],res+=d[i];
	ans=min(ans,res2*n-res*res);
	for(int i=2;i<n;++i){
		if(i==lst) continue;
		int tmp=d[i];
		d[i]=d[i-1]+d[i+1]-d[i];
		dfs(t+1,i);
		d[i]=tmp;
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&h[i]);
		d[i]=h[i];
	}
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}
