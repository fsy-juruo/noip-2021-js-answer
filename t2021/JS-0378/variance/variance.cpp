#include<bits/stdc++.h>
using namespace std;
int main( )
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int n,a[10007],sum=0,aver,D;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];	
	}
	aver=sum/n;
	for(int i=1;i<=n;i++)
	D+=(a[i]-aver)*(a[i]-aver)/n;
	cout<<D*n*n;
}
