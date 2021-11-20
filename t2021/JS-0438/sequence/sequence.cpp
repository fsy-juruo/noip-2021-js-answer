#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
#define debug printf
#else
#define debug(...)
#endif
int read()
{
	int s = 0,f = 1;
	char c = getchar();
	while(!isdigit(c))
	{
		if(c == '-')
		{
			f = 0;
		}
		c = getchar();	
	} 
	while(isdigit(c))
	{
		s = s * 10 + c - '0';
		c = getchar();
	}
	return f ? s : -s;
}
ll readll()
{
	ll s = 0,f = 1;
	char c = getchar();
	while(!isdigit(c))
	{
		if(c == '-')
		{
			f = 0;
		}
		c = getchar();	
	} 
	while(isdigit(c))
	{
		s = s * 10 + c - '0';
		c = getchar();
	}
	return f ? s : -s;
}
const int mod = 998244353;
int mypow(int a,int b)
{
	int ret = 1;
	for(;b;b >>= 1,a = 1ll * a * a % mod)
	{
		if(b & 1)
		{
			ret = 1ll * ret * a % mod; 
		}
	}
	return ret;
 } 
const int maxn = 105;

int v[maxn],fac[maxn],ifac[maxn];
int cnt[maxn],cnt2[maxn];
int n,m,K;
ll ans;
inline void dfs(int sum,int id,ll now,ll k,int last,ll p)
{
//	for(int i = 0;i <= m; ++i)
//	{
//		printf("%d,",cnt[i]);
//	}
//	printf("\n");
	if(sum == n)
	{
		register int s = 0;
		while(p)
		{
			s += p & 1;
			p >>= 1;
		}
		if(s <= k)
		{
//			printf("ok\n");
			ans += now * fac[n] % mod * k % mod * ifac[last] % mod;
			ans %= mod;
		}
		return;
	}
	for(int i = id;i <= m; ++i)
	{
		cnt[i]++;
		if(i == id)
		{
			dfs(sum + 1,i,now * v[i] % mod,k,last + 1,p + (1 << i));
		}
		else
		{
			dfs(sum + 1,i,now * v[i] % mod,k * ifac[last] % mod,1,p + (1 << i));
		}
		cnt[i]--;
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&K);
	fac[0] = 1;
	for(int i = 1;i <= n; ++i)
	{
		fac[i] = 1ll * fac[i - 1] * i % mod;
	}
	ifac[n] = mypow(fac[n],mod - 2);
	for(int i = n - 1;i >= 0; --i)
	{
		ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
//		printf("ifac[%d] = %lld\n",i,ifac[i]);
	} 
	for(int i = 0;i <= m; ++i)
	{
		scanf("%d",&v[i]);
	}
	dfs(0,0,1ll,1ll,0,0ll);
	printf("%lld\n",ans);
	return 0;
}
