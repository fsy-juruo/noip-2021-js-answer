#include<bits/stdc++.h>
using namespace std;
template<typename T>
void read(T &x)
{
	x=0;
	int tag=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
			tag=-tag;
		c=getchar();
	}
	while(isdigit(c))
	{
		x*=10;
		x+=c-'0';
		c=getchar();
	}
	x*=tag;
	return;
}
template<typename T>
void write(T x)
{
	T y=0;
	int cnt=0;
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x==0)
	{
		putchar('0');
		return;
	}
	while(x%10==0)
	{
		++cnt;
		x/=10;
	}
	while(x>0)
	{
		y*=10;
		y+=x%10;
		x/=10;
	}
	while(y>0)
	{
		putchar(y%10+'0');
		y/=10;
	}
	while(cnt--)
		putchar('0');
	return;
}
long long lowbit(long long x)
{
	return x&(-x);
}
long long count(long long x)
{
	long long ans=0;
	while(x)
	{
		x-=lowbit(x);
		++ans;
	}
	return ans;
}
long long n,m,k,ans=0;
const long long mod=998244353;
vector<long long> v,a;
void dfs(long long i)
{
	if(i==n)
	{
		long long s=0,t=1;
		for(long long j:a)
		{
			s+=1<<j;
			t*=v[j];
		}
		if(count(s)<=k)
			ans=(t+ans)%mod;
		return;
	}
	for(long long j=0;j<=m;++j)
	{
		a[i]=j;
		dfs(i+1);
	}
	return;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);
	read(m);
	read(k);
	v.resize(m+1);
	a.resize(n);
	for(long long i=0;i<=m;++i)
		read(v[i]);
	dfs(0);
	write(ans);
	putchar('\n');
	return 0;
}

