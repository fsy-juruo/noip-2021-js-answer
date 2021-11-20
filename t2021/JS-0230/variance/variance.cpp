#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,a[110],t[110],ans,ave,tt,sum;
void dcl(int step)
{
	tt-=a[step];
	a[step]=a[step-1]+a[step+1]-a[step];
	if(a[step]==t[step]&&a[step-1]==t[step-1]&&a[step+1]==t[step+1])return;
	tt+=a[step];
	ave=tt/n;
	sum=0;
	for(int i=1;i<=n;i++)sum+=pow(ave-a[i],2);
	ans=min(ans,sum/n);
	dcl(5-step);
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]*=n;
		t[i]=a[i];
		tt+=a[i];
	}
	ave=tt/n;
	for(int i=1;i<=n;i++)ans+=pow(ave-a[i],2);
	ans/=n;
	if(n==4)
	{
		if(a[1]+a[3]!=2*a[2])dcl(2);
		else if(a[2]+a[4]!=2*a[3])dcl(3);
	}
	cout<<ans<<"\n";
	return 0;
}
