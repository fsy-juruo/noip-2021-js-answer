#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;

int n,m,q;
bool flag;

inline int read()
{
	int date=0,w=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') w=-1;c=getchar();}
	while(c>='0'&&c<='9'){date=date*10+c-'0';c=getchar();}
	return date*w;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}

bool check(int x)
{
	while(x)
	{
		if(x-(x/10*10)==7)
		{
			return true;
		}
		x/=10;
	}
	return false;
}

bool find(int x)
{
	for(int i=2;i<=sqrt(x)+1;i++)
	{
		if(x-(x/i*i)==0)
		{
			if(check(i)||(check(x/i))) return false;
		}
	}
	return true;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	int T=read();
	while(T--)
	{
		int x=read();
		if(check(x))
		{
			write(-1);
			puts("");
			continue;
		}
		if(!find(x))
		{
			write(-1);
			puts("");
			continue;
		}
		else
		{
			for(int i=1;i<=20;i++)
			{
				int t=x+i;
				if(t>=70&&t/10-t/100*10==7)
				{
					x+=1e1;
				}
				else if(t>=700&&t/100-t/1000*10==7)
				{
					x+=1e2;
				}
				else if(t>=7000&&t/1000-t/10000*10==7)
				{
					x+=1e3;
				}
				else if(t>=70000&&t/10000-t/100000*10==7)
				{
					x+=1e4;
				}
				else if(t>=700000&&t/100000-t/1000000*10==7)
				{
					x+=1e5;
				}
				else if(t>=7000000&&t/1000000-t/100000000*10==7)
				{
					x+=1e6;
				}
				if(check(x+i)) continue;
				if(find(x+i))
				{
					write(x+i);
					puts("");
					break;
				}
			}
		}
	}
	return 0;
}
/*
5
90
99
106
114
169
*/
