#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const ULL Mod=998244353;
const int N=105;
int v[N];
inline int read();
bool check();
int n,m,k;
int ans=0;
int a[N];
int pd[300];
void dfs(int i)
{
	if(i==n+1)
	{
		if(check())
		{
			ULL tot=1;
			for(int j=1;j<=n;++j)
			{
				tot=((tot)*(ULL(v[a[j]])))%Mod;
			}
				
				
			ans=(ans+tot)%Mod;
		}
		
	}
	else
	{
		for(int j=0;j<=m;++j)
		{
			a[i]=j;
			dfs(i+1);
		}
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=0;i<=m;++i)
	{
		v[i]=read();
	}
	dfs(1);
	cout<<ans;
	return 0;
}

inline int read()
{
	int s=0;bool w=1;
	char c;
	while(c<'0'||c>'9'){if(c=='-')w=0;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return w?s:-s;
}

bool check()
{
	int tot=0;
	memset(pd,0,sizeof(pd));
	for(int i=1;i<=n;++i)
	{
		pd[a[i]]++;
	}
	for(int i=0;i<=200;++i)
	{
		pd[i+1]+=pd[i]/2;
		pd[i]%=2;
		if(pd[i]==1)tot++;
	}
	return tot<=k;
}


