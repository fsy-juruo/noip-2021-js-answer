#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 35;
const int M = 105;
const int MOD = 998244353;
int n,m,k;
int v[M];
int ans;
int a[N];
inline bool check()
{
	int S=0;
	for(int i=1;i<=n;++i) S+=(1<<a[i]);
	int cnt=0;
	while(S)
	{
		if(S&1) ++cnt;
		S>>=1;
	}
	if(cnt<=k) return 1;
	return 0;
}
int tim[M];
int fac[N],ifac[N];
inline int qpow(int x,int b)
{
	int ret=1;
	while(b)
	{
		if(b&1) ret=ret*x%MOD;
		x=x*x%MOD;
		b>>=1;
	}
	return ret;
}
inline int C(int x,int y)
{
	return fac[x]*ifac[y]%MOD*ifac[x-y]%MOD;
}
inline int calc()
{
	int ret=1;
	int lf=n;
	for(int i=0;i<=m;++i)
	{
		ret=ret*C(lf,tim[i]);
		lf-=tim[i];
	}
	return ret;
}
inline void dfs(int step,int pl,int las)
{
	if(step==n+1)
	{
		if(check()) 
		  ans=(ans+pl*calc())%MOD;
		return ;
	}
	for(int i=las;i<=m;++i) 
	{
		a[step]=i;
		++tim[i];
		dfs(step+1,pl*v[i]%MOD,i);
		--tim[i];
	}
}
signed main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	fac[0]=1;for(int i=1;i<=n;++i) fac[i]=fac[i-1]*i%MOD;
	ifac[n]=qpow(fac[n],MOD-2);for(int i=n;i>=1;--i) ifac[i-1]=ifac[i]*i%MOD;
	for(int i=0;i<=m;++i) scanf("%lld",&v[i]);
	dfs(1,1,0);
	printf("%lld",ans);
}
