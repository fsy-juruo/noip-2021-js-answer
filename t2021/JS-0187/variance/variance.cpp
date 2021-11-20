#include<bits/stdc++.h>
using namespace std;
int a[10010];
int main(){
	int n;
	double avenum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		avenum+=a[i];
	}
	avenum/=n;
	for(int i=2;i<n;i++){
		if(abs(avenum+(double)(a[i-1]+a[i+1]-a[i]-a[i])/n-(a[i-1]+a[i+1]-a[i]))<abs(avenum-a[i])){
			avenum+=(double)(a[i-1]+a[i+1]-a[i]-a[i])/n;
			a[i]=a[i-1]+a[i+1]-a[i];
		}
	}
	double ans=0;
	for(int i=1;i<=n;i++){
		ans+=pow(a[i]-avenum,2);
	}
	ans*=n;
	printf("%d",int(ans));
	return 0;
}
