#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
int inline read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,k,ans,a[110],sum[110]; 
priority_queue<int> q;
int c(int M,int N)
{
	N=min(N,M-N);
	int t=1;
	for(int i=0;i<N;i++)t*=M-i;
	for(int i=1;i<=N;i++)t/=i;
	return t;
}
int check(int zrq)
{
	int ww=zrq,dy=0;
	while(ww!=0)
	{
		dy+=ww%2;
		ww/=2;
	}
	return dy;
}
void dfs(int step,int ww,int now,int ng)
{
	if(ng*(n+1-step)<ww-now)return;
	if(ww<now)return;
	if(step==n+1)
	{
		if(ww!=now)return;
		int t=n,an=1,su=1;
		for(int i=0;i<=m;i++)
		{
			su*=c(t,sum[i]);
			t-=sum[i];
			an*=pow(a[i],sum[i]);
		}
		ans+=an*su;
		return ;
	}
	for(int i=ng;i>=0;i--)
	{
		sum[i]++;
		dfs(step+1,ww,now+i,i);
		sum[i]--;
	}
}
void consider(int zrq)
{
	dfs(1,zrq,0,m);
}
void change(int zrq)
{
	while(zrq!=0)
	{
		for(int i=30;i>=0;i--)
		{
			if(pow(2,i)<=zrq)
			{
				consider(i);
				zrq-=pow(2,i);
				break;
			}
		}
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=0;i<=m;i++)a[i]=read();
	int wnn=n,ltl=n*pow(2,m);
	for(int dcl=wnn;dcl<=ltl;dcl++)
	{
		if(check(dcl)<=k)
		{
			change(dcl);
		}
	}
	cout<<ans<<"\n";
	return 0;
}
