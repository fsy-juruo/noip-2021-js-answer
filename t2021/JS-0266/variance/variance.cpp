#include<bits/stdc++.h>
using namespace std;

int n,a[10005];
int s,ans;
inline int var(){
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=(a[i]*n-s)*(a[i]*n-s);
	}
	sum/=n;
	return sum;
}
void dfs(int b){
	s=0;
	for(int i=1;i<=n;i++){
		s+=a[i];
	}
	ans=min(ans,var());
	for(int i=b;i<n;i++){
		int t=a[i-1]+a[i+1]-a[i];
		if(t!=a[i]){
			swap(a[i],t);
			dfs(b+1);
			swap(a[i],t);
		}
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s+=a[i];
	}
	ans=var();
	dfs(2);
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
