#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
int a[5];
double fc;
int n;
int main(){
	cin>>n;
	if(n==1){
		cout<<0<<endl;
	}
	else if(n==2){
		double xx;
		int sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum+=a[i];
		} 
		for(int i=1;i<=n;i++){
			xx+=(a[i]-sum/n)*(a[i]-sum/n);
		}
		xx*=n;
		cout<<xx<<endl;
	}
	else if(n==3){
		int sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum+=a[i];
		} 
		int mn=0x3f3f3f3f;
		double xx=0;
		for(int i=1;i<=n;i++){
			xx+=(a[i]-sum/n)*(a[i]-sum/n);
		}
		xx*=n;
		if(xx<=mn) mn=xx;
		
		xx=0;
		int t=a[2];
		a[2]=a[3]+a[1]-t;
		for(int i=1;i<=n;i++){
			xx+=(a[i]-sum/n)*(a[i]-sum/n);
		}
		xx*=n;
		if(xx<=mn) mn=xx;
		cout<<mn;
	}
	else if(n==4){
		int sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum+=a[i];
		} 
		int mn=0x3f3f3f3f;
		double xx=0;
		for(int i=1;i<=n;i++){
			xx+=(a[i]-sum/n)*(a[i]-sum/n);
		}
		xx*=n;
		if(xx<=mn) mn=xx;
		
		xx=0;
		a[2]=a[3]+a[1]-a[2];
		for(int i=1;i<=n;i++){
			xx+=(a[i]-sum/n)*(a[i]-sum/n);
		}
		xx*=n;
		if(xx<=mn) mn=xx;
		
		a[3]=a[2]+a[4]-a[3];
		for(int i=1;i<=n;i++){
			xx+=(a[i]-sum/n)*(a[i]-sum/n);
		}
		xx*=n;
		if(xx<=mn) mn=xx;
		
		a[3]=a[2]+a[4]-a[3];
		for(int i=1;i<=n;i++){
			xx+=(a[i]-sum/n)*(a[i]-sum/n);
		}
		xx*=n;
		if(xx<=mn) mn=xx;
		
		a[3]=a[2]+a[4]-a[3];
		for(int i=1;i<=n;i++){
			xx+=(a[i]-sum/n)*(a[i]-sum/n);
		}
		xx*=n;
		if(xx<=mn) mn=xx;
		
		a[3]=a[2]+a[4]-a[3];
		for(int i=1;i<=n;i++){
			xx+=(a[i]-sum/n)*(a[i]-sum/n);
		}
		xx*=n;
		if(xx<=mn) mn=xx;
		
		a[3]=a[2]+a[4]-a[3];
		for(int i=1;i<=n;i++){
			xx+=(a[i]-sum/n)*(a[i]-sum/n);
		}
		xx*=n;
		if(xx<=mn) mn=xx;
		
	}
	return 0;
}
