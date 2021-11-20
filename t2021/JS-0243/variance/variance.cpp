#include<bits/stdc++.h>
using namespace std;
int a[1000001],n,summ,sum,fc,Min,Minn,c[1000001],s[1000001],f;
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		summ+=a[i]*a[i];
		sum+=a[i];
	}
	fc=summ*n-sum*sum;
	for(int i=1;i;i++)
	{
		Min=fc;
		//cout<<i<<endl;
		for(int j=2;j<n;j++)
		{
			c[j]=summ;
			s[j]=sum;
			c[j]=c[j]-a[j]*a[j]+(a[j+1]+a[j-1]-a[j])*(a[j+1]+a[j-1]-a[j]);
			s[j]=s[j]-a[j]+a[j+1]+a[j-1]-a[j];
			f=c[j]*n-s[j]*s[j];
		//	cout<<j<<' '<<f<<endl;
		    if(f<Min)
		    {
		    	Min=f;
		    	Minn=j;
			}
		}
		if(fc==Min)
		{
			break;
		}
		a[Minn]=a[Minn+1]+a[Minn-1]-a[Minn];
		summ=c[Minn];
		sum=s[Minn];
		fc=Min;
		//cout<<Minn<<' '<<Min<<endl;
	}
	cout<<fc<<endl;
	return 0;
}

