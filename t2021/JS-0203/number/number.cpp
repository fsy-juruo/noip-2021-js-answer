#include<bits/stdc++.h>
using namespace std;
template<typename T> void read(T &x)
{
	long long f=1;x=0;char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		x=(x<<1)+(x<<3)+c-48;
		c=getchar();
	}
	x*=f;
}
template<typename T> void write(T x)
{
	if(x<0)
	{
		putchar('-');x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+48);
}
template<typename T> void writek(T x)
{
	write(x);putchar(' ');
}
template<typename T> void writeln(T x)
{
	write(x);putchar('\n');
}
const int maxn=10000010;
bool chicken[maxn+10];
int T,x,g[2000010],n;
bool fj(int ji)
{
	int seven,f=0;
	while(ji>0)
	{
		seven=ji%10;ji=ji/10;
		if(seven==7) f=1;
	}
	return f;
}
int ck(int x)
{
	int l=1,r=n,mid=0;
	while(l<r)
	{
		mid=(l+r)/2;
		if(g[mid]<x) l=mid+1;else r=mid;
	}
	return l;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(chicken,0,sizeof(chicken));n=0;
	for(int i=1;i<=maxn;i++)
	{
		if(chicken[i]) continue;
		if(fj(i))
		{
			for(int j=1;j<=maxn/i;j++) chicken[i*j]=1;
		}
	}
	for(int i=1;i<=maxn;i++)
	{
		if(!chicken[i])
		{
			n++;g[n]=i;
		}
	}
	read(T);
	while(T--)
	{
		read(x);
		if(chicken[x])
		{
			writeln(-1);continue;
		}
		writeln(g[ck(x)+1]);
	}
	return 0;
}
//¼´¼Ç¡¶¼¾¼§»÷¼¦¼Ç¡· 
