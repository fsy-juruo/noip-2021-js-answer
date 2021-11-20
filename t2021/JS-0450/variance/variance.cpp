#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],s=0,s1=0,ans=36000000;
int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],s+=a[i],s1+=a[i]*a[i];
	for(int i=1;i<=n*10;i++)
		for(int j=1;j<=n-2;j++) {
			if(n*a[j+1]<s) {
				//cout<<j+1<<" "<<a[j+2]<<endl; 
				s-=a[j+1];s1-=a[j+1]*a[j+1];
				a[j+1]=max(a[j+1],a[j]+a[j+2]-a[j+1]);
				s+=a[j+1];s1+=a[j+1]*a[j+1];
			}
			else {
				s-=a[j+1];s1-=a[j+1]*a[j+1];
				a[j+1]=min(a[j+1],a[j]+a[j+2]-a[j+1]);
				s+=a[j+1];s1+=a[j+1]*a[j+1];
			}
			ans=min(ans,s1*n-s*s);//cout<<j+1<<" "<<a[j+1]<<endl;
		}
	//for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	//cout<<endl; 
	cout<<ans<<endl;
}
/*
syk yyds!
syk txdy!
*/
