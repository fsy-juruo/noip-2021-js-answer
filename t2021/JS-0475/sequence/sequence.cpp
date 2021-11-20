#include<bits/stdc++.h>
using namespace std;
int n,m,k,v[150],a[50],mod=998244353;
unsigned long long ans,k1=1;
void dfs(int dep,int l){
	if(dep>n){
		int t=0,i;
		unsigned long long x=0;
		for(i=1;i<=n;i++){
			x+=(1<<a[i]);
		}
		while(x){
			t+=x%2;
			x>>=1;
		}
		if(t<=k){
			
			unsigned long long sum=1,s=1,s2=1,q=1;
			for(i=1;i<=n;i++){
				sum*=v[a[i]];
				sum%=mod;
			}
			for(i=2;i<=n;i++){
				if(a[i]==a[i-1]){
					q++;
				    s2*=q; 
				}else{
					s*=s2;
					q=1;
					s2=1;
				}
			}
			s*=s2;
			sum*=((k1/s)%mod);
			sum%=mod;
			ans+=sum;
			ans%=mod;
			
		}
	}else{
		register int i;
	    for(i=l;i<=m;i++){
		    a[dep]=i;
		    dfs(dep+1,i);
	   }
	}
	
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	int i,j;
	for(i=0;i<=m;i++){
		scanf("%d",&v[i]);
	}
	for(i=1;i<=n;i++){
		k1*=i;
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}
