#include<bits/stdc++.h>
using namespace std;
//#define int long long

//bool st;
int mx=-1e9;
bool st[20000010];
int a[10000005];
int cnt=0;
//bool en;

bool bascheck(int x)
{
	if(x%7==0)
		return false;
	int n=x;
	while(n)
	{
		if(n%10==7)
			return false;
		n/=10;
	}
	return true;
}

void init()
{
	for(int i=7;i<=mx<<1;i++)
	{
		if(st[i])
			continue;
		if(!bascheck(i))
		{
			int x=i;
			while(x<=mx<<1)
			{
				st[x]=true;
				x+=i;
			}
		}
	}
}

signed main()
{
	//cout<<(&en-&st)/1024.0/1024.0<<endl;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		int x;
		scanf("%d",&x);
		a[++cnt]=x;
		mx=max(mx,x);
	}
	init();
	for(int i=1;i<=cnt;i++)
	{
		int x=a[i];
		if(st[x])
		{
			printf("-1\n");
			continue;
		}
		x++;
		while(st[x])
			x++;
		printf("%d\n",x);
	}
	return 0;
}
