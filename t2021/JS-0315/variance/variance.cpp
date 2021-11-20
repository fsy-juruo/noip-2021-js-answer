#include<bits/stdc++.h>
using namespace std;
int n;
int a[10002],f[10002];
int qiu(){
	int fc=0,s=0;
	for(int i=1;i<=n;i++){
		s+=a[i];
	}
	for(int i=1;i<=n;i++){
		fc+=n*a[i]*a[i]-2*a[i]*s+s*s/n;
	}
	return fc;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	f[1]=qiu();
	for(int i=2;i<n;i++){
		a[i]=a[i-1]+a[i+1]-a[i];
		if(qiu()<f[i-1]) f[i]=qiu();
		else {
			f[i]=f[i-1];
			a[i]=a[i-1]+a[i+1]-a[i];
		}
	}
	cout<<f[n-1];
	return 0;
}
