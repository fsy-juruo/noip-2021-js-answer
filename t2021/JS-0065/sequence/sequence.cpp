#include<bits/stdc++.h>
#define ll long long
#define P 998244353
using namespace std;
ll n,m,k,ans,b;
ll v[111],a[111];
int check(ll x)
{
	int c=0;
	while(x)
	{
		if (x&1)c++;
		x=x>>1;
	}
	return c;
}
void dfs(ll dep,ll x,ll s)
{
	if (dep>n)
	{
		if (check(x)<=k)
		{
			//cout<<x<<endl;
			ans=(ans+s)%P;
		}
		return ;
	}
	for (int i=1,j=0;j<=m;i=i<<1,j++)
	{
		a[dep]=j;
		dfs(dep+1,x+i,s*v[j]%P);
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=0;i<=m;i++)cin>>v[i];
	dfs(1,0,1);
	cout<<ans<<endl;
	return 0;
}

