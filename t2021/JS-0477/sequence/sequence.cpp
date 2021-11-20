#include<bits/stdc++.h>
#define ll long long
#define md 998244353
using namespace std;
int n,m,k,ans,v[103],a[32],C[32][32];
int count(int x){
	int num=0;
	for(;x;x-=x&-x)num++;
	return num;
}
void dfs(int x,ll nm,int q){
	if(x>n){
		if(count(nm)<=k){
			int cnt=1,t=n,c=1;
			for(int i=2;i<=n;++i){
				if(a[i]!=a[i-1]){
					cnt=(ll)cnt*C[t][c]%md;
					t-=c,c=1;
				}else c++;
			}
			cnt=(ll)cnt*C[t][c]%md;
			ans=(ans+(ll)q*cnt)%md;
		} 
		return;
	}
	for(int i=a[x-1];i<=m;++i){
		a[x]=i;
		dfs(x+1,nm+(1ll<<i),(ll)q*v[i]%md);
	}
}
signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;++i)scanf("%d",&v[i]);
	C[0][0]=1;
	for(int i=1;i<=n;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j)C[i][j]=(C[i-1][j]+C[i-1][j-1])%md;
	}
	dfs(1,0,1);
	printf("%d\n",ans);
	return 0;
}
