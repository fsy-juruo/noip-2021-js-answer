#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int s=0,sig=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') sig=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		s=(s<<3)+(s<<1)+(c^48);
		c=getchar();
	}
	return s*sig;
}
bool p[11000005];
int nxt[11000005];
int t,x;
bool check(int s)
{
	while(s!=0)
	{
		if(s%10==7) return 1;
		s/=10;
	}
	return 0;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	t=read();
	int ls=0;
	const int lim=t<=10000?200100:10000100;
	for(int i=1;i<=lim;i++)
	{
		if(p[i]==1) continue;
		if(i%7==0||check(i))
		{
			p[i]=1;
			for(int j=i;j<=lim;j+=i)
			{
				if(p[j]==0)
				{
					p[j]=1;
				}
			}
			continue;
		}
		if(p[i]==0)
		{
			nxt[ls]=i;
			ls=i;
		}
	}
	while(t--)
	{
		x=read();
		if(p[x]==1)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n",nxt[x]);
		}
	}
	return 0;
}
