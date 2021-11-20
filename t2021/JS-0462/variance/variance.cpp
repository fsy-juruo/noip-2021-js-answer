#include<bits/stdc++.h>
using namespace std;
long long n,a[10101];
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	srand(time(NULL));
	cin>>n;
	long long sm=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sm+=a[i];
	}
	for(double t=10000.0;t>=1.0;t*=0.9996)
	{
		for(int i=2;i<n;i++)
		{
			int x=a[i-1]+a[i+1]-a[i],y=a[i]-x;
			double r=rand()*rand()%10000;
			if(((sm-y)*(sm-y)-sm*sm>n*x*x-n*a[i]*a[i]) || r<=t)
			{
				a[i]=x;
				sm-=y;
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=a[i]*a[i]*n;
	}
	ans-=sm*sm;
	cout<<ans<<endl;
	return 0;
}
