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
bool chicken(unsigned long long x)
{
	while(x)
	{
		if(x%10==7)
			return true;
		x/=10;
	}
	return false;
}
array<bool,10000001> ds;
array<int,10000001> p;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(unsigned long long i=1;i<ds.size();++i)
	{
		if(ds[i])
			continue;
		if(chicken(i))
			for(unsigned long long j=1;i*j<=ds.size();++j)
				ds[i*j]=true;
	}
	for(unsigned long long t=10000001,i=ds.size()-1;i>0;--i)
	{
		if(ds[i])
			p[i]=-1;
		else
		{
			p[i]=t;
			t=i;
		}
	}
	int T,x;
	read(T);
	while(T--)
	{
		read(x);
		write(p[x]);
		putchar('\n');
	}
	return 0;
}

