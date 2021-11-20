#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	float n;
	cin>>n;
	int a[100000];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	float ping=0,he=0;
	float fh=0;
	float minn=100000000;
	for(int i=0;i<6;i++){
		for(int j=1;j<n-1;j++){
			a[j]=a[j-1]+a[j+1]-a[j];
			he=0;
			for(int l=0;l<n;l++){
				he+=a[l];
			}
			ping=he/n;
			fh=0;
			for(int l=0;l<n;l++){
				fh+=(a[l]-ping)*(a[l]-ping);
			}
			minn=min(minn,fh*n);
		}
	}
	for(int i=0;i<6;i++){
		for(int j=n-1;j>0;j--){
			a[j]=a[j-1]+a[j+1]-a[j];
			he=0;
			for(int l=0;l<n;l++){
				he+=a[l];
			}
			ping=he/n;
			fh=0;
			for(int l=0;l<n;l++){
				fh+=(a[l]-ping)*(a[l]-ping);
			}
			minn=min(minn,fh*n);
		}
	}
	cout<<minn;
}
