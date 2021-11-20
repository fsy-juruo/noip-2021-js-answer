#include <bits/stdc++.h>
using namespace std;
long long a[10005],sum1,sum2;
int n;
int read1()
{
	char cc=getchar();
	while(!(cc>=48&&cc<=57))
	{
		if(cc=='-')
		{
			break;
		}
		cc=getchar();
	}
	bool f=false;
	int s=0;
	if(cc=='-')
	{
		f=true;
	}
	else
	{
		s=cc-48;
	}
	while(1)
	{
		cc=getchar();
		if(cc>=48&&cc<=57)
		{
			s=s*10+cc-48;
		}
		else
		{
			break;
		}
	}
	if(f==true)
	{
		s=-s;
	}
	return s;
}
double Rand()
{
	return (double)rand()/RAND_MAX;
}
long long w()
{
	return n*sum1-sum2*sum2;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	srand(time(NULL));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a[i]=read1();
	}
	for(int i=1;i<=n;i++)
	{
		sum1=sum1+a[i]*a[i];
		sum2=sum2+a[i];
	}
	if(n==2)
	{
		cout<<w()<<endl;
		return 0;
	}
	long long s=LLONG_MAX;
	for(int i=1;i<=10;i++)
	{
		long long ans=w(),cur=w();
		double T=5000,t=0.9999;
		while(T>1e-6)
		{
			T=T*t;
			int p=rand()%(n-2)+2;
			sum1=sum1-a[p]*a[p];
			sum2=sum2-a[p];
			a[p]=a[p-1]+a[p+1]-a[p];
			sum1=sum1+a[p]*a[p];
			sum2=sum2+a[p];
			long long tmp=w();
			if(tmp<=cur)
			{
				cur=tmp;
			}
			else if(Rand()<=exp((-(tmp-cur))/T))
			{
				cur=tmp;
			}
			else
			{
				sum1=sum1-a[p]*a[p];
		    	sum2=sum2-a[p];
				a[p]=a[p-1]+a[p+1]-a[p];
				sum1=sum1+a[p]*a[p];
		    	sum2=sum2+a[p];
			}
			ans=min(ans,cur);
		}
		s=min(ans,s);
	}
	cout<<s<<endl;
	return 0;
}
//20 points
