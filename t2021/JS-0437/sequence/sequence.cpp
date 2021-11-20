#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll mod=998244353ll;
ll lmod=998244353ll*20ll;
//struct P35
//{
//	ll dp[105][35][35][20];
//	ll f[105];
//	ll a[35],mmm=1;
//	int n,m,l;
//	ll mi(ll x,ll y)
//	{
//		if(y==0)return 1;
//		ll res=1;
//		if(y&1)res=x;
//		ll g=mi(x,y>>1);
//		return g*g%mod*res%mod;
//	}
//	void solve()
//	{
//		scanf("%d%d%d",&n,&m,&l);
//		f[n+1]=1;
//		for(int i=n;i>0;i--)f[i]=f[i+1]*i;
////		for(int i=0;i<=n;i++)cout<<f[i]<<' ';
////		cout<<endl;
//		for(int i=1;i<=m+1;i++)scanf("%d",&a[i]);
//		dp[0][0][0][0]=f[1];
//		for(int i=0;i<=m+5;i++)for(int j=0;j<=n;j++)for(int k=0;k<=l;k++)for(int p=0;p<=15;p++)
//		{
//			if(i<=m)for(int x=0;x+j<=n;x++)
//			{
//				dp[i+1][j+x][k+((x+p)&1)][(x+p)>>1]+=dp[i][j][k][p]*f[x+1]/f[1]%mod*mi(a[i+1],x)%mod;
//				if(dp[i+1][j+x][k+((x+p)&1)][(x+p)>>1]>=mod)dp[i+1][j+x][k+((x+p)&1)][(x+p)>>1]-=mod;
////				cout<<i+1<<' '<<j+x<<' '<<k+(x+p)%2<<' '<<((x+p)>>1)<<' '<<dp[i+1][j+x][k+((x+p)&1)][(x+p)>>1]<<endl;
//			}
//			else
//			{
//				dp[i+1][j][k+(p&1)][p>>1]+=dp[i][j][k][p];
//				if(dp[i+1][j][k+(p&1)][p>>1]>=mod)dp[i+1][j][k+(p&1)][p>>1]-=mod;
//			}
//		}
//		ll ans=0;
//		for(int i=1;i<=l;i++)
//		{
//			ans+=dp[m+6][n][i][0];
//			if(ans>=mod)ans-=mod;
//		}
//		printf("%lld\n",ans);
//	}
//}p35;
struct P100
{
	ll dp[105][35][35][20];
	ll f[105];
	ll a[35];
	int n,m,l;
	ll mi(ll x,ll y)
	{
		if(y==0)return 1;
		ll res=1;
		if(y&1)res=x;
		ll g=mi(x,y>>1);
		return g*g%mod*res%mod;
	}
	void solve()
	{
		scanf("%d%d%d",&n,&m,&l);
		f[n+1]=1;
		for(int i=n;i>0;i--)f[i]=f[i+1]*i%mod;
//		for(int i=0;i<=n;i++)cout<<f[i]<<' ';
//		cout<<endl;
		for(int i=1;i<=m+1;i++)scanf("%lld",&a[i]);
		dp[0][0][0][0]=f[1];
		for(int i=0;i<=m+5;i++)for(int j=0;j<=n;j++)for(int k=0;k<=l;k++)for(int p=0;p<=15;p++)
		{
			if(i<=m)for(int x=0;x+j<=n;x++)
			{
				dp[i+1][j+x][k+((x+p)&1)][(x+p)>>1]+=dp[i][j][k][p]*f[x+1]/f[1]*mi(a[i+1],x)%mod;
				if(dp[i+1][j+x][k+((x+p)&1)][(x+p)>>1]>=mod)dp[i+1][j+x][k+((x+p)&1)][(x+p)>>1]-=mod;
//				cout<<i+1<<' '<<j+x<<' '<<k+(x+p)%2<<' '<<((x+p)>>1)<<' '<<dp[i+1][j+x][k+((x+p)&1)][(x+p)>>1]<<endl;
			}
			else
			{
				dp[i+1][j][k+(p&1)][p>>1]+=dp[i][j][k][p];
				if(dp[i+1][j][k+(p&1)][p>>1]>=mod)dp[i+1][j][k+(p&1)][p>>1]-=mod;
			}
		}
		ll ans=0;
		for(int i=1;i<=l;i++)
		{
			ans+=dp[m+6][n][i][0];
			if(ans>=mod)ans-=mod;
		}
		printf("%lld\n",ans);
	}
}p100;
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	p100.solve();
	return 0;
}
