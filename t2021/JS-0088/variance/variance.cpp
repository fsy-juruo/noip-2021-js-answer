#include <bits/stdc++.h>
using namespace std;
long long n,a[100005],sum,ans;
vector <int> v[10005];
void dfs(void ){
	for(int i=2;i<n;i++){
		int y=a[i-1]+a[i+1]-a[i];
		int t=a[i];a[i]=y;
		bool p=1;
		for(int j=0;j<v[1].size();j++){
			bool k=1;
			for(int w=1;w<=n;w++)
			if(v[w][j]!=a[w]){
				k=0;break;
			}
			if(k){
				p=0;break;
			}
		}
		if(p){
			long long f=0;
			sum=sum-t+y;
			for(int j=1;j<=n;j++)
			f=f+(n*a[j]-sum)*(n*a[j]-sum);
			ans=min(ans,f/n);
			for(int j=1;j<=n;j++)
			v[j].push_back(a[j]);
			dfs();
		}
		a[i]=t;
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
		v[i].push_back(a[i]);
	}
	long long f=0;
	for(int i=1;i<=n;i++)
	f=f+(n*a[i]-sum)*(n*a[i]-sum);
	ans=f/n;
	dfs();
	printf("%d",ans);
	return 0;
}
