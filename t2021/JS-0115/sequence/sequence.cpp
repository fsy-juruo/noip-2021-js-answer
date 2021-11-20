#include<bits/stdc++.h>
using namespace std;

long long f[102][32][50][33];
int n,m,w;
long long v[120],p[120][120],fac[200],bin[200];

const long long mod=998244353;

int cnt(int x)
{
	int tmp=0;
	while(x)
	{
		tmp+=x&1;
		x>>=1;
	}
	return tmp;
}

long long calc(long long a,long long x)
{
	if(x==0) return 1ll;
	if(x==1) return a;
	long long y=x>>1;
	long long tmp=calc(a,y);
	tmp=tmp*tmp%mod;
	if(x&1) tmp=tmp*a%mod;
	return tmp%mod;
}

long long inv(long long a)
{
	return calc(a,mod-2);
}

int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&w);
	for(int i=0;i<=m;i++) scanf("%lld",&v[i]),p[i][0]=1;
	fac[0]=1;
	for(int i=1;i<=110;i++) fac[i]=fac[i-1]*i%mod;
	
	for(int i=0;i<=m;i++)
		for(int j=1;j<=n;j++) p[i][j]=p[i][j-1]*v[i]%mod;
		
	for(int i=0;i<=n;i++) f[0][i][cnt(i)][i]=p[0][i];
	
	for(int i=1;i<=m;i++)
	for(int j=0;j<=n;j++)
	for(int k=0;k<=n;k++)
	for(int l=0;l<=31;l++)
	{
		if(k<cnt(l)) continue;
		for(int j1=0;j1<=j;j1++)
		{
			long long l1=(l-j1)*2;
			if(l1<0||l1>31) continue;
			long long k1=(cnt(l1)-cnt(l))+k;
			if(k1<0) continue;
			
			long long g=(f[i-1][j-j1][k1][l1]+f[i-1][j-j1][k1][l1+1])%mod; 
			f[i][j][k][l]=(f[i][j][k][l]+g*fac[j]%mod*inv(fac[j-j1])%mod*inv(fac[j1])%mod*p[i][j1]%mod)%mod;
		}
	}
	
	long long ans=0;
	
	for(int k=0;k<=w;k++)
	for(int l=0;l<=31;l++) 
	{
		ans=(ans+f[m][n][k][l])%mod;
	}
	
	printf("%lld",ans%mod);
	
	return 0;
}
