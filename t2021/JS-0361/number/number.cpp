#include<bits/stdc++.h>
using namespace std;

int T;
int x;
int seven[4000005];

inline int read()
{
	int res=0,t=1;
	char ch=getchar();
	while(ch>'9'||ch<'0') 
	{
		if(ch='-') t=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0')
	{
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res*t;
}

//bool checkseven(int k)
//{
//	while(k)
//	{
//		if(k%10==7) return true;
//		k/=10;
//	}
//	return false;
//}
bool check1(int m)
{
	while(m)
	{
		if(m%10==7) return false;
		m/=10;
	}
	return true;
}

bool check(int u)
{
	for(int i=2;i+i<=u;i++)
	{
		if(u%i==0&&(!check(i)||!check(u/i))) 
		{
			return false;
		}
	}
	while(u)
	{
		if(u%10==7) return false;
		
		u/=10;
	}
	return true;
}

int main()
{
	
    freopen("number.in","r",stdin);	
	freopen("number.out","w",stdout);
	T=read();
	begin:
	while(T--)
	{
		x=read();
		if(!check(x)) 
		{
			printf("-1\n");
			goto begin;
		}
		x++;
		while(!check(x))
		{
			x++;
		}
		printf("%d\n",x);
	}
	
	
	return 0;
}
