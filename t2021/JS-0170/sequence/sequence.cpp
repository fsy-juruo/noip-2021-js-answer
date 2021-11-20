#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long LL;

const int N=110,mod=998244353;

int n,m,k;
int v[N];

int read()
{
	int f=1,x=0;
	char c=getchar();
	
	while(c<'0'||c>'9')
	{
		f=-f;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}

inline int lowbit(int x)
{
	return x&-x;
}

bool check(int x)
{
	int cnt=0;
	while(x)
	{
		cnt++;
		x-=lowbit(x);
	}
	return cnt==k;
}

int ans[N];
LL res=0;
void dfs(int u,int sum,int to)
{
	if(sum==to&&u<=n) return;
	if(u>n)
	{
		if(sum==to) 
		{
			LL r=1;
			for(int i=1;i<=n;i++)
				r=r*v[ans[i]]%mod;
			res=(res+r)%mod;
		} 
		return;
	}
	for(int i=0;i<=m;i++)
	{
		int k=sum+(1<<i);
		if(k>to) continue;
		ans[u]=i;
		dfs(u+1,k,to);
	}
}

int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	
	n=read(),m=read(),k=read();
	for(int i=0;i<=m;i++) v[i]=read();
	
	for(int i=n;i<=n*(1<<m);i++)
		if(check(i))
			dfs(1,0,i);
	printf("%lld\n",res);
	
	return 0;	
}
