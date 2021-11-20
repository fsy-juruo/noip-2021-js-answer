#include<bits/stdc++.h>
using namespace std;
int read()
{
	int res=1,num=0;
	char ch;ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') res=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){num=num*10+ch-'0';ch=getchar();}
	return res*num;
}
int n,m,k;
int v[110];
long long const mod=998244353;
int rec[35];
int tmp[110];
long long ans;
void dfs(int dep)
{
	if(dep>n)
	{
		for(int i=0;i<=m+3;i++)
			tmp[i]=0;
		for(int i=1;i<=n;i++)
		{
			int p=rec[i];
			tmp[p]++;
			while(tmp[p]==2)
			{
				tmp[p]=0;
				++tmp[++p];
			}
		}
		int sum=0;
		for(int i=0;i<=m+3;i++)
			sum+=tmp[i];
		if(sum<=k)
		{
			long long s=1;
			for(int i=1;i<=n;i++)
				s=s*(long long)v[rec[i]]%mod;
			ans=(ans+s)%mod;
		}
		return;
	}
	for(int i=0;i<=m;i++)
	{
		rec[dep]=i;
		dfs(dep+1);
	}	
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=0;i<=m;i++)
		v[i]=read();
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}
