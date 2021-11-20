#include<stdio.h>
#define MOD 998244353
typedef long long ll;
using namespace std;
template<typename qwq> void read(qwq &a)
{
	a=0;char c=getchar();int x=1;
	for	(;c<'0'||c>'9';c=getchar())	x=c=='-'?-x:x;
	for	(;c>='0'&&c<='9';a=(a<<1)+(a<<3)+(c^48),c=getchar());
	a*=x;
}

template<typename qwq> void write(qwq a)
{
	if	(a>9)	write(a/10);
	putchar(a%10+48);
}
template<typename qwq> void twrite(qwq a)
{
	if	(a<0)	putchar('-'),write(-a);
		else	write(a);
}
template<typename qwq> void writeln(qwq a)
{
	twrite(a),puts("");
}
int v[105];
ll f[31][130000];
int N,M,K;
int fac[6]={1,1,2,6,24,120};
int a[6];
ll ans=0;
int cnt(ll x)
{
	int ans=0;
	while	(x)	ans++,x-=x&-x;
	return ans;
}
void dfs(int dep,ll now,ll zt)
{
	if	(dep>N)
		{
			if	(cnt(zt)<=K)
				{
					int b[6]={0};
					b[1]=1;
					int zz=1;
					for	(int i=2;i<=N;i++)
						if	(a[i]==a[i-1])	b[zz]++;
									else	b[++zz]=1;
					int xs=fac[N];
					for	(int i=1;i<=zz;i++)
						xs/=fac[b[i]];
					ans+=now*xs%MOD;
					ans%=MOD;
				}
			return;
		}
	for	(int i=a[dep-1];i<=M;i++)
		{
			a[dep]=i;
			dfs(dep+1,now*v[i]%MOD,zt+(1<<i));
		}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(N),read(M),read(K);
	for	(int i=0;i<=M;i++)	read(v[i]);
	if	(M<=12)
		{
			f[0][0]=1;
			for	(int i=1;i<=N;i++)
				{
					int sx=(i-1)*(1<<M);
					for	(int j=i-1;j<=sx;j++)
						{
							if	(f[i-1][j]==0)	continue;
							for	(int k=0;k<=M;k++)
								{
									f[i][j+(1<<k)]+=f[i-1][j]*v[k]%MOD;
									f[i][j+(1<<k)]%=MOD;
								}
						}
				}
			int sx=N*(1<<M);
			for	(int i=N;i<=sx;i++)
				if	(cnt(i)<=K)
					ans=(ans+f[N][i])%MOD;
			writeln(ans);
			return 0;
		}
	if	(N<=5)
		{
			a[0]=0;
			dfs(1,1,0);
			writeln(ans);
		}
	return 0;
}

