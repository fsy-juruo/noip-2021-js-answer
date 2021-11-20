#include<bits/stdc++.h>
using namespace std;
double n,a[1004],sum,ans,avg,xx,yy,tot;
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	sum+=a[i];
	}
	avg=sum/n;
	for(int i=1;i<=n;i++)
	{
		xx=(avg-a[i])*(avg-a[i]);
		ans+=xx;
	}
    for(int i=2;i<n;i++)
    {
    	tot=0;
    	yy=sum-a[i];
    	a[i]=a[i-1]+a[i+1]-a[i];
    	avg=(yy+a[i])/n;
    	sum=yy+a[i];
    	for(int j=1;j<=n;j++)
		{
			xx=(avg-a[j])*(avg-a[j]);
			tot+=xx;
		}
		ans=min(ans,tot);
	}
	cout<<int(ans*n);
	return 0;
}

