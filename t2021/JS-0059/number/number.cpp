#include<bits/stdc++.h>
#define maxx 10000000
using namespace std;
inline int read()
{
	int b=0;char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))
	{
		b*=10;
		b+=c-'0';
		c=getchar();
	}
	return b;
}
bool p[10000005],w[10000005];
int nxt[10000005];
void aaa()
{
	p[7]=1;
	for(int x=1;x<=10000000;++x)
	{
		int q=x/10;
		if(p[q]||p[x-q*10])p[x]=1;
	}

	for(int x=1;x<=10000000;++x)
	{
		if(w[x])continue;
		w[x]=p[x];
		if(!w[x])continue;
		for(int v=2;;++v)
		{
			int u=v*x;
			if(u>maxx)break;
			w[u]=1;
		}
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	aaa();
	int nu=maxx-2;
	for(int x=maxx-3;x>=1;--x)
	{
		nxt[x]=nu;
		if(!w[x])nu=x;
	}
	int n=read();
	for(register int i=1;i<=n;++i)
	{
		int k=read();
		if(w[k]){printf("-1\n");continue;}
		else printf("%d\n",nxt[k]);
	}
	return 0;
}

