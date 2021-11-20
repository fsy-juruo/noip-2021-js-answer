#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;++i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define mpr make_pair
#define pb push_back

using namespace std;

const LL MOD=998244353;

LL n,m,t,v[110],c[40][40],dp[2][35][10][35][35],ans=0;
//dp[v中第i个][a中填了j个][最近3位(不包括当前位)为msk][这3位之前有连续的k个1][一共p个1] 

int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>t;
	rep(i,m+1) scanf("%lld",&v[i]);
	reverse(v,v+m+1);
	c[0][0]=c[1][0]=c[1][1]=1;
	for(int i=2;i<=35;++i)
	{
		c[i][0]=c[i][i]=1;
		repn(j,i-1) c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
	}
	dp[0][0][0][0][0]=1;
	rep(ii,m+1)
	{
		int i=ii&1;
		rep(j,n+1) rep(msk,8) rep(k,j+1) for(int p=k;p<=j;++p) if(dp[i][j][msk][k][p]>0)
		{
			LL val=dp[i][j][msk][k][p],mul=1;
			rep(pt,n-j+1)
			{
				LL rval=val*mul%MOD*c[n-j][pt]%MOD,ni=i^1,nj=j+pt,nmsk=0,nk=0,np=p,nv=msk+msk+pt,car=nv/16;
				nk=(car==0 ? k:0);if((nv&8)>0) ++nk;else nk=0;
				nmsk=(nv&7);
				if(car==1) np-=(k-1);
				np-=(LL)(__builtin_popcount(msk))-__builtin_popcountll(nv&15);
				(dp[ni][nj][nmsk][nk][np]+=rval)%=MOD;
				(mul*=v[ii])%=MOD;
			}
			dp[i][j][msk][k][p]=0;
		}
	}
	int i=(m+1)&1,j=n;
	rep(msk,8) rep(k,t+1) for(int p=k;p<=t;++p) (ans+=dp[i][j][msk][k][p])%=MOD;
	cout<<ans<<endl;
	return 0;
}
