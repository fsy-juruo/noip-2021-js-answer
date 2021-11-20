#include<bits/stdc++.h>
#define LL long long
using namespace std;
int sum,a[100000],n;
int fc(){
	int s=0;
	for(int i=1;i<=n;i++){
		s+=n*a[i]*a[i]-2*sum*a[i];
	}
	s+=sum*sum;
	return s;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	for(int i=2;i<n;i++){
		a[i]=a[i-1]+a[i+1]-a[i];
		sum+=a[i];
	}
	cout<<fc()<<endl;
return 0;
}

