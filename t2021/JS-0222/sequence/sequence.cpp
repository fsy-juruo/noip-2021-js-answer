#include<bits/stdc++.h>
using namespace std;
#define int long long
inline void read(int &x)
{
	x=0;
	int f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-48;
		c=getchar();
	}
	x*=f;
}

const int maxn = 107;
const int mod = 998244353;

int n,m,k;
long long ans;
int v[maxn],a[maxn],ct[maxn];
long long jc[maxn];

long long ksm(int x,int k)
{
	long long res = 1;
	while(k)
	{
		if(k&1)
			res=(res*x)%mod;
		x=(x*x)%mod;
		k>>=1;
	}
	return res;
}

bool check()
{
	int nw = 0,lst = 0;
	long long rr = 0;
	for(int i=0;i<=m;++i)
		ct[i]=0;
	for(int i=1;i<=n;++i)
		rr+=(1<<a[i]);
	while(rr)
	{
		if(rr&1)
			++nw;
		rr>>=1;
	}
	if(nw>k)
		return false;
	return true;
}

long long calc()
{
	long long res = 1;
	for(int i=0;i<=m;++i)
		ct[i]=0;
	for(int i=1;i<=n;++i)
		res=(res*v[a[i]])%mod;
	for(int i=1;i<=n;++i)
		ct[a[i]]++;
	long long tim = jc[n];
	for(int i=0;i<=m;++i)
	{
		if(ct[i])
		{
			tim=(tim*ksm(jc[ct[i]],mod-2))%mod;
		}
	}
	res=res*tim%mod;
	return res%mod;
}

void dfs(int len,int lst)
{
	if(len==n+1)
	{
		if(check())
		{
			ans=(ans+calc()+mod)%mod;
		}
		return;
	}
	for(int i=lst;i<=m;++i)
	{
		a[len]=i;
		dfs(len+1,i);
	}
}

signed main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n),read(m),read(k);
	jc[0]=1;
	for(int i=1;i<=n;++i)
		jc[i]=(jc[i-1]*i)%mod;
	ans=0;
	for(int i=0;i<=m;++i)
		read(v[i]);
	dfs(1,0);
	printf("%lld\n",ans%mod);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

