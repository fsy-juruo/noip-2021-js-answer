#include<bits/stdc++.h>
using namespace std;

const int N=35,M=105;
const long long MOD=998244353;
int n,m,k,cnt[M];
long long v[M],C[N][N],a[M][N];
long long f[105][N][N][18],ans;

void add(long long&x,long long y)
{
	x+=y;
	if(x>=MOD) x-=MOD;
}

void initc()
{
	for(int i=0;i<=m;i++)
	{
		a[i][0]=1;
		for(int j=1;j<=n;j++) a[i][j]=a[i][j-1]*v[i]%MOD;
	}
	for(int i=0;i<=n;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
	}
}

void workdp()
{
	for(int i=1;i<(1<<4);i++) cnt[i]=cnt[i>>1]+(i&1);
	for(int i=0;i<=n;i++) f[0][i][i&1][i>>1]=C[n][i]*a[0][i]%MOD;
	for(int i=1;i<=m+1;i++)
	{
		for(int j=0;j<=n;j++) for(int c=0;c<=k;c++) for(int msk=0;msk<(1<<4);msk++)
		{
			if(!f[i-1][j][c][msk]) continue;
			long long dp=f[i-1][j][c][msk];
			if(j==n)
			{
				if(c+cnt[msk]<=k) add(ans,dp);
				continue;
			}
			if(i==m+1) continue;
			for(int nw=0;nw+j<=n;nw++)
			{
				int nm=msk+nw;
				add(f[i][j+nw][c+(nm&1)][nm>>1],dp*C[n-j][nw]%MOD*a[i][nw]%MOD);
			}
		}
	}
	printf("%lld\n",ans);
}

int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++) scanf("%lld",&v[i]);
	initc(),workdp();
} 
