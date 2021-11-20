#include<bits/stdc++.h>
using namespace std;
bool f[10000010];
int T,nxt[10000010],k=10000001;
int read()
{
	int res=0;
	char c=getchar();
	while(c>='0'&&c<='9')
	{
		res=(res<<1)+(res<<3)+c-48;
		c=getchar();
	}
	return res;
}
bool check(int x)
{
	while(x)
	{
		if(x%10==7)return true;
		x/=10;
	}
	return false;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=7;i<=1e7;++i)
	{
		if(f[i])continue;
		if(check(i))
		for(int j=1;j*i<=1e7;++j)f[j*i]=true;
	}
	for(int i=1e7;i>=1;--i)
	{
		if(f[i])nxt[i]=-1;
		else 
		{
			nxt[i]=k;
			k=i;
		}
	}
	T=read();
	while(T--)
	{
		int x;
		x=read();
		printf("%d\n",nxt[x]);
	}
	return 0;
}
