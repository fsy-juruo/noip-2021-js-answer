#include<bits/stdc++.h>
using namespace std;
int t;
int a[200005];
int ans;
bool digit(int k)
{
	int temp=k;
	while(temp)
	{
		if(temp%10==7)
		  return 1;
	    temp/=10;
	}
	return 0;
}
bool solve(int k)
{
	if(digit(k))
	  return 0;
	for(int i=2;i*i<=k;i++)
	{
		if(k%i==0)
		{
			if(digit(i)||digit(k/i))
			  return 0;
		}
	}
	return 1;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=t;i++)
	{
		if(!solve(a[i]))
		{
			printf("-1\n");
			continue;
		}
		int ans=a[i]+1;
		while(!solve(ans))
		    ans++;
		printf("%d\n",ans);
	}
	return 0;
}

