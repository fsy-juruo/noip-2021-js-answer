#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[10003];
int var(){
	long double aver=0,ans=0;
	for (int i=0;i<n;++i)
		aver+=1.0*a[i]/n;
	for (int i=0;i<n;++i)	
		ans+=(a[i]-aver)*(a[i]-aver);
	return round(ans*n);
}
int main(){
	ios::sync_with_stdio(0);
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int i,j,ans=1000000;cin>>n;
	for (i=0;i<n;++i)cin>>a[i];
	for (int loop=0;loop<n-1;++loop)
	for (i=1;i<n-1;++i){
		ans=min(ans,var());
		a[i]=a[i-1]+a[i+1]-a[i];
	}
	cout<<min(ans,var());
	return 0;
}
