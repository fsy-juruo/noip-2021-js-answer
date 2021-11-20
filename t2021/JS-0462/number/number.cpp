#include<bits/stdc++.h>
using namespace std;
int t,n,cn[11000000],to[11000000];
bool ck(int x)
{
	while(x)
	{
		if(x%10==7)
		{
			return true;
		}
		x/=10;
	}
	return false;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=7;i<=11000000;i++)
	{
		if(cn[i])
		{
			continue;
		}
		if(ck(i))
		{
			for(int j=i;j<=11000000;j+=i)
			{
				cn[j]=1;
			}
		}
	}
	for(int i=11000000;i>=1;i--)
	{
		if(cn[i])
		{
			to[i]=to[i+1];
		}
		else
		{
			to[i]=i;
		}
	}
	cin>>t;
	while(t--)
	{
		scanf("%d",&n);
		if(cn[n]==1)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n",to[n+1]);
		}
	}
	return 0;
}
