#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
inline int read()
{
	char c=getchar();
	int x=0;
	while(c<'0'||c>'9')
		c=getchar();
	while(c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x;
}
inline void fl()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
}
long long a[105][35],C[35][35],f[105][35][35][35];
int popc[105];
int main()
{
	fl();
	int n=read(),m=read(),k=n-read(),i,j,x,y,t;
	long long ans=0;
	for(i=0;i<=m;i++)
	{
		a[i][0]=1;
		a[i][1]=read();
		for(j=2;j<=n;j++)
			a[i][j]=a[i][j-1]*a[i][1]%mod;
	}
	for(i=1;i<=n;i++)
		popc[i]=popc[i>>1]+(i&1);
	for(i=0;i<=n;i++)
	{
		C[i][0]=1;
		for(j=1;j<=i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	for(i=0;i<=n;i++)
		f[0][i][i/2][i/2]=a[0][i]*C[n][i]%mod;
	for(i=0;i<m;i++)
		for(j=0;j<=n;j++)
			for(x=0;x<=n;x++)
				for(y=0;y<=n;y++)
					if(f[i][j][x][y])
						for(t=0;t<=n-j;t++)
							f[i+1][j+t][x+(t+y)/2][(t+y)/2]=(f[i+1][j+t][x+(t+y)/2][(t+y)/2]+f[i][j][x][y]*a[i+1][t]%mod*C[n-j][t]%mod)%mod;
	for(x=0;x<=n;x++)
		for(y=0;y<=n;y++)
			if(x+y-popc[y]>=k)
				ans=(ans+f[m][n][x][y])%mod;
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
