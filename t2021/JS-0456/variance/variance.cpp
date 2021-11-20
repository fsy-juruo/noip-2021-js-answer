#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[10005];
bool k;
double t,ans=99999.99;
bool work(ll x)
{
	ll t1=a[x-1]+a[x+1]-a[x];
	if((t-t1)*(t-t1)<(t-a[x])*(t-a[x]))
	{
		return 1;
	}
	return 0;
}
double aksb()
{
	double sum=0;
	for(ll i=1;i<=n;i++)
	{
		sum+=a[i];
	}
	sum=sum/n;
	return sum;
}
double ase()
{
	double kk=aksb();
	double sum=0;
	for(ll i=1;i<=n;i++)
	{
		sum+=(kk-a[i])*(kk-a[i]);
	}
	return sum/=n;
}
void dfs()
{
	double ks=ase();
	ans=min(ans,ks);
	for(ll i=2;i<n;i++)
	{
		if(work(i))
		{
			a[i]=a[i-1]+a[i+1]-a[i];
			dfs();
			a[i]=a[i-1]+a[i+1]-a[i];
		}
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	t=(a[1]+a[n])/2;
	for(ll i=2;i<n;i++)
	{
		if(work(i))
		{
			a[i]=a[i-1]+a[i+1]-a[i];
			dfs();
			a[i]=a[i-1]+a[i+1]-a[i];
		}
	}
	ll answer=ans*n*n;
	cout<<answer;
	return 0;
}
/*
4
1 2 4 6
*/
