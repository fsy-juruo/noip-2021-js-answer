#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int x=0;
	bool f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			f=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return (f?x:~(x-1));
}
inline void writes(int x)//positive!
{
	if(x<10)
	{
		putchar('0'+x);
		return ;
	}
	writes(x/10);
	putchar(x%10+'0');
}
const int mod=998244353;
int n,m,k,ans,C[31][31],pw[101][31];
map<int,int>f[31][102][31];
signed main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	for(int i=0;i<=30;i++)
	{
		C[i][0]=1;
		for(int l=1;l<=i;l++)
			C[i][l]=(C[i-1][l]+C[i-1][l-1])%mod;
	}
	n=read();
	m=read();
	k=read();
	for(int i=0;i<=m;i++)
	{
		pw[i][0]=1;
		pw[i][1]=read();
		for(int l=2;l<=n;l++)
			pw[i][l]=(pw[i][l-1]*pw[i][1])%mod;
	}
	f[0][0][0][0]=1;
		for(int l=0;l<=m;l++)
	for(int i=0;i<n;i++)
			for(int j=0;j<=k;j++)
				for(auto p:f[i][l][j])
				{
//					cout<<i<<" "<<l<<" "<<j<<" "<<p.first<<" "<<p.second<<endl;
					for(int q=n-i;q>=0;q--)
					{
						int p1=p.first,p2=p.second;
						p1+=q;
						int nj=j+(p1&1);
						if(nj>k)
							break;
						p1>>=1;
//						p2=(1ll*(1ll*p2*pw[l][q]%mod)*C[i+q][q])%mod;
						(p2*=pw[l][q]*C[i+q][q]%mod)%=mod;
						(f[i+q][l+1][nj][p1]+=p2)%=mod;
						if(l==m)
							break;
					}
					/*
					if(l==m)
						break;
					for(int q=n-i-1;q>=0;q-=2)
					{
						int p1=p.first,p2=p.second;
						p1+=q;
						int nj=j+(p1&1);
						if(nj>k)
							break;
						p1>>=1;
//						p2=(1ll*(1ll*p2*pw[l][q]%mod)*C[i+q][q])%mod;
						(p2*=1ll*pw[l][q]*C[i+q][q]%mod)%=mod;
						(f[i+q][l+1][nj][p1]+=p2)%=mod;
					}
					*/
				}
	for(int i=1;i<=m+1;i++)
		for(int j=0;j<=k;j++)
			for(auto l:f[n][i][j])
			{
				int p1=l.first,p2=l.second,nj=j,ok=1;
				while(p1)
				{
					nj+=(p1&1);
					if(nj>k)
					{
						ok=0;
						break;
					}
					p1>>=1;
				}
				if(ok)
					(ans+=p2)%=mod;
			}
	writes(ans);
	return 0;
}

