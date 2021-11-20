#include<bits/stdc++.h>
using namespace std;
long long n,m,k,sum[1000],stac[1000],mi[1000],qq,ans;
void dfs(int x)
{
	if(x>n)
	{
		for(int i=0;i<=60;i++)
		mi[i]=0;
		for(int i=1;i<=n;i++)
		{
			mi[stac[i]]++;
		}
		ans=0;
		for(int i=0;i<=60;i++)
		{
			ans=ans+mi[i]%2;
			mi[i+1]+=mi[i]/2;
		}
		if(ans<=k)
		{
			long long w=1;
			for(int i=1;i<=n;i++)
			{
				w=w*sum[stac[i]]%998244353;
			}
			qq=(qq+w)%998244353;
		}
	}
	else
	{
		for(int i=0;i<=m;i++)
		{
			stac[x]=i;
			dfs(x+1); 
		}
	}
}
int main()
{
  freopen("sequence.in","r",stdin);
  freopen("sequence.out","w",stdout);
 	cin>>n>>m>>k;
 	for(int i=0;i<=m;i++)
 	cin>>sum[i];
	dfs(1);
	cout<<qq;
  return 0;
}