#include<bits/stdc++.h>
using namespace std;
long long an[100000];
//double am[100000];
int n;
long long calc(long long a[])
{
	long long b=0;
	for(int i=1;i<=n;i++)
	{
		b+=a[i];
	}
//	b=(double)(b/n);
//	printf("%lf ",b);
	long long c=0;
	long long nn=n;
	for(int i=1;i<=n;i++)
	{
		c+=(nn*a[i]-b)*(nn*a[i]-b);
	}
//	printf("%lf ",c);
	return c/nn;
}
long long work()
{
	int mi=-1;
	long long de=100000;
	long long x=calc(an);
	for(int i=2;i<n;i++)
	{
		long long tem=an[i];
		an[i]=an[i-1]+an[i+1]-an[i];
		long long y=calc(an);
		if(y<x)
		{
			if(de>y-x)
			{
				de=y-x;
				mi=i;
			}
		}
		an[i]=tem;
	}
	if(mi==-1)
	{
		return x;
	}
	else
	{
		an[mi]=an[mi-1]+an[mi+1]-an[mi];
		return work();
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&an[i]);
	}
	printf("%lld",work());
	return 0;
}
//打不出dp见祖宗 
