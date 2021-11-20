#include<bits/stdc++.h>
#define mid ((l+r)>>1)
using namespace std;
long long read()
{
	long long k=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		k=(k<<1)+(k<<3)+c-'0';
		c=getchar();
	}
	return k*f;
}

long long nxt[10000500],cnt;
long long sev[10000500],scnt;
int n;
bool flag[10000050];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long now=1;
	flag[7]=true;
	for(long long i=1;i<=10000100;i++)
	{
		if(i>=now*10)now*=10;
		if(flag[i/10]||flag[i%now]||flag[i])
			flag[i]=true,sev[++scnt]=i;
	}
	now=0;
	for(int i=2;i<=10000100;i++)
	{
		for(int j=1;j<=scnt&&i*sev[j]<=10000100;j++)
		{
			flag[i*sev[j]]=true;
			if(i%sev[j]==0)break;
		}
		if(!flag[i])
			while(now+1<i)nxt[++now]=i;
	}
	now=19260817;
	int t=read();
	while(t--)
	{
		long long x=read();
		if(flag[x])printf("-1\n");
		else printf("%d\n",nxt[x]);
	}
	return 0;
}
