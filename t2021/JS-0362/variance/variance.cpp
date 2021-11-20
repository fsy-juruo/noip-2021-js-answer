#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,a[1001],ave,s,m,b,aver;
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);	
		ave+=a[i];
		a[i]*=n;
	}
	for(int i=1;i<=n;i++)
		s+=(a[i]-ave)*(a[i]-ave);
	for(int i=2;i<=n-1;i++)
	{
		b=a[i];
		aver=ave+(a[i-1]+a[i+1]-2*a[i])/n;
		a[i]=a[i-1]+a[i+1]-a[i];
		for(int i=1;i<=n;i++)
			m+=(a[i]-aver)*(a[i]-aver);
		if (m<s)
		{
			s=m;
			ave=aver;			
		}
		else
			a[i]=b;
	}	
	for(int i=2;i<=n-1;i++)
	{
		b=a[i];
		aver=ave+(a[i-1]+a[i+1]-2*a[i])/n;
		a[i]=a[i-1]+a[i+1]-a[i];
		for(int i=1;i<=n;i++)
			m+=(a[i]-aver)*(a[i]-aver);
		if (m<s)
		{
			s=m;
			ave=aver;			
		}
		else
			a[i]=b;
	}
	for(int i=2;i<=n-1;i++)
	{
		b=a[i];
		aver=ave+(a[i-1]+a[i+1]-2*a[i])/n;
		a[i]=a[i-1]+a[i+1]-a[i];
		for(int i=1;i<=n;i++)
			m+=(a[i]-aver)*(a[i]-aver);
		if (m<s)
		{
			s=m;
			ave=aver;			
		}
		else
			a[i]=b;
	}
	cout<<s/n<<endl;
	return 0;
}

