#include<bits/stdc++.h>
using namespace std;
inline void file(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
}
int n;
int a[5];
int main(){
	ios::sync_with_stdio(0);
	file();
	cin>>n;
	for(register int i=1;i<=n;i++)cin>>a[i];
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	if(n==2){
		cout<<a[1]*a[1]-a[1]*a[2]*2+a[2]*a[2]<<endl;
		return 0;
	}
	if(n==3){
		int ans1=0,ans2=0;int sum1=0;int sum2=0;
		for(register int i=1;i<=3;i++)sum1+=a[i];
		for(register int i=1;i<=3;i++){
			ans1+=(n*a[i]-sum1)*(n*a[i]-sum1);
		}ans1/=3;
		a[2]=a[1]+a[3]-a[2];
		for(register int i=1;i<=3;i++)sum1+=a[i];
		for(register int i=1;i<=3;i++){
			ans2+=(n*a[i]-sum1)*(n*a[i]-sum1);
		}ans2/=3;
		cout<<min(ans1,ans2)<<endl;
		return 0;
	}
	if(n==4){
		int lhc=5739857;int ans1=0,sum1=0;
		int b[5];
		for(register int i=1;i<=n;i++)b[i]=a[i];
		for(register int i=1;i<=4;i++)sum1+=a[i];
		for(register int i=1;i<=4;i++){
			ans1+=(n*a[i]-sum1)*(n*a[i]-sum1);
		}ans1/=4;
		lhc=min(lhc,ans1);
		a[2]=a[1]+a[3]-a[2];
		ans1=0,sum1=0;
		for(register int i=1;i<=4;i++)sum1+=a[i];
		for(register int i=1;i<=4;i++){
			ans1+=(n*a[i]-sum1)*(n*a[i]-sum1);
		}ans1/=4;
		lhc=min(lhc,ans1);
		for(register int i=1;i<=n;i++)a[i]=b[i];
		a[3]=a[4]+a[2]-a[3];
		ans1=0,sum1=0;
		for(register int i=1;i<=4;i++)sum1+=a[i];
		for(register int i=1;i<=4;i++){
			ans1+=(n*a[i]-sum1)*(n*a[i]-sum1);
		}ans1/=4;
		lhc=min(lhc,ans1);
		for(register int i=1;i<=n;i++)a[i]=b[i];
		a[3]=a[2]+a[4]-a[3];
		a[2]=a[3]+a[1]-a[2];
		ans1=0,sum1=0;
		for(register int i=1;i<=4;i++)sum1+=a[i];
		for(register int i=1;i<=4;i++){
			ans1+=(n*a[i]-sum1)*(n*a[i]-sum1);
		}ans1/=4;
		lhc=min(lhc,ans1);
		for(register int i=1;i<=n;i++)a[i]=b[i];
		a[2]=a[3]+a[1]-a[2];
		a[3]=a[2]+a[4]-a[3];
		ans1=0,sum1=0;
		for(register int i=1;i<=4;i++)sum1+=a[i];
		for(register int i=1;i<=4;i++){
			ans1+=(n*a[i]-sum1)*(n*a[i]-sum1);
		}ans1/=4;
		lhc=min(lhc,ans1);
		for(register int i=1;i<=n;i++)a[i]=b[i];
		cout<<lhc<<endl;
	}
	return 0;
}

