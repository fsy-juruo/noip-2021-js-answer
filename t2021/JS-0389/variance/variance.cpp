#include<bits/stdc++.h>
using namespace std;
int n;	
double ans=0,tot=0;
double mid;
double a[10000010];
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool flag=0;
	mid=(a[1]+a[n])/2;
	while(flag==0){
		flag=1;
		for(int i=2;i<=n-1;i++){
			if(abs(a[i-1]+a[i+1]-a[i]-mid)<abs(a[i]-mid)){
				a[i]=a[i-1]+a[i+1]-a[i];
				flag=0;
			}
		}	
	}
	for(int i=1;i<=n;i++){
		tot=tot+a[i];
	}
	mid=tot/n;
	for(int i=1;i<=n;i++){
		ans=(a[i]-mid)*(a[i]-mid)+ans;
	}
	cout<<ans*n<<endl;
	return 0;
}
