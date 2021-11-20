#include <bits/stdc++.h>
#define MP make_pair
#define Fst first
#define Snd second
using namespace std;
int n,m,lim;
long long a[110];
long long md=998244353;
long long d[110][40][40][40];
long long val[110][40];
long long C[40][40];
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&lim);
	for (int i=0;i<=m;i++) scanf("%lld",&a[i]);
	for (int i=0;i<=m;i++)
	{
		val[i][0]=1;
		for (int j=1;j<=n;j++) val[i][j]=(val[i][j-1]*a[i])%md; 
	}
	C[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		C[i][0]=1;
		for (int j=1;j<=i;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%md;
	}
	d[0][0][0][0]=1;
	for (int i=0;i<=m;i++)
	{
		for (int j=0;j<=n;j++)
		{
			for (int k=0;k<=lim;k++)
			{
				for (int it=0;it<=n;it++)
				{
					if (!d[i][j][k][it]) continue;
					for (int ad=0;j+ad<=n;ad++)
						if (k+((it+ad)%2)<=lim) d[i+1][j+ad][k+((it+ad)%2)][(it+ad)/2]=(d[i+1][j+ad][k+((it+ad)%2)][(it+ad)/2]+((d[i][j][k][it]*((val[i][ad]*C[j+ad][ad])%md))%md))%md;
				}
			}
		}
	}
	/*for (int i=0;i<=m+1;i++)
		for (int j=0;j<=n;j++)
			for (int k=0;k<=lim;k++)
				for (int it=0;it<=n;it++)
					if (d[i][j][k][it]) cout <<i<<" "<<j<<" "<<k<<" "<<it<<" "<<d[i][j][k][it]<<" ##\n";*/
	long long res=0;
	for (int i=0;i<=lim;i++)
	{
		for (int j=0;j<=n;j++)
		{
			int k=i+__builtin_popcount(j);
			if (k<=lim) res=(res+d[m+1][n][i][j])%md;
		}
	}
	printf("%lld",res);
	return 0;
}
