#include<bits/stdc++.h>
using namespace std;
inline void openfiles()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
}
const int N=100005;
inline int rd()
{
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
	return x*y;
}
int T,p[20000005],nex[20000005];
inline bool check(int x)
{
	if(p[x])return 1;
	for(int i=2;i*i<=x;++i)if(x%i==0&&(p[i]||p[x/i]))return p[x]=1;
	return 0;
}
vector<int>pl;
inline void dfs(int pos,bool flag,int x)
{
	if(pos==0)
	{
		p[x]=1;
		return;
	}
	if(pos==1&&!flag)dfs(pos-1,1,x*10+7);
	else for(int i=9;i!=-1;--i)dfs(pos-1,flag||i==7,x*10+i);
}
int main()
{
	openfiles();
	dfs(7,0,0);
	for(int i=0;i<=10000000;i+=7)p[i]=1;
	for(int i=1;i<=10000000;++i)nex[i]=i;
	for(int i=10000000;i;--i)
	{
		if(p[i+1])nex[i]=nex[i+1];
		else ++nex[i];
	}
	T=rd();
	while(T--)
	{
		int x=rd();
		if(check(x))
		{
			puts("-1");
			continue;
		}
		while(check(x=nex[x]));
		printf("%d\n",x);
	}
	return 0;
}
/*

*/
