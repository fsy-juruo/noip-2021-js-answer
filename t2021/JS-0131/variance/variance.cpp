#include<bits/stdc++.h>
using namespace std;

#define _N 401

int n;
double a[_N];
double f[_N][_N][_N];

double ans=0;
double b[_N];

signed main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	double t=(a[1]+a[n])/2;
	for(int i=2;i<=n-1;i++)
	{
		int cnt=0;
		for(int l=1;l<=n-2;l++)
		{
			for(int r=3;r<=n;r++)
			{
				f[i][l][r]=a[l]+a[r]-a[l+r-i];
			}
		}
	}
	for(int i=2;i<n;i++)
	{
		double res=0x3f3f3f3f;
		double p=0;
		for(int l=1;l<=n-2;l++)
		{
			for(int r=3;r<=n;r++)
			{
				int j=l+r-i;
				if((f[i][l][r]-t)*(f[i][l][r]-t)+(f[j][l][r]-t)*(f[j][l][r]-t)<res)
				{
					res=(f[i][l][r]-t)*(f[i][l][r]-t)+(f[j][l][r]-t)*(f[j][l][r]-t);
					p=f[i][l][r];
				}			
			}
		}
		b[i]=p;
	}
	for(int i=2;i<n;i++)
	{
		ans+=(b[i]-t)*(b[i]-t);
	}
	ans+=(a[1]-t)*(a[1]-t);
	ans+=(a[n]-t)*(a[n]-t);
	cout<<ans*n<<endl;
	return 0;
}
