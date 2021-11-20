#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0;
	bool f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			f=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return (f?x:~(x-1));
}
inline void writes(int x)//positive!
{
	if(x<10)
	{
		putchar('0'+x);
		return ;
	}
	writes(x/10);
	putchar(x%10+'0');
}
const int N=1e7+100;
int T,cnt,ok[N+1],ans[N+1];
bool check(int x)
{
	while(x)
	{
		if(x%10==7)
			return 1;
		x/=10;
	}
	return 0;
}
void init()
{
	for(int i=1;i<=N;i++)
	{
		if(ok[i]==0&&check(i))
		{
			ok[i]=-1;
			for(int l=2;l*i<=N;l++)
				ok[i*l]=-1;
		}
		if(ok[i]==0)
		{
			ok[i]=++cnt;
			ans[cnt]=i;
		}
	}
}
void solve()
{
	int x=read();
	if(ok[x]<0)
		puts("-1");
	else
	{
		writes(ans[ok[x]+1]);
		putchar('\n');
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init();
	T=read();
	while(T--)
		solve();
	return 0;
}

