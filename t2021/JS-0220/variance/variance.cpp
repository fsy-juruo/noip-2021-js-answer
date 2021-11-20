#include<bits/stdc++.h>
using namespace std;

int read()
{
	int x=0,w=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')
		{
			w=-w;
		}
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*w;
}
void write(int x)
{
	if(x<0)
	{
		x=-x;
		putchar('-');
	}
	if(x>9)
	{
		write(x/10);
	}
	putchar(x%10^48);
}
int n;
int a[100010],t[100010];
int xb;
int ans;
void dfs()
{
	for(int i=2;i<n;i++)
	{
		if(a[i]!=a[i-1]+a[i+1]-a[i] && t[i]!=a[i-1]+a[i+1]-a[i])
		{
			int tb=xb;
			t[i]=a[i];
			a[i]=a[i-1]+a[i+1]-a[i];
			xb=xb-t[i]/n+a[i]/n;
			int cur=0;
			for(int j=1;j<=n;j++)
			{
				cur=cur+(a[j]-xb)*(a[j]-xb);
			}
			cur/=n;
			ans=min(ans,cur);
			dfs();
			a[i]=t[i];
			xb=tb;
		}
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		a[i]=a[i]*n*n;
		t[i]=a[i];
		xb+=a[i];
	}
	xb/=n;
	for(int j=1;j<=n;j++)
	{
		ans=ans+(a[j]-xb)*(a[j]-xb);
	}
	ans/=n;
	dfs();
	write(ans/n/n);
	return 0;
}	
