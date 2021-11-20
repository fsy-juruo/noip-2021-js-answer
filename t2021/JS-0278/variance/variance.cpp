#include<bits/stdc++.h>
#define ll long long
#define d double
using namespace std;
d n,a[100010];
int v[100010];
d calc()
{
	d sum=0;
	for (int i=1;i<=n;i++)sum+=a[i];
	d ping=sum/n;
	sum=0;
	for (int i=1;i<=n;i++)sum+=(a[i]-ping)*(a[i]-ping);
	return sum/n;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i];
	d minn=calc();
	for (int i=1;i<=n;i++)
	{
		if (i>=2&&i<=n-1&&a[i-1]+a[i+1]-a[i]!=a[i]&&v[i]==0)
		{
			a[i]=a[i-1]+a[i+1]-a[i];
			v[i]=1;
			i-=2;
			minn=min(minn,calc());
		}
	}
	cout<<fixed<<setprecision(0)<<minn*n*n<<endl;
	return 0;
}
