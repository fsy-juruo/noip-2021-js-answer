#include<bits/stdc++.h>
using namespace std;
//const int N=
//int a[N],head[N],to[M],nxt[M];
bool c[10000005];
int read()
{
	int f=1,x=0;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int seven(int x)
{
	int cn=-1,ans=-1;
	while(x)
	{
		cn++;
		if(x%10==7) ans=cn;
		x/=10;
	}
	if(ans!=-1) c[x]=true;
	return ans;
}
bool check(int x)
{
	for(int i=2; i<=sqrt(x); i++)
	{
		if(x%i==0)
		{
			if(seven(i)!=-1||seven(x/i)!=-1)
			{
				return c[x]=true;
			}
//			x/=i;
		}
	}
	return false;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n=read();
//	puts("ccf");
	if(n<=1000)
	while(n--)
	{
		int x=read();
		if(seven(x)!=-1)
		{
			puts("-1");
			continue;
		}
		if(c[x])
		{
			puts("-1");
			continue;
		}
		if(check(x))
		{
			puts("-1");
			continue;
		}
		while(true)
		{
			x++;
			if(seven(x)!=-1) x+=pow(10,seven(x));
			if(c[x]) continue;
			if(!check(x))
			{
				printf("%d\n",x);
				break;
			}
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		puts("-1");
	}
	return 0;
}

