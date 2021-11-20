#include <bits/stdc++.h>
using namespace std;

#define int long long

const int M = 998244353;

int n,m,lim,v[105];
int c[105][105],p[105][105];
int f[105][35][45][45],ans;

int ksm(int x,int w)
{
	int s=1;
	while(w)
	{
		if(w&1)
			s = s*x%M;
		x = x*x%M;
		w >>= 1;
	}
	return s;
}

signed main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&lim);
	for(int i=0;i<=m;scanf("%lld",v+i),i++);
	for(int i=0;i<=m;i++)
	{
		p[i][0] = 1;
		for(int j=1;j<=n;j++)
			p[i][j] = p[i][j-1]*v[i]%M;
	}
	for(int i=0;i<=n+1;i++)
		c[i][0] = 1;
	for(int i=1;i<=n+1;i++)
		for(int j=1;j<=i;j++)
			c[i][j] = (c[i-1][j-1]+c[i-1][j])%M;
	for(int j=0;j<=n;j++)
		f[0][j][j/2][j/2] = c[n][j]*ksm(v[0],j)%M;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			int mx=j/2+j/4+j/8+j/16;
			for(int k=0;k<=40;k++)
			for(int l=0;l<=mx;l++)
			{
				for(int j1=0;j1<=n-j;j1++)
				{
					int l1=(j1+l)/2;
					if(l1>40 || l1+k>40) continue;
					int add=c[n-j][j1]*p[i+1][j1]%M;
					f[i+1][j+j1][l1+k][l1] = (f[i+1][j+j1][l1+k][l1]+f[i][j][k][l]*add%M)%M;
				}
			}
		}
	}
	for(int k=0;k<=40;k++)
	for(int l=0;l<=40;l++)
	{
		int cnt=k,tmp=l;
		while(tmp>1)
			cnt += tmp/2, tmp /= 2;
		if(cnt>=n-lim)
			ans = (ans+f[m][n][k][l])%M;
	}
	printf("%lld\n",(ans+M)%M);
	
	return 0;
}
