#include<bits/stdc++.h>
using namespace std;
const int N = 2e7+5;
int tr[N];
inline bool check(int x)
{
	while(x)
	{
		if(x%10==7) return 1;
		x/=10;
	}
	return 0;
}
int T,n;
inline int read()
{
	char ch=getchar();
	int a=0;
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch))
	{
		a=a*10+(ch^48);
		ch=getchar();
	}
	return a;
}
inline void write(int x)
{
	if(x>9) write(x/10);
	putchar(x%10+48);
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=10000050;++i)
	{
		if(!tr[i]&&check(i))
		{
			for(int j=i;j<=10000050;j+=i)
			  tr[j]=1;
		}
	}
	for(int i=1;i<=10000050;++i) tr[i]+=tr[i-1];
	T=read();
	while(T--)
	{
		n=read();
		if(tr[n]-tr[n-1])
		{
			puts("-1");
			continue;
		}
		int pos=n+1,len=1;
		while(len)
		{
			int now=tr[pos+len-1]-tr[n];
			if(now==pos+len-1-n)
			{
				pos+=len;
				len*=2;
			}
			else
			{
				len/=2;
			}
		}
		write(pos),putchar('\n');
	}
}
