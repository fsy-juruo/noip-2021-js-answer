#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,a[N],sum;
int ans=0x3f3f3f3f;
void dfs(int s){
	double tmp=0,ave=1.0*s/n;
	for(int i=1;i<=n;++i){
		tmp+=((double)a[i]-ave)*((double)a[i]-ave);
	}
	int x=tmp*n;
	if(x>ans) return;
	ans=x;
	for(int i=2;i<n;++i){
		int dlt=a[i-1]+a[i+1]-a[i]-a[i];
		if(!dlt) continue;
		a[i]+=dlt;
		dfs(s+dlt);
		a[i]-=dlt;
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		sum+=a[i];
	}
	dfs(sum);
	cout<<ans<<endl;
	return 0;
}
// T3 written by Skaditxdy
