#include<bits/stdc++.h>
#define mod 998244353
#define ll long long
ll n,m,k;
ll a[1010],sum;
int m2(int x)
{
	int sum=1;
	for (int i=1;i<=x;i++)sum*=2;
	return sum;
}
int c1(int x)
{
	int sum=0;
	while (x)
	{
		if (x%2==0)x/=2;
		else
		{
			sum++;
			x-=1;
			x/=2;
		}
	}
	return sum;
}
using namespace std;
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;ll sum=1;
	for (int i=0;i<=m;i++)
	{
		cin>>a[i];sum*=a[i];sum%=mod;
	}
//	if (k==1)
//	{
//		for (int i=5;i<=104;i++)
//		{
//			
//		}
//	}
	/*for (int i=n;i<=n*m2(m);i++)
	{
		if (c1(x)>k)continue;
		else
		{
			
		}
	}*/
	cout<<sum<<endl;
	return 0;
}
