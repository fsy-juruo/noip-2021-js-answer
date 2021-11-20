#include<bits/stdc++.h>
using namespace std;
int n,ans,tot;
double ave;
int a[501];
inline int fc(){
	double sum=0;
	for(register int i=1;i<=n;i++)
		sum+=(a[i]*1.0-ave)*(a[i]*1.0-ave);
	return sum*1.0*n;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],tot+=a[i];
	ave=tot*1.0/n;
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	if(n==2){
		cout<<fc()<<endl;
		return 0;
	}
	ans=fc();
	for(register int i=2;i<=n-1;i++){
		tot-=a[i];
		a[i]=a[i-1]+a[i+1]-a[i];
		tot+=a[i],ave=tot*1.0/n;
		ans=min(ans,fc());
	}
	cout<<ans<<endl;
	return 0;
}
