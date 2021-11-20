#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e7+10;
int a[maxn];

int isseven(int x)
{
	while (x>0)
	{
		int t;
		t=x%10;
		if(t==7)
		{
			return 1;
		}
		x/=10;
	}
	return 0;
}

int pd(int x)
{
	for(int i=1;a[i]<=x;i++)
	{
		if(x%a[i]==0)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int op=1;
	for(int i=1;i<=1e7;i++)
	{
		if(isseven(i)==1)
		{
			a[op]=i;
			op++;
		}
	}
	int T;
	cin>>T;
	while (T--)
	{
		int n;
		cin>>n;
		if(pd(n)==1)
		{
			puts("-1");
			continue;
		}
		for(int i=n+1;;i++)
		{
			if(pd(i)==0)
			{
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}

