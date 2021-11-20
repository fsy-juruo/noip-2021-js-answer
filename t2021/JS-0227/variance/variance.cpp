#include<bits/stdc++.h>
using namespace std;
bool v[1234321];
long long a[10005];
int n;
long double exp(){
	long double s=0,ans=0;
	for(int i=0;i<n;i++)
		s+=a[i];
	s/=n;
	for(int i=0;i<n;i++)
		ans+=pow(a[i]-s,2);
	return ans;
}
long double dfs(){
	int mark=a[0]*11*11*11*11+a[1]*11*11*11+a[2]*11*11+a[3]*11+a[4];
	long double mn=10000000000000;
	if(v[mark])
		return mn;
	v[mark]=1;
	for(int i=1;i<n-1;i++){
		int mem1=a[i];
		a[i]=a[i-1]+a[i+1]-a[i];
		mn=min(dfs(),mn);
		a[i]=mem1;		
	}
	return min(mn,exp());
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<setprecision(0)<<fixed<<dfs()*n;
	return 0;
}	                                                                            

