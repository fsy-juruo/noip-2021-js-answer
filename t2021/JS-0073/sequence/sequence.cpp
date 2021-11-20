#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long v[105][35],jc[35],jcinv[35];
int f[105][35][35][35];
int power(long long n,int p)
{
	int s=1;
	for(p;p;p>>=1)
	{
		if((p&1)==1)
		{
			s=s*n%mod;
		}
		n=n*n%mod;
	}
	return s;
}
int lowbit(int n)
{
	return n&(-n);
}
int w(int n)
{
	int s=0;
	while(n>0)
	{
		n-=lowbit(n);
		s++;
	}
	return s;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n,m,q;
	cin>>n>>m>>q;
	jc[0]=1;
	jcinv[0]=1;
	for(int i=1;i<=n;i++)
	{
		jc[i]=jc[i-1]*i%mod;
		jcinv[i]=power(jc[i],998244351);
	}
	for(int i=0;i<=m;i++)
	{
		v[i][0]=1;
		cin>>v[i][1];
		for(int j=2;j<=n;j++)
		{
			v[i][j]=v[i][j-1]*v[i][1]%mod;
		}
	}
	for(int cnt=0;cnt<=n;cnt++)
	{
		f[0][cnt][cnt][0]=v[0][cnt]*jcinv[cnt]%mod;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			for(int k=0;k<=j;k++)
			{
				for(int l=0;l<=q;l++)
				{
					for(int cnt=0;cnt<=k;cnt++)
					{
						for(int la=0;la<2;la++)
						{
							if(l==0&&la==1)
							{
								continue;
							}
							int lak=(k-cnt)*2+la;
							int lal=l-la;
							f[i][j][k][l]=(f[i][j][k][l]+f[i-1][j-cnt][lak][lal]*v[i][cnt]%mod*jcinv[cnt]%mod)%mod;
						}
					}
				}
			}
		}
	}
	long long ans=0;
	for(int k=0;k<=n;k++)
	{
		for(int l=0;l<=q;l++)
		{
			if(l+w(k)<=q)
			{
				ans=(ans+jc[n]*f[m][n][k][l]%mod)%mod;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
//90 points
