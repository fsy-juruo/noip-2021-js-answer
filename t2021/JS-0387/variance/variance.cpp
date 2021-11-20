#include<bits/stdc++.h>
using namespace std;
int n;
int a[10];
double v,sum[4][4],ans=10000;
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n==4){
		v=(a[1]+a[2]+a[3]+a[4])/4;
		sum[1][1]=((a[1]-v)*(a[1]-v)+(a[2]-v)*(a[2]-v)+(a[3]-v)*(a[3]-v)+(a[4]-v)*(a[4]-v))/n;
		a[2]=a[1]+a[3]-a[2];
		v=(a[1]+a[2]+a[3]+a[4])/4;
		sum[1][2]=((a[1]-v)*(a[1]-v)+(a[2]-v)*(a[2]-v)+(a[3]-v)*(a[3]-v)+(a[4]-v)*(a[4]-v))/n;
		a[3]=a[2]+a[4]-a[3];
		v=(a[1]+a[2]+a[3]+a[4])/4;
		sum[1][3]=((a[1]-v)*(a[1]-v)+(a[2]-v)*(a[2]-v)+(a[3]-v)*(a[3]-v)+(a[4]-v)*(a[4]-v))/n;
		for(int i=1;i<=3;i++)
			ans=min(ans,sum[1][i]);
	}
	if(n==3){
		v=(a[1]+a[2]+a[3])/3;
		sum[2][1]=((a[1]-v)*(a[1]-v)+(a[2]-v)*(a[2]-v)+(a[3]-v)*(a[3]-v))/n;
		a[2]=a[1]+a[3]-a[2];
		v=(a[1]+a[2]+a[3])/3;
		sum[2][2]=((a[1]-v)*(a[1]-v)+(a[2]-v)*(a[2]-v)+(a[3]-v)*(a[3]-v))/n;
		for(int i=1;i<=2;i++)
			ans=min(ans,sum[2][i]);
	}
	if(n==2){
		v=(a[1]+a[2])/2;
		ans=((a[1]-v)*(a[1]-v)+(a[2]-v)*(a[2]-v))/n;
	}
	ans=ans*n*n;
	cout<<ans;
	return 0;
}
