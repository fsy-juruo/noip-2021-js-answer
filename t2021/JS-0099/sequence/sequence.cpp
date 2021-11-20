#include<bits/stdc++.h>
#define LL long long
using namespace std;
void read(int &x)
{
	x=0;bool flg=0;char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-') flg=1;else x=c^48;c=getchar();
	while(isdigit(c)) x=x*10+(c^48),c=getchar();
	if(flg) x=-x;
}
void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10^48);
}
void writeln(int x)
{
	write(x);
	puts("");
}
const int mod=998244353;
const int M=105,N=35;
int n,m,K,f[N][N][M][N],Pow[N],v;//f[j][sta][i][k]:S0..i has j ones,S>>i=sta,have choose 0..i,cnt(choose)=k
int cnt1(int x)
{
	int ret=0;
	while(x) ret+=x&1,x>>=1;
	return ret;
}
int ksm(int x,int y)
{
	if(!y) return  1;
	if(y==1) return x;
	if(y&1) return 1ll*x*ksm(1ll*x*x%mod,y>>1)%mod;
	return ksm(1ll*x*x%mod,y>>1);
}
int Fact[N],Inv[N];
int C(int n1,int k1)
{
	return 1ll*Fact[n1]*Inv[k1]%mod*Inv[n1-k1]%mod;
}
int main()
{
	
	//S=[j ones]+sta
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n),read(m),read(K);
	Fact[0]=1;
	for(int i=1;i<=n;i++) Fact[i]=1ll*Fact[i-1]*i%mod;
	Inv[n]=ksm(Fact[n],mod-2);for(int i=n-1;i>=0;i--) Inv[i]=1ll*Inv[i+1]*(i+1)%mod;
	Pow[0]=1;
	// solv 0
	read(v);
	for(int j=1;j<=n;j++) Pow[j]=1ll*Pow[j-1]*v%mod;
	for(int t=0;t<=n;t++) f[t&1][t>>1][0][t]=1ll*Pow[t]*C(n,t)%mod;//0..0 has t&1 ones,S=t,choose from0..0 total t numbers
	for(int i=0;i<m;i++)//use ith to update (i+1)th
	{
		read(v);
		for(int j=1;j<=n;j++) Pow[j]=1ll*v*Pow[j-1]%mod; 
		for(int j=0;j<=K;j++)//S0..i has j ones
		{
			for(int k=j;k<=n;k++)//have choose k numbers
			{
				for(int sta=0;sta<=k;sta++)//S>>i=sta
				{
					
					int val=f[j][sta][i][k];
					if(!val) continue;
					for(int t=0;t+k<=n;t++)//i+1 choose t
					{
						(f[j+(sta+t&1)][sta+t>>1][i+1][t+k]+=1ll*val*Pow[t]%mod*C(n-k,t)%mod)%=mod;//S->S+(t<<i),cnt1(S[0..i+1])=j+
					}
				}
			}
		}
	}
	//i=m
	int ans=0;
	for(int j=0;j<=K;j++)
	{
		//k=n
		for(int sta=0;sta<=n;sta++)
		{
			if(j+cnt1(sta)<=K) 
			(ans+=f[j][sta][m][n])%=mod;
		}
	}
	writeln(ans);
	return 0;
}

