#include<bits/stdc++.h>
using namespace std;
int n,a[10010],ans,f,sum;
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;f=1;sum=0;ans=0;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];sum+=a[i];
	}
	while(f==1)
	{
		f=0;int k=0;
		for(int i=2;i<n;i++)
		{
			k=a[i+1]+a[i-1]-2*a[i];
			if(2*n*a[i]*k+n*k*k-2*sum*k-k*k<0)
			{
				sum+=k;
				a[i]=a[i-1]+a[i+1]-a[i];
				f=1;
			}
		}
	}
	for(int i=1;i<=n;i++) ans=ans+a[i]*a[i];
	ans=ans*n-sum*sum;
	cout<<ans<<endl;
	return 0;
}
//prevent ph from the square
