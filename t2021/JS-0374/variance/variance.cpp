#include<bits/stdc++.h>
using namespace std;
double a[10005];
int answ=9999999;
double aver(int n)
{
	double x=0;
	for(int i=1;i<=n;i++)
	x+=a[i];
	return x/n;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int n,b=0,pre=0;
	double max=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	bool flag;
	while(flag==0)
	{
		max=0;
		for(int i=2;i<=n-1;i++)
		{
			double ad=a[i-1]+a[i+1]-a[i];
			if(ad!=a[i]&&i!=pre&&abs(ad-aver(n))>max)
			{
				max=ad;
				b=i;
			}
		}
		if(max==0)
		flag=1;
		if(max!=0)
		{
			a[b]=max;
			pre=b;
			double w=0;
			for(int i=1;i<=n;i++)
				w+=(a[i]-aver(n))*(a[i]-aver(n));
			int sh=w*n;
			if(sh<answ)
			answ=sh;
			else if(sh==answ)
			break;
		}
	}
	cout<<answ;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
