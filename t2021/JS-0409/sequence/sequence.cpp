#include <bits/stdc++.h>
#define inf 1000000007
#define mod 998244353
//#define int long long
using namespace std;
template <typename T> void read(T &x){
	x=0;int fh=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') fh=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	x*=fh;
}
template <typename T> void write(T x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
template <typename T> void writeln(T x){
	write(x);
	puts("");
}
int qpow(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=1ll*res*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return res;
}
int n,m,lim;
int v[105];
int fac[35];
int inv[35];
int val[105][35];
int dp[105][35][35][35];
signed main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);read(m);read(lim);
	fac[0]=1;
	for(int i=1;i<=n;++i)
		fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;--i)
		inv[i]=1ll*inv[i+1]*(i+1)%mod;
	for(int i=0;i<=m;++i)
	{
		read(v[i]);
		val[i][0]=1;
		for(int j=1;j<=n;++j)
			val[i][j]=1ll*val[i][j-1]*v[i]%mod;
	}
	for(int i=0;i<=m;++i)
		for(int j=1;j<=n;++j)
			(dp[i][j][j&1][j>>1]+=1ll*val[i][j]*inv[j]%mod)%=mod;
	for(int i=0;i<m;++i)
		for(int j=1;j<n;++j)
			for(int k=0;k<=lim;++k)
				for(int l=0;l<=n;++l)
					if(dp[i][j][k][l])
					{
						for(int nxt=i+1;nxt<=m;++nxt)
							for(int num=1;num<=n-j;++num)
							{
								int nxtk=0,nxtcarry=0;
								if(nxt-i>6)
								{
									nxtk=k+__builtin_popcount(l)+(num&1);
									nxtcarry=(num>>1);
								}
								else
								{
									int carry=l+(num<<(nxt-i-1));
									nxtk=k+__builtin_popcount(carry&((1<<(nxt-i))-1));
									nxtcarry=carry>>(nxt-i);
								}
								if(nxtk<=lim)
									(dp[nxt][j+num][nxtk][nxtcarry]+=1ll*dp[i][j][k][l]*val[nxt][num]%mod*inv[num]%mod)%=mod;
							}
					}
	int ans=0;
	for(int i=0;i<=m;++i)
		for(int k=0;k<=lim;++k)
			for(int l=0;l<=n;++l)
				if(k+__builtin_popcount(l)<=lim)
					(ans+=dp[i][n][k][l])%=mod;
	writeln(1ll*ans*fac[n]%mod);
	return 0;
}

