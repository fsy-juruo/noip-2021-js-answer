#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int n,a[N],d[N],s[N];
long long ans,b[N];
long long cal()
{
	long long s=0,t=0;
	for(register int i=1;i<n;i++)
		b[i]=b[i-1]+d[i],s+=b[i];
	for(register int i=0;i<n;i++)
		t+=(s-b[i]*n)*(s-b[i]*n);
	return t/n;
}
vector<int>x,y;
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	srand(time(0));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
		d[i]=a[i+1]-a[i];
	sort(d+1,d+n);
	int sx=0,sy=0;
	for(int i=1;i<n;i++)
	{
		if(sx<sy)
		{
			x.push_back(d[i]);
			sx+=d[i];
		}
		else
		{
			y.push_back(d[i]);
			sy+=d[i];
		}
	}
	int z=0;
	for(int i=(int)(y.size())-1;i>=0;i--)
		s[++z]=y[i];
	for(int i=0;i<x.size();i++)
		s[++z]=x[i];
	ans=cal();
	for(int z=0;z<2;z++)
	{
		for(int i=1;i<n;i++)
			d[i]=s[i];
		int t=min(300000,120000000/n);
		long long dans=cal();
		while(t--)
		{
			int x=rand()%(n-1)+1,y=rand()%(n-1)+1;
			if(x==y)
				continue;
			swap(d[x],d[y]);
			long long v=cal();
			if(v<dans)
				dans=v;
			else
				swap(d[x],d[y]);
		}
		ans=min(ans,dans);
	}
	printf("%lld\n",ans);
	return 0;
}

