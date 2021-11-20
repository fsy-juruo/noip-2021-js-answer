#include<bits/stdc++.h>

#define N 10000000

using namespace std;

int prim[665000],cnt;
int p[N+5];
bool f[N+5];
bool g[N+5];
int nxt[200005];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	int T;
	scanf("%d",&T);
	int ans=0;
	for(int i=2;i<=N+2;++i)
	{
		if(!p[i]) p[i]=i,prim[++cnt]=i;
		for(int j=1;j<=cnt;++j)
		{
			if(prim[j]>p[i]||prim[j]>(N+2)/i) break;
			p[prim[j]*i]=prim[j];
		}
	}
	
	f[1]=0;
	if(T<=10000)
	{
		for(int i=2;i<=200000+2;++i)
		{
			int x=i;
			while(x!=1)
			{
				f[i]|=f[i/p[x]];
				x/=p[x];
			}
			g[i]=g[i/10]|(i%10==7);
			f[i]|=g[i];
		}
		for(int i=20000+2;i>=1;--i)
		{
			if(!f[i]) nxt[i]=i;
			else nxt[i]=nxt[i+1];
		}
		while(T--)
		{
			int x;
			scanf("%d",&x);
			if(f[x]) printf("-1\n");
			else printf("%d\n",nxt[x+1]);
		}
	}
	else
	{	
		/*
		for(int i=2;i<=(N+2);++i)
		{
			int x=i;
			while(x!=1)
			{
				f[i]|=f[i/p[x]];
				x/=p[x];
			}	
			g[i]=g[i/10]|(i%10==7);
			f[i]|=g[i];
		}
		*/
	}
	return 0;
}
