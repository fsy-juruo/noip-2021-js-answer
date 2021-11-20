#include<bits/stdc++.h>
using namespace std;
const long long modd=998244353;
long long read()
{
	long long x=0,w=1;
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
void write(long long x)
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
long long xx,yy;
void exgcd(long long aa, long long bb)
{
	if(bb==0)
	{
		xx=1;
		yy=0;
		return;
	}
	exgcd(bb,aa%bb);
	long long tt=xx;
	xx=yy;
	yy=tt-aa/bb*yy;
}
long long n,m,k;
long long sum=1;
long long a[110];
long long inv[33];
long long mnt[110];
long long cursum[110][33];
long long ans;
bool judge()
{
	long long cnt=0;
	long long tmp=0;
	for(int i=0;i<=m;i++)
	{
		long long cur=tmp+mnt[i];
		if(cur%2==1)
		{
			cnt++;
			if(cnt>k)
			{
				return false;
			}
		}
		tmp=cur/2;
	}
	while(tmp>0)
	{
		if(tmp%2==1)
		{
			cnt++;
			if(cnt>k)
			{
				return false;
			}
		}
		tmp/=2;
	}
	return true;
}
void dfs(long long p, long long cnt)
{
	if(cnt==n)
	{
		if(judge())
		{
			long long curans=sum;
			for(int i=0;i<p;i++)
			{
				curans=(((curans*inv[mnt[i]])%modd)*cursum[i][mnt[i]])%modd;
			}
			ans=(ans+curans)%modd;
		}
		return;
	}
	if(p>m)
	{
		return;
	}
	for(int i=0;i<=n-cnt;i++)
	{
		mnt[p]=i;
		dfs(p+1,cnt+i);
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=0;i<=m;i++)
	{
		a[i]=read();
	}
	for(int i=0;i<=m;i++)
	{
		cursum[i][0]=1;
		for(int j=1;j<=n;j++)
		{
			cursum[i][j]=(cursum[i][j-1]*a[i])%modd;
		}
	}
	for(int i=1;i<=n;i++)
	{
		sum=sum*i%modd;
	}
	exgcd(sum,modd);
	inv[n]=xx;
	inv[0]=1;
	for(int i=n-1;i>=1;i--)
	{
		inv[i]=(inv[i+1]*(i+1))%modd;
	}
	dfs(0,0);
	write((ans+modd)%modd);
	return 0;
}
