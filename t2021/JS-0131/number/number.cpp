#include<bits/stdc++.h>
using namespace std;

#define _N 200001
#define _X 50000001
int t;
int prime[_X];
bool vis[_X];
int cnt;

void xxs()
{
	vis[1]=1;
	for(int i=2;i<=_X;i++)
	{
		if(!vis[i])
		{
			prime[++cnt]=i;
		}
		for(int j=1;j<=cnt;j++)
		{
			if(prime[j]*i>_X) break;
			vis[prime[j]*i]=1;
			if(i%prime[j]==0) break;
		}
	}	
}

int p[30],c[30];
int q;

bool check(int x)
{
	while(x)
	{
		int y=x%10;
		if(y==7)
		{
			return 1;
		}
		x/=10;
	}
	return 0;
}


bool chec(int s,int k)
{
	if(check(s))
	{
		return 1;
	}
	if(k==q+1)
	{
		return 0;
	}
	if(chec(s*p[k],k+1)) return 1;
	if(chec(s,k+1)) return 1;
	return 0;
}

bool solve(int x)
{
	q=0;
	memset(p,0,sizeof(p));
	memset(c,0,sizeof(c));
	if(check(x)) 
	{
		return 1;
	}
	for(int i=1;i<=cnt;i++)
	{
		while(x%prime[i]==0)
		{
			p[++q]=prime[i];
			x/=prime[i];
		}
	}
	if(chec(1,1))
	{
		return 1;
	}
	return 0;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	xxs();
	while(t--)
	{
		int x;
		scanf("%d",&x);
		if(solve(x))
		{
			puts("-1");
			continue;
		}
		x++;
		while(solve(x))
		{
			x++;
		}
		printf("%d\n",x);
	}

	return 0;
}
