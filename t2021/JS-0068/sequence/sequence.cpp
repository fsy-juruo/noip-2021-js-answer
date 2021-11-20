#include<bits/stdc++.h>
using namespace std;
const int maxm=105,mod=998244353;
int n,m,k;
long long ans;
int v[maxm];
int check(int x)
{
	int tot=0;
	while(x)
	{
		if(x&1)
		{
			tot++;	
		}
		x>>=1;
	}
	return tot;
}
int a[maxm];
void dfs(int now)
{
	if(now==n+1)
	{
		int tt=0;
		for(int i=1;i<=n;i++)
		{
			tt+=pow(2,a[i]);

		}			
		if(check(tt)<=k)
		{
				int qzh=1;
				for(int i=1;i<=n;i++)
				{
					//cout<<a[i]<<" ";
					qzh*=v[a[i]];
					qzh%=mod;
				}
				ans+=qzh;
				//cout<<tt<<endl;
				ans%=mod;
			}
		return;
	}
	for(int i=0;i<=m;i++)
	{
		a[now]=i;
		dfs(now+1);
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++)
	{
		scanf("%d",&v[i]);
	}
	dfs(1);
	//cout<<check(5);
	cout<<ans%mod;
}

