#include <bits/stdc++.h>
using namespace std;
int ans,x,T,mx;
bool tg[10200007];
int nxt[10200007];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>T;
	if(T<=10000)
	mx=300005;
	else
	mx=10100000;
	for(int i=1;i<=mx;i++)
	{
		x=i;
		if(tg[x])continue;
		while(x)
		{
			if(x%10==7)
			{
				for(int j=i;j<=mx;j+=i)
				tg[j]|=1;
				break;
			}
			x/=10;
		}
	}
	nxt[mx+1]=-1;
	for(int i=mx+1;i>=0;i--)
	{
		nxt[i]=nxt[i+1];
		if(!tg[i+1])
		nxt[i]=i+1;
	}
	while(T--)
	{
		scanf("%d",&x);
		if(tg[x]==1)
		printf("-1\n");
		else
		printf("%d\n",nxt[x]);
	}
	return 0;
}
