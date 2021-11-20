#include<bits/stdc++.h>
#define MAX 10000
using namespace std;
typedef long long ll;
typedef double db;
const ll mod=998244353;
int n; ll a[MAX+5],ans=1e18; db aver;
map<ll,bool>used;
ll calc()
{
	ll sum=0,val=0;
	for(int i=1; i<=n; i++) sum+=a[i];
	for(int i=1; i<=n; i++)
	{
		val+=(n*a[i]-sum)*(n*a[i]-sum);
	}
	val/=n;
	return val;
}
ll run()
{
	ll val=0;
    for(int i=1; i<=n; i++)
    val=(val*404+a[i])%mod;
    return val;
}
void dfs(int cnt)
{
	for(int i=2; i<n; i++)
	{
		ll ori=a[i];
		a[i]=a[i-1]+a[i+1]-a[i];
		ll check=calc();
		if(check<ans) ans=check;
		if(n>10) 
		{
		if(!used[run()]&&cnt<=5) { used[run()]=1; dfs(cnt+1); }
	    }
		else if(n<=10)
		{
		if(!used[run()]&&cnt<=20) { used[run()]=1; dfs(cnt+1); }
	    }
		a[i]=ori;
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n; 
	for(int i=1; i<=n; i++) 
	{
	cin>>a[i];
	aver+=a[i];
    }
    dfs(1);
    cout<<ans;
	return 0;
}
