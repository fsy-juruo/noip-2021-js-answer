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
int t;
int a[200020];
bool flag[10000010];
int ans[10000010];
vector<int>v;
int cur,last;
bool judge1(int x)
{
	while(x>0)
	{
		if(x%10==7)
		{
			v.push_back(cur);
			return true;
		}
		x/=10;
	}
	return false;
}
bool judge2(int x)
{
	for(int i=0;i<(int)v.size();i++)
	{
		if(v[i]*2>x)
		{
			break;
		}
		if(x%v[i]==0)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	t=read();
	for(int i=1;i<=t;i++)
	{
		a[i]=read();
		if(cur<=a[i])
		{
			cur++;
			for(;last<=a[i];cur++)
			{
				while(judge1(cur) || judge2(cur))
				{
					ans[cur]=-1;
					cur++;
				}
				ans[last]=cur;
				last=cur;
			}
		}
		write(ans[a[i]]);
		putchar('\n');
	}
	
	return 0;
}
