#include<bits/stdc++.h>
using namespace std;
int a[200],b[200],v[200];
int c[200];
int n,m,k;
long long ans=0;
void dfs(int dep){
	if (dep==n){
		int tot=0;
		memcpy(c,a,sizeof(a));
		for (int i=0;i<=m;i++){
		    if (c[i]%2!=0){
		    	tot++;
			}	
			c[i+1]+=c[i]/2;
		}
		int p=m+1;
		while (c[p]!=0){
			tot+=c[p]%2;
			c[p+1]=c[p]/2;
			p++;
		}
		
		if (tot<=k){
			long long s=1;
			for (int i=1;i<=dep;i++){
				s=(s*v[b[i]])%998244353;
			}
			ans=(ans+s)%998244353;
		}
	}
	else{
		for (int i=0;i<=m;i++){
			b[dep+1]=i;a[i]++;
			dfs(dep+1);
			a[i]--;
		}
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);

    scanf("%d%d%d",&n,&m,&k);
    for (int i=0;i<=m;i++)
       scanf("%d",&v[i]);
    ans=0;
    for (int i=0;i<=m;i++){
    	b[1]=i;a[i]++;
    	dfs(1);
    	a[i]=0;
	}
	printf("%lld\n",ans);

	return 0;
}