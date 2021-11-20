#include<bits/stdc++.h>
#define int long long
#define N 10010
using namespace std;
int n,ans=1e18;
int a[N],d[N],c[N],f[N];
pair<int,int> p[N];
void dfs(int x){
	if(x>=n){
		int sum=a[1],sq=a[1]*a[1];
		for(int i=2;i<=n;i++) a[i]=a[i-1]+c[i-1],sum+=a[i],sq+=a[i]*a[i];
		ans=min(ans,n*sq-sum*sum);
		return;
	}
	for(int i=1;i<n;i++){
		if(c[i]==d[x]) break;
		if(c[i]==-1){
			c[i]=d[x];
			dfs(x+1);
			c[i]=-1;
		}
	}
}
signed main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++) d[i]=a[i+1]-a[i];
	sort(d+1,d+n);
	if(n<=15){
		memset(c,-1,sizeof(c));
		dfs(1);
		cout<<ans<<endl;
	}else{
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++) f[i]++,f[j]--;
		for(int i=1;i<n;i++) f[i]+=f[i-1],p[i]=make_pair(f[i],i);
		sort(p+1,p+n);
		for(int i=1;i<n;i++) c[p[i].second]=d[n-i];
		for(int i=1;i<n;i++) a[i]=a[i-1]+c[i-1];
		int sum=a[1],sq=a[1]*a[1];
		for(int i=2;i<=n;i++) a[i]=a[i-1]+c[i-1],sum+=a[i],sq+=a[i]*a[i];
		cout<<n*sq-sum*sum<<endl;
	}
	return 0;
}
