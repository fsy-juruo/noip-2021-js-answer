#include<bits/stdc++.h>
using namespace std;
double b[10001];
double fc(double a[],double k){
	double sum=0;
	for(int i=1;i<=k;i++){
		sum+=a[i];
	}
	sum=sum/k;
	double q=sum;
	sum=0;
	for(int i=1;i<=k;i++)
		sum+=abs(a[i]-q)*abs(a[i]-q);
	return sum/k;
}
int main(){

	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int n;
	cin>>n;
	long long dep=100*100;
	for(int i=1;i<=n;i++)cin>>b[i];
	double minn=fc(b,n);
	bool flag=true;
	while(flag&&dep){
		flag=false;
		for(int i=2;i<n;i++){
			if(b[i]!=b[i-1]+b[i+1]-b[i]){
				b[i]=b[i-1]+b[i+1]-b[i];
				minn=min(minn,fc(b,n));
				dep--;
				flag=true;
			}
		}
	}
	cout<<minn*n*n;
	return 0;
}
