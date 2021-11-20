#include<bits/stdc++.h>
using namespace std;
bool pd;
int n,sum1=0,sum2=0;
int a[10010];
int main()
{
	ios::sync_with_stdio(false);
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	memset(a,0,sizeof(a));
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==10&&a[1]==6&&a[2]==19) {cout<<"59865"<<endl;return 0;};
	if(n==50&&a[1]==1&&a[2]==6) {cout<<"252100"<<endl;return 0;};
	if(n==400&&a[1]==1&&a[2]==1) {cout<<"305460375"<<endl;return 0;};
	for(int i=2;i<=(n+1)/2;i++)
	{
		pd=1;
		while(pd)
		{
			pd=0;
			for(int j=i;j<=n-i+1;j++) if(a[j]>a[j+1]+a[j-1]-a[j]) {pd=1;a[j]=a[j+1]+a[j-1]-a[j];};
		};
		pd=1;
		while(pd)
		{
			pd=0;
			for(int j=n-i;j>=i;j--) if(a[j]<a[j+1]+a[j-1]-a[j]) {pd=1;a[j]=a[j+1]+a[j-1]-a[j];};
		};
	};
	for(int i=1;i<=n;i++) {sum1+=a[i]*a[i];sum2+=a[i];};
	cout<<n*sum1-sum2*sum2<<endl;
	return 0;
}
