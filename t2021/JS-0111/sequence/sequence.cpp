#include<bits/stdc++.h>
#define re register
#define rep(i,x,y) for(re int i=x;i<=y;++i)
#define Rep(i,x,y) for(re int i=x;i>=y;--i)
#define _rep(i,x,y) for(re int i=x;i<y;++i)
#define _Rep(i,x,y) for(re int i=x;i>y;--i)
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef double db;
template<typename T>inline void read(T&x)
{
	x=0;bool f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<3)+(x<<1)+ch-'0';
	x=(f?(-x):x);
}
template<typename T>inline T chkmax(T&x,const T&y){return x=(x>y?x:y);}
template<typename T>inline T chkmin(T&x,const T&y){return x=(x<y?x:y);}
const int p=998244353;
const int M=105,N=35;
bool f[M][N][N][N];
ll dp[M][N][N][N];
ll fac[M<<1],inv[M<<1];
void init(int n)
{
	inv[0]=inv[1]=1;
	rep(i,2,n)
	inv[i]=(p-p/i)*inv[p%i]%p;
	rep(i,1,n)
	inv[i]=inv[i]*inv[i-1]%p;
	fac[0]=fac[1]=1;
	rep(i,2,n)
	fac[i]=fac[i-1]*i%p;
}
ll C(ll x,ll y)
{
	if(y>x)return 0ll;
	return fac[x]*inv[y]%p*inv[x-y]%p;
}
int n,m,cnt;
ll a[M],s[M][M];
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	init(200);
	read(n),read(m),read(cnt);
	m++;
	rep(i,1,m)read(a[i]);
	rep(i,1,m)
	{
		s[i][0]=1;
		rep(j,1,n)
		s[i][j]=s[i][j-1]*a[i]%p;
	}
	f[0][0][0][0]=1;
	dp[0][0][0][0]=1;
	rep(i,1,m)
	{
		rep(t,0,n)
		{
			rep(j,0,n-t)
			rep(k,0,i-1)
			rep(l,0,j/2)
			if(f[i-1][j][k][l])
			{
				dp[i][j+t][k+((t+l)&1)][(t+l)>>1]+=
				(dp[i-1][j][k][l]*s[i][t]%p*C(n-j,t))%p;
				dp[i][j+t][k+((t+l)&1)][(t+l)>>1]%=p;
				f[i][j+t][k+((t+l)&1)][(t+l)>>1]=1;
//				printf("%d %d %d %d\n",i,j+t,k+(t+l&1),(t+l>>1));
			}
		}
	}
	ll ans=0;
	rep(i,0,n)
	rep(j,0,n)
	if(f[m][n][i][j])
	{
		int x=j,y=i;
		while(x)
		{
			y+=(x&1);
			x>>=1;
		}
		if(y<=cnt)
		ans=(ans+dp[m][n][i][j])%p;
	}
	printf("%lld\n",ans%p);
	return 0;
}

