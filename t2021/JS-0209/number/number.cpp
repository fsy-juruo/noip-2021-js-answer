#include<bits/stdc++.h>
using namespace std;
int T,x;
int sum=0;
int se[1000000];
bool u[1000000];
bool check1(int x)
{
	for(int i=1;i<=sum;i++)
	{
		if(x%se[i]==0)
		{
			return false;
		}
	}
	return true;
}
bool check2(int x)
{
	while(x)
	{
		if(x%10==7)
			return true;
		x/=10;
	}
	return false;
}
bool check(int x)
{
	for(int i=1;se[i]<=x&&i<=sum;i++)
	{
		if(x%se[i]==0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=100010;i++)
	{
		if(check1(i))
		{
			if(check2(i))
			{
				sum++;
				se[sum]=i;
				u[i]=true;
//				printf("%d ",i);
			}
		}
	}
	scanf("%d",&T);
	if(T>100010)
	{
		for(int i=1;i<=T;i++)
		{
			printf("-1\n");
		}
		return 0;
	}
	for(int t=1;t<=T;t++)
	{
		scanf("%d",&x);
		if(!check(x)||u[x]==true)
		{
			printf("-1\n");
			continue;
		}
		int i=x+1;
		while(!check(i)||u[i]==true)
		{
			i++;
		}
		printf("%d\n",i);
	}
	return 0;
}

