#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll maxn=1e5;
const ll mod=998244353;
ll v[maxn],n,m,k,dp[35][200005],s[35][200005];
ll pows(ll x,ll k)
{
	ll cnt=1;
	while(k)
	{
		x%=mod;
		cnt%=mod;
		if(k&1)
			cnt*=x;
		k>>=1;
		x*=x;
		x%=mod;
		cnt%=mod;
	}
	return cnt%mod;
}
ll inv(ll x)
{
	return pows(x%mod,mod-2);
}
ll counts(ll x)
{
	ll cnt=0;
	while(x)
	{
		x&=(x-1);
		cnt++;
	}
	return cnt;
}
ll dfs(ll cur,ll now,ll sums)
{
	if(cur==n&&counts(now)<=k)
	{
		return sums;
	}
	if(cur==n)
		return 0;
	if(s[cur][now]==0)
		return 0;
	if(s[cur][now]!=-1)
		return s[cur][now]*sums%mod;
	ll cnt=0;
	for(ll i=0;i<=m;i++)
	{
		cnt+=dfs(cur+1,now+(1ull<<i),sums*v[i]%mod);
		cnt%=mod;
	}
	s[cur][now]=cnt*inv(sums)%mod;
	return cnt;
}
int main()
{
	cin>>n>>m>>k;
	memset(s,-1,sizeof(s));
	for(ll i=0;i<=m;i++)
		cin>>v[i];
	cout<<dfs(0,0,1);
	
} 
