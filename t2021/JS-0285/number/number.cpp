#include <bits/stdc++.h>
using namespace std;
const int maxn=10000100;
bool b[20000010];
int p[20000010],pri[10000010],cnt;
inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')	{if(ch=='-')	w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')	{s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
bool check(int x)
{
	while(x)
	{
		if(x%10==7)	return 1;
		x/=10;
	}
	return 0;
}
void shai()
{
	int wz=1;
	for(int i=2;i<=maxn;i++)
	{
		if(!b[i])
		{
			if(check(i))
			{
				b[i]=1;
				pri[++cnt]=i;
				for(int i=1;1ll*i*pri[cnt]<=maxn;i++)
				b[i*pri[cnt]]=1;
			}
			else
			{
				p[wz]=i;
				wz=i;
			}
		}
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t=read();
	shai();
	while(t--)
	{
		int x=read();
		if(b[x])	printf("-1\n");
		else	printf("%d\n",p[x]);
	}
	return 0;
}

