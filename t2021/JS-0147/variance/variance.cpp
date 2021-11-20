#include <bits/stdc++.h>
using namespace std;
unsigned long long ans,sgm,sgms;
int n,a[10005];
int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i]; sgm+=a[i]; sgms+=a[i]*a[i];
	}
	if(n==1) {
		cout<<0<<endl;
		return 0;
	}
	if(n==2) {
		cout<<(2*(a[1]*a[1]+a[2]*a[2])-(a[1]+a[2])*(a[1]+a[2]))<<endl;
		return 0;
	}
	if(n==3) {
		cout<<(3*(a[1]*a[1]+a[2]*a[2]+a[3]*a[3])-(a[1]+a[2]+a[3])*(a[1]+a[2]+a[3]))<<endl;
		return 0;
	}
	if(n==4) {
		ans=n*sgms-sgm*sgm;
		int mdf=0;
		int l=200;
		while(l) {
			//cerr<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<" "<<endl;
			//cerr<<sgms<<" "<<sgm<<" "<<"ANS="<<n*sgms-sgm*sgm<<endl;
			//sgms+=-2*a[2+mdf]*a[2+mdf]+a[1+mdf]*a[1+mdf]+a[3+mdf]*a[3+mdf];
			sgms+=-a[2+mdf]*a[2+mdf]+pow(a[1+mdf]+a[3+mdf]-a[2+mdf],2);
			sgm+=-2*a[2+mdf]+a[1+mdf]+a[3+mdf];
			ans=min(ans,n*sgms-sgm*sgm);
			a[2+mdf]=a[1+mdf]+a[3+mdf]-a[2+mdf];
			mdf^=1;
			//system("pause");
			l--;
		}
		cout<<ans<<endl;
		return 0;
	}
	ans=n*sgms-sgm*sgm;
	int mdf=0;
	int l=500;
	while(l) {
		//cerr<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<" "<<endl;
		//cerr<<sgms<<" "<<sgm<<" "<<"ANS="<<n*sgms-sgm*sgm<<endl;
		//sgms+=-2*a[2+mdf]*a[2+mdf]+a[1+mdf]*a[1+mdf]+a[3+mdf]*a[3+mdf];
		sgms+=-a[2+mdf]*a[2+mdf]+pow(a[1+mdf]+a[3+mdf]-a[2+mdf],2);
		sgm+=-2*a[2+mdf]+a[1+mdf]+a[3+mdf];
		ans=min(ans,n*sgms-sgm*sgm);
		a[2+mdf]=a[1+mdf]+a[3+mdf]-a[2+mdf];
		mdf++; mdf%=n-1;
		//system("pause");
		l--;
	}
	cout<<ans<<endl;
	return 0;
}
