#include<bits/stdc++.h>
using namespace std;
int f[35][105][40][35],n,m,k,v[105],vv[105][35],cnt[105],l[6]={1,3,7,15,31},prod[105],inv[105];//f[i][j][p][mask]:选了i个[0,j)中的数，s有p个1，s的j-1~j+3位为mask   转移：枚举接下来放多少j 
const int md=998244353;
int c(int x)
{
	int res=0;
	while(x)
		res+=x%2,x/=2;
	return res;
}
void aa(int&a,int b)
{
	a+=b;
	if(a>=md)
		a-=md;
}
int pw(int a,int b)
{
	int c=1;
	while(b)
	{
		if(b&1)
			c=1ll*c*a%md;
		a=1ll*a*a%md,b>>=1;
	}
	return c;
}
int main()
{
	//freopen("out.txt","w",stdout);
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;++i)
		scanf("%d",&v[i]);
	prod[0]=inv[0]=1;
	for(int i=1;i<=100;++i)
		cnt[i]=c(i),prod[i]=1ll*prod[i-1]*i%md,inv[i]=pw(prod[i],md-2);
	for(int i=0;i<=m;++i)
		for(int j=0;j<=n;++j)
			vv[i][j]=pw(v[i],j);//,printf("%d ",vv[i][j]);
	f[0][0][0][0]=1;
	for(int j=0;j<=m;++j)
		for(int i=0;i<n;++i)
			for(int p=0;p<=min(i,k+3);++p)
				for(int q=0;q<=n;++q)
					if(f[i][j][p][q])
						for(int x=0;x+i<=n;++x)
						{
							int msk=q+(x<<1);
							f[i+x][j+1][p+cnt[msk]-cnt[q]][msk>>1]+=1ll*f[i][j][p][q]*prod[i+x]%md*inv[i]%md*inv[x]%md*vv[j][x]%md;
							//printf("%d %d %d %d %d->%d %d %d %d %d  %d %d\n",i,j,p,q,f[i][j][p][q],i+x,j+1,p+cnt[msk]-cnt[q],msk>>1,f[i+x][j+1][p+cnt[msk]-cnt[q]][msk>>1],x,vv[j][x]);
							if(f[i+x][j+1][p+cnt[msk]-cnt[q]][msk>>1]>=md)
								f[i+x][j+1][p+cnt[msk]-cnt[q]][msk>>1]-=md;
						}
	/*for(int i=0;i<=n;++i)
		for(int j=0;j<=m+1;++j)
			for(int p=0;p<=k;++p)
				for(int q=0;q<=n;++q)
					printf("f[%d][%d][%d][%d]=%d\n",i,j,p,q,f[i][j][p][q]);*/
	int ans=0;
	for(int j=0;j<=m+1;++j)
	for(int p=0;p<=k;++p)
		for(int q=0;q<=n;++q)
			aa(ans,f[n][j][p][q]);
	printf("%d\n",ans);
	return 0;
}

