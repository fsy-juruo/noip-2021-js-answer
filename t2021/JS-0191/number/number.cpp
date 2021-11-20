#include <bits/stdc++.h>
#define N 10000005
using namespace std;
int scan()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0')
	{
		x=(x<<3)+(x<<1)+(ch^'0');
		ch=getchar();
	}
	return x*f;
}
#define scan scan()
int seven[N*2];
bool check(int x)
{
	while(x)
	{
		if(x%10==7)return false;
		x/=10;
	}
	return true;
}
void solve(int T)
{
	for(int i=1;i<=T;i++)
	{
		if(seven[i])continue;
		if(!check(i))
			for(int j=i;j<=T;j+=i)
				seven[j]=1;
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int T=scan;
	if(T<=10000)solve(400005);
	else solve(10000005);
	while(T--)
	{
		int x=scan;
		if(seven[x])puts("-1");
		else 
			for(int i=x+1;i;i++)
				if(!seven[i])
				{
					printf("%d\n",i);
					break;
				}
	}
	return 0;
}
