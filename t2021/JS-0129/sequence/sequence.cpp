#include<bits/stdc++.h>
using namespace std;
const int N=110,P=998244353;
int n,m,k;
typedef long long LL;
LL ans,sum;
int p;
int stk[N],tt,v[N];
void work(){
	ans=1;
	for(int i=1;i<=tt;i++) ans=ans*v[stk[i]]%P;
	sum=(sum+ans)%P;
}
void dfs(int s){
	if(s==n+1){
		if(__builtin_popcount(p)<=k) work();
	}
	else 
		for(int i=0;i<=m;i++){
			p+=1<<i;
			stk[++tt]=i;
			dfs(s+1);
			p-=1<<i;
			tt--;
		}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++) scanf("%d",&v[i]);
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
