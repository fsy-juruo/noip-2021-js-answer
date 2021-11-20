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
vector<unsigned long long> a;
unsigned long long n,ans=ULLONG_MAX;
set<vector<unsigned long long>> vis;
void dfs(unsigned long long sqrsum,unsigned long long sum)
{
	if(vis.find(a)!=vis.end())
		return;
	vis.insert(a);
	ans=min(ans,n*sqrsum-sum*sum);
	for(unsigned long long ss,s,t,r,i=1;i<n-1;++i)
	{
		t=a[i-1]+a[i+1]-a[i];
		ss=sqrsum-a[i]*a[i]+t*t;
		s=sum-a[i]+t;
		r=a[i];
		a[i]=t;
		dfs(ss,s);
		a[i]=r;
	}
	return;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	read(n);
	a.resize(n);
	unsigned long long sqrsum=0,sum=0;
	for(unsigned long long i=0;i<n;++i)
	{
		read(a[i]);
		sum+=a[i];
		sqrsum+=a[i]*a[i];
	}
	dfs(sqrsum,sum);
	write(ans);
	putchar('\n');
	return 0;
}

